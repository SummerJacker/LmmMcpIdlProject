from __future__ import annotations

import json
from pathlib import Path
from unittest.mock import AsyncMock

import pytest

from console_client import ConsoleTaskClient
from main import create_app
from task_api.contracts import PRODUCTION_TOOL_NAMES


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


@pytest.mark.asyncio
async def test_runtime_navigate_to_preserves_exact_fastmcp_schema() -> None:
    tool = await create_app().get_tool("navigateTo")

    assert tool.parameters == EXPECTED_NAVIGATE_SCHEMA


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
async def test_mock_profile_keeps_fourteen_tools_and_routes_mock_unit() -> None:
    app = create_app(PROFILES / "mock-navigation.json")

    assert {tool.name for tool in await app.list_tools()} == PRODUCTION_TOOL_NAMES
    result = await app.call_tool(
        "navigateTo",
        {"unit_id": "MOCK1", "target": {"x": 1.0, "y": 2.0}},
    )

    assert json.loads(result.content[0].text)["data"]["state"] == "COMPLETED"
