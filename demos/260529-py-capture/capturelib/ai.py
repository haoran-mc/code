"""用本地 Ollama 对 OCR 文本降噪。

Ollama 默认监听 http://localhost:11434。
若服务不可用，直接返回原文（降级，不影响主流程）。
"""
import json
import urllib.request
import urllib.error

from .config import OLLAMA_ENABLE, OLLAMA_MODEL, OLLAMA_URL

_PROMPT_TMPL = """\
下面是对屏幕截图做 OCR 后得到的原始文本，其中可能夹杂 UI 控件残影、乱码、无意义符号。
请去掉所有噪声，只保留有实际阅读价值的句子或段落，保持原有语言（中文或英文），不要添加任何解释。
如果全部都是噪声，输出空字符串。

--- OCR 原文 ---
{text}
--- END ---
"""


def denoise(text: str) -> str:
    """把 OCR 文本交给本地 Ollama 模型降噪，返回清洗后的文本。
    OLLAMA_ENABLE=False 或服务不可用时静默降级，返回原文。
    """
    if not OLLAMA_ENABLE:
        return text
    prompt = _PROMPT_TMPL.format(text=text)
    payload = json.dumps({
        "model":  OLLAMA_MODEL,
        "prompt": prompt,
        "stream": False,
    }).encode()

    try:
        req = urllib.request.Request(
            f"{OLLAMA_URL}/api/generate",
            data=payload,
            headers={"Content-Type": "application/json"},
        )
        with urllib.request.urlopen(req, timeout=120) as resp:
            data = json.loads(resp.read())
            return data.get("response", "").strip()
    except Exception:
        return text
