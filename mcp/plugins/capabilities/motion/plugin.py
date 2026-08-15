from __future__ import annotations

from typing import Any, Mapping

from swarm_runtime.context import SwarmContext
from swarm_runtime.models import CapabilitySpec, ToolSpec

from .tools import build_stop_units


class MotionCapabilityPlugin:
    plugin_id = "capability.motion"
    version = "1.0.0"

    def setup(self, ctx: SwarmContext, config: Mapping[str, Any]) -> None:
        ctx.capabilities.register(
            CapabilitySpec(
                name="motion.stop",
                version="1.0",
                description="Stop one or more mobile units",
                scope="multi_unit",
                tool_name="stopUnits",
            )
        )
        ctx.tools.register(ToolSpec("stopUnits", build_stop_units(ctx)))
