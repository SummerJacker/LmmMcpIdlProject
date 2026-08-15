from __future__ import annotations

from typing import Any, Mapping

from config import DEFAULT_TOOL_TIMEOUT_S, load_robot_configs
from console_client import ConsoleTaskClient
from robot_adapter import RobotAdapter
from swarm_runtime.context import SwarmContext
from swarm_runtime.models import UnitDescriptor

from .providers import (
    KisorbFollowPath2DProvider,
    KisorbGoto2DProvider,
    KisorbStopProvider,
)
from .unit_resolver import KisorbLiveUnitResolver


class KisorbPlugin:
    plugin_id = "platform.kisorb-sau"
    version = "1.1.0"

    def setup(self, ctx: SwarmContext, config: Mapping[str, Any]) -> None:
        tool_timeout_s = float(config.get("tool_timeout_s", DEFAULT_TOOL_TIMEOUT_S))
        if tool_timeout_s <= 0:
            raise ValueError("tool_timeout_s must be positive")

        adapter = RobotAdapter(tool_timeout_s=tool_timeout_s)
        client = ConsoleTaskClient(adapter)
        ctx.services.register("legacy.robot_adapter", adapter)
        ctx.services.register("legacy.console_task_client", client)
        ctx.unit_resolvers.register(KisorbLiveUnitResolver(adapter))

        for robot in load_robot_configs():
            ctx.units.register(
                UnitDescriptor(
                    unit_id=robot.unit_id,
                    kind="ugv",
                    platform="kisorb-sau",
                    provider_plugin_id=self.plugin_id,
                    aliases=(robot.robot_id,),
                    metadata={
                        "mode": robot.mode,
                        "simulator_type": robot.simulator_type,
                    },
                )
            )

        ctx.providers.register(KisorbGoto2DProvider(client))
        ctx.providers.register(KisorbFollowPath2DProvider(client))
        ctx.providers.register(KisorbStopProvider(client))
