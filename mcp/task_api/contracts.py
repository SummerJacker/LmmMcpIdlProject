"""Shared task-level names, states, error codes and response helpers."""

from __future__ import annotations

import json
import time
from typing import Any

UNSUPPORTED_CAPABILITY = "UNSUPPORTED_CAPABILITY"

TASK_STATES = frozenset(
    {
        "PENDING",
        "RUNNING",
        "COMPLETED",
        "PARTIAL_COMPLETED",
        "FAILED",
        "TIMEOUT",
        "CANCELLED",
        "REJECTED",
    }
)

CANCELLATION_EFFECTS = frozenset(
    {
        "NOT_APPLICABLE",
        "CANCEL_CONFIRMED",
        "STOP_REQUESTED",
        "STATE_ONLY_CANCELLED",
    }
)

PRODUCTION_TOOL_NAMES = frozenset(
    {
        "getCapabilities",
        "getFleetSnapshot",
        "navigateTo",
        "followPath",
        "createStaticFormation",
        "createFollowFormation",
        "createAirGroundFormation",
        "getAirGroundFormationStatus",
        "disbandAirGroundFormation",
        "moveFollowFormation",
        "moveFollowFormationSequence",
        "executeMotion",
        "getFormationStatus",
        "disbandFormation",
        "getTaskStatus",
        "cancelTask",
        "stopUnits",
    }
)

LOW_LEVEL_TOOL_NAMES = frozenset(
    {
        "send_move",
        "stop_robot",
        "emergency_stop_all",
        "get_robot_status",
        "list_robots",
        "set_task_point",
        "set_task_path",
        "set_leader",
        "set_group_mode",
        "set_group_minor_mode",
        "reset_unit_relations",
        "add_trap_point",
        "clear_traps",
        "goto_pose",
        "goto_pose_batch",
        "execute_formation",
        "execute_geometric_formation",
        "send_follow_formation",
        "goto_follow_formation",
        "get_formation_status",
        "execute_formation_mission",
    }
)


def response(*, success: bool, message: str, data: Any = None, error_code: str = "") -> str:
    """Serialize the single MCP/HTTP response envelope."""

    payload: dict[str, Any] = {"success": success, "message": message, "data": data}
    if error_code:
        payload["error_code"] = error_code
    return json.dumps(payload, ensure_ascii=False)


def parse_response(raw: str) -> dict[str, Any]:
    """Parse a response without raising into a normalized dictionary."""

    try:
        value = json.loads(raw)
    except (TypeError, json.JSONDecodeError):
        return {
            "success": False,
            "message": "invalid Console response",
            "data": None,
            "error_code": "INTERNAL_ERROR",
        }
    if not isinstance(value, dict):
        return {
            "success": False,
            "message": "invalid Console response shape",
            "data": None,
            "error_code": "INTERNAL_ERROR",
        }
    return value


def normalize_console_response(
    body: dict[str, Any] | None,
    *,
    fallback_message: str,
    fallback_error_code: str = "INTERNAL_ERROR",
) -> str:
    """Preserve Console's envelope and lift a nested business error code if present."""

    if not isinstance(body, dict):
        return response(
            success=False,
            message=fallback_message,
            error_code=fallback_error_code,
        )

    success = bool(body.get("success", False))
    message = str(body.get("message", fallback_message))
    data = body.get("data")
    error_code = str(body.get("error_code", "") or "")
    if not error_code and isinstance(data, dict):
        error_code = str(data.get("error_code", "") or "")
    if not success and not error_code:
        error_code = fallback_error_code
    return response(success=success, message=message, data=data, error_code=error_code)


def task_payload_has_contract_shape(data: Any) -> bool:
    """Return whether a payload has the stable task-result fields."""

    if not isinstance(data, dict):
        return False
    required = {
        "success",
        "task_id",
        "task_type",
        "state",
        "progress_pct",
        "message",
        "error_code",
        "unit_results",
        "elapsed_ms",
        "started_at_ms",
        "cancellation_effect",
    }
    return (
        required <= data.keys()
        and str(data.get("state")) in TASK_STATES
        and str(data.get("cancellation_effect")) in CANCELLATION_EFFECTS
        and isinstance(data.get("unit_results"), list)
    )


def formation_payload_has_contract_shape(data: Any) -> bool:
    """Return whether a payload has every FormationStatus field."""

    if not isinstance(data, dict):
        return False
    required = {
        "has_active_formation",
        "state",
        "leader_id",
        "followers",
        "active_move_task_id",
        "message",
        "error_code",
    }
    return required <= data.keys() and isinstance(data.get("followers"), list)


