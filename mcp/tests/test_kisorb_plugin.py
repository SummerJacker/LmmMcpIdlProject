from __future__ import annotations

import json
from pathlib import Path
from unittest.mock import AsyncMock

import pytest

from console_client import ConsoleTaskClient
from plugins.platforms.kisorb_sau.plugin import KisorbPlugin
from plugins.platforms.kisorb_sau.providers import (
    KisorbCancelTaskProvider,
    KisorbDisbandFormationProvider,
    KisorbExecuteMotionProvider,
    KisorbFollowFormationCreateProvider,
    KisorbFollowFormationMoveProvider,
    KisorbFollowFormationMoveSequenceProvider,
    KisorbFollowPath2DProvider,
    KisorbFormationStatusProvider,
    KisorbGoto2DProvider,
    KisorbStaticFormationProvider,
    KisorbStopProvider,
)
from plugins.platforms.kisorb_sau.unit_resolver import KisorbLiveUnitResolver
from robot_adapter import RobotAdapter
from swarm_runtime.context import SwarmContext
from swarm_runtime.errors import RuntimeExecutionError
from swarm_runtime.models import ExecutionRequest, UnitDescriptor
from swarm_runtime.plugin_loader import PluginLoader


MCP_ROOT = Path(__file__).parents[1]
PLUGIN_ROOT = MCP_ROOT / "plugins"
DEFAULT_PROFILE = MCP_ROOT / "profiles" / "default.json"


