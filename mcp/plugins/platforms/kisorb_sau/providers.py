from __future__ import annotations

from console_client import ConsoleTaskClient
from swarm_runtime.models import ExecutionRequest, ExecutionResult, UnitDescriptor


class KisorbGoto2DProvider:
    provider_id = "kisorb.navigation.goto2d"
    capability = "navigation.goto2d"
    version = "1.0"
    priority = 100

    def __init__(self, client: ConsoleTaskClient) -> None:
        self._client = client

    def supports(self, units: tuple[UnitDescriptor, ...]) -> bool:
        return len(units) == 1 and units[0].platform == "kisorb-sau"

    async def execute(
        self,
        request: ExecutionRequest,
        units: tuple[UnitDescriptor, ...],
    ) -> ExecutionResult:
        unit = units[0]
        raw = await self._client.navigate_to(
            unit_id=unit.unit_id,
            x=request.arguments["x"],
            y=request.arguments["y"],
            tolerance_m=request.arguments["tolerance_m"],
            timeout_ms=request.arguments["timeout_ms"],
        )
        return ExecutionResult.from_json(raw)
