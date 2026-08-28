#!/usr/bin/env python3
"""
capture.py — 截图 → OCR → 去重 → 追加日志 → 删图
每 10 秒由 LaunchAgent 调用一次
使用这个命令获取你需要录制的应用↓
    sleep 1; osascript -e "tell application \"System Events\" to get name of first application process whose frontmost is true"
"""

import subprocess
import os
import re
import time
import datetime
from pathlib import Path

# ── 配置 ──────────────────────────────────────────────────────────────
SNAPSHOT_PATH        = str(Path.home() / "screenlogs" / "_snap.png")
DAILY_DIR            = Path.home() / "screenlogs" / "logs"
TESSERACT_BIN        = "/opt/homebrew/bin/tesseract"   # which tesseract
OCR_LANG             = "chi_sim+eng"                   # 繁体改 chi_tra+eng
SIMILARITY_THRESHOLD = 0.72   # 高于此值视为屏幕无变化，跳过
MIN_TEXT_LEN         = 30     # 清洗后文本太短视为噪声，跳过

# 前台 App 白名单；空集合 = 监控所有 App
ALLOWED_APPS = {
        "Feishu",
        "Microsoft Edge"
}

# ── 清洗配置 ──────────────────────────────────────────────────────────
# 整行完全匹配则丢弃（UI 固定字符串）
NOISE_EXACT = {
    "Click the button to save this photo",
    "Write a message...",
    "Show more",
    "View changelog >",
    "其他收藏夹",
    "收藏夹栏",
}

# 行内包含以下正则则丢弃（UI 控件残影）
NOISE_PATTERNS = [re.compile(p) for p in [
    r"[vy][wy]\s*Star\s*[~～]",         # GitHub Star 按钮
    r"Built\s+by\s*[¥Y@©]",             # GitHub 贡献者头像行
    r"^\s*[.·•]\s*$",                   # 孤立句点/点
    r"^\s*[@©®¥€$#*+\-=|\\/<>]{2,}\s*$",  # 纯符号行
]]

# 脏字符比率阈值：超过此比率的行丢弃
DIRTY_CHAR_RATIO = 0.38

# 行最短长度（清洗前，过短直接丢）
MIN_LINE_LEN = 3
# ─────────────────────────────────────────────────────────────────────


def is_clean_char(c: str) -> bool:
    cp = ord(c)
    if 0x20 <= cp <= 0x7E:   return True   # ASCII 可打印
    if 0x4E00 <= cp <= 0x9FFF: return True  # CJK 基本区
    if 0x3400 <= cp <= 0x4DBF: return True  # CJK 扩展 A
    if 0x3000 <= cp <= 0x303F: return True  # CJK 标点
    if 0xFF00 <= cp <= 0xFFEF: return True  # 全角字符
    return False


def is_meaningful_line(line: str) -> bool:
    s = line.strip()
    if len(s) < MIN_LINE_LEN:
        return False
    if s in NOISE_EXACT:
        return False
    for pat in NOISE_PATTERNS:
        if pat.search(s):
            return False
    dirty = sum(1 for c in s if not is_clean_char(c))
    if dirty / len(s) > DIRTY_CHAR_RATIO:
        return False
    return True


def clean_ocr_text(text: str) -> str:
    lines = text.splitlines()
    clean_lines = [l for l in lines if l.strip() and is_meaningful_line(l)]  # 加了 l.strip()
    result = re.sub(r'\n{3,}', '\n\n', '\n'.join(clean_lines))
    return result.strip()


def get_active_app() -> str:
    result = subprocess.run(
        ["osascript", "-e",
         "tell application \"System Events\" to get name of "
         "first application process whose frontmost is true"],
        capture_output=True, text=True
    )
    return result.stdout.strip()


def take_screenshot(path: str) -> None:
    subprocess.run(["screencapture", "-x", "-m", path], check=True)
    for _ in range(20):
        if os.path.exists(path) and os.path.getsize(path) > 0:
            return
        time.sleep(0.1)
    raise RuntimeError(f"截图文件未生成：{path}")


def ocr_image(path: str) -> str:
    result = subprocess.run(
        [TESSERACT_BIN, path, "stdout", "-l", OCR_LANG],
        capture_output=True
    )
    return result.stdout.decode("utf-8", errors="replace").strip()


def trigram_similarity(a: str, b: str) -> float:
    def trigrams(s: str):
        return set(s[i:i+3] for i in range(len(s) - 2))
    ta, tb = trigrams(a), trigrams(b)
    if not ta and not tb: return 1.0
    if not ta or not tb:  return 0.0
    return len(ta & tb) / len(ta | tb)


def get_last_text(daily_file: Path) -> str:
    if not daily_file.exists():
        return ""
    content = daily_file.read_text(encoding="utf-8")
    blocks = [b for b in content.split("\n---\n") if b.strip()]
    if not blocks:
        return ""
    parts = blocks[-1].split("\n", 1)
    return parts[1].strip() if len(parts) > 1 else ""


def append_entry(daily_file: Path, text: str) -> None:
    daily_file.parent.mkdir(parents=True, exist_ok=True)
    ts = datetime.datetime.now().strftime("%H:%M:%S")
    with open(daily_file, "a", encoding="utf-8") as f:
        f.write(f"[{ts}]\n{text}\n---\n")


def main() -> None:
    today      = datetime.date.today().strftime("%Y-%m-%d")
    daily_file = DAILY_DIR / f"{today}.txt"

    try:
        if ALLOWED_APPS and get_active_app() not in ALLOWED_APPS:
            return

        take_screenshot(SNAPSHOT_PATH)
        raw_text   = ocr_image(SNAPSHOT_PATH)
        clean_text = clean_ocr_text(raw_text)

        if len(clean_text) < MIN_TEXT_LEN:
            return

        last_text  = get_last_text(daily_file)
        similarity = trigram_similarity(clean_text, last_text)

        if similarity < SIMILARITY_THRESHOLD:
            append_entry(daily_file, clean_text)

    except Exception as e:
        err_log = DAILY_DIR / "capture_error.log"
        err_log.parent.mkdir(parents=True, exist_ok=True)
        with open(err_log, "a", encoding="utf-8") as f:
            f.write(f"[{datetime.datetime.now()}] {e}\n")
    finally:
        if os.path.exists(SNAPSHOT_PATH):
            os.remove(SNAPSHOT_PATH)


if __name__ == "__main__":
    main()
