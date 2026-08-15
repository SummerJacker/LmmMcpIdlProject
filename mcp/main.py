"""Production FastMCP entry point for the task-level swarm contract.

By default only methods declared by mcp/idl/mcp_swarm_task.idl are exposed.
Set MCP_EXPOSE_LOW_LEVEL_TOOLS=1 to opt into legacy/debug tools.
"""

from __future__ import annotations

import json
import os
import time
from pathlib import Path
from typing import Literal
from typing_extensions import TypedDict

from fastmcp import FastMCP

from config import LOG_FILE, expose_low_level_tools
from debug_tools import register_low_level_tools
from swarm_runtime.context import SwarmContext
from swarm_runtime.fastmcp_bridge import install_runtime_tools
from swarm_runtime.plugin_loader import PluginLoader
from task_api import CapabilityService, TaskService
from task_api.contracts import failed_formation_response, rejected_task_response
from utils.logging_setup import setup_logging


MCP_ROOT = Path(__file__).resolve().parent
DEFAULT_PROFILE = MCP_ROOT / "profiles" / "default.json"
PLUGIN_ROOT = MCP_ROOT / "plugins"


def _with_mcp_contract_timing(raw: str, elapsed_ms: float) -> str:
    if os.getenv("SAU_BENCHMARK_TIMINGS", "0").strip() != "1":
        return raw
    try:
        payload = json.loads(raw)
    except (TypeError, json.JSONDecodeError):
        return raw
    if not isinstance(payload, dict) or not isinstance(payload.get("data"), dict):
        return raw
    timing = payload["data"].get("_benchmark_timing")
    if not isinstance(timing, dict):
        timing = {}
        payload["data"]["_benchmark_timing"] = timing
    timing["mcp_contract_mapping_ms"] = max(0.0, float(elapsed_ms))
    return json.dumps(payload, ensure_ascii=False)


class Point2D(TypedDict):
    x: float
    y: float


class StaticFormationRequest(TypedDict):
    formation_type: Literal["line", "triangle", "column"]
    unit_ids: list[str]
    spacing_m: float
    anchor: Point2D
    heading_rad: float
    tolerance_m: float
    timeout_ms: int


class FollowMember(TypedDict):
    unit_id: str
    distance_m: float


class FollowFormationRequest(TypedDict):
    leader_id: str
    followers: list[FollowMember]


class FollowMotionSegment(TypedDict):
    linear_velocity: float
    angular_velocity: float
    duration_ms: int
    buffer_ms: int


class MotionCommandRequest(TypedDict):
    unit_id: str
    linear_velocity: float
    angular_velocity: float
    duration_ms: int


def create_runtime(profile_path: str | Path | None = None) -> SwarmContext:
    ctx = SwarmContext()
    loader = PluginLoader(ctx, PLUGIN_ROOT)
    loader.load_profile(Path(profile_path) if profile_path else DEFAULT_PROFILE)
    ctx.plugin_loader = loader
    return ctx


