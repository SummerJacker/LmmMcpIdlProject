"""
pytest 配置文件。

目的：让 tests 在“未安装为包”的情况下也能 import 项目根目录模块（如 robot_adapter.py）。
"""

from __future__ import annotations

import sys
from pathlib import Path


PROJECT_ROOT = Path(__file__).resolve().parents[1]
if str(PROJECT_ROOT) not in sys.path:
    sys.path.insert(0, str(PROJECT_ROOT))

