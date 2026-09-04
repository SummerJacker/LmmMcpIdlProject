"""Opt-in registration for legacy and low-level MCP tools.

Nothing in this module is registered unless MCP_EXPOSE_LOW_LEVEL_TOOLS=1.
The functions intentionally delegate to the existing RobotAdapter so legacy HTTP,
Mock and real-RPC paths remain available for diagnostics.
"""

from __future__ import annotations

from fastmcp import FastMCP

from robot_adapter import RobotAdapter


def register_low_level_tools(mcp: FastMCP, adapter: RobotAdapter) -> None:
    from config import expose_low_level_tools

    if not expose_low_level_tools():
        return

    @mcp.tool
    async def send_move(robot_id: str, linear_velocity: float, angular_velocity: float,
                        duration_ms: int = 1000, timestamp: float | None = None) -> str:
        """DEBUG: send a raw Unit movement action."""
        return await adapter.send_move(
            robot_id=robot_id,
            linear_velocity=linear_velocity,
            angular_velocity=angular_velocity,
            duration_ms=duration_ms,
            timestamp=timestamp,
        )

    @mcp.tool
    async def stop_robot(robot_id: str) -> str:
        """DEBUG: send Unit_MA_Stop to one unit."""
        return await adapter.stop_robot(robot_id=robot_id)

    @mcp.tool
    async def emergency_stop_all() -> str:
        """DEBUG: request stop for every bound unit."""
        return await adapter.emergency_stop_all()

    @mcp.tool
    async def get_robot_status(robot_id: str) -> str:
        """DEBUG: read one unit's low-level status."""
        return await adapter.get_robot_status(robot_id=robot_id)

    @mcp.tool
    async def list_robots() -> str:
        """DEBUG: list the legacy Console bind table."""
        return await adapter.list_robots()

    @mcp.tool
    async def set_leader(robot_id: str) -> str:
        """DEBUG: directly set the Console leader."""
        return await adapter.set_leader(robot_id=robot_id)

    @mcp.tool
    async def set_group_mode(mode: str) -> str:
        """DEBUG: directly set the ground group mode."""
        return await adapter.set_group_mode(mode=mode)

    @mcp.tool
    async def set_group_minor_mode(mode: str) -> str:
        """DEBUG: directly set the ground group minor mode."""
        return await adapter.set_group_minor_mode(mode=mode)

    @mcp.tool
    async def set_task_point(robot_id: str, x: float, y: float) -> str:
        """DEBUG: directly call the legacy task-point route."""
        return await adapter.set_task_point(robot_id=robot_id, x=x, y=y)

    @mcp.tool
    async def set_task_path(robot_id: str, points_json: str) -> str:
        """DEBUG: directly call the legacy task-path route."""
        return await adapter.set_task_path(robot_id=robot_id, points_json=points_json)

    @mcp.tool
    async def reset_unit_relations() -> str:
        """DEBUG: reset legacy unit relationships."""
        return await adapter.reset_unit_relations()

    @mcp.tool
    async def add_trap_point(x: float, y: float, radius: float) -> str:
        """DEBUG: add a legacy trap point."""
        return await adapter.add_trap_point(x=x, y=y, radius=radius)

    @mcp.tool
    async def clear_traps() -> str:
        """DEBUG: clear legacy trap points."""
        return await adapter.clear_traps()

    @mcp.tool
    async def goto_pose(robot_id: str, x: float, y: float, yaw: float = 0.0,
                        linear_speed_m_s: float = 0.3, angular_speed_rad_s: float = 0.6,
                        tolerance_m: float = 0.15, timeout_ms: int = 30000) -> str:
        """LEGACY: old goto_pose contract; yaw and speed are not guaranteed."""
        return await adapter.goto_pose(
            robot_id=robot_id, x=x, y=y, yaw=yaw,
            linear_speed_m_s=linear_speed_m_s,
            angular_speed_rad_s=angular_speed_rad_s,
            tolerance_m=tolerance_m, timeout_ms=timeout_ms,
        )

    @mcp.tool
    async def goto_pose_batch(targets_json: str, tolerance_m: float = 0.15,
                              timeout_ms: int = 30000) -> str:
        """LEGACY: old batch-navigation contract."""
        return await adapter.goto_pose_batch(
            targets_json=targets_json,
            tolerance_m=tolerance_m,
            timeout_ms=timeout_ms,
        )

    @mcp.tool
    async def execute_formation(formation_type: str, unit_ids_csv: str = "",
                                spacing_m: float = 1.0, anchor_json: str = "",
                                heading_rad: float = 0.0, tolerance_m: float = 0.15,
                                timeout_ms: int = 30000) -> str:
        """LEGACY: old ambiguous geometric formation entry point."""
        return await adapter.execute_formation(
            formation_type=formation_type,
            unit_ids_csv=unit_ids_csv,
            spacing_m=spacing_m,
            anchor_json=anchor_json,
            heading_rad=heading_rad,
            tolerance_m=tolerance_m,
            timeout_ms=timeout_ms,
        )

    @mcp.tool
    async def execute_geometric_formation(formation_type: str, unit_ids_csv: str = "",
                                          spacing_m: float = 1.0, anchor_json: str = "",
                                          heading_rad: float = 0.0, tolerance_m: float = 0.15,
                                          timeout_ms: int = 30000) -> str:
        """LEGACY: compatibility alias for static formation."""
        return await execute_formation(
            formation_type, unit_ids_csv, spacing_m, anchor_json,
            heading_rad, tolerance_m, timeout_ms,
        )

    @mcp.tool
    async def send_follow_formation(leader_id: str, followers_json: str) -> str:
        """LEGACY: send formation data after a leader was set separately."""
        return await adapter.send_follow_formation(
            leader_id=leader_id,
            followers_json=followers_json,
        )

    @mcp.tool
    async def goto_follow_formation(x: float, y: float) -> str:
        """LEGACY: move the current follow leader."""
        return await adapter.goto_follow_formation(x=x, y=y)

    @mcp.tool
    async def get_formation_status() -> str:
        """LEGACY: read the compatibility follow-formation status route."""
        return await adapter.get_follow_formation_status()

    @mcp.tool
    async def execute_formation_mission(formation_type: str, unit_ids_csv: str = "",
                                        leader_id: str = "", spacing_m: float = 1.0,
                                        heading_rad: float = 0.0, tolerance_m: float = 0.15,
                                        timeout_ms: int = 30000) -> str:
        """LEGACY: geometry-only wrapper; leader_id is ignored."""
        del leader_id
        return await adapter.execute_formation(
            formation_type=formation_type,
            unit_ids_csv=unit_ids_csv,
            spacing_m=spacing_m,
            anchor_json="",
            heading_rad=heading_rad,
            tolerance_m=tolerance_m,
            timeout_ms=timeout_ms,
        )
