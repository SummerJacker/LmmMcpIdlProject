"""Truthful capability reporting for the task-level MCP contract."""

from __future__ import annotations

from typing import TYPE_CHECKING

from .contracts import parse_response, response

if TYPE_CHECKING:
    from console_client.console_task_client import ConsoleTaskClient


class CapabilityService:
    def __init__(self, client: ConsoleTaskClient) -> None:
        self._client = client

    async def get_capabilities(self) -> str:
        raw = await self._client.get_capabilities()
        parsed = parse_response(raw)
        if parsed.get("success"):
            return raw
        if parsed.get("error_code") != "TASK_NOT_FOUND":
            return raw

        # Compatibility with an older Console: expose only unchanged-IDL basics and
        # remain conservative about follow, strict cancellation and real RPC.
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
        return response(
            success=True,
            message="compatibility capability fallback",
            data={"capabilities": capabilities, "source": "mcp-conservative-fallback"},
        )

    async def get_fleet_snapshot(self) -> str:
        return await self._client.get_fleet_snapshot()
