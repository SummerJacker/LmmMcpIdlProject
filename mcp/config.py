"""
项目配置：机器人列表、QT HTTP 端点、速度校验阈值、日志路径等。
"""

from __future__ import annotations

import json
from dataclasses import dataclass
from pathlib import Path
from typing import Any


@dataclass(frozen=True)
class RobotInitConfig:
    """
    @param robot_id: MCP 工具入参（别名，如 robot_1）。
    @param unit_id: 主控台绑定表中的单元 ID（如 GV1、AV1）；缺省则与 robot_id 相同（演示用）。
    @param mode: robots.json 部署意图（sim / real），非主控台运行态；运行态见 list_robots 的 run_mode。
    @param simulator_type: 预留扩展；当前链路不依赖该字段，仅保留 JSON 兼容。
    """

    robot_id: str
    unit_id: str
    mode: str
    simulator_type: str


ROBOTS_CONFIG_PATH: str = str(Path(__file__).resolve().with_name("robots.json"))


def load_robot_configs(config_path: str = ROBOTS_CONFIG_PATH) -> tuple[RobotInitConfig, ...]:
    """
    从 robots.json 读取机器人列表；失败时回退默认 robot_1 / robot_2。

    @param config_path: 配置文件路径
    @returns: RobotInitConfig 元组
    """

    default_configs: tuple[RobotInitConfig, ...] = (
        RobotInitConfig(robot_id="robot_1", unit_id="GV1", mode="sim", simulator_type="sau"),
        RobotInitConfig(robot_id="robot_2", unit_id="GV2", mode="sim", simulator_type="sau"),
    )

    path = Path(config_path)
    if not path.exists():
        return default_configs

    try:
        raw = json.loads(path.read_text(encoding="utf-8"))
        robots = raw.get("robots", [])
        if not isinstance(robots, list) or not robots:
            return default_configs

        configs: list[RobotInitConfig] = []
        for item in robots:
            if not isinstance(item, dict):
                continue
            robot_id = str(item.get("robot_id", "")).strip()
            if not robot_id:
                continue
            unit_id = str(item.get("unit_id", "")).strip() or robot_id
            mode = str(item.get("mode", "sim")).strip()
            simulator_type = str(item.get("simulator_type", "sau")).strip()
            configs.append(
                RobotInitConfig(
                    robot_id=robot_id,
                    unit_id=unit_id,
                    mode=mode,
                    simulator_type=simulator_type,
                )
            )

        return tuple(configs) if configs else default_configs
    except Exception:
        return default_configs


# --- QT HTTP：默认对接 SAU 主控台 HttpPlugin（console -httpPort 9001）---
# QT_HTTP_BASE: str = "http://127.0.0.1:9001"
QT_HTTP_BASE: str = "http://127.0.0.1:9001"
QT_SEND_MOVE_PATH: str = "/api/robot/sendmove"
QT_STOP_PATH: str = "/api/robot/stop"
QT_STOP_ALL_PATH: str = "/api/robot/stop_all"
QT_STATUS_PATH: str = "/api/robot/status"
QT_LIST_PATH: str = "/api/robot/list"
QT_SET_LEADER_PATH: str = "/api/formation/set_leader"
QT_SET_GROUP_MODE_PATH: str = "/api/formation/set_group_mode"
QT_SET_GROUP_MINOR_MODE_PATH: str = "/api/formation/set_group_minor_mode"
QT_TASK_POINT_PATH: str = "/api/task/set_point"
QT_TASK_PATH_PATH: str = "/api/task/set_path"
QT_TRAP_ADD_PATH: str = "/api/trap/add"
QT_TRAP_CLEAR_PATH: str = "/api/trap/clear"
QT_RESET_RELATIONS_PATH: str = "/api/system/reset_relations"
QT_HTTP_TIMEOUT_S: float = 5.0

# --- Agent API v1 路由（Phase 2: 智能体目录、状态与别名系统）---
QT_AGENT_LIST_PATH: str = "/api/agent/list"
QT_AGENT_STATUS_PATH: str = "/api/agent/status"
QT_AGENT_ALIAS_SET_PATH: str = "/api/agent/alias/set"
QT_AGENT_ALIAS_CLEAR_PATH: str = "/api/agent/alias/clear"

# --- MCP-IDL Task-Level API (mcp_swarm_task.idl) ---
QT_GOTO_POSE_PATH: str = "/api/task/goto_pose"
QT_GOTO_POSE_BATCH_PATH: str = "/api/task/goto_pose_batch"
QT_FORMATION_EXECUTE_PATH: str = "/api/formation/execute"
QT_FOLLOW_FORMATION_SEND_PATH: str = "/api/formation/send_follow"
QT_FOLLOW_FORMATION_STATUS_PATH: str = "/api/formation/status"
QT_FOLLOW_FORMATION_TARGET_PATH: str = "/api/formation/goto_target"
QT_TASK_STATUS_PATH: str = "/api/task/status"
QT_TASK_CANCEL_PATH: str = "/api/task/cancel"

# --- 线速度 / 角速度 demo 安全范围 ---
LINEAR_VELOCITY_MAX_ABS_M_S: float = 5.0
ANGULAR_VELOCITY_MAX_ABS_RAD_S: float = 10.0

# --- MCP 工具层：含 HTTP 的整体最大等待 ---
DEFAULT_TOOL_TIMEOUT_S: float = 12.0

LOG_DIR: str = "logs"
LOG_FILE: str = "logs/server.log"


def qt_url(path: str) -> str:
    """
    @param path: 以 / 开头的路径
    @returns: 完整 URL
    """

    base = QT_HTTP_BASE.rstrip("/")
    p = path if path.startswith("/") else f"/{path}"
    return f"{base}{p}"
