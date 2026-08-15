"""Task-level Console client.

This facade keeps the MCP service independent from legacy low-level adapter methods.
The underlying RobotAdapter remains available to debug tools and compatibility callers.
"""

from __future__ import annotations

from robot_adapter import RobotAdapter
from task_api.contracts import normalize_formation_response, normalize_task_response


class ConsoleTaskClient:
    def __init__(self, adapter: RobotAdapter) -> None:
        self._adapter = adapter

    async def get_capabilities(self) -> str:
        return await self._adapter.get_capabilities()

    async def get_fleet_snapshot(self) -> str:
        return await self._adapter.get_fleet_snapshot()

    async def navigate_to(
        self, *, unit_id: str, x: float, y: float, tolerance_m: float, timeout_ms: int
    ) -> str:
        return normalize_task_response(await self._adapter.navigate_to(
            unit_id=unit_id,
            x=x,
            y=y,
            tolerance_m=tolerance_m,
            timeout_ms=timeout_ms,
        ), task_type="navigate_to")

    async def follow_path(
        self, *, unit_id: str, points_json: str, tolerance_m: float, timeout_ms: int
    ) -> str:
        return normalize_task_response(await self._adapter.follow_path(
            unit_id=unit_id,
            points_json=points_json,
            tolerance_m=tolerance_m,
            timeout_ms=timeout_ms,
        ), task_type="follow_path")

    async def execute_motion(
        self,
        *,
        unit_id: str,
        linear_velocity: float,
        angular_velocity: float,
        duration_ms: int,
    ) -> str:
        return normalize_task_response(
            await self._adapter.execute_motion_task(
                unit_id=unit_id,
                linear_velocity=linear_velocity,
                angular_velocity=angular_velocity,
                duration_ms=duration_ms,
            ),
            task_type="execute_motion",
        )

    async def create_static_formation(
        self,
        *,
        formation_type: str,
        unit_ids_csv: str,
        spacing_m: float,
        anchor_x: float,
        anchor_y: float,
        heading_rad: float,
        tolerance_m: float,
        timeout_ms: int,
    ) -> str:
        return normalize_task_response(await self._adapter.create_static_formation(
            formation_type=formation_type,
            unit_ids_csv=unit_ids_csv,
            spacing_m=spacing_m,
            anchor_x=anchor_x,
            anchor_y=anchor_y,
            heading_rad=heading_rad,
            tolerance_m=tolerance_m,
            timeout_ms=timeout_ms,
        ), task_type="create_static_formation")

    async def create_follow_formation(self, *, leader_id: str, followers_json: str) -> str:
        return normalize_formation_response(
            await self._adapter.create_follow_formation(
                leader_id=leader_id,
                followers_json=followers_json,
            )
        )

    async def move_follow_formation(self, *, x: float, y: float) -> str:
        return normalize_task_response(
            await self._adapter.move_follow_formation(x=x, y=y),
            task_type="move_follow_formation",
        )

    async def move_follow_formation_sequence(
        self, *, segments: list[dict[str, object]]
    ) -> str:
        return normalize_task_response(
            await self._adapter.move_follow_formation_sequence(segments=segments),
            task_type="move_follow_formation_sequence",
        )

    async def get_formation_status(self) -> str:
        return normalize_formation_response(await self._adapter.get_formation_status())

    async def disband_formation(self) -> str:
        return normalize_formation_response(await self._adapter.disband_formation())

    async def get_task_status(self, *, task_id: str) -> str:
        return normalize_task_response(
            await self._adapter.get_task_status(task_id=task_id),
            task_type="get_task_status",
        )

    async def cancel_task(self, *, task_id: str) -> str:
        return normalize_task_response(
            await self._adapter.cancel_task(task_id=task_id),
            task_type="cancel_task",
        )

    async def stop_units(self, *, unit_ids_csv: str) -> str:
        return normalize_task_response(
            await self._adapter.stop_units(unit_ids_csv=unit_ids_csv),
            task_type="stop_units",
        )
