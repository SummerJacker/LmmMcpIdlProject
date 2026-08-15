from __future__ import annotations

import uuid

from typing_extensions import TypedDict

from swarm_runtime.context import SwarmContext
from swarm_runtime.errors import RuntimeExecutionError, RuntimeResolutionError
from swarm_runtime.models import ExecutionRequest
from task_api.contracts import empty_task_result, rejected_task_response, response


class Point2D(TypedDict):
    x: float
    y: float


def build_navigate_to(ctx: SwarmContext):
    async def navigateTo(
        unit_id: str,
        target: Point2D,
        tolerance_m: float = 0.15,
        timeout_ms: int = 30000,
    ) -> str:
        """Navigate one ground unit to an x/y target.

        The unchanged Ground_Unit task-point RPC does not support final yaw or
        task-specific navigation speeds, so neither is accepted here.
        """
        if not isinstance(target, dict) or "x" not in target or "y" not in target:
            return rejected_task_response(
                task_type="navigate_to",
                error_code="SAFETY_REJECTED",
                message="target requires x and y",
            )

        request = ExecutionRequest(
            request_id=str(uuid.uuid4()),
            capability="navigation.goto2d",
            version="1.0",
            unit_ids=(unit_id,),
            arguments={
                "x": target["x"],
                "y": target["y"],
                "tolerance_m": tolerance_m,
                "timeout_ms": timeout_ms,
            },
            metadata={"tool_name": "navigateTo"},
        )
        try:
            return (await ctx.executor.execute(request)).to_json()
        except RuntimeResolutionError as exc:
            return rejected_task_response(
                task_type="navigate_to",
                error_code=exc.error_code,
                message=exc.message,
            )
        except RuntimeExecutionError as exc:
            return response(
                success=False,
                message=exc.message,
                error_code=exc.error_code,
                data=empty_task_result(
                    task_type="navigate_to",
                    state="FAILED",
                    message=exc.message,
                    error_code=exc.error_code,
                ),
            )

    return navigateTo


def build_follow_path(ctx: SwarmContext):
    async def followPath(
        unit_id: str,
        points: list[dict[str, float]],
        tolerance_m: float = 0.15,
        timeout_ms: int = 30000,
    ) -> str:
        """Execute an ordered x/y task path on one ground unit."""
        request = ExecutionRequest(
            request_id=str(uuid.uuid4()),
            capability="navigation.follow_path2d",
            version="1.0",
            unit_ids=(unit_id,),
            arguments={
                "points": points,
                "tolerance_m": tolerance_m,
                "timeout_ms": timeout_ms,
            },
            metadata={"tool_name": "followPath"},
        )
        try:
            return (await ctx.executor.execute(request)).to_json()
        except RuntimeResolutionError as exc:
            return rejected_task_response(
                task_type="follow_path",
                error_code=exc.error_code,
                message=exc.message,
            )
        except RuntimeExecutionError as exc:
            return response(
                success=False,
                message=exc.message,
                error_code=exc.error_code,
                data=empty_task_result(
                    task_type="follow_path",
                    state="FAILED",
                    message=exc.message,
                    error_code=exc.error_code,
                ),
            )

    return followPath
