"""OCR 文本清洗 + trigram 相似度"""
import re

# ── CJK 间距标准化 ──────────────────────────────────────────────────
# 所有正则使用普通字符串（非 raw string），确保 \u 被解析为 Unicode

_CJK  = '[\u4e00-\u9fff\u3400-\u4dbf\u3000-\u303f\uff00-\uffef]'
_PUNC = r'[?!,.:;()\[\]{}\'"<>%]'   # OCR 常见 ASCII 标点

# 1. CJK 与 CJK 之间的空格
_RE_CJK_CJK   = re.compile(f'(?<={_CJK}) +(?={_CJK})')
# 2. CJK 后接 ASCII 标点前的空格：'模式 ?' → '模式?'
_RE_CJK_PUNC  = re.compile(f'(?<={_CJK}) +(?={_PUNC})')
# 3. ASCII 标点后接 CJK 前的空格：', 追求' → ',追求'
_RE_PUNC_CJK  = re.compile(f'(?<={_PUNC}) +(?={_CJK})')


def normalize_cjk_spaces(text: str) -> str:
    """去除 OCR 在中文排版中强插的多余空格。"""
    text = _RE_CJK_CJK.sub('', text)
    text = _RE_CJK_PUNC.sub('', text)
    text = _RE_PUNC_CJK.sub('', text)
    return text


from .config import (
    DIRTY_CHAR_RATIO,
    MIN_LINE_LEN,
    NOISE_EXACT,
    NOISE_PATTERNS,
)


def is_clean_char(c: str) -> bool:
    cp = ord(c)
    if 0x20 <= cp <= 0x7E:     return True
    if 0x4E00 <= cp <= 0x9FFF: return True
    if 0x3400 <= cp <= 0x4DBF: return True
    if 0x3000 <= cp <= 0x303F: return True
    if 0xFF00 <= cp <= 0xFFEF: return True
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
    # 短行且空格比率高 → UI 图标/书签行（normalize 后 CJK 已压缩，剩余空格都是可疑的）
    if len(s) <= 20 and s.count(' ') / len(s) > 0.20:
        return False
    return True


def clean_ocr_text(text: str) -> str:
    # 先整体去掉 CJK 间空格，再按行过滤，最后去掉所有空行
    text = normalize_cjk_spaces(text)
    lines = text.splitlines()
    clean_lines = [l for l in lines if is_meaningful_line(l) and l.strip()]
    return '\n'.join(clean_lines)


def trigram_similarity(a: str, b: str) -> float:
    def trigrams(s: str):
        return set(s[i:i+3] for i in range(len(s) - 2))
    ta, tb = trigrams(a), trigrams(b)
    if not ta and not tb: return 1.0
    if not ta or not tb:  return 0.0
    return len(ta & tb) / len(ta | tb)
