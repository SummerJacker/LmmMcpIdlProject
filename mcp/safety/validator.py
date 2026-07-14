"""
MCP-IDL 安全校验层 (MCP Server 侧)。

在发送 HTTP 请求到 Console 之前进行客户端侧预检，
与 Console 侧 SafetyValidator (C++) 形成双重校验。

对应 mcp_swarm_task.idl 中定义的 ErrorCode 常量。
"""

from __future__ import annotations

import math
from typing import Any

from config import LINEAR_VELOCITY_MAX_ABS_M_S, ANGULAR_VELOCITY_MAX_ABS_RAD_S


# ---- Error codes (mirrors mcp_swarm_task.idl) ----
ERR_OK = ""
ERR_UNIT_NOT_FOUND = "UNIT_NOT_FOUND"
ERR_UNIT_OFFLINE = "UNIT_OFFLINE"
ERR_UNIT_BUSY = "UNIT_BUSY"
ERR_TARGET_OUT_OF_BOUNDS = "TARGET_OUT_OF_BOUNDS"
ERR_SPEED_OUT_OF_BOUNDS = "SPEED_OUT_OF_BOUNDS"
ERR_DISTANCE_TOO_FAR = "DISTANCE_TOO_FAR"
ERR_SAFETY_REJECTED = "SAFETY_REJECTED"
ERR_FORMATION_NOT_READY = "FORMATION_NOT_READY"
ERR_FORMATION_CONFLICT = "FORMATION_CONFLICT"
ERR_TASK_CONFLICT = "TASK_CONFLICT"

# ---- Configurable limits ----
MAX_TARGET_DISTANCE_M = 100.0
MIN_TOLERANCE_M = 0.02
MAX_BATCH_SIZE = 10
MAX_TARGET_COORD = 1000.0
MIN_FOLLOW_DISTANCE_M = 0.5
MAX_FOLLOW_DISTANCE_M = 20.0


def validate_follow_target(x: float, y: float) -> tuple[bool, str, str]:
    """Validate the Leader target used by persistent follow formations."""

    if not math.isfinite(x) or not math.isfinite(y):
        return False, ERR_TARGET_OUT_OF_BOUNDS, "target coordinates must be finite numbers"
    if abs(x) > MAX_TARGET_COORD or abs(y) > MAX_TARGET_COORD:
        return False, ERR_TARGET_OUT_OF_BOUNDS, (
            f"target ({x:.1f}, {y:.1f}) exceeds max coordinate {MAX_TARGET_COORD}"
        )
    return True, ERR_OK, ""


def validate_follow_distance(distance_m: float) -> tuple[bool, str, str]:
    """Validate one requested follower spacing before any float conversion."""

    if not math.isfinite(distance_m):
        return False, ERR_SAFETY_REJECTED, "distance_m must be a finite number"
    if distance_m < MIN_FOLLOW_DISTANCE_M or distance_m > MAX_FOLLOW_DISTANCE_M:
        return False, ERR_SAFETY_REJECTED, (
            f"distance_m must be between {MIN_FOLLOW_DISTANCE_M} and "
            f"{MAX_FOLLOW_DISTANCE_M} metres"
        )
    return True, ERR_OK, ""


def validate_navigate_to(
    unit_id: str,
    x: float,
    y: float,
    tolerance_m: float,
) -> tuple[bool, str, str]:
    """Validate the production x/y-only navigation contract."""

    if not unit_id or not unit_id.strip():
        return False, ERR_SAFETY_REJECTED, "unit_id is empty"
    if not unit_id.strip().upper().startswith("G"):
        return False, ERR_SAFETY_REJECTED, "target-point navigation supports ground units only"
    if not math.isfinite(x) or not math.isfinite(y):
        return False, ERR_TARGET_OUT_OF_BOUNDS, "target coordinates must be finite numbers"
    if abs(x) > MAX_TARGET_COORD or abs(y) > MAX_TARGET_COORD:
        return False, ERR_TARGET_OUT_OF_BOUNDS, (
            f"target ({x:.1f}, {y:.1f}) exceeds max coordinate {MAX_TARGET_COORD}"
        )
    if not math.isfinite(tolerance_m) or tolerance_m < MIN_TOLERANCE_M:
        return False, ERR_SAFETY_REJECTED, (
            f"tolerance_m {tolerance_m} is below minimum {MIN_TOLERANCE_M}"
        )
    return True, ERR_OK, ""


