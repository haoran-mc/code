#!/usr/bin/env python3
"""capture.py — 入口脚本，由 systemd user timer 每 10 秒触发一次。

具体逻辑都在 capturelib/ 包里。
"""
import datetime
import os
import sys
from pathlib import Path

# 允许从任意 cwd 启动（systemd 默认 cwd=/）
sys.path.insert(0, str(Path(__file__).resolve().parent))

from capturelib.ai import denoise
from capturelib.clean import clean_ocr_text, trigram_similarity
from capturelib.config import (
    DAILY_DIR,
    MIN_TEXT_LEN,
    SIMILARITY_THRESHOLD,
    SNAPSHOT_PATH,
)
from capturelib.log import append_entry, get_last_text, log_error
from capturelib.screenshot import ocr_image, take_screenshot
from capturelib.window import app_allowed, get_active_window


def main() -> None:
    daily_file = DAILY_DIR / f"{datetime.date.today():%Y%m%d}.txt"

    try:
        app_cls, win_title = get_active_window()
        if not app_allowed(app_cls):
            return

        take_screenshot(SNAPSHOT_PATH)
        clean_text = denoise(clean_ocr_text(ocr_image(SNAPSHOT_PATH)))
        if len(clean_text) < MIN_TEXT_LEN:
            return

        if trigram_similarity(clean_text, get_last_text(daily_file)) < SIMILARITY_THRESHOLD:
            append_entry(daily_file, clean_text, app_cls, win_title)

    except Exception as e:
        log_error(DAILY_DIR, str(e))
    finally:
        if os.path.exists(SNAPSHOT_PATH):
            try:
                os.remove(SNAPSHOT_PATH)
            except OSError:
                pass


if __name__ == "__main__":
    main()
