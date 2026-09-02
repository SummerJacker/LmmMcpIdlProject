from __future__ import annotations

import json
from dataclasses import dataclass
from pathlib import Path

import pytest
from fastmcp import FastMCP

from plugins.capabilities.formation.plugin import FormationCapabilityPlugin
from swarm_runtime.context import SwarmContext
from swarm_runtime.fastmcp_bridge import install_runtime_tools
from swarm_runtime.models import ExecutionRequest, ExecutionResult, UnitDescriptor
from task_api.contracts import (
    formation_payload_has_contract_shape,
    task_payload_has_contract_shape,
)


@dataclass
class CapturingProvider:
    provider_id: str
    capability: str
    version: str = "1.0"
    priority: int = 100
    request: ExecutionRequest | None = None
    result: ExecutionResult | None = None

    def supports(self, units: tuple[UnitDescriptor, ...]) -> bool:
        return True

    async def execute(self, request, units) -> ExecutionResult:
        self.request = request
        return self.result or ExecutionResult(True, "ok", {})


def formation_context(
    provider: CapturingProvider | None = None,
) -> tuple[SwarmContext, CapturingProvider]:
    ctx = SwarmContext()
    FormationCapabilityPlugin().setup(ctx, {})
    selected = provider or CapturingProvider("test.formation.static", "formation.static")
    ctx.providers.register(selected)
    return ctx, selected


def test_formation_plugin_registers_six_capabilities_and_tools() -> None:
    ctx = SwarmContext()

    FormationCapabilityPlugin().setup(ctx, {})

    assert {tool.name for tool in ctx.tools.list()} == {
        "createStaticFormation",
        "createFollowFormation",
        "moveFollowFormation",
        "moveFollowFormationSequence",
        "getFormationStatus",
        "disbandFormation",
        "createAirGroundFormation",
    }
    assert ctx.capabilities.get("formation.static", "1.0").tool_name == "createStaticFormation"
    assert ctx.capabilities.get("formation.static", "1.0").scope == "multi_unit"
    assert ctx.capabilities.get("formation.follow.create", "1.0").scope == "fleet"
    assert ctx.capabilities.get("formation.follow.status", "1.0").tool_name == "getFormationStatus"
    assert ctx.capabilities.get("formation.air_ground", "1.0").tool_name == "createAirGroundFormation"


@pytest.mark.asyncio
async def test_formation_structured_tool_schemas_match_idl() -> None:
    ctx, _ = formation_context()
    app = FastMCP("test")
    install_runtime_tools(app, ctx.tools)

    static = await app.get_tool("createStaticFormation")
    create = await app.get_tool("createFollowFormation")
    move = await app.get_tool("moveFollowFormation")
    sequence = await app.get_tool("moveFollowFormationSequence")

    assert set(static.parameters["properties"]) == {"request"}
    assert set(create.parameters["properties"]) == {"request"}
    assert set(move.parameters["properties"]) == {"target"}
    assert set(sequence.parameters["properties"]) == {"segments"}
    assert static.parameters["$defs"]["StaticFormationRequest"]["properties"][
        "formation_type"
    ]["enum"] == ["line", "triangle", "column"]
    assert move.parameters["$defs"]["Point2D"]["required"] == ["x", "y"]


@pytest.mark.asyncio
async def test_create_static_formation_resolves_units_and_forwards_geometry() -> None:
    ctx, provider = formation_context(
        CapturingProvider("test.formation.static", "formation.static")
    )
    ctx.units.register(
        UnitDescriptor("GV1", "ugv", "test", "platform.test", ("robot_1",))
    )
    ctx.units.register(
        UnitDescriptor("GV2", "ugv", "test", "platform.test", ("robot_2",))
    )

    raw = await ctx.tools.get("createStaticFormation").callable(
        {
            "formation_type": "line",
            "unit_ids": ["robot_1", "GV2"],
            "spacing_m": 2.0,
            "anchor": {"x": 10.0, "y": -3.0},
            "heading_rad": 1.2,
            "tolerance_m": 0.15,
            "timeout_ms": 30000,
        }
    )
    payload = json.loads(raw)

    assert payload["success"] is True
    assert provider.request is not None
    assert provider.request.capability == "formation.static"
    assert provider.request.unit_ids == ("robot_1", "GV2")
    assert provider.request.arguments == {
        "formation_type": "line",
        "spacing_m": 2.0,
        "anchor_x": 10.0,
        "anchor_y": -3.0,
        "heading_rad": 1.2,
        "tolerance_m": 0.15,
        "timeout_ms": 30000,
    }


