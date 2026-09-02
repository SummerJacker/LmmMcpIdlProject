from __future__ import annotations

import json
import uuid
from typing import Literal

from typing_extensions import TypedDict

from swarm_runtime.context import SwarmContext
from swarm_runtime.errors import RuntimeExecutionError, RuntimeResolutionError
from swarm_runtime.models import ExecutionRequest
from task_api.contracts import (
    empty_task_result,
    failed_formation_response,
    rejected_task_response,
    response,
)


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


class AirGroundFollower(TypedDict):
    unit_id: str
    distance_m: float
    angle_deg: float


class AirGroundFormationRequest(TypedDict):
    air_leader: dict
    ground_followers: list[AirGroundFollower]


async def _run(
    ctx: SwarmContext,
    request: ExecutionRequest,
    *,
    task_type: str | None = None,
    formation: bool = False,
) -> str:
    try:
        return (await ctx.executor.execute(request)).to_json()
    except RuntimeResolutionError as exc:
        if formation:
            return failed_formation_response(
                error_code=exc.error_code, message=exc.message
            )
        return rejected_task_response(
            task_type=task_type,
            error_code=exc.error_code,
            message=exc.message,
        )
    except RuntimeExecutionError as exc:
        if formation:
            return failed_formation_response(
                error_code=exc.error_code, message=exc.message
            )
        return response(
            success=False,
            message=exc.message,
            error_code=exc.error_code,
            data=empty_task_result(
                task_type=task_type,
                state="FAILED",
                message=exc.message,
                error_code=exc.error_code,
            ),
        )


def build_create_static_formation(ctx: SwarmContext):
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

        execution_request = ExecutionRequest(
            request_id=str(uuid.uuid4()),
            capability="formation.static",
            version="1.0",
            unit_ids=tuple(str(value) for value in unit_ids),
            arguments={
                "formation_type": str(request.get("formation_type", "")),
                "spacing_m": spacing_m,
                "anchor_x": anchor.get("x"),
                "anchor_y": anchor.get("y"),
                "heading_rad": heading_rad,
                "tolerance_m": tolerance_m,
                "timeout_ms": timeout_ms,
            },
            metadata={"tool_name": "createStaticFormation"},
        )
        return await _run(ctx, execution_request, task_type="create_static_formation")

    return createStaticFormation


def build_create_follow_formation(ctx: SwarmContext):
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

        execution_request = ExecutionRequest(
            request_id=str(uuid.uuid4()),
            capability="formation.follow.create",
            version="1.0",
            unit_ids=(),
            arguments={
                "leader_id": str(request.get("leader_id", "")),
                "followers_json": json.dumps(followers, ensure_ascii=False),
            },
            metadata={"tool_name": "createFollowFormation"},
        )
        return await _run(ctx, execution_request, formation=True)

    return createFollowFormation


def build_move_follow_formation(ctx: SwarmContext):
    async def moveFollowFormation(target: Point2D) -> str:
        """Send an x/y target only to the current leader; followers use base follow logic."""
        if not isinstance(target, dict) or "x" not in target or "y" not in target:
            return rejected_task_response(
                task_type="move_follow_formation",
                error_code="SAFETY_REJECTED",
                message="target requires x and y",
            )

        execution_request = ExecutionRequest(
            request_id=str(uuid.uuid4()),
            capability="formation.follow.move",
            version="1.0",
            unit_ids=(),
            arguments={"x": target["x"], "y": target["y"]},
            metadata={"tool_name": "moveFollowFormation"},
        )
        return await _run(ctx, execution_request, task_type="move_follow_formation")

    return moveFollowFormation


def build_move_follow_formation_sequence(ctx: SwarmContext):
    async def moveFollowFormationSequence(
        segments: list[FollowMotionSegment],
    ) -> str:
        """Execute ordered open-loop velocity segments on the current Leader."""
        if not isinstance(segments, list):
            return rejected_task_response(
                task_type="move_follow_formation_sequence",
                error_code="SAFETY_REJECTED",
                message="segments must be an array",
            )

        execution_request = ExecutionRequest(
            request_id=str(uuid.uuid4()),
            capability="formation.follow.move_sequence",
            version="1.0",
            unit_ids=(),
            arguments={"segments": segments},
            metadata={"tool_name": "moveFollowFormationSequence"},
        )
        return await _run(
            ctx, execution_request, task_type="move_follow_formation_sequence"
        )

    return moveFollowFormationSequence


def build_get_formation_status(ctx: SwarmContext):
    async def getFormationStatus() -> str:
        """Return the Console-owned persistent follow-formation state."""
        execution_request = ExecutionRequest(
            request_id=str(uuid.uuid4()),
            capability="formation.follow.status",
            version="1.0",
            unit_ids=(),
            arguments={},
            metadata={"tool_name": "getFormationStatus"},
        )
        return await _run(ctx, execution_request, formation=True)

    return getFormationStatus


def build_disband_formation(ctx: SwarmContext):
    async def disbandFormation() -> str:
        """Remove leader/follower relationships and restore group mode to none."""
        execution_request = ExecutionRequest(
            request_id=str(uuid.uuid4()),
            capability="formation.follow.disband",
            version="1.0",
            unit_ids=(),
            arguments={},
            metadata={"tool_name": "disbandFormation"},
        )
        return await _run(ctx, execution_request, formation=True)

    return disbandFormation


def build_create_air_ground_formation(ctx: SwarmContext):
    async def createAirGroundFormation(request: AirGroundFormationRequest) -> str:
        """Create a hybrid air-ground formation: a UAV air leader + a UGV ground chain.

        The air leader flies at altitude_m; each ground follower follows the previous
        unit in a chain (the first ground unit follows the air leader's ground projection).
        """
        air_leader = request.get("air_leader") if isinstance(request, dict) else None
        followers = request.get("ground_followers") if isinstance(request, dict) else None
        if not isinstance(air_leader, dict) or not isinstance(followers, list) or not followers:
            return failed_formation_response(
                error_code="SAFETY_REJECTED",
                message="request requires air_leader{unit_id,altitude_m} and a non-empty ground_followers array",
            )

        air_leader_id = str(air_leader.get("unit_id", "")).strip()
        try:
            air_altitude_m = float(air_leader.get("altitude_m", 20.0))
        except (TypeError, ValueError):
            air_altitude_m = 20.0

        follower_ids = tuple(
            str(f.get("unit_id", "")) for f in followers if isinstance(f, dict)
        )

        execution_request = ExecutionRequest(
            request_id=str(uuid.uuid4()),
            capability="formation.air_ground",
            version="1.0",
            unit_ids=(air_leader_id, *follower_ids),
            arguments={
                "air_leader_id": air_leader_id,
                "air_altitude_m": air_altitude_m,
                "followers_json": json.dumps(followers, ensure_ascii=False),
            },
            metadata={"tool_name": "createAirGroundFormation"},
        )
        return await _run(ctx, execution_request, formation=True)

    return createAirGroundFormation
