from __future__ import annotations

import json
from pathlib import Path
from unittest.mock import AsyncMock

import pytest

from console_client import ConsoleTaskClient
from main import create_app, create_runtime
from task_api.contracts import PRODUCTION_TOOL_NAMES, task_payload_has_contract_shape


PROFILES = Path(__file__).parents[1] / "profiles"
EXPECTED_NAVIGATE_SCHEMA = {
    "$defs": {
        "Point2D": {
            "properties": {"x": {"type": "number"}, "y": {"type": "number"}},
            "required": ["x", "y"],
            "type": "object",
        }
    },
    "additionalProperties": False,
    "properties": {
        "unit_id": {"type": "string"},
        "target": {"$ref": "#/$defs/Point2D"},
        "tolerance_m": {"default": 0.15, "type": "number"},
        "timeout_ms": {"default": 30000, "type": "integer"},
    },
    "required": ["unit_id", "target"],
    "type": "object",
}
EXPECTED_FOLLOW_PATH_SCHEMA = {
    "additionalProperties": False,
    "properties": {
        "unit_id": {"type": "string"},
        "points": {
            "items": {
                "additionalProperties": {"type": "number"},
                "type": "object",
            },
            "type": "array",
        },
        "tolerance_m": {"default": 0.15, "type": "number"},
        "timeout_ms": {"default": 30000, "type": "integer"},
    },
    "required": ["unit_id", "points"],
    "type": "object",
}
EXPECTED_STOP_UNITS_SCHEMA = {
    "additionalProperties": False,
    "properties": {
        "unit_ids": {
            "items": {"type": "string"},
            "type": "array",
        }
    },
    "required": ["unit_ids"],
    "type": "object",
}


def complete_running_task_json(task_type: str = "navigate_to") -> str:
    return json.dumps(
        {
            "success": True,
            "message": "task accepted",
            "data": {
                "success": True,
                "task_id": f"{task_type}-1",
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


@pytest.mark.asyncio
async def test_runtime_navigate_to_preserves_exact_fastmcp_schema() -> None:
    tool = await create_app().get_tool("navigateTo")

    assert tool.parameters == EXPECTED_NAVIGATE_SCHEMA


@pytest.mark.asyncio
async def test_runtime_path_and_stop_preserve_exact_legacy_contracts() -> None:
    app = create_app()
    follow = await app.get_tool("followPath")
    stop = await app.get_tool("stopUnits")

    assert follow.description == (
        "Execute an ordered x/y task path on one ground unit."
    )
    assert follow.parameters == EXPECTED_FOLLOW_PATH_SCHEMA
    assert stop.description == (
        "Request Unit_MA_Stop without cancelling tasks or disbanding formations."
    )
    assert stop.parameters == EXPECTED_STOP_UNITS_SCHEMA


@pytest.mark.asyncio
async def test_runtime_and_production_tool_names_are_exact() -> None:
    assert {tool.name for tool in create_runtime().tools.list()} == {
        "navigateTo",
        "followPath",
        "stopUnits",
    }
    assert {tool.name for tool in await create_app().list_tools()} == (
        PRODUCTION_TOOL_NAMES
    )


@pytest.mark.asyncio
async def test_production_navigate_to_routes_through_kisorb_provider(
    monkeypatch,
) -> None:
    call = AsyncMock(return_value=complete_running_task_json())
    monkeypatch.setattr(ConsoleTaskClient, "navigate_to", call)

    result = await create_app().call_tool(
        "navigateTo",
        {
            "unit_id": "robot_1",
            "target": {"x": 3.0, "y": 5.0},
            "tolerance_m": 0.2,
            "timeout_ms": 5000,
        },
    )

    payload = json.loads(result.content[0].text)
    assert payload["success"] is True
    call.assert_awaited_once_with(
        unit_id="GV1",
        x=3.0,
        y=5.0,
        tolerance_m=0.2,
        timeout_ms=5000,
    )


@pytest.mark.asyncio
async def test_production_follow_path_routes_through_kisorb_provider(
    monkeypatch,
) -> None:
    call = AsyncMock(return_value=complete_running_task_json("follow_path"))
    monkeypatch.setattr(ConsoleTaskClient, "follow_path", call)
    points = [{"x": 0.0, "y": 1.0}, {"x": 2.0, "y": 3.0}]

    result = await create_app().call_tool(
        "followPath",
        {
            "unit_id": "robot_1",
            "points": points,
            "tolerance_m": 0.2,
            "timeout_ms": 5000,
        },
    )

    payload = json.loads(result.content[0].text)
    assert payload["success"] is True
    call.assert_awaited_once_with(
        unit_id="GV1",
        points_json=json.dumps(points),
        tolerance_m=0.2,
        timeout_ms=5000,
    )


@pytest.mark.asyncio
async def test_production_stop_units_routes_through_kisorb_provider(
    monkeypatch,
) -> None:
    call = AsyncMock(return_value=complete_running_task_json("stop_units"))
    monkeypatch.setattr(ConsoleTaskClient, "stop_units", call)

    result = await create_app().call_tool(
        "stopUnits",
        {"unit_ids": ["robot_2", "GV1", "robot_1"]},
    )

    payload = json.loads(result.content[0].text)
    assert payload["success"] is True
    call.assert_awaited_once_with(unit_ids_csv="GV2,GV1")


@pytest.mark.asyncio
async def test_mock_profile_keeps_fourteen_tools_and_routes_mock_unit() -> None:
    app = create_app(PROFILES / "mock-navigation.json")

    assert {tool.name for tool in await app.list_tools()} == PRODUCTION_TOOL_NAMES
    result = await app.call_tool(
        "navigateTo",
        {"unit_id": "MOCK1", "target": {"x": 1.0, "y": 2.0}},
    )

    assert json.loads(result.content[0].text)["data"]["state"] == "COMPLETED"


@pytest.mark.asyncio
async def test_mock_profile_routes_follow_path_and_stop_units() -> None:
    app = create_app(PROFILES / "mock-navigation.json")

    follow = await app.call_tool(
        "followPath",
        {
            "unit_id": "MOCK1",
            "points": [{"x": 1.0, "y": 2.0}, {"x": 3.0, "y": 4.0}],
        },
    )
    stop = await app.call_tool(
        "stopUnits",
        {"unit_ids": ["mock_robot", "MOCK1"]},
    )

    follow_payload = json.loads(follow.content[0].text)
    stop_payload = json.loads(stop.content[0].text)
    assert follow_payload["data"]["task_type"] == "follow_path"
    assert follow_payload["data"]["state"] == "COMPLETED"
    assert stop_payload["data"]["task_type"] == "stop_units"
    assert stop_payload["data"]["state"] == "COMPLETED"


@pytest.mark.asyncio
async def test_mock_profile_rejects_mixed_platform_stop_as_unsupported() -> None:
    app = create_app(PROFILES / "mock-navigation.json")

    result = await app.call_tool(
        "stopUnits",
        {"unit_ids": ["GV1", "MOCK1"]},
    )

    payload = json.loads(result.content[0].text)
    assert payload["success"] is False
    assert payload["error_code"] == "UNSUPPORTED_CAPABILITY"
    assert task_payload_has_contract_shape(payload["data"])
    assert payload["data"]["task_type"] == "stop_units"
    assert payload["data"]["state"] == "REJECTED"