@pytest.mark.asyncio
async def test_create_static_formation_rejects_missing_anchor_or_unit_ids() -> None:
    ctx, _ = formation_context(
        CapturingProvider("test.formation.static", "formation.static")
    )

    raw = await ctx.tools.get("createStaticFormation").callable(
        {"formation_type": "line", "unit_ids": ["GV1"], "spacing_m": 1.0}
    )
    payload = json.loads(raw)

    assert payload["error_code"] == "SAFETY_REJECTED"
    assert task_payload_has_contract_shape(payload["data"])
    assert payload["data"]["task_type"] == "create_static_formation"
    assert payload["data"]["state"] == "REJECTED"


@pytest.mark.asyncio
async def test_create_static_formation_missing_unit_returns_rejected_task() -> None:
    ctx, _ = formation_context(
        CapturingProvider("test.formation.static", "formation.static")
    )

    raw = await ctx.tools.get("createStaticFormation").callable(
        {
            "formation_type": "line",
            "unit_ids": ["missing"],
            "spacing_m": 1.0,
            "anchor": {"x": 0.0, "y": 0.0},
            "heading_rad": 0.0,
            "tolerance_m": 0.15,
            "timeout_ms": 30000,
        }
    )
    payload = json.loads(raw)

    assert payload["error_code"] == "UNIT_NOT_FOUND"
    assert payload["data"]["task_type"] == "create_static_formation"
    assert payload["data"]["state"] == "REJECTED"


@pytest.mark.asyncio
async def test_follow_formation_tools_are_zero_unit_and_formation_shaped() -> None:
    ctx = SwarmContext()
    FormationCapabilityPlugin().setup(ctx, {})
    create = CapturingProvider(
        "test.formation.follow.create", "formation.follow.create"
    )
    status = CapturingProvider(
        "test.formation.follow.status", "formation.follow.status"
    )
    ctx.providers.register(create)
    ctx.providers.register(status)

    raw_create = await ctx.tools.get("createFollowFormation").callable(
        {
            "leader_id": "GV1",
            "followers": [{"unit_id": "GV2", "distance_m": 0.3}],
        }
    )
    raw_status = await ctx.tools.get("getFormationStatus").callable()

    assert create.request is not None
    assert create.request.unit_ids == ()
    assert create.request.arguments["leader_id"] == "GV1"
    assert json.loads(create.request.arguments["followers_json"]) == [
        {"unit_id": "GV2", "distance_m": 0.3}
    ]
    assert status.request is not None
    assert status.request.unit_ids == ()
    assert status.request.capability == "formation.follow.status"


@pytest.mark.asyncio
async def test_formation_error_maps_to_formation_status_shape() -> None:
    ctx = SwarmContext()
    FormationCapabilityPlugin().setup(ctx, {})

    raw = await ctx.tools.get("createFollowFormation").callable(
        {"leader_id": "GV1", "followers": "not-a-list"}
    )
    payload = json.loads(raw)

    assert payload["error_code"] == "SAFETY_REJECTED"
    assert formation_payload_has_contract_shape(payload["data"])
    assert payload["data"]["state"] == "FAILED"


@pytest.mark.asyncio
async def test_move_follow_formation_sequence_rejects_non_array() -> None:
    ctx, _ = formation_context()

    raw = await ctx.tools.get("moveFollowFormationSequence").callable("not-a-list")
    payload = json.loads(raw)

    assert payload["error_code"] == "SAFETY_REJECTED"
    assert task_payload_has_contract_shape(payload["data"])
    assert payload["data"]["task_type"] == "move_follow_formation_sequence"


def test_formation_plugin_manifest_is_exact() -> None:
    manifest_path = (
        Path(__file__).parents[1]
        / "plugins"
        / "capabilities"
        / "formation"
        / "plugin.json"
    )

    assert json.loads(manifest_path.read_text(encoding="utf-8")) == {
        "api_version": 1,
        "id": "capability.formation",
        "version": "1.0.0",
        "type": "capability",
        "entrypoint": (
            "plugins.capabilities.formation.plugin:FormationCapabilityPlugin"
        ),
        "requires": [],
        "provides": [
            "capability:formation.static@1.0",
            "capability:formation.follow.create@1.0",
            "capability:formation.follow.move@1.0",
            "capability:formation.follow.move_sequence@1.0",
            "capability:formation.follow.status@1.0",
            "capability:formation.follow.disband@1.0",
            "capability:formation.air_ground@1.0",
            "tool:createStaticFormation",
            "tool:createFollowFormation",
            "tool:moveFollowFormation",
            "tool:moveFollowFormationSequence",
            "tool:getFormationStatus",
            "tool:disbandFormation",
            "tool:createAirGroundFormation",
        ],
    }
