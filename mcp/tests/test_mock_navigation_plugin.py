from __future__ import annotations

import hashlib
import json
from pathlib import Path

import pytest

from plugins.platforms.mock_navigation.providers import (
    MockFollowPath2DProvider,
    MockStopProvider,
)
from swarm_runtime.context import SwarmContext
from swarm_runtime.errors import UnitNotFoundError
from swarm_runtime.models import ExecutionRequest, UnitDescriptor
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
    MCP_ROOT / "plugins" / "capabilities" / "motion" / "plugin.py",
    MCP_ROOT / "plugins" / "capabilities" / "motion" / "tools.py",
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
    assert result.data["unit_results"][0]["progress_pct"] == 100.0
    assert loader.loaded_plugin_ids == (
        "capability.navigation",
        "capability.motion",
        "capability.formation",
        "capability.task",
        "capability.fleet",
        "platform.kisorb-sau",
        "platform.mock-navigation",
    )
    assert {provider.provider_id for provider in ctx.providers.list()} == {
        "kisorb.navigation.goto2d",
        "kisorb.navigation.follow_path2d",
        "kisorb.motion.stop",
        "kisorb.motion.execute",
        "kisorb.formation.static",
        "kisorb.formation.follow.create",
        "kisorb.formation.follow.move",
        "kisorb.formation.follow.move_sequence",
        "kisorb.formation.follow.status",
        "kisorb.formation.follow.disband",
        "kisorb.formation.air_ground",
        "kisorb.formation.air_ground.status",
        "kisorb.formation.air_ground.disband",
        "kisorb.task.status",
        "kisorb.task.cancel",
        "kisorb.fleet.capabilities",
        "kisorb.fleet.snapshot",
        "mock.navigation.goto2d",
        "mock.navigation.follow_path2d",
        "mock.motion.stop",
    }
    assert file_hashes() == before


@pytest.mark.asyncio
async def test_mock_follow_path_provider_returns_completed_task() -> None:
    provider = MockFollowPath2DProvider()
    points = [{"x": 0.0, "y": 1.0}, {"x": 2.0, "y": 3.0}]
    request = ExecutionRequest(
        request_id="req-mock-path",
        capability="navigation.follow_path2d",
        version="1.0",
        unit_ids=("mock_robot",),
        arguments={
            "points": points,
            "tolerance_m": 0.2,
            "timeout_ms": 5000,
        },
    )
    unit = UnitDescriptor(
        "MOCK1", "ugv", "mock-navigation", "platform.mock-navigation"
    )

    result = await provider.execute(request, (unit,))

    assert result.success is True
    assert task_payload_has_contract_shape(result.data)
    assert result.data["success"] is True
    assert result.data["task_type"] == "follow_path"
    assert result.data["state"] == "COMPLETED"
    assert result.data["unit_results"] == [
        {
            "unit_id": "MOCK1",
            "state": "COMPLETED",
            "progress_pct": 100.0,
            "message": "mock path completed",
            "error_code": "",
            "target": {"points": points},
        }
    ]


@pytest.mark.asyncio
async def test_mock_stop_provider_deduplicates_completed_unit_results() -> None:
    provider = MockStopProvider()
    request = ExecutionRequest(
        request_id="req-mock-stop",
        capability="motion.stop",
        version="1.0",
        unit_ids=("mock_robot", "MOCK1"),
        arguments={},
    )
    unit = UnitDescriptor(
        "MOCK1", "ugv", "mock-navigation", "platform.mock-navigation"
    )

    result = await provider.execute(request, (unit, unit))

    assert result.success is True
    assert task_payload_has_contract_shape(result.data)
    assert result.data["success"] is True
    assert result.data["task_type"] == "stop_units"
    assert result.data["state"] == "COMPLETED"
    assert result.data["unit_results"] == [
        {
            "unit_id": "MOCK1",
            "state": "COMPLETED",
            "progress_pct": 100.0,
            "message": "mock units stopped",
            "error_code": "",
        }
    ]


def test_mock_follow_path_and_stop_provider_support_semantics() -> None:
    follow = MockFollowPath2DProvider()
    stop = MockStopProvider()
    mock = UnitDescriptor(
        "MOCK1", "ugv", "mock-navigation", "platform.mock-navigation"
    )
    kisorb = UnitDescriptor("GV1", "ugv", "kisorb-sau", "platform.kisorb-sau")

    assert follow.supports((mock,)) is True
    assert follow.supports(()) is False
    assert follow.supports((mock, mock)) is False
    assert follow.supports((kisorb,)) is False
    assert follow.supports((mock, kisorb)) is False
    assert stop.supports((mock,)) is True
    assert stop.supports((mock, mock)) is True
    assert stop.supports(()) is False
    assert stop.supports((mock, kisorb)) is False


def test_default_profile_does_not_register_mock_unit() -> None:
    ctx, _ = load_runtime("default.json")

    with pytest.raises(UnitNotFoundError):
        ctx.units.resolve("MOCK1")


def test_mock_manifest_and_profile_are_exact() -> None:
    manifest_path = (
        PLUGIN_ROOT / "platforms" / "mock_navigation" / "plugin.json"
    )
    profile_path = PROFILES / "mock-navigation.json"

    assert json.loads(manifest_path.read_text(encoding="utf-8")) == {
        "api_version": 1,
        "id": "platform.mock-navigation",
        "version": "1.1.0",
        "type": "platform",
        "entrypoint": (
            "plugins.platforms.mock_navigation.plugin:MockNavigationPlugin"
        ),
        "requires": ["capability.navigation", "capability.motion"],
        "provides": [
            "provider:mock.navigation.goto2d",
            "provider:mock.navigation.follow_path2d",
            "provider:mock.motion.stop",
            "unit:MOCK1",
        ],
    }
    assert json.loads(profile_path.read_text(encoding="utf-8")) == {
        "profile_api_version": 1,
        "plugins": [
            {"id": "capability.navigation", "enabled": True, "config": {}},
            {"id": "capability.motion", "enabled": True, "config": {}},
            {"id": "capability.formation", "enabled": True, "config": {}},
            {"id": "capability.task", "enabled": True, "config": {}},
            {"id": "capability.fleet", "enabled": True, "config": {}},
            {"id": "platform.kisorb-sau", "enabled": True, "config": {}},
            {
                "id": "platform.mock-navigation",
                "enabled": True,
                "config": {},
            },
        ],
    }
