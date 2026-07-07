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

# ---- Configurable limits ----
MAX_TARGET_DISTANCE_M = 100.0
MIN_TOLERANCE_M = 0.02
MAX_BATCH_SIZE = 10
MAX_TARGET_COORD = 1000.0


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

    for i, t in enumerate(targets):
        if not isinstance(t, dict):
            return False, ERR_SAFETY_REJECTED, f"targets[{i}] is not a JSON object", i

        uid = str(t.get("unit_id", "")).strip()
        if not uid:
            return False, ERR_SAFETY_REJECTED, f"targets[{i}] missing unit_id", i

        x_raw = t.get("x")
        y_raw = t.get("y")
        try:
            x = float(x_raw)
            y = float(y_raw)
        except (TypeError, ValueError):
            return False, ERR_SAFETY_REJECTED, f"targets[{i}] has invalid x or y", i

        passed, err_code, msg = validate_goto_pose(uid, x, y, 0.3, 0.6, tolerance_m)
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
