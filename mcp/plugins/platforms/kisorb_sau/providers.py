from __future__ import annotations

import json

from console_client import ConsoleTaskClient
from swarm_runtime.models import ExecutionRequest, ExecutionResult, UnitDescriptor
from task_api.contracts import parse_response


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


def _all_ground(units: tuple[UnitDescriptor, ...]) -> bool:
    return bool(units) and all(
        unit.platform == "kisorb-sau" and unit.kind == "ugv" for unit in units
    )


def _no_units(units: tuple[UnitDescriptor, ...]) -> bool:
    return len(units) == 0


class KisorbExecuteMotionProvider:
    provider_id = "kisorb.motion.execute"
    capability = "motion.execute"
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
        raw = await self._client.execute_motion(
            unit_id=units[0].unit_id,
            linear_velocity=request.arguments["linear_velocity"],
            angular_velocity=request.arguments["angular_velocity"],
            duration_ms=request.arguments["duration_ms"],
        )
        return ExecutionResult.from_json(raw)


class KisorbStaticFormationProvider:
    provider_id = "kisorb.formation.static"
    capability = "formation.static"
    version = "1.0"
    priority = 100

    def __init__(self, client: ConsoleTaskClient) -> None:
        self._client = client

    def supports(self, units: tuple[UnitDescriptor, ...]) -> bool:
        return _all_ground(units)

    async def execute(
        self,
        request: ExecutionRequest,
        units: tuple[UnitDescriptor, ...],
    ) -> ExecutionResult:
        unit_ids_csv = ",".join(unit.unit_id for unit in units)
        raw = await self._client.create_static_formation(
            formation_type=request.arguments["formation_type"],
            unit_ids_csv=unit_ids_csv,
            spacing_m=request.arguments["spacing_m"],
            anchor_x=request.arguments["anchor_x"],
            anchor_y=request.arguments["anchor_y"],
            heading_rad=request.arguments["heading_rad"],
            tolerance_m=request.arguments["tolerance_m"],
            timeout_ms=request.arguments["timeout_ms"],
        )
        return ExecutionResult.from_json(raw)


class KisorbFollowFormationCreateProvider:
    provider_id = "kisorb.formation.follow.create"
    capability = "formation.follow.create"
    version = "1.0"
    priority = 100

    def __init__(self, client: ConsoleTaskClient) -> None:
        self._client = client

    def supports(self, units: tuple[UnitDescriptor, ...]) -> bool:
        return _no_units(units)

    async def execute(
        self,
        request: ExecutionRequest,
        units: tuple[UnitDescriptor, ...],
    ) -> ExecutionResult:
        raw = await self._client.create_follow_formation(
            leader_id=request.arguments["leader_id"],
            followers_json=request.arguments["followers_json"],
        )
        return ExecutionResult.from_json(raw)


class KisorbFollowFormationMoveProvider:
    provider_id = "kisorb.formation.follow.move"
    capability = "formation.follow.move"
    version = "1.0"
    priority = 100

    def __init__(self, client: ConsoleTaskClient) -> None:
        self._client = client

    def supports(self, units: tuple[UnitDescriptor, ...]) -> bool:
        return _no_units(units)

    async def execute(
        self,
        request: ExecutionRequest,
        units: tuple[UnitDescriptor, ...],
    ) -> ExecutionResult:
        raw = await self._client.move_follow_formation(
            x=request.arguments["x"],
            y=request.arguments["y"],
        )
        return ExecutionResult.from_json(raw)


class KisorbFollowFormationMoveSequenceProvider:
    provider_id = "kisorb.formation.follow.move_sequence"
    capability = "formation.follow.move_sequence"
    version = "1.0"
    priority = 100

    def __init__(self, client: ConsoleTaskClient) -> None:
        self._client = client

    def supports(self, units: tuple[UnitDescriptor, ...]) -> bool:
        return _no_units(units)

    async def execute(
        self,
        request: ExecutionRequest,
        units: tuple[UnitDescriptor, ...],
    ) -> ExecutionResult:
        raw = await self._client.move_follow_formation_sequence(
            segments=request.arguments["segments"],
        )
        return ExecutionResult.from_json(raw)


class KisorbFormationStatusProvider:
    provider_id = "kisorb.formation.follow.status"
    capability = "formation.follow.status"
    version = "1.0"
    priority = 100

    def __init__(self, client: ConsoleTaskClient) -> None:
        self._client = client

    def supports(self, units: tuple[UnitDescriptor, ...]) -> bool:
        return _no_units(units)

    async def execute(
        self,
        request: ExecutionRequest,
        units: tuple[UnitDescriptor, ...],
    ) -> ExecutionResult:
        raw = await self._client.get_formation_status()
        return ExecutionResult.from_json(raw)


