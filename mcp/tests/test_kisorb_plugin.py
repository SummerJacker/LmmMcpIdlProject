from __future__ import annotations

import json
from pathlib import Path
from unittest.mock import AsyncMock

import pytest

from console_client import ConsoleTaskClient
from plugins.platforms.kisorb_sau.plugin import KisorbPlugin
from plugins.platforms.kisorb_sau.providers import KisorbGoto2DProvider
from swarm_runtime.context import SwarmContext
from swarm_runtime.errors import RuntimeExecutionError
from swarm_runtime.models import ExecutionRequest, UnitDescriptor
from swarm_runtime.plugin_loader import PluginLoader


MCP_ROOT = Path(__file__).parents[1]
PLUGIN_ROOT = MCP_ROOT / "plugins"
DEFAULT_PROFILE = MCP_ROOT / "profiles" / "default.json"


def complete_running_task_json() -> str:
    return json.dumps(
        {
            "success": True,
            "message": "task accepted",
            "data": {
                "success": True,
                "task_id": "goto-1",
                "task_type": "navigate_to",
                "state": "RUNNING",
                "progress_pct": 0.0,
                "message": "task accepted",
                "error_code": "",
                "unit_results": [],
                "elapsed_ms": 0,
                "started_at_ms": 1,
                "cancellation_effect": "NOT_APPLICABLE",
            },
        }
    )


def request_for(unit_id: str) -> ExecutionRequest:
    return ExecutionRequest(
        request_id="req-kisorb",
        capability="navigation.goto2d",
        version="1.0",
        unit_ids=(unit_id,),
        arguments={
            "x": 3.0,
            "y": -2.0,
            "tolerance_m": 0.15,
            "timeout_ms": 30000,
        },
    )


def load_default_runtime() -> tuple[SwarmContext, PluginLoader]:
    ctx = SwarmContext()
    loader = PluginLoader(ctx, PLUGIN_ROOT)
    loader.load_profile(DEFAULT_PROFILE)
    return ctx, loader


def test_kisorb_plugin_registers_configured_units_and_shared_services() -> None:
    ctx = SwarmContext()

    KisorbPlugin().setup(ctx, {"tool_timeout_s": 7.5})

    assert ctx.units.resolve("robot_1").unit_id == "GV1"
    assert ctx.units.resolve("GV1").platform == "kisorb-sau"
    adapter = ctx.services.get("legacy.robot_adapter")
    client = ctx.services.get("legacy.console_task_client")
    assert client._adapter is adapter
    assert adapter._manager.tool_timeout_s == 7.5


@pytest.mark.asyncio
async def test_kisorb_provider_forwards_canonical_unit_and_arguments(
    monkeypatch,
) -> None:
    call = AsyncMock(return_value=complete_running_task_json())
    monkeypatch.setattr(ConsoleTaskClient, "navigate_to", call)
    ctx, _ = load_default_runtime()

    result = await ctx.executor.execute(request_for("robot_1"))

    assert result.success is True
    call.assert_awaited_once_with(
        unit_id="GV1",
        x=3.0,
        y=-2.0,
        tolerance_m=0.15,
        timeout_ms=30000,
    )


def test_kisorb_provider_supports_only_one_kisorb_unit() -> None:
    provider = KisorbGoto2DProvider(AsyncMock())
    kisorb = UnitDescriptor("GV1", "ugv", "kisorb-sau", "platform.kisorb-sau")
    mock = UnitDescriptor("MOCK1", "ugv", "mock-navigation", "platform.mock")

    assert provider.supports((kisorb,)) is True
    assert provider.supports((mock,)) is False
    assert provider.supports((kisorb, kisorb)) is False


@pytest.mark.asyncio
async def test_malformed_console_response_becomes_internal_runtime_error(
    monkeypatch,
) -> None:
    monkeypatch.setattr(
        ConsoleTaskClient,
        "navigate_to",
        AsyncMock(return_value="not-json"),
    )
    ctx, _ = load_default_runtime()

    with pytest.raises(RuntimeExecutionError) as error:
        await ctx.executor.execute(request_for("GV1"))

    assert error.value.error_code == "INTERNAL_ERROR"


def test_default_profile_loads_navigation_and_kisorb_only() -> None:
    _, loader = load_default_runtime()

    assert loader.loaded_plugin_ids == (
        "capability.navigation",
        "platform.kisorb-sau",
    )