def validate_goto_pose(
    unit_id: str,
    x: float,
    y: float,
    linear_speed_m_s: float,
    angular_speed_rad_s: float,
    tolerance_m: float,
) -> tuple[bool, str, str]:
    """
    校验单点导航参数。

    @returns: (passed: bool, error_code: str, message: str)
    """
    if not unit_id or not unit_id.strip():
        return False, ERR_SAFETY_REJECTED, "unit_id is empty"

    if not math.isfinite(x) or not math.isfinite(y):
        return False, ERR_TARGET_OUT_OF_BOUNDS, "target coordinates must be finite numbers"

    if abs(x) > MAX_TARGET_COORD or abs(y) > MAX_TARGET_COORD:
        return False, ERR_TARGET_OUT_OF_BOUNDS, (
            f"target ({x:.1f}, {y:.1f}) exceeds max coordinate {MAX_TARGET_COORD}"
        )

    if abs(linear_speed_m_s) > LINEAR_VELOCITY_MAX_ABS_M_S:
        return False, ERR_SPEED_OUT_OF_BOUNDS, (
            f"linear speed {linear_speed_m_s} exceeds max {LINEAR_VELOCITY_MAX_ABS_M_S} m/s"
        )

    if abs(angular_speed_rad_s) > ANGULAR_VELOCITY_MAX_ABS_RAD_S:
        return False, ERR_SPEED_OUT_OF_BOUNDS, (
            f"angular speed {angular_speed_rad_s} exceeds max {ANGULAR_VELOCITY_MAX_ABS_RAD_S} rad/s"
        )

    if tolerance_m < MIN_TOLERANCE_M:
        return False, ERR_SAFETY_REJECTED, (
            f"tolerance_m {tolerance_m} is below minimum {MIN_TOLERANCE_M}"
        )

    return True, ERR_OK, ""


def validate_goto_pose_batch(
    targets: list[dict[str, Any]],
    tolerance_m: float,
) -> tuple[bool, str, str, int | None]:
    """
    校验批量导航参数。

    @returns: (passed, error_code, message, failed_index | None)
    """
    if not targets:
        return False, ERR_SAFETY_REJECTED, "targets list is empty", None

    if len(targets) > MAX_BATCH_SIZE:
        return False, ERR_SAFETY_REJECTED, (
            f"batch size {len(targets)} exceeds max {MAX_BATCH_SIZE}"
        ), None

    seen: set[str] = set()
    for i, t in enumerate(targets):
        if not isinstance(t, dict):
            return False, ERR_SAFETY_REJECTED, f"targets[{i}] is not a JSON object", i

        uid = str(t.get("unit_id", "")).strip()
        if not uid:
            return False, ERR_SAFETY_REJECTED, f"targets[{i}] missing unit_id", i
        if uid in seen:
            return False, ERR_SAFETY_REJECTED, f"targets[{i}] duplicates unit_id {uid}", i
        seen.add(uid)

        x_raw = t.get("x")
        y_raw = t.get("y")
        try:
            x = float(x_raw)
            y = float(y_raw)
        except (TypeError, ValueError):
            return False, ERR_SAFETY_REJECTED, f"targets[{i}] has invalid x or y", i

        passed, err_code, msg = validate_navigate_to(uid, x, y, tolerance_m)
        if not passed:
            return False, err_code, f"targets[{i}] ({uid}): {msg}", i

    return True, ERR_OK, "", None


def validate_formation(
    formation_type: str,
    unit_ids: list[str],
    spacing_m: float,
) -> tuple[bool, str, str]:
    """
    校验编队请求。

    @returns: (passed, error_code, message)
    """
    valid_types = ("line", "triangle", "column")
    if formation_type not in valid_types:
        return False, ERR_SAFETY_REJECTED, (
            f"unknown formation_type '{formation_type}'; expected one of {valid_types}"
        )

    if not unit_ids:
        return False, ERR_SAFETY_REJECTED, (
            "unit_ids is empty; provide explicit unit_ids or ensure auto-selection is available"
        )

    n = len(unit_ids)
    if formation_type == "line" and n < 2:
        return False, ERR_SAFETY_REJECTED, "line formation requires at least 2 units"
    if formation_type == "triangle" and n < 3:
        return False, ERR_SAFETY_REJECTED, "triangle formation requires at least 3 units"
    if formation_type == "column" and n < 2:
        return False, ERR_SAFETY_REJECTED, "column formation requires at least 2 units"

    if spacing_m <= 0.0 or spacing_m > 50.0:
        return False, ERR_SAFETY_REJECTED, "spacing_m must be > 0 and <= 50"

    return True, ERR_OK, ""


# =============================================================================
# 编队任务级校验 (FormationMissionOrchestrator 用)
# =============================================================================