def complete_running_task_json(task_type: str = "navigate_to") -> str:
    return json.dumps(
        {
            "success": True,
            "message": "task accepted",
            "data": {
                "success": True,
                "task_id": "goto-1",
                "task_type": task_type,
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


def live_directory_json(*unit_ids: str) -> str:
    return json.dumps(
        {
            "success": True,
            "message": "ok",
            "data": {
                "rpc_enabled": False,
                "units": [
                    {"unit_id": unit_id, "mock": False}
                    for unit_id in unit_ids
                ]
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


@pytest.mark.asyncio
@pytest.mark.parametrize(
    ("canonical_unit_id", "kind"),
    [("GV_DYNAMIC", "ugv"), ("AV_DYNAMIC", "uav")],
)
async def test_live_unit_resolver_returns_canonical_typed_console_unit(
    canonical_unit_id: str,
    kind: str,
) -> None:
    adapter = AsyncMock(spec=RobotAdapter)
    adapter.list_robots.return_value = live_directory_json(canonical_unit_id)

    resolved = await KisorbLiveUnitResolver(adapter).resolve(
        f" {canonical_unit_id.casefold()} "
    )

    assert resolved == UnitDescriptor(
        unit_id=canonical_unit_id,
        kind=kind,
        platform="kisorb-sau",
        provider_plugin_id="platform.kisorb-sau",
        metadata={"source": "console-live"},
    )


@pytest.mark.asyncio
async def test_live_unit_resolver_propagates_transport_type_error() -> None:
    adapter = AsyncMock(spec=RobotAdapter)
    adapter.list_robots.side_effect = TypeError("transport failed")

    with pytest.raises(TypeError, match="transport failed"):
        await KisorbLiveUnitResolver(adapter).resolve("GV_DYNAMIC")


@pytest.mark.asyncio
@pytest.mark.parametrize(
    ("raw_directory", "requested_unit"),
    [
        ("not-json", "GV_DYNAMIC"),
        (json.dumps({"success": False, "data": {"units": []}}), "GV_DYNAMIC"),
        (
            json.dumps(
                {
                    "success": "false",
                    "data": {"units": [{"unit_id": "GV_DYNAMIC"}]},
                }
            ),
            "GV_DYNAMIC",
        ),
        (json.dumps({"success": True}), "GV_DYNAMIC"),
        (json.dumps({"success": True, "data": {}}), "GV_DYNAMIC"),
        (
            json.dumps(
                {
                    "success": True,
                    "data": {
                        "units": [
                            None,
                            "GV_DYNAMIC",
                            {"unit_id": None},
                            {"unit_id": "   "},
                        ]
                    },
                }
            ),
            "GV_DYNAMIC",
        ),
        (live_directory_json("GV_OTHER"), "GV_DYNAMIC"),
        (live_directory_json("XV_DYNAMIC"), "xv_dynamic"),
        (live_directory_json("gv_lowercase"), "GV_LOWERCASE"),
    ],
)
async def test_live_unit_resolver_abstains_from_invalid_or_unmatched_directory(
    raw_directory: str,
    requested_unit: str,
) -> None:
    adapter = AsyncMock(spec=RobotAdapter)
    adapter.list_robots.return_value = raw_directory

    assert await KisorbLiveUnitResolver(adapter).resolve(requested_unit) is None


def test_kisorb_plugin_registers_configured_units_and_shared_services() -> None:
    ctx = SwarmContext()

    KisorbPlugin().setup(ctx, {"tool_timeout_s": 7.5})

    assert ctx.units.resolve("robot_1").unit_id == "GV1"
    assert ctx.units.resolve("GV1").platform == "kisorb-sau"
    adapter = ctx.services.get("legacy.robot_adapter")
    client = ctx.services.get("legacy.console_task_client")
    assert client._adapter is adapter
    assert adapter._manager.tool_timeout_s == 7.5
    resolvers = ctx.unit_resolvers.list()
    assert len(resolvers) == 1
    assert resolvers[0].resolver_id == "kisorb.live"
    assert resolvers[0].priority == 100
    assert resolvers[0]._adapter is adapter
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
        "kisorb.task.status",
        "kisorb.task.cancel",
        "kisorb.fleet.capabilities",
        "kisorb.fleet.snapshot",
    }


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
    kisorb_uav = UnitDescriptor(
        "AV1", "uav", "kisorb-sau", "platform.kisorb-sau"
    )
    mock = UnitDescriptor("MOCK1", "ugv", "mock-navigation", "platform.mock")

    assert provider.supports((kisorb,)) is True
    assert provider.supports((kisorb_uav,)) is False
    assert provider.supports((mock,)) is False
    assert provider.supports((kisorb, kisorb)) is False


@pytest.mark.asyncio
async def test_follow_path_provider_forwards_canonical_unit_and_arguments() -> None:
    client = AsyncMock(spec=ConsoleTaskClient)
    client.follow_path.return_value = complete_running_task_json("follow_path")
    provider = KisorbFollowPath2DProvider(client)
    request = ExecutionRequest(
        request_id="req-follow-path",
        capability="navigation.follow_path2d",
        version="1.0",
        unit_ids=("robot_1",),
        arguments={
            "points": [{"x": 0.0, "y": 1.0}, {"x": 2.0, "y": 3.0}],
            "tolerance_m": 0.2,
            "timeout_ms": 5000,
        },
    )
    unit = UnitDescriptor("GV1", "ugv", "kisorb-sau", "platform.kisorb-sau")

    result = await provider.execute(request, (unit,))

    assert result.success is True
    client.follow_path.assert_awaited_once_with(
        unit_id="GV1",
        points_json='[{"x": 0.0, "y": 1.0}, {"x": 2.0, "y": 3.0}]',
        tolerance_m=0.2,
        timeout_ms=5000,
    )


@pytest.mark.asyncio
async def test_stop_provider_deduplicates_canonical_units_in_first_occurrence_order() -> None:
    client = AsyncMock(spec=ConsoleTaskClient)
    client.stop_units.return_value = complete_running_task_json("stop_units")
    provider = KisorbStopProvider(client)
    request = ExecutionRequest(
        request_id="req-stop",
        capability="motion.stop",
        version="1.0",
        unit_ids=("robot_2", "GV1", "robot_1"),
        arguments={},
    )
    units = (
        UnitDescriptor("GV2", "ugv", "kisorb-sau", "platform.kisorb-sau"),
        UnitDescriptor("GV1", "ugv", "kisorb-sau", "platform.kisorb-sau"),
        UnitDescriptor("GV1", "ugv", "kisorb-sau", "platform.kisorb-sau"),
    )

    result = await provider.execute(request, units)

    assert result.success is True
    client.stop_units.assert_awaited_once_with(unit_ids_csv="GV2,GV1")


def test_follow_path_and_stop_provider_support_semantics() -> None:
    client = AsyncMock(spec=ConsoleTaskClient)
    follow = KisorbFollowPath2DProvider(client)
    stop = KisorbStopProvider(client)
    kisorb = UnitDescriptor("GV1", "ugv", "kisorb-sau", "platform.kisorb-sau")
    kisorb_uav = UnitDescriptor(
        "AV1", "uav", "kisorb-sau", "platform.kisorb-sau"
    )
    mock = UnitDescriptor("MOCK1", "ugv", "mock-navigation", "platform.mock")

    assert follow.supports((kisorb,)) is True
    assert follow.supports((kisorb_uav,)) is False
    assert follow.supports((kisorb, kisorb)) is False
    assert follow.supports((mock,)) is False
    assert stop.supports((kisorb,)) is True
    assert stop.supports((kisorb_uav,)) is True
    assert stop.supports((kisorb, kisorb_uav)) is True
    assert stop.supports((kisorb, kisorb)) is True
    assert stop.supports(()) is False
    assert stop.supports((kisorb, mock)) is False


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


@pytest.mark.asyncio
async def test_execute_motion_provider_forwards_canonical_unit_and_arguments() -> None:
    client = AsyncMock(spec=ConsoleTaskClient)
    client.execute_motion.return_value = complete_running_task_json("execute_motion")
    provider = KisorbExecuteMotionProvider(client)
    request = ExecutionRequest(
        request_id="req-motion",
        capability="motion.execute",
        version="1.0",
        unit_ids=("robot_1",),
        arguments={
            "linear_velocity": 0.2,
            "angular_velocity": 0.0,
            "duration_ms": 100,
        },
    )
    unit = UnitDescriptor("GV1", "ugv", "kisorb-sau", "platform.kisorb-sau")

    result = await provider.execute(request, (unit,))

    assert result.success is True
    client.execute_motion.assert_awaited_once_with(
        unit_id="GV1",
        linear_velocity=0.2,
        angular_velocity=0.0,
        duration_ms=100,
    )


def test_execute_motion_provider_supports_only_single_ground_unit() -> None:
    provider = KisorbExecuteMotionProvider(AsyncMock())
    ugv = UnitDescriptor("GV1", "ugv", "kisorb-sau", "platform.kisorb-sau")
    uav = UnitDescriptor("AV1", "uav", "kisorb-sau", "platform.kisorb-sau")

    assert provider.supports((ugv,)) is True
    assert provider.supports((uav,)) is False
    assert provider.supports((ugv, ugv)) is False
    assert provider.supports(()) is False


@pytest.mark.asyncio
async def test_static_formation_provider_forwards_resolved_unit_csv() -> None:
    client = AsyncMock(spec=ConsoleTaskClient)
    client.create_static_formation.return_value = complete_running_task_json(
        "create_static_formation"
    )
    provider = KisorbStaticFormationProvider(client)
    request = ExecutionRequest(
        request_id="req-static",
        capability="formation.static",
        version="1.0",
        unit_ids=("robot_1", "GV2"),
        arguments={
            "formation_type": "line",
            "spacing_m": 2.0,
            "anchor_x": 10.0,
            "anchor_y": -3.0,
            "heading_rad": 1.2,
            "tolerance_m": 0.15,
            "timeout_ms": 30000,
        },
    )
    units = (
        UnitDescriptor("GV1", "ugv", "kisorb-sau", "platform.kisorb-sau"),
        UnitDescriptor("GV2", "ugv", "kisorb-sau", "platform.kisorb-sau"),
    )

    result = await provider.execute(request, units)

    assert result.success is True
    client.create_static_formation.assert_awaited_once_with(
        formation_type="line",
        unit_ids_csv="GV1,GV2",
        spacing_m=2.0,
        anchor_x=10.0,
        anchor_y=-3.0,
        heading_rad=1.2,
        tolerance_m=0.15,
        timeout_ms=30000,
    )


@pytest.mark.asyncio
async def test_follow_formation_and_task_providers_delegate_without_units() -> None:
    client = AsyncMock(spec=ConsoleTaskClient)
    client.create_follow_formation.return_value = '{"success": true, "message": "ok", "data": {"state": "READY"}}'
    client.move_follow_formation.return_value = complete_running_task_json(
        "move_follow_formation"
    )
    client.move_follow_formation_sequence.return_value = complete_running_task_json(
        "move_follow_formation_sequence"
    )
    client.get_formation_status.return_value = '{"success": true, "message": "ok", "data": {"state": "READY"}}'
    client.disband_formation.return_value = '{"success": true, "message": "ok", "data": {"state": "IDLE"}}'
    client.cancel_task.return_value = complete_running_task_json("cancel_task")

    create = KisorbFollowFormationCreateProvider(client)
    move = KisorbFollowFormationMoveProvider(client)
    sequence = KisorbFollowFormationMoveSequenceProvider(client)
    status = KisorbFormationStatusProvider(client)
    disband = KisorbDisbandFormationProvider(client)
    cancel = KisorbCancelTaskProvider(client)

    assert create.supports(()) is True
    await create.execute(
        ExecutionRequest(
            "r1",
            "formation.follow.create",
            "1.0",
            (),
            {"leader_id": "GV1", "followers_json": '[{"unit_id": "GV2", "distance_m": 0.3}]'},
        ),
        (),
    )
    await move.execute(
        ExecutionRequest("r2", "formation.follow.move", "1.0", (), {"x": 5.0, "y": 6.0}),
        (),
    )
    await sequence.execute(
        ExecutionRequest("r3", "formation.follow.move_sequence", "1.0", (), {"segments": []}),
        (),
    )
    await status.execute(
        ExecutionRequest("r4", "formation.follow.status", "1.0", (), {}),
        (),
    )
    await disband.execute(
        ExecutionRequest("r5", "formation.follow.disband", "1.0", (), {}),
        (),
    )
    await cancel.execute(
        ExecutionRequest("r6", "task.cancel", "1.0", (), {"task_id": "t-9"}),
        (),
    )

    client.create_follow_formation.assert_awaited_once_with(
        leader_id="GV1",
        followers_json='[{"unit_id": "GV2", "distance_m": 0.3}]',
    )
    client.move_follow_formation.assert_awaited_once_with(x=5.0, y=6.0)
    client.move_follow_formation_sequence.assert_awaited_once_with(segments=[])
    client.get_formation_status.assert_awaited_once_with()
    client.disband_formation.assert_awaited_once_with()
    client.cancel_task.assert_awaited_once_with(task_id="t-9")


def test_default_profile_loads_capabilities_before_kisorb() -> None:
    ctx, loader = load_default_runtime()

    assert loader.loaded_plugin_ids == (
        "capability.navigation",
        "capability.motion",
        "capability.formation",
        "capability.task",
        "capability.fleet",
        "platform.kisorb-sau",
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
        "kisorb.task.status",
        "kisorb.task.cancel",
        "kisorb.fleet.capabilities",
        "kisorb.fleet.snapshot",
    }


def test_kisorb_manifest_and_default_profile_are_exact() -> None:
    manifest_path = PLUGIN_ROOT / "platforms" / "kisorb_sau" / "plugin.json"

    assert json.loads(manifest_path.read_text(encoding="utf-8")) == {
        "api_version": 1,
        "id": "platform.kisorb-sau",
        "version": "1.2.0",
        "type": "platform",
        "entrypoint": "plugins.platforms.kisorb_sau.plugin:KisorbPlugin",
        "requires": [
            "capability.navigation",
            "capability.motion",
            "capability.formation",
            "capability.task",
            "capability.fleet",
        ],
        "provides": [
            "provider:kisorb.fleet.capabilities",
            "provider:kisorb.fleet.snapshot",
            "provider:kisorb.formation.follow.create",
            "provider:kisorb.formation.follow.disband",
            "provider:kisorb.formation.follow.move",
            "provider:kisorb.formation.follow.move_sequence",
            "provider:kisorb.formation.follow.status",
            "provider:kisorb.formation.static",
            "provider:kisorb.motion.execute",
            "provider:kisorb.motion.stop",
            "provider:kisorb.navigation.follow_path2d",
            "provider:kisorb.navigation.goto2d",
            "provider:kisorb.task.cancel",
            "provider:kisorb.task.status",
            "unit_resolver:kisorb.live",
            "service:legacy.robot_adapter",
            "service:legacy.console_task_client",
        ],
    }
    assert json.loads(DEFAULT_PROFILE.read_text(encoding="utf-8")) == {
        "profile_api_version": 1,
        "plugins": [
            {"id": "capability.navigation", "enabled": True, "config": {}},
            {"id": "capability.motion", "enabled": True, "config": {}},
            {"id": "capability.formation", "enabled": True, "config": {}},
            {"id": "capability.task", "enabled": True, "config": {}},
            {"id": "capability.fleet", "enabled": True, "config": {}},
            {"id": "platform.kisorb-sau", "enabled": True, "config": {}},
        ],
    }
