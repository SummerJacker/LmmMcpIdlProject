from __future__ import annotations

import json
import re
from pathlib import Path
from unittest.mock import AsyncMock

import pytest

from main import create_app
from robot_adapter import RobotAdapter
from task_api.capability_service import CapabilityService
import task_api.contracts as contracts
from task_api.contracts import LOW_LEVEL_TOOL_NAMES, PRODUCTION_TOOL_NAMES
import safety.validator as safety_validator


IDL_PATH = Path(__file__).parents[1] / "idl" / "mcp_swarm_task.idl"


def _idl_method_names() -> set[str]:
    text = IDL_PATH.read_text(encoding="utf-8")
    interface = text.split("interface SwarmTaskControl", 1)[1]
    return set(re.findall(r"\b(?:Capabilities|FleetSnapshot|TaskResult|FormationStatus)\s+(\w+)\s*\(", interface))


@pytest.mark.asyncio
async def test_idl_and_production_mcp_tool_names_match(monkeypatch) -> None:
    monkeypatch.setenv("MCP_EXPOSE_LOW_LEVEL_TOOLS", "0")
    tools = {tool.name for tool in await create_app().list_tools()}
    assert tools == PRODUCTION_TOOL_NAMES
    assert tools == _idl_method_names()


@pytest.mark.asyncio
async def test_low_level_tools_hidden_by_default(monkeypatch) -> None:
    monkeypatch.delenv("MCP_EXPOSE_LOW_LEVEL_TOOLS", raising=False)
    tools = {tool.name for tool in await create_app().list_tools()}
    assert tools.isdisjoint(LOW_LEVEL_TOOL_NAMES)


@pytest.mark.asyncio
async def test_low_level_tools_can_be_enabled_for_debug(monkeypatch) -> None:
    monkeypatch.setenv("MCP_EXPOSE_LOW_LEVEL_TOOLS", "1")
    tools = {tool.name for tool in await create_app().list_tools()}
    assert PRODUCTION_TOOL_NAMES <= tools
    assert tools - PRODUCTION_TOOL_NAMES == LOW_LEVEL_TOOL_NAMES


@pytest.mark.asyncio
async def test_navigate_tool_has_no_yaw_or_speed_parameters(monkeypatch) -> None:
    monkeypatch.setenv("MCP_EXPOSE_LOW_LEVEL_TOOLS", "0")
    tool = await create_app().get_tool("navigateTo")
    properties = tool.parameters["properties"]
    assert "target" in properties
    assert "x" not in properties
    assert "y" not in properties
    assert "yaw" not in properties
    assert "linear_speed_m_s" not in properties
    assert "angular_speed_rad_s" not in properties


@pytest.mark.asyncio
async def test_structured_mcp_tool_schemas_match_idl_requests(monkeypatch) -> None:
    monkeypatch.setenv("MCP_EXPOSE_LOW_LEVEL_TOOLS", "0")
    app = create_app()
    static_tool = await app.get_tool("createStaticFormation")
    follow_tool = await app.get_tool("createFollowFormation")
    move_tool = await app.get_tool("moveFollowFormation")
    assert set(static_tool.parameters["properties"]) == {"request"}
    assert set(follow_tool.parameters["properties"]) == {"request"}
    assert set(move_tool.parameters["properties"]) == {"target"}


@pytest.mark.asyncio
async def test_static_formation_forwards_anchor_and_heading(monkeypatch) -> None:
    monkeypatch.setenv("MCP_EXPOSE_LOW_LEVEL_TOOLS", "0")
    call = AsyncMock(return_value='{"success":true,"message":"ok","data":{}}')
    monkeypatch.setattr(RobotAdapter, "create_static_formation", call)

    await create_app().call_tool(
        "createStaticFormation",
        {
            "request": {
                "formation_type": "line",
                "unit_ids": ["GV1", "GV2"],
                "spacing_m": 2.0,
                "anchor": {"x": 10.0, "y": -3.0},
                "heading_rad": 1.2,
                "tolerance_m": 0.15,
                "timeout_ms": 30000,
            }
        },
    )

    call.assert_awaited_once_with(
        formation_type="line",
        unit_ids_csv="GV1,GV2",
        spacing_m=2.0,
        anchor_x=10.0,
        anchor_y=-3.0,
        heading_rad=1.2,
        tolerance_m=0.15,
        timeout_ms=30000,
    )