def create_app(profile_path: str | Path | None = None) -> FastMCP:
    mcp = FastMCP(name="mcp-swarm-task-server")
    ctx = create_runtime(profile_path)
    adapter = ctx.services.get("legacy.robot_adapter")
    client = ctx.services.get("legacy.console_task_client")
    capabilities = CapabilityService(client)
    tasks = TaskService(client)

    @mcp.tool
    async def getCapabilities() -> str:
        """Return only capabilities the Console and unchanged base IDLs can execute."""
        return await capabilities.get_capabilities()

    @mcp.tool
    async def getFleetSnapshot() -> str:
        """Return bound units, runtime Mock/real mode and real-RPC availability."""
        return await capabilities.get_fleet_snapshot()

    @mcp.tool
    async def createStaticFormation(request: StaticFormationRequest) -> str:
        """Navigate units to rotated/translated geometric targets.

        This method does not create leader/follower relationships.
        """
        anchor = request.get("anchor") if isinstance(request, dict) else None
        unit_ids = request.get("unit_ids") if isinstance(request, dict) else None
        if not isinstance(anchor, dict) or not isinstance(unit_ids, list):
            return rejected_task_response(
                task_type="create_static_formation",
                error_code="SAFETY_REJECTED",
                message="request requires unit_ids and anchor{x,y}",
            )
        try:
            spacing_m = float(request.get("spacing_m", 0.0))
            heading_rad = float(request.get("heading_rad", 0.0))
            tolerance_m = float(request.get("tolerance_m", 0.15))
            timeout_ms = int(request.get("timeout_ms", 30000))
        except (TypeError, ValueError):
            return rejected_task_response(
                task_type="create_static_formation",
                error_code="SAFETY_REJECTED",
                message="request contains invalid numeric fields",
            )
        return await tasks.create_static_formation(
            formation_type=str(request.get("formation_type", "")),
            unit_ids_csv=",".join(str(value) for value in unit_ids),
            spacing_m=spacing_m,
            anchor_x=anchor.get("x"),
            anchor_y=anchor.get("y"),
            heading_rad=heading_rad,
            tolerance_m=tolerance_m,
            timeout_ms=timeout_ms,
        )

    @mcp.tool
    async def createFollowFormation(request: FollowFormationRequest) -> str:
        """Atomically create a persistent Console leader/follower formation.

        Each follower item contains unit_id and distance_m. READY is returned
        only after the Console completes relationship, formation and follow-mode setup.
        """
        followers = request.get("followers") if isinstance(request, dict) else None
        if not isinstance(followers, list):
            return failed_formation_response(
                error_code="SAFETY_REJECTED",
                message="request requires a followers array",
            )
        return await tasks.create_follow_formation(
            leader_id=str(request.get("leader_id", "")),
            followers_json=json.dumps(followers, ensure_ascii=False),
        )

    @mcp.tool
    async def moveFollowFormation(target: Point2D) -> str:
        """Send an x/y target only to the current leader; followers use base follow logic."""
        if not isinstance(target, dict) or "x" not in target or "y" not in target:
            return rejected_task_response(
                task_type="move_follow_formation",
                error_code="SAFETY_REJECTED",
                message="target requires x and y",
            )
        return await tasks.move_follow_formation(x=target["x"], y=target["y"])

    @mcp.tool
    async def moveFollowFormationSequence(segments: list[FollowMotionSegment]) -> str:
        """Execute ordered open-loop velocity segments on the current Leader."""
        if not isinstance(segments, list):
            return rejected_task_response(
                task_type="move_follow_formation_sequence",
                error_code="SAFETY_REJECTED",
                message="segments must be an array",
            )
        return await tasks.move_follow_formation_sequence(segments=segments)

    @mcp.tool
    async def executeMotion(request: MotionCommandRequest) -> str:
        """Execute one typed open-loop motion command on a bound ground unit."""
        contract_started_ns = time.perf_counter_ns()
        if not isinstance(request, dict):
            raw = rejected_task_response(
                task_type="execute_motion",
                error_code="SAFETY_REJECTED",
                message="request must be an object",
            )
            return _with_mcp_contract_timing(
                raw, (time.perf_counter_ns() - contract_started_ns) / 1_000_000.0
            )
        required = {
            "unit_id", "linear_velocity", "angular_velocity", "duration_ms"
        }
        if not required <= set(request):
            raw = rejected_task_response(
                task_type="execute_motion",
                error_code="SAFETY_REJECTED",
                message="request requires unit_id, velocities and duration_ms",
            )
            return _with_mcp_contract_timing(
                raw, (time.perf_counter_ns() - contract_started_ns) / 1_000_000.0
            )
        contract_ms = (
            time.perf_counter_ns() - contract_started_ns
        ) / 1_000_000.0
        raw = await tasks.execute_motion(
            unit_id=str(request["unit_id"]),
            linear_velocity=request["linear_velocity"],
            angular_velocity=request["angular_velocity"],
            duration_ms=request["duration_ms"],
        )
        return _with_mcp_contract_timing(raw, contract_ms)

    @mcp.tool
    async def getFormationStatus() -> str:
        """Return the Console-owned persistent follow-formation state."""
        return await tasks.get_formation_status()

    @mcp.tool
    async def disbandFormation() -> str:
        """Remove leader/follower relationships and restore group mode to none."""
        return await tasks.disband_formation()

    @mcp.tool
    async def getTaskStatus(task_id: str) -> str:
        """Return aggregate and per-unit state for a task."""
        return await tasks.get_task_status(task_id=task_id)

    @mcp.tool
    async def cancelTask(task_id: str) -> str:
        """Cancel a task state machine and request Unit_MA_Stop for its units.

        The result reports CANCEL_CONFIRMED, STOP_REQUESTED or
        STATE_ONLY_CANCELLED because the base IDLs expose no clear-task RPC.
        """
        return await tasks.cancel_task(task_id=task_id)

    install_runtime_tools(mcp, ctx.tools)

    if expose_low_level_tools():
        register_low_level_tools(mcp, adapter)

    return mcp


app = create_app()


if __name__ == "__main__":
    setup_logging(log_file=LOG_FILE, level="INFO")
    app.run()
