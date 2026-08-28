#!/bin/bash
# setup.sh — 一键安装、配置、启动 screenlogs
# 用法：bash setup.sh

set -e

INSTALL_DIR="$HOME/screenlogs"
SCRIPTS_DIR="$INSTALL_DIR/scripts"
LOGS_DIR="$INSTALL_DIR/logs"
PLIST_NAME="com.user.screenlogs"
PLIST_DST="$HOME/Library/LaunchAgents/$PLIST_NAME.plist"

echo "=== screenlogs setup ==="

# ── 1. 检查 Homebrew ─────────────────────────────────────────────────
if ! command -v brew &>/dev/null; then
    echo "[错误] 未检测到 Homebrew，请先安装：https://brew.sh"
    exit 1
fi

# ── 2. 安装 tesseract + 语言包 ───────────────────────────────────────
echo "[1/4] 安装 tesseract..."
brew install tesseract tesseract-lang 2>/dev/null || true

# ── 3. 安装 Python 依赖 ──────────────────────────────────────────────
echo "[2/4] 安装 Python 依赖..."
pip3 install anthropic --quiet

# ── 4. 部署脚本文件 ──────────────────────────────────────────────────
echo "[3/4] 部署脚本..."
mkdir -p "$SCRIPTS_DIR" "$LOGS_DIR"

SCRIPT_DIR_REAL="$(cd "$(dirname "$0")" && pwd)"
cp "$SCRIPT_DIR_REAL/capture.py"  "$SCRIPTS_DIR/"
cp "$SCRIPT_DIR_REAL/analyze.py"  "$SCRIPTS_DIR/"
chmod +x "$SCRIPTS_DIR/capture.py" "$SCRIPTS_DIR/analyze.py"

# ── 5. 注册 LaunchAgent ──────────────────────────────────────────────
echo "[4/4] 注册 LaunchAgent..."
PYTHON3_PATH="$(which python3)"
CAPTURE_PATH="$SCRIPTS_DIR/capture.py"

# 把 plist 模板里的占位符替换为实际路径
sed \
    -e "s|PYTHON3_PATH|$PYTHON3_PATH|g" \
    -e "s|CAPTURE_SCRIPT_PATH|$CAPTURE_PATH|g" \
    "$SCRIPT_DIR_REAL/com.user.screenlogs.plist" > "$PLIST_DST"

# 卸载旧的（如果有）
launchctl unload "$PLIST_DST" 2>/dev/null || true
launchctl load "$PLIST_DST"

echo ""
echo "✅ 安装完成！"
echo ""
echo "  日志目录：$LOGS_DIR"
echo "  每天日志：$LOGS_DIR/YYYY-MM-DD.txt"
echo ""
echo "  分析今日内容："
echo "    ANTHROPIC_API_KEY=sk-xxx python3 $SCRIPTS_DIR/analyze.py"
echo ""
echo "  分析指定日期："
echo "    ANTHROPIC_API_KEY=sk-xxx python3 $SCRIPTS_DIR/analyze.py 2025-05-25"
echo ""
echo "  停止采集："
echo "    launchctl unload $PLIST_DST"
echo ""
echo "  查看实时错误："
echo "    tail -f /tmp/screenlogs_stderr.log"

# ── 提示：需要授予辅助功能权限 ──────────────────────────────────────
echo ""
echo "⚠️  首次运行 screencapture 需要授权："
echo "   系统设置 → 隐私与安全性 → 屏幕录制 → 勾选 Terminal（或你的终端 App）"
