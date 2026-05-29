"""每日日志的读写"""
import datetime
from pathlib import Path


def get_last_text(daily_file: Path) -> str:
    if not daily_file.exists():
        return ""
    content = daily_file.read_text(encoding="utf-8")
    blocks = [b for b in content.split("\n---\n") if b.strip()]
    if not blocks:
        return ""
    parts = blocks[-1].split("\n", 1)
    return parts[1].strip() if len(parts) > 1 else ""


def append_entry(daily_file: Path, text: str, app: str, title: str) -> None:
    daily_file.parent.mkdir(parents=True, exist_ok=True)
    ts = datetime.datetime.now().strftime("%H:%M:%S")
    header = f"[{ts}][{app or '?'}]"
    if title:
        header += f" {title}"
    with open(daily_file, "a", encoding="utf-8") as f:
        f.write(f"{header}\n{text}\n---\n")


def log_error(err_dir: Path, msg: str) -> None:
    err_dir.mkdir(parents=True, exist_ok=True)
    with open(err_dir / "capture_error.log", "a") as f:
        f.write(f"[{datetime.datetime.now()}] {msg}\n")
