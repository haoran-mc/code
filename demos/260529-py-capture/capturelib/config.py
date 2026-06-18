"""统一配置项"""
from pathlib import Path
import re

SNAPSHOT_PATH        = str(Path.home() / "_snap.png")
DAILY_DIR            = Path.home() / "logs"
TESSERACT_BIN        = "/usr/bin/tesseract"
OCR_LANG             = "chi_sim+eng"   # 繁体改 chi_tra+eng
SIMILARITY_THRESHOLD = 0.72            # 高于此值视为屏幕无变化，跳过
MIN_TEXT_LEN         = 5               # 清洗后文本太短视为噪声，跳过

# 前台窗口 class 白名单（小写，子串匹配）。空集合 = 监控所有窗口
ALLOWED_APP_CLASSES = {
    "microsoft-edge",
}

# ── 清洗配置 ──────────────────────────────────────────────────────────
NOISE_EXACT = {
    "Click the button to save this photo",
    "Write a message...",
    "Show more",
    "View changelog >",
    "其他收藏夹",
    "收藏夹栏",
}

NOISE_PATTERNS = [re.compile(p) for p in [
    r"[vy][wy]\s*Star\s*[~～]",
    r"Built\s+by\s*[¥Y@©]",
    r"^\s*[.·•]\s*$",
    r"^\s*[@©®¥€$#*+\-=|\\/<>]{2,}\s*$",
    # ── 浏览器 UI 残影 ────────────────────────────────────────────────
    r"Ctrl\+",                                # 键盘快捷键标签（如 Ctrl+T）
    r"^\s*©\)",                              # 书签图标行 ©) 开头
    r"^\s*[&©]\s*[\"C\u81ea]",             # 地址栏残影 & "C 自
    r"Microsoft[\u200b\s]*Edge",             # 浏览器窗口标题后缀
    r"^\s*%\s+\w{1,20}\s*$",               # % username 行（如 % lidang）
    r"^\s*[A-Z\d]{2,7}\s*$",                  # 纯大写/数字乱码（SRR / L3RR 等）
    r"\b(saner|subs|anking|doeler|Emojing|boak|lidang)\b",  # 书签栏固定字符串
    r"^[\s\d]{0,4}[A-Za-z]{1,3}[\s\d]{0,4}$",  # 极短字母+数字混合行（如 5 于 -、克 f）
    r"^\s*&\s+[A-Z]",                          # 书签行 & Site Name
]]

DIRTY_CHAR_RATIO = 0.38
MIN_LINE_LEN     = 3

# ── Ollama 降噪（可选） ───────────────────────────────────────────────
# 设为 False 跳过 AI 降噪
OLLAMA_ENABLE = True
OLLAMA_URL    = "http://localhost:11434"
OLLAMA_MODEL  = "qwen2.5:1.5b"
