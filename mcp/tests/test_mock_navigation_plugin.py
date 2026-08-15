from __future__ import annotations

import hashlib
from pathlib import Path

import pytest

from swarm_runtime.context import SwarmContext
from swarm_runtime.errors import UnitNotFoundError
from swarm_runtime.models import ExecutionRequest
from swarm_runtime.plugin_loader import PluginLoader
from task_api.contracts import task_payload_has_contract_shape


MCP_ROOT = Path(__file__).parents[1]
PLUGIN_ROOT = MCP_ROOT / "plugins"
PROFILES = MCP_ROOT / "profiles"
CORE_FILES = (
    MCP_ROOT / "swarm_runtime" / "executor.py",
    MCP_ROOT / "swarm_runtime" / "registry" / "capability.py",
    MCP_ROOT / "swarm_runtime" / "registry" / "provider.py",
    MCP_ROOT / "swarm_runtime" / "registry" / "unit.py",
    MCP_ROOT / "plugins" / "capabilities" / "navigation" / "plugin.py",
    MCP_ROOT / "plugins" / "capabilities" / "navigation" / "tools.py",
)


def file_hashes() -> dict[Path, str]:
    return {
        path: hashlib.sha256(path.read_bytes()).hexdigest() for path in CORE_FILES
    }


def load_runtime(profile_name: str) -> tuple[SwarmContext, PluginLoader]:
    ctx = SwarmContext()
    loader = PluginLoader(ctx, PLUGIN_ROOT)
    loader.load_profile(PROFILES / profile_name)
    return ctx, loader


@pytest.mark.asyncio
async def test_mock_profile_executes_same_capability_without_core_changes() -> None:
    before = file_hashes()
    ctx, loader = load_runtime("mock-navigation.json")
    request = ExecutionRequest(
        request_id="req-mock",
        capability="navigation.goto2d",
        version="1.0",
        unit_ids=("mock_robot",),
        arguments={
            "x": 2.0,
            "y": 3.0,
            "tolerance_m": 0.15,
            "timeout_ms": 30000,
        },
    )

    result = await ctx.executor.execute(request)

    assert result.success is True
    assert task_payload_has_contract_shape(result.data)
    assert result.data["task_type"] == "navigate_to"
    assert result.data["state"] == "COMPLETED"
    assert result.data["unit_results"][0]["unit_id"] == "MOCK1"
    assert loader.loaded_plugin_ids == (
        "capability.navigation",
        "platform.kisorb-sau",
        "platform.mock-navigation",
    )
    assert file_hashes() == before


def test_default_profile_does_not_register_mock_unit() -> None:
    ctx, _ = load_runtime("default.json")

    with pytest.raises(UnitNotFoundError):
        ctx.units.resolve("MOCK1")
