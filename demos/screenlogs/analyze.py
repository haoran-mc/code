#!/usr/bin/env python3
"""
analyze.py — 读取今日日志 → 去重压缩 → Claude API 分析 → 输出建议
用法：python3 analyze.py [YYYY-MM-DD]（不传日期则分析今天）

依赖：pip3 install anthropic
环境变量：ANTHROPIC_API_KEY
"""

import sys
import datetime
from pathlib import Path

try:
    import anthropic
except ImportError:
    print("请先安装：pip3 install anthropic")
    sys.exit(1)

# ── 配置 ──────────────────────────────────────────────────────────────
DAILY_DIR      = Path.home() / "screenlogs" / "logs"
MODEL          = "claude-opus-4-5"
MAX_CHARS      = 40000   # 压缩后喂给 API 的上限
# ─────────────────────────────────────────────────────────────────────


def load_log(date_str: str) -> str:
    daily_file = DAILY_DIR / f"{date_str}.txt"
    if not daily_file.exists():
        print(f"找不到日志文件：{daily_file}")
        sys.exit(1)
    return daily_file.read_text(encoding="utf-8")


def extract_entries(raw: str) -> list[tuple[str, str]]:
    """返回 [(timestamp, text), ...]"""
    entries = []
    for block in raw.split("\n---\n"):
        block = block.strip()
        if not block:
            continue
        lines = block.split("\n", 1)
        if len(lines) == 2:
            ts   = lines[0].strip("[]")
            text = lines[1].strip()
            if text:
                entries.append((ts, text))
    return entries


def trigram_similarity(a: str, b: str) -> float:
    def trigrams(s):
        return set(s[i:i+3] for i in range(len(s) - 2))
    ta, tb = trigrams(a), trigrams(b)
    if not ta and not tb:
        return 1.0
    if not ta or not tb:
        return 0.0
    return len(ta & tb) / len(ta | tb)


def deduplicate(entries: list[tuple[str, str]], threshold=0.8) -> list[tuple[str, str]]:
    """
    相邻去重：连续相似度 > threshold 的条目只保留第一条。
    比 capture.py 的阈值更严格，做二次压缩。
    """
    if not entries:
        return []
    result = [entries[0]]
    for ts, text in entries[1:]:
        if trigram_similarity(text, result[-1][1]) < threshold:
            result.append((ts, text))
    return result


def build_prompt(entries: list[tuple[str, str]], date_str: str) -> str:
    # 把去重后的条目拼接为时间线文本，超出 MAX_CHARS 则截断
    lines = []
    total = 0
    for ts, text in entries:
        chunk = f"[{ts}] {text}\n"
        if total + len(chunk) > MAX_CHARS:
            lines.append("...(内容过长，已截断)...")
            break
        lines.append(chunk)
        total += len(chunk)

    timeline = "\n".join(lines)

    return f"""以下是 {date_str} 这一天，用户屏幕上的文字内容（OCR 采集，按时间排列，已去重）。

内容涵盖用户查看的网页、文档、代码、聊天等，可能混有 UI 控件文字，请自行过滤。

{timeline}

请完成以下分析：

## 一、今日关注点总结
用 3-5 句话概括用户今天主要在做什么、关注什么话题。

## 二、值得深入的方向
列出 2-3 个今天触及但可能还不够深入的主题，说明为什么值得深挖。

## 三、书籍推荐
推荐 3-5 本书，每本注明：书名、推荐理由（结合今天的具体内容）、适合哪个阶段读。

## 四、文章 / 资源推荐
推荐 3-5 篇文章、文档或学习资源，说明推荐理由。

## 五、一句话建议
给用户今天的状态或工作方式一条直接的、可执行的建议。
"""


def analyze(date_str: str) -> None:
    print(f"加载 {date_str} 日志...")
    raw     = load_log(date_str)
    entries = extract_entries(raw)
    print(f"原始条目：{len(entries)} 条")

    entries = deduplicate(entries)
    print(f"去重后：{len(entries)} 条，开始分析...\n")

    prompt = build_prompt(entries, date_str)
    client = anthropic.Anthropic()

    with client.messages.stream(
        model=MODEL,
        max_tokens=2000,
        messages=[{"role": "user", "content": prompt}]
    ) as stream:
        for text in stream.text_stream:
            print(text, end="", flush=True)

    print("\n")


if __name__ == "__main__":
    date_str = sys.argv[1] if len(sys.argv) > 1 else datetime.date.today().strftime("%Y-%m-%d")
    analyze(date_str)
