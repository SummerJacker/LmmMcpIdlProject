"""
MCP-IDL Safety Validation Layer.

客户端侧安全预检，在发送 HTTP 请求到 Console 之前进行校验，
与 Console 侧 SafetyValidator (C++) 形成双重校验。

包含:
- 导航参数校验 (goto_pose / goto_pose_batch)
- 编队参数校验 (formation)
- 任务冲突检测 (task conflict)
- 运动安全校验 (motion safety)
"""

from safety.validator import (
    # Error codes
    ERR_OK,
    ERR_UNIT_NOT_FOUND,
    ERR_UNIT_OFFLINE,
    ERR_UNIT_BUSY,
    ERR_TARGET_OUT_OF_BOUNDS,
    ERR_SPEED_OUT_OF_BOUNDS,
    ERR_DISTANCE_TOO_FAR,
    ERR_SAFETY_REJECTED,
    ERR_FORMATION_NOT_READY,
    ERR_FORMATION_CONFLICT,
    ERR_TASK_CONFLICT,
    # Configurable limits
    MAX_TARGET_DISTANCE_M,
    MIN_TOLERANCE_M,
    MAX_BATCH_SIZE,
    MAX_TARGET_COORD,
    # Validation functions
    validate_goto_pose,
    validate_goto_pose_batch,
    validate_formation,
    validate_formation_mission,
    validate_unit_available,
    validate_formation_feasible,
    validate_move_formation,
    check_task_conflict,
)

__all__ = [
    "ERR_OK",
    "ERR_UNIT_NOT_FOUND",
    "ERR_UNIT_OFFLINE",
    "ERR_UNIT_BUSY",
    "ERR_TARGET_OUT_OF_BOUNDS",
    "ERR_SPEED_OUT_OF_BOUNDS",
    "ERR_DISTANCE_TOO_FAR",
    "ERR_SAFETY_REJECTED",
    "ERR_FORMATION_NOT_READY",
    "ERR_FORMATION_CONFLICT",
    "ERR_TASK_CONFLICT",
    "MAX_TARGET_DISTANCE_M",
    "MIN_TOLERANCE_M",
    "MAX_BATCH_SIZE",
    "MAX_TARGET_COORD",
    "validate_goto_pose",
    "validate_goto_pose_batch",
    "validate_formation",
    "validate_formation_mission",
    "validate_unit_available",
    "validate_formation_feasible",
    "validate_move_formation",
    "check_task_conflict",
]
