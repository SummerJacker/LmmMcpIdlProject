"""Production task-level service exposed to the language model."""

from __future__ import annotations

from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from console_client.console_task_client import ConsoleTaskClient


class TaskService:
    def __init__(self, client: ConsoleTaskClient) -> None:
        self._client = client

    async def navigate_to(
        self, *, unit_id: str, x: float, y: float, tolerance_m: float, timeout_ms: int
    ) -> str:
        return await self._client.navigate_to(
            unit_id=unit_id,
            x=x,
            y=y,
            tolerance_m=tolerance_m,
            timeout_ms=timeout_ms,
        )

    async def follow_path(
        self, *, unit_id: str, points_json: str, tolerance_m: float, timeout_ms: int
    ) -> str:
        return await self._client.follow_path(
            unit_id=unit_id,
            points_json=points_json,
            tolerance_m=tolerance_m,
            timeout_ms=timeout_ms,
        )

    async def execute_motion(
        self,
        *,
        unit_id: str,
        linear_velocity: float,
        angular_velocity: float,
        duration_ms: int,
    ) -> str:
        return await self._client.execute_motion(
            unit_id=unit_id,
            linear_velocity=linear_velocity,
            angular_velocity=angular_velocity,
            duration_ms=duration_ms,
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
        return await self._client.create_static_formation(
            formation_type=formation_type,
            unit_ids_csv=unit_ids_csv,
            spacing_m=spacing_m,
            anchor_x=anchor_x,
            anchor_y=anchor_y,
            heading_rad=heading_rad,
            tolerance_m=tolerance_m,
            timeout_ms=timeout_ms,
        )

    async def create_follow_formation(self, *, leader_id: str, followers_json: str) -> str:
        return await self._client.create_follow_formation(
            leader_id=leader_id,
            followers_json=followers_json,
        )

    async def move_follow_formation(self, *, x: float, y: float) -> str:
        return await self._client.move_follow_formation(x=x, y=y)

    async def move_follow_formation_sequence(
        self, *, segments: list[dict[str, object]]
    ) -> str:
        return await self._client.move_follow_formation_sequence(segments=segments)

    async def get_formation_status(self) -> str:
        return await self._client.get_formation_status()

    async def disband_formation(self) -> str:
        return await self._client.disband_formation()

    async def get_task_status(self, *, task_id: str) -> str:
        return await self._client.get_task_status(task_id=task_id)

    async def cancel_task(self, *, task_id: str) -> str:
        return await self._client.cancel_task(task_id=task_id)

    async def stop_units(self, *, unit_ids_csv: str) -> str:
        return await self._client.stop_units(unit_ids_csv=unit_ids_csv)