class KisorbDisbandFormationProvider:
    provider_id = "kisorb.formation.follow.disband"
    capability = "formation.follow.disband"
    version = "1.0"
    priority = 100

    def __init__(self, client: ConsoleTaskClient) -> None:
        self._client = client

    def supports(self, units: tuple[UnitDescriptor, ...]) -> bool:
        return _no_units(units)

    async def execute(
        self,
        request: ExecutionRequest,
        units: tuple[UnitDescriptor, ...],
    ) -> ExecutionResult:
        raw = await self._client.disband_formation()
        return ExecutionResult.from_json(raw)


class KisorbTaskStatusProvider:
    provider_id = "kisorb.task.status"
    capability = "task.status"
    version = "1.0"
    priority = 100

    def __init__(self, client: ConsoleTaskClient) -> None:
        self._client = client

    def supports(self, units: tuple[UnitDescriptor, ...]) -> bool:
        return _no_units(units)

    async def execute(
        self,
        request: ExecutionRequest,
        units: tuple[UnitDescriptor, ...],
    ) -> ExecutionResult:
        raw = await self._client.get_task_status(
            task_id=request.arguments["task_id"],
        )
        return ExecutionResult.from_json(raw)


class KisorbCancelTaskProvider:
    provider_id = "kisorb.task.cancel"
    capability = "task.cancel"
    version = "1.0"
    priority = 100

    def __init__(self, client: ConsoleTaskClient) -> None:
        self._client = client

    def supports(self, units: tuple[UnitDescriptor, ...]) -> bool:
        return _no_units(units)

    async def execute(
        self,
        request: ExecutionRequest,
        units: tuple[UnitDescriptor, ...],
    ) -> ExecutionResult:
        raw = await self._client.cancel_task(task_id=request.arguments["task_id"])
        return ExecutionResult.from_json(raw)


class KisorbCapabilitiesProvider:
    provider_id = "kisorb.fleet.capabilities"
    capability = "fleet.capabilities"
    version = "1.0"
    priority = 100

    def __init__(self, client: ConsoleTaskClient) -> None:
        self._client = client

    def supports(self, units: tuple[UnitDescriptor, ...]) -> bool:
        return _no_units(units)

    async def execute(
        self,
        request: ExecutionRequest,
        units: tuple[UnitDescriptor, ...],
    ) -> ExecutionResult:
        raw = await self._client.get_capabilities()
        parsed = parse_response(raw)
        if parsed.get("success") or parsed.get("error_code") != "TASK_NOT_FOUND":
            return ExecutionResult.from_json(raw)

        capabilities = {
            "target_point_navigation": {
                "supported": False,
                "reason": "legacy Console cannot establish current executable fleet availability",
            },
            "path_tasks": {
                "supported": False,
                "reason": "legacy Console cannot establish current executable fleet availability",
            },
            "static_geometric_formation": {
                "supported": False,
                "reason": "legacy Console cannot establish current executable fleet availability",
            },
            "continuous_follow_formation": {
                "supported": False,
                "reason": "legacy Console does not expose authoritative task-level follow capability status",
            },
            "final_yaw": {
                "supported": False,
                "reason": "Ground_Unit.setTaskPoint accepts only x and y",
            },
            "navigation_speed": {
                "supported": False,
                "reason": "task-point and task-path RPCs expose no navigation speed parameter",
            },
            "strict_cancel": {
                "supported": False,
                "reason": "Unit_MA_Stop exists, but the base IDL exposes no clearTaskPoint/clearTaskPath",
            },
            "real_unit_rpc": {
                "supported": False,
                "reason": "authoritative Console capability route is unavailable",
            },
        }
        return ExecutionResult(
            True,
            "compatibility capability fallback",
            {"capabilities": capabilities, "source": "mcp-conservative-fallback"},
        )


class KisorbFleetSnapshotProvider:
    provider_id = "kisorb.fleet.snapshot"
    capability = "fleet.snapshot"
    version = "1.0"
    priority = 100

    def __init__(self, client: ConsoleTaskClient) -> None:
        self._client = client

    def supports(self, units: tuple[UnitDescriptor, ...]) -> bool:
        return _no_units(units)

    async def execute(
        self,
        request: ExecutionRequest,
        units: tuple[UnitDescriptor, ...],
    ) -> ExecutionResult:
        raw = await self._client.get_fleet_snapshot()
        return ExecutionResult.from_json(raw)
