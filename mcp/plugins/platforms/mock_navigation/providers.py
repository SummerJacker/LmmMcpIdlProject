from __future__ import annotations

import time
from typing import Any

from swarm_runtime.models import ExecutionRequest, ExecutionResult, UnitDescriptor


def _completed_result(
    request: ExecutionRequest,
    units: tuple[UnitDescriptor, ...],
    *,
    task_type: str,
    message: str,
    target: dict[str, Any] | None = None,
) -> ExecutionResult:
    canonical_unit_ids = dict.fromkeys(unit.unit_id for unit in units)
    unit_results: list[dict[str, Any]] = []
    for unit_id in canonical_unit_ids:
        unit_result: dict[str, Any] = {
            "unit_id": unit_id,
            "state": "COMPLETED",
            "progress_pct": 100.0,
            "message": message,
            "error_code": "",
        }
        if target is not None:
            unit_result["target"] = target
        unit_results.append(unit_result)

    data = {
        "success": True,
        "task_id": f"mock-{request.request_id}",
        "task_type": task_type,
        "state": "COMPLETED",
        "progress_pct": 100.0,
        "message": message,
        "error_code": "",
        "unit_results": unit_results,
        "elapsed_ms": 0,
        "started_at_ms": int(time.time() * 1000),
        "cancellation_effect": "NOT_APPLICABLE",
    }
    return ExecutionResult(True, message, data)


class MockGoto2DProvider:
    provider_id = "mock.navigation.goto2d"
    capability = "navigation.goto2d"
    version = "1.0"
    priority = 100

    def supports(self, units: tuple[UnitDescriptor, ...]) -> bool:
        return len(units) == 1 and units[0].platform == "mock-navigation"

    async def execute(
        self,
        request: ExecutionRequest,
        units: tuple[UnitDescriptor, ...],
    ) -> ExecutionResult:
        return _completed_result(
            request,
            units,
            task_type="navigate_to",
            message="mock navigation completed",
            target={
                "x": request.arguments["x"],
                "y": request.arguments["y"],
            },
        )


class MockFollowPath2DProvider:
    provider_id = "mock.navigation.follow_path2d"
    capability = "navigation.follow_path2d"
    version = "1.0"
    priority = 100

    def supports(self, units: tuple[UnitDescriptor, ...]) -> bool:
        return len(units) == 1 and units[0].platform == "mock-navigation"

    async def execute(
        self,
        request: ExecutionRequest,
        units: tuple[UnitDescriptor, ...],
    ) -> ExecutionResult:
        return _completed_result(
            request,
            units,
            task_type="follow_path",
            message="mock path completed",
            target={"points": request.arguments["points"]},
        )


class MockStopProvider:
    provider_id = "mock.motion.stop"
    capability = "motion.stop"
    version = "1.0"
    priority = 100

    def supports(self, units: tuple[UnitDescriptor, ...]) -> bool:
        return bool(units) and all(
            unit.platform == "mock-navigation" for unit in units
        )

    async def execute(
        self,
        request: ExecutionRequest,
        units: tuple[UnitDescriptor, ...],
    ) -> ExecutionResult:
        return _completed_result(
            request,
            units,
            task_type="stop_units",
            message="mock units stopped",
        )
