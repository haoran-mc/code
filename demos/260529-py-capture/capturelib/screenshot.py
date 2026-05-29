"""截屏 + OCR"""
import os
import subprocess
import time
from pathlib import Path

from .config import OCR_LANG, TESSERACT_BIN


def take_screenshot(path: str) -> None:
    Path(path).parent.mkdir(parents=True, exist_ok=True)
    # spectacle: -b 无 UI，-n 不通知，-f 全屏，-o 输出文件
    subprocess.run(
        ["spectacle", "-b", "-n", "-f", "-o", path],
        check=True, capture_output=True, timeout=10,
    )
    for _ in range(20):
        if os.path.exists(path) and os.path.getsize(path) > 0:
            return
        time.sleep(0.1)
    raise RuntimeError(f"截图文件未生成：{path}")


def ocr_image(path: str) -> str:
    result = subprocess.run(
        [TESSERACT_BIN, path, "stdout", "-l", OCR_LANG],
        capture_output=True,
    )
    return result.stdout.decode("utf-8", errors="replace").strip()
