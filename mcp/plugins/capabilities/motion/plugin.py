from __future__ import annotations

from typing import Any, Mapping

from swarm_runtime.context import SwarmContext
from swarm_runtime.models import CapabilitySpec, ToolSpec

from .tools import build_execute_motion, build_stop_units


class MotionCapabilityPlugin:
    plugin_id = "capability.motion"
    version = "1.1.0"

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
        ctx.capabilities.register(
            CapabilitySpec(
                name="motion.execute",
                version="1.0",
                description="Execute one typed open-loop motion command",
                scope="unit",
                tool_name="executeMotion",
            )
        )
        ctx.tools.register(ToolSpec("stopUnits", build_stop_units(ctx)))
        ctx.tools.register(ToolSpec("executeMotion", build_execute_motion(ctx)))
