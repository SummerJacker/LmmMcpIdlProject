"""
日志初始化与 logger 工具方法。

要求：将运行日志写入 `logs/server.log`，并尽量在控制台也可见，便于调试演示。
"""

from __future__ import annotations

import logging
import os
from logging.handlers import RotatingFileHandler


def setup_logging(*, log_file: str, level: str = "INFO") -> logging.Logger:
    """
    初始化日志系统（只初始化一次，避免重复输出）。

    @param log_file: 日志文件路径，如 'logs/server.log'
    @param level: 日志等级字符串，如 'DEBUG' / 'INFO'
    @returns: 根 logger
    """

    root_logger = logging.getLogger()
    if root_logger.handlers:
        return root_logger

    os.makedirs(os.path.dirname(log_file), exist_ok=True)

    numeric_level = getattr(logging, level.upper(), logging.INFO)
    root_logger.setLevel(numeric_level)

    formatter = logging.Formatter(
        fmt="%(asctime)s [%(levelname)s] %(name)s: %(message)s",
        datefmt="%Y-%m-%d %H:%M:%S",
    )

    file_handler = RotatingFileHandler(log_file, maxBytes=2 * 1024 * 1024, backupCount=3, encoding="utf-8")
    file_handler.setLevel(numeric_level)
    file_handler.setFormatter(formatter)

    console_handler = logging.StreamHandler()
    console_handler.setLevel(numeric_level)
    console_handler.setFormatter(formatter)

    root_logger.addHandler(file_handler)
    root_logger.addHandler(console_handler)
    return root_logger


def get_logger(name: str) -> logging.Logger:
    """
    获取 logger（setup_logging 之后再调用更合适）。

    @param name: logger 名称
    @returns: logger 对象
    """

    return logging.getLogger(name)

