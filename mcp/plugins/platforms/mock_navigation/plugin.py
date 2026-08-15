from __future__ import annotations

from typing import Any, Mapping

from swarm_runtime.context import SwarmContext
from swarm_runtime.models import UnitDescriptor

from .providers import MockGoto2DProvider


class MockNavigationPlugin:
    plugin_id = "platform.mock-navigation"
    version = "1.0.0"

    def setup(self, ctx: SwarmContext, config: Mapping[str, Any]) -> None:
        ctx.units.register(
            UnitDescriptor(
                unit_id="MOCK1",
                kind="ugv",
                platform="mock-navigation",
                provider_plugin_id=self.plugin_id,
                aliases=("mock_robot",),
                metadata={"mode": "in-memory"},
            )
        )
        ctx.providers.register(MockGoto2DProvider())
