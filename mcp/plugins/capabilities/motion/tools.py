from __future__ import annotations

import json
import os
import time
import uuid

from typing_extensions import TypedDict

from swarm_runtime.context import SwarmContext
from swarm_runtime.errors import RuntimeExecutionError, RuntimeResolutionError
from swarm_runtime.models import ExecutionRequest
from task_api.contracts import empty_task_result, rejected_task_response, response


class MotionCommandRequest(TypedDict):
    unit_id: str
    linear_velocity: float
    angular_velocity: float
    duration_ms: int


def _with_contract_timing(raw: str, elapsed_ms: float) -> str:
    if os.getenv("SAU_BENCHMARK_TIMINGS", "0").strip() != "1":
        return raw
    try:
        payload = json.loads(raw)
    except (TypeError, json.JSONDecodeError):
        return raw
    if not isinstance(payload, dict) or not isinstance(payload.get("data"), dict):
        return raw
    timing = payload["data"].get("_benchmark_timing")
    if not isinstance(timing, dict):
        timing = {}
        payload["data"]["_benchmark_timing"] = timing
    timing["mcp_contract_mapping_ms"] = max(0.0, float(elapsed_ms))
    return json.dumps(payload, ensure_ascii=False)


def build_stop_units(ctx: SwarmContext):
    async def stopUnits(unit_ids: list[str]) -> str:
        """Request Unit_MA_Stop without cancelling tasks or disbanding formations."""
        normalized_unit_ids = [
            unit_id.strip() for unit_id in unit_ids if unit_id.strip()
        ]
        if not normalized_unit_ids:
            message = "Validation failed: unit_ids is empty"
            return response(
                success=False,
                message=message,
                error_code="INTERNAL_ERROR",
                data=empty_task_result(
                    task_type="stop_units",
                    state="FAILED",
                    message=message,
                    error_code="INTERNAL_ERROR",
                ),
            )

        request = ExecutionRequest(
            request_id=str(uuid.uuid4()),
            capability="motion.stop",
            version="1.0",
            unit_ids=tuple(normalized_unit_ids),
            arguments={},
            metadata={"tool_name": "stopUnits"},
        )
        try:
            return (await ctx.executor.execute(request)).to_json()
        except RuntimeResolutionError as exc:
            return rejected_task_response(
                task_type="stop_units",
                error_code=exc.error_code,
                message=exc.message,
            )
        except RuntimeExecutionError as exc:
            return response(
                success=False,
                message=exc.message,
                error_code=exc.error_code,
                data=empty_task_result(
                    task_type="stop_units",
                    state="FAILED",
                    message=exc.message,
                    error_code=exc.error_code,
                ),
            )

    return stopUnits


def build_execute_motion(ctx: SwarmContext):
    async def executeMotion(request: MotionCommandRequest) -> str:
        """Execute one typed open-loop motion command on a bound ground unit."""
        contract_started_ns = time.perf_counter_ns()

        def elapsed_ms() -> float:
            return (time.perf_counter_ns() - contract_started_ns) / 1_000_000.0

        if not isinstance(request, dict):
            return _with_contract_timing(
                rejected_task_response(
                    task_type="execute_motion",
                    error_code="SAFETY_REJECTED",
                    message="request must be an object",
                ),
                elapsed_ms(),
            )
        required = {
            "unit_id", "linear_velocity", "angular_velocity", "duration_ms"
        }
        if not required <= set(request):
            return _with_contract_timing(
                rejected_task_response(
                    task_type="execute_motion",
                    error_code="SAFETY_REJECTED",
                    message="request requires unit_id, velocities and duration_ms",
                ),
                elapsed_ms(),
            )

        execution_request = ExecutionRequest(
            request_id=str(uuid.uuid4()),
            capability="motion.execute",
            version="1.0",
            unit_ids=(str(request["unit_id"]),),
            arguments={
                "linear_velocity": request["linear_velocity"],
                "angular_velocity": request["angular_velocity"],
                "duration_ms": request["duration_ms"],
            },
            metadata={"tool_name": "executeMotion"},
        )
        try:
            raw = (await ctx.executor.execute(execution_request)).to_json()
        except RuntimeResolutionError as exc:
            raw = rejected_task_response(
                task_type="execute_motion",
                error_code=exc.error_code,
                message=exc.message,
            )
        except RuntimeExecutionError as exc:
            raw = response(
                success=False,
                message=exc.message,
                error_code=exc.error_code,
                data=empty_task_result(
                    task_type="execute_motion",
                    state="FAILED",
                    message=exc.message,
                    error_code=exc.error_code,
                ),
            )
        return _with_contract_timing(raw, elapsed_ms())

    return executeMotion
