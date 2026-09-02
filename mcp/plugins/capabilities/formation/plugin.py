from __future__ import annotations

from typing import Any, Mapping

from swarm_runtime.context import SwarmContext
from swarm_runtime.models import CapabilitySpec, ToolSpec

from .tools import (
    build_create_air_ground_formation,
    build_create_follow_formation,
    build_create_static_formation,
    build_disband_formation,
    build_get_formation_status,
    build_move_follow_formation,
    build_move_follow_formation_sequence,
)


class FormationCapabilityPlugin:
    plugin_id = "capability.formation"
    version = "1.0.0"

    def setup(self, ctx: SwarmContext, config: Mapping[str, Any]) -> None:
        specs = [
            ("formation.static", "1.0", "Form a rotated/translated static geometric shape", "multi_unit", "createStaticFormation"),
            ("formation.follow.create", "1.0", "Create a persistent leader/follower formation", "fleet", "createFollowFormation"),
            ("formation.follow.move", "1.0", "Move the current formation leader to a target", "fleet", "moveFollowFormation"),
            ("formation.follow.move_sequence", "1.0", "Run ordered open-loop velocity segments on the leader", "fleet", "moveFollowFormationSequence"),
            ("formation.follow.status", "1.0", "Report the persistent follow-formation state", "fleet", "getFormationStatus"),
            ("formation.follow.disband", "1.0", "Remove leader/follower relationships", "fleet", "disbandFormation"),
            ("formation.air_ground", "1.0", "Create a hybrid air-ground formation (UAV leader + UGV chain)", "multi_unit", "createAirGroundFormation"),
        ]
        for name, version, description, scope, tool_name in specs:
            ctx.capabilities.register(
                CapabilitySpec(
                    name=name,
                    version=version,
                    description=description,
                    scope=scope,
                    tool_name=tool_name,
                )
            )

        ctx.tools.register(ToolSpec("createStaticFormation", build_create_static_formation(ctx)))
        ctx.tools.register(ToolSpec("createFollowFormation", build_create_follow_formation(ctx)))
        ctx.tools.register(ToolSpec("moveFollowFormation", build_move_follow_formation(ctx)))
        ctx.tools.register(ToolSpec("moveFollowFormationSequence", build_move_follow_formation_sequence(ctx)))
        ctx.tools.register(ToolSpec("getFormationStatus", build_get_formation_status(ctx)))
        ctx.tools.register(ToolSpec("disbandFormation", build_disband_formation(ctx)))
        ctx.tools.register(ToolSpec("createAirGroundFormation", build_create_air_ground_formation(ctx)))
