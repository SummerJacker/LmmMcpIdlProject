from __future__ import annotations

from typing import Any, Mapping

from swarm_runtime.context import SwarmContext
from swarm_runtime.models import CapabilitySpec, ToolSpec

from .tools import build_follow_path, build_navigate_to


class NavigationCapabilityPlugin:
    plugin_id = "capability.navigation"
    version = "1.1.0"

    def setup(self, ctx: SwarmContext, config: Mapping[str, Any]) -> None:
        ctx.capabilities.register(
            CapabilitySpec(
                name="navigation.goto2d",
                version="1.0",
                description="Navigate one mobile unit to a two-dimensional target",
                scope="unit",
                tool_name="navigateTo",
            )
        )
        ctx.capabilities.register(
            CapabilitySpec(
                name="navigation.follow_path2d",
                version="1.0",
                description="Follow an ordered two-dimensional path",
                scope="unit",
                tool_name="followPath",
            )
        )
        ctx.tools.register(ToolSpec("navigateTo", build_navigate_to(ctx)))
        ctx.tools.register(ToolSpec("followPath", build_follow_path(ctx)))
