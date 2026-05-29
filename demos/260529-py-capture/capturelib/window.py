"""KDE Wayland 前台窗口信息：class + title"""
import shutil
import subprocess

from .config import ALLOWED_APP_CLASSES


def get_active_window() -> tuple[str, str]:
    """返回 (class_lower, title)；取不到则返回空串。"""
    if not shutil.which("kdotool"):
        return "", ""
    try:
        wid = subprocess.run(
            ["kdotool", "getactivewindow"],
            capture_output=True, text=True, timeout=2,
        ).stdout.strip()
        if not wid:
            return "", ""
        cls = subprocess.run(
            ["kdotool", "getwindowclassname", wid],
            capture_output=True, text=True, timeout=2,
        ).stdout.strip()
        title = subprocess.run(
            ["kdotool", "getwindowname", wid],
            capture_output=True, text=True, timeout=2,
        ).stdout.strip()
        return cls.lower(), title
    except Exception:
        return "", ""


def app_allowed(cls: str) -> bool:
    if not ALLOWED_APP_CLASSES:
        return True
    if not cls:
        # 取不到窗口信息时放行，避免漏记
        return True
    return any(key in cls for key in ALLOWED_APP_CLASSES)
