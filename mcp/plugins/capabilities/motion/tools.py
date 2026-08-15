from __future__ import annotations

import uuid

from swarm_runtime.context import SwarmContext
from swarm_runtime.errors import RuntimeExecutionError, RuntimeResolutionError
from swarm_runtime.models import ExecutionRequest
from task_api.contracts import empty_task_result, rejected_task_response, response


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