def empty_formation_status(*, message: str, error_code: str = "") -> dict[str, Any]:
    """Build a complete FormationStatus when no authoritative record exists."""

    return {
        "has_active_formation": False,
        "state": "FAILED" if error_code else "IDLE",
        "leader_id": "",
        "followers": [],
        "active_move_task_id": "",
        "message": message,
        "error_code": error_code,
    }


def empty_task_result(
    *,
    task_type: str,
    state: str,
    message: str,
    error_code: str = "",
) -> dict[str, Any]:
    """Build a complete TaskResult for failures before Console created a task."""

    terminal = state not in {"PENDING", "RUNNING"}
    return {
        "success": state in {"PENDING", "RUNNING", "COMPLETED", "PARTIAL_COMPLETED"},
        "task_id": "",
        "task_type": task_type,
        "state": state,
        "progress_pct": 100.0 if terminal else 0.0,
        "message": message,
        "error_code": error_code,
        "unit_results": [],
        "elapsed_ms": 0,
        "started_at_ms": int(time.time() * 1000),
        "cancellation_effect": "NOT_APPLICABLE",
    }


_REJECTED_TASK_ERRORS = frozenset(
    {
        "UNIT_NOT_FOUND",
        "UNIT_OFFLINE",
        "UNIT_BUSY",
        "TASK_CONFLICT",
        "TASK_NOT_FOUND",
        "TASK_ALREADY_CANCELLED",
        "TARGET_OUT_OF_BOUNDS",
        "SAFETY_REJECTED",
        "FORMATION_NOT_READY",
        "FORMATION_CONFLICT",
        "UNSUPPORTED_CAPABILITY",
        "RPC_DISABLED",
    }
)


def normalize_task_response(raw: str, *, task_type: str) -> str:
    """Guarantee that every task-level response carries a complete TaskResult."""

    parsed = parse_response(raw)
    if task_payload_has_contract_shape(parsed.get("data")):
        return raw

    original_success = bool(parsed.get("success", False))
    message = str(parsed.get("message", "task failed"))
    data = parsed.get("data")
    error_code = str(parsed.get("error_code", "") or "")
    if not error_code and isinstance(data, dict):
        error_code = str(data.get("error_code", "") or "")
    if original_success:
        message = "Console returned a response without a valid TaskResult payload"
        error_code = "INTERNAL_ERROR"
    elif not error_code:
        error_code = "INTERNAL_ERROR"

    state = "REJECTED" if error_code in _REJECTED_TASK_ERRORS else "FAILED"
    parsed["success"] = False
    parsed["message"] = message
    parsed["error_code"] = error_code
    parsed["data"] = empty_task_result(
        task_type=task_type,
        state=state,
        message=message,
        error_code=error_code,
    )
    return json.dumps(parsed, ensure_ascii=False)


def normalize_formation_response(raw: str) -> str:
    """Guarantee that formation methods always return a complete FormationStatus."""

    parsed = parse_response(raw)
    if formation_payload_has_contract_shape(parsed.get("data")):
        return raw

    success = bool(parsed.get("success", False))
    message = str(parsed.get("message", "formation operation failed"))
    data = parsed.get("data")
    error_code = str(parsed.get("error_code", "") or "")
    if not error_code and isinstance(data, dict):
        error_code = str(data.get("error_code", "") or "")
    if success or not error_code:
        success = False
        error_code = "INTERNAL_ERROR"
        if parsed.get("success"):
            message = "Console returned a response without a valid FormationStatus payload"
    parsed["success"] = success
    parsed["message"] = message
    parsed["error_code"] = error_code
    parsed["data"] = empty_formation_status(message=message, error_code=error_code)
    return json.dumps(parsed, ensure_ascii=False)


def rejected_task_response(*, task_type: str, error_code: str, message: str) -> str:
    """Return a complete locally rejected task response."""

    return response(
        success=False,
        message=message,
        error_code=error_code,
        data=empty_task_result(
            task_type=task_type,
            state="REJECTED",
            message=message,
            error_code=error_code,
        ),
    )


def failed_formation_response(*, error_code: str, message: str) -> str:
    """Return a complete locally failed FormationStatus response."""

    return response(
        success=False,
        message=message,
        error_code=error_code,
        data=empty_formation_status(message=message, error_code=error_code),
    )
