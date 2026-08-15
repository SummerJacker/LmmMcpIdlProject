from __future__ import annotations

import json

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
        return (
            len(units) == 1
            and units[0].platform == "kisorb-sau"
            and units[0].kind == "ugv"
        )

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


class KisorbFollowPath2DProvider:
    provider_id = "kisorb.navigation.follow_path2d"
    capability = "navigation.follow_path2d"
    version = "1.0"
    priority = 100

    def __init__(self, client: ConsoleTaskClient) -> None:
        self._client = client

    def supports(self, units: tuple[UnitDescriptor, ...]) -> bool:
        return (
            len(units) == 1
            and units[0].platform == "kisorb-sau"
            and units[0].kind == "ugv"
        )

    async def execute(
        self,
        request: ExecutionRequest,
        units: tuple[UnitDescriptor, ...],
    ) -> ExecutionResult:
        raw = await self._client.follow_path(
            unit_id=units[0].unit_id,
            points_json=json.dumps(request.arguments["points"], ensure_ascii=False),
            tolerance_m=request.arguments["tolerance_m"],
            timeout_ms=request.arguments["timeout_ms"],
        )
        return ExecutionResult.from_json(raw)


class KisorbStopProvider:
    provider_id = "kisorb.motion.stop"
    capability = "motion.stop"
    version = "1.0"
    priority = 100

    def __init__(self, client: ConsoleTaskClient) -> None:
        self._client = client

    def supports(self, units: tuple[UnitDescriptor, ...]) -> bool:
        return bool(units) and all(unit.platform == "kisorb-sau" for unit in units)

    async def execute(
        self,
        request: ExecutionRequest,
        units: tuple[UnitDescriptor, ...],
    ) -> ExecutionResult:
        unit_ids = list(dict.fromkeys(unit.unit_id for unit in units))
        raw = await self._client.stop_units(unit_ids_csv=",".join(unit_ids))
        return ExecutionResult.from_json(raw)
