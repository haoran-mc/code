#!/usr/bin/env bash
# setup.sh — 在 EndeavourOS (Arch) + KDE Plasma Wayland 上部署 capture.py
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SYSTEMD_USER_DIR="${XDG_CONFIG_HOME:-$HOME/.config}/systemd/user"

# ── 1. 依赖检查 / 安装 ────────────────────────────────────────────────
need_pkgs=()

command -v tesseract >/dev/null || need_pkgs+=(tesseract tesseract-data-chi_sim tesseract-data-eng)
command -v spectacle >/dev/null || need_pkgs+=(spectacle)

if (( ${#need_pkgs[@]} > 0 )); then
    echo ">>> 安装官方仓库依赖: ${need_pkgs[*]}"
    sudo pacman -S --needed --noconfirm "${need_pkgs[@]}"
fi

# kdotool 在 AUR，需要 yay/paru
if ! command -v kdotool >/dev/null; then
    if command -v yay >/dev/null; then
        echo ">>> 安装 AUR 包: kdotool"
        yay -S --needed --noconfirm kdotool
    elif command -v paru >/dev/null; then
        paru -S --needed --noconfirm kdotool
    else
        echo "!!! 未找到 yay/paru，请手动安装 kdotool；若不装则脚本会忽略前台窗口白名单。"
    fi
fi

# ── 2. 目录 & 权限 ───────────────────────────────────────────────────
mkdir -p "$HOME/logs"
chmod +x "$SCRIPT_DIR/capture.py"

# ── 3. 安装 systemd user units ───────────────────────────────────────
mkdir -p "$SYSTEMD_USER_DIR"
install -m 644 "$SCRIPT_DIR/systemd/screen-capture.service" "$SYSTEMD_USER_DIR/"
install -m 644 "$SCRIPT_DIR/systemd/screen-capture.timer"   "$SYSTEMD_USER_DIR/"

systemctl --user daemon-reload
systemctl --user enable --now screen-capture.timer

# 让 timer 在登录前也能跑（可选）
# loginctl enable-linger "$USER"

echo
echo "✅ 部署完成。"
echo "   日志目录:   ~/logs/"
echo "   查看状态:   systemctl --user status screen-capture.timer"
echo "   立即触发:   systemctl --user start screen-capture.service"
echo "   查看日志:   journalctl --user -u screen-capture.service -f"
echo "   停止:       systemctl --user disable --now screen-capture.timer"