def validate_formation_mission(
    formation_type: str,
    unit_ids: list[str],
    leader_id: str | None,
    spacing_m: float,
    existing_formation: bool = False,
) -> tuple[bool, str, str]:
    """
    校验编队任务请求（任务级编排器入口校验）。

    比 validate_formation 更全面：检查领航者有效性、编队冲突等。

    @param formation_type: 编队类型
    @param unit_ids: 参与智能体列表
    @param leader_id: 指定领航者，None=自动选择
    @param spacing_m: 间距
    @param existing_formation: 是否已有活跃编队
    @returns: (passed, error_code, message)
    """
    # 基础参数校验
    passed, err_code, msg = validate_formation(formation_type, unit_ids, spacing_m)
    if not passed:
        return False, err_code, msg

    # 编队冲突检查：是否已有活跃编队
    if existing_formation:
        return False, ERR_FORMATION_CONFLICT, (
            "已有活跃编队存在，请先取消当前编队或等待其完成后再发起新编队"
        )

    # 领航者有效性检查
    if leader_id is not None:
        leader = leader_id.strip()
        if not leader:
            return False, ERR_SAFETY_REJECTED, "leader_id 不能为空"
        if leader not in unit_ids:
            return False, ERR_UNIT_NOT_FOUND, (
                f"指定的领航者 {leader} 不在参与智能体列表中: {unit_ids}"
            )

    # 去重检查
    if len(set(unit_ids)) != len(unit_ids):
        return False, ERR_SAFETY_REJECTED, "unit_ids 中存在重复的智能体 ID"

    return True, ERR_OK, ""


def validate_unit_available(
    unit_id: str,
    unit_data: dict | None,
) -> tuple[bool, str, str]:
    """
    检查单个智能体是否可用（在线、无故障、可接受任务）。

    @param unit_id: 智能体 ID
    @param unit_data: 智能体状态数据（来自 get_robot_status），None = 不在线
    @returns: (passed, error_code, message)
    """
    if unit_data is None:
        return False, ERR_UNIT_OFFLINE, f"智能体 {unit_id} 不在线或无法查询状态"

    # 检查基本在线状态
    online = unit_data.get("online", True)  # 默认 True（无此字段时假定在线）
    if online is False:
        return False, ERR_UNIT_OFFLINE, f"智能体 {unit_id} 当前离线"

    # 检查故障状态
    fault = unit_data.get("fault", unit_data.get("error", ""))
    if fault:
        return False, ERR_UNIT_BUSY, f"智能体 {unit_id} 存在故障: {fault}"

    return True, ERR_OK, ""


def validate_formation_feasible(
    unit_positions: dict[str, tuple[float, float]],
    formation_type: str,
    spacing_m: float,
    max_initial_distance_m: float = 10.0,
) -> tuple[bool, str, str]:
    """
    检查编队是否可行：各智能体初始位置不能相距太远。

    @param unit_positions: {unit_id: (x, y), ...}
    @param formation_type: 编队类型
    @param spacing_m: 目标间距
    @param max_initial_distance_m: 最大初始距离（超过则拒绝）
    @returns: (passed, error_code, message)
    """
    if len(unit_positions) < 2:
        return True, ERR_OK, ""  # 单智能体不需要检查距离

    positions = list(unit_positions.values())
    max_dist = 0.0
    for i in range(len(positions)):
        for j in range(i + 1, len(positions)):
            dx = positions[i][0] - positions[j][0]
            dy = positions[i][1] - positions[j][1]
            dist = math.hypot(dx, dy)
            if dist > max_dist:
                max_dist = dist

    if max_dist > max_initial_distance_m:
        return False, ERR_DISTANCE_TOO_FAR, (
            f"智能体间最大初始距离 {max_dist:.1f}m 超过限制 {max_initial_distance_m:.1f}m，"
            f"请先让智能体靠近后再编队"
        )

    return True, ERR_OK, ""


def validate_move_formation(
    has_active_formation: bool,
    is_ready: bool,
) -> tuple[bool, str, str]:
    """
    检查是否可以移动编队。

    @param has_active_formation: 是否有活跃编队
    @param is_ready: 编队是否就绪
    @returns: (passed, error_code, message)
    """
    if not has_active_formation:
        return False, ERR_FORMATION_NOT_READY, (
            "没有活跃编队。请先使用 execute_formation_mission 建立编队"
        )

    if not is_ready:
        return False, ERR_FORMATION_NOT_READY, (
            "当前编队未就绪，无法移动。请等待编队建立完成或检查编队状态"
        )

    return True, ERR_OK, ""


def check_task_conflict(
    unit_ids: list[str],
    active_tasks: list[dict],
) -> tuple[bool, str, str]:
    """
    检查指定智能体是否已有冲突任务。

    @param unit_ids: 要检查的智能体列表
    @param active_tasks: 当前活跃任务列表 [{"unit_id":"GV1","task_type":"..."}, ...]
    @returns: (passed, error_code, message)
    """
    for task in active_tasks:
        task_unit = task.get("unit_id", "")
        if task_unit in unit_ids:
            return False, ERR_TASK_CONFLICT, (
                f"智能体 {task_unit} 正在执行任务 {task.get('task_type', 'unknown')}，"
                f"无法参与编队"
            )

    return True, ERR_OK, ""
