from __future__ import annotations

import json
from dataclasses import dataclass

import pytest
from fastmcp import FastMCP

from plugins.capabilities.navigation.plugin import NavigationCapabilityPlugin
from swarm_runtime.context import SwarmContext
from swarm_runtime.fastmcp_bridge import install_runtime_tools
from swarm_runtime.models import (
    ExecutionRequest,
    ExecutionResult,
    PolicyDecision,
    PolicyOutcome,
    UnitDescriptor,
)
from task_api.contracts import task_payload_has_contract_shape


@dataclass
class CapturingProvider:
    provider_id: str = "test.navigation.goto2d"
    capability: str = "navigation.goto2d"
    version: str = "1.0"
    priority: int = 100
    request: ExecutionRequest | None = None
    raises: bool = False

    def supports(self, units: tuple[UnitDescriptor, ...]) -> bool:
        return len(units) == 1 and units[0].platform == "test"

    async def execute(self, request, units) -> ExecutionResult:
        self.request = request
        if self.raises:
            raise ValueError("do not leak this")
        return ExecutionResult(True, "ok", {"unit_id": units[0].unit_id})


class DenyPolicy:
    policy_id = "test.deny"
    priority = 100

    def applies_to(self, request: ExecutionRequest) -> bool:
        return True

    async def evaluate(self, request, units, provider) -> PolicyOutcome:
        return PolicyOutcome(PolicyDecision.DENY, "blocked by test policy")


def context_with_navigation_provider(
    provider: CapturingProvider | None = None,
) -> tuple[SwarmContext, CapturingProvider]:
    ctx = SwarmContext()
    NavigationCapabilityPlugin().setup(ctx, {})
    ctx.units.register(
        UnitDescriptor("GV1", "ugv", "test", "platform.test", ("robot_1",))
    )
    selected = provider or CapturingProvider()
    ctx.providers.register(selected)
    return ctx, selected


def app_with_provider(
    provider: CapturingProvider | None = None,
) -> tuple[FastMCP, CapturingProvider]:
    ctx, selected = context_with_navigation_provider(provider)
    app = FastMCP("test")
    install_runtime_tools(app, ctx.tools)
    return app, selected


@pytest.mark.asyncio
async def test_navigation_plugin_preserves_navigate_to_schema() -> None:
    app, _ = app_with_provider()

    tool = await app.get_tool("navigateTo")

    assert tool.parameters["required"] == ["unit_id", "target"]
    assert tool.parameters["properties"]["tolerance_m"] == {
        "default": 0.15,
        "type": "number",
    }
    assert tool.parameters["properties"]["timeout_ms"] == {
        "default": 30000,
        "type": "integer",
    }
    assert tool.parameters["$defs"]["Point2D"]["required"] == ["x", "y"]


@pytest.mark.asyncio
async def test_navigate_to_builds_versioned_execution_request() -> None:
    app, provider = app_with_provider()

    result = await app.call_tool(
        "navigateTo",
        {"unit_id": "robot_1", "target": {"x": 3.0, "y": 5.0}},
    )

    assert json.loads(result.content[0].text)["success"] is True
    assert provider.request is not None
    assert provider.request.capability == "navigation.goto2d"
    assert provider.request.version == "1.0"
    assert provider.request.arguments == {
        "x": 3.0,
        "y": 5.0,
        "tolerance_m": 0.15,
        "timeout_ms": 30000,
    }


@pytest.mark.asyncio
async def test_direct_callable_rejects_missing_target_fields_with_full_task() -> None:
    ctx, _ = context_with_navigation_provider()

    raw = await ctx.tools.get("navigateTo").callable("GV1", {})
    payload = json.loads(raw)

    assert payload["error_code"] == "SAFETY_REJECTED"
    assert task_payload_has_contract_shape(payload["data"])
    assert payload["data"]["state"] == "REJECTED"


@pytest.mark.asyncio
async def test_missing_unit_maps_to_unit_not_found_task() -> None:
    ctx = SwarmContext()
    NavigationCapabilityPlugin().setup(ctx, {})

    raw = await ctx.tools.get("navigateTo").callable(
        "missing", {"x": 1.0, "y": 2.0}
    )
    payload = json.loads(raw)

    assert payload["error_code"] == "UNIT_NOT_FOUND"
    assert task_payload_has_contract_shape(payload["data"])


@pytest.mark.asyncio
async def test_missing_provider_maps_to_unsupported_capability() -> None:
    ctx = SwarmContext()
    NavigationCapabilityPlugin().setup(ctx, {})
    ctx.units.register(UnitDescriptor("GV1", "ugv", "test", "platform.test"))

    raw = await ctx.tools.get("navigateTo").callable(
        "GV1", {"x": 1.0, "y": 2.0}
    )
    payload = json.loads(raw)

    assert payload["error_code"] == "UNSUPPORTED_CAPABILITY"
    assert payload["data"]["state"] == "REJECTED"


@pytest.mark.asyncio
async def test_policy_denial_maps_to_safety_rejected() -> None:
    ctx, _ = context_with_navigation_provider()
    ctx.policies.register(DenyPolicy())

    raw = await ctx.tools.get("navigateTo").callable(
        "GV1", {"x": 1.0, "y": 2.0}
    )
    payload = json.loads(raw)

    assert payload["error_code"] == "SAFETY_REJECTED"
    assert payload["message"] == "blocked by test policy"


@pytest.mark.asyncio
async def test_unexpected_execution_failure_returns_internal_failed_task() -> None:
    ctx, _ = context_with_navigation_provider(CapturingProvider(raises=True))

    raw = await ctx.tools.get("navigateTo").callable(
        "GV1", {"x": 1.0, "y": 2.0}
    )
    payload = json.loads(raw)

    assert payload["error_code"] == "INTERNAL_ERROR"
    assert payload["data"]["state"] == "FAILED"
    assert task_payload_has_contract_shape(payload["data"])
    assert "do not leak this" not in payload["message"]