def test_idl_reports_effective_follow_distance_and_non_cancel_effect() -> None:
    text = IDL_PATH.read_text(encoding="utf-8")
    assert "NOT_APPLICABLE" in text
    assert "requested_distance_m" in text
    assert "effective_distance_m" in text
    assert "active_move_task_id" in text
    assert "online_verified" in text
    assert "rpc_available" in text
    formation_status = text.split("struct FormationStatus", 1)[1].split("};", 1)[0]
    assert "error_code" in formation_status


def test_idl_formation_values_match_mcp_wire_values() -> None:
    text = IDL_PATH.read_text(encoding="utf-8")
    enum = text.split("enum FormationType", 1)[1].split("};", 1)[0]
    values = set(re.findall(r"\b\w+\b", enum))
    assert {"line", "triangle", "column"} <= values
    assert {"LINE", "TRIANGLE", "COLUMN"}.isdisjoint(values)


def test_failed_task_response_is_normalized_to_full_task_result() -> None:
    assert hasattr(contracts, "normalize_task_response")
    raw = json.dumps(
        {
            "success": False,
            "message": "unit not bound",
            "data": None,
            "error_code": "UNIT_NOT_FOUND",
        }
    )

    normalized = json.loads(
        contracts.normalize_task_response(raw, task_type="navigate_to")
    )

    assert normalized["success"] is False
    assert normalized["data"]["task_type"] == "navigate_to"
    assert normalized["data"]["state"] == "REJECTED"
    assert normalized["data"]["error_code"] == "UNIT_NOT_FOUND"
    assert contracts.task_payload_has_contract_shape(normalized["data"])


def test_follow_safety_limits_match_task_contract() -> None:
    assert safety_validator.validate_follow_distance(0.49)[0] is False
    assert safety_validator.validate_follow_distance(0.5)[0] is True
    assert safety_validator.validate_follow_distance(20.0)[0] is True
    assert safety_validator.validate_follow_distance(20.01)[0] is False
    assert safety_validator.validate_follow_target(1000.0, -1000.0)[0] is True
    passed, error_code, _ = safety_validator.validate_follow_target(1000.01, 0.0)
    assert passed is False
    assert error_code == "TARGET_OUT_OF_BOUNDS"


def test_failed_formation_response_has_full_contract_shape() -> None:
    raw = json.dumps(
        {
            "success": False,
            "message": "invalid follower distance",
            "data": None,
            "error_code": "SAFETY_REJECTED",
        }
    )
    normalized = json.loads(contracts.normalize_formation_response(raw))
    assert normalized["success"] is False
    assert normalized["data"]["state"] == "FAILED"
    assert normalized["data"]["error_code"] == "SAFETY_REJECTED"
    assert contracts.formation_payload_has_contract_shape(normalized["data"])


@pytest.mark.asyncio
async def test_capability_service_does_not_mask_console_unavailability() -> None:
    client = AsyncMock()
    client.get_capabilities.return_value = json.dumps(
        {
            "success": False,
            "message": "real unit rpc is disabled",
            "data": None,
            "error_code": "RPC_DISABLED",
        }
    )
    result = json.loads(await CapabilityService(client).get_capabilities())
    assert result["success"] is False
    assert result["error_code"] == "RPC_DISABLED"


@pytest.mark.asyncio
async def test_capability_service_uses_conservative_fallback_only_for_missing_route() -> None:
    client = AsyncMock()
    client.get_capabilities.return_value = json.dumps(
        {
            "success": False,
            "message": "not found",
            "data": None,
            "error_code": "TASK_NOT_FOUND",
        }
    )
    result = json.loads(await CapabilityService(client).get_capabilities())
    assert result["success"] is True
    capabilities = result["data"]["capabilities"]
    assert capabilities["target_point_navigation"]["supported"] is False
    assert capabilities["path_tasks"]["supported"] is False
    assert capabilities["static_geometric_formation"]["supported"] is False
    assert capabilities["continuous_follow_formation"]["supported"] is False
    assert capabilities["real_unit_rpc"]["supported"] is False
