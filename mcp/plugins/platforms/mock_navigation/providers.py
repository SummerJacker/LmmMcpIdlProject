from __future__ import annotations

import time

from swarm_runtime.models import ExecutionRequest, ExecutionResult, UnitDescriptor


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
        unit = units[0]
        message = "mock navigation completed"
        target = {
            "x": request.arguments["x"],
            "y": request.arguments["y"],
        }
        data = {
            "success": True,
            "task_id": f"mock-{request.request_id}",
            "task_type": "navigate_to",
            "state": "COMPLETED",
            "progress_pct": 100.0,
            "message": message,
            "error_code": "",
            "unit_results": [
                {
                    "unit_id": unit.unit_id,
                    "state": "COMPLETED",
                    "message": message,
                    "error_code": "",
                    "target": target,
                }
            ],
            "elapsed_ms": 0,
            "started_at_ms": int(time.time() * 1000),
            "cancellation_effect": "NOT_APPLICABLE",
        }
        return ExecutionResult(True, message, data)
