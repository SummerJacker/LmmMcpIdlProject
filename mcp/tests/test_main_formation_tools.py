from __future__ import annotations

from unittest.mock import AsyncMock

import pytest

from main import create_app
from robot_adapter import RobotAdapter


TASK_RESULT = (
    '{"success":true,"message":"ok","data":'
    '{"task_id":"task-1","task_type":"move_follow_formation","state":"RUNNING",'
    '"progress_pct":0,"unit_results":[],"elapsed_ms":0,"started_at_ms":1,'
    '"cancellation_effect":"NOT_APPLICABLE"}}'
)


@pytest.mark.asyncio
async def test_production_follow_tools_delegate_to_task_adapter(monkeypatch) -> None:
    monkeypatch.setenv("MCP_EXPOSE_LOW_LEVEL_TOOLS", "0")
    create = AsyncMock(return_value='{"success":true,"message":"ok","data":{"state":"READY"}}')
    move = AsyncMock(return_value=TASK_RESULT)
    status = AsyncMock(return_value='{"success":true,"message":"ok","data":{"state":"READY"}}')
    monkeypatch.setattr(RobotAdapter, "create_follow_formation", create)
    monkeypatch.setattr(RobotAdapter, "move_follow_formation", move)
    monkeypatch.setattr(RobotAdapter, "get_formation_status", status)

    app = create_app()
    await app.call_tool(
        "createFollowFormation",
        {
            "request": {
                "leader_id": "GV1",
                "followers": [{"unit_id": "GV2", "distance_m": 0.3}],
            }
        },
    )
    await app.call_tool("moveFollowFormation", {"target": {"x": 5.0, "y": 6.0}})
    await app.call_tool("getFormationStatus", {})

    create.assert_awaited_once_with(
        leader_id="GV1",
        followers_json='[{"unit_id": "GV2", "distance_m": 0.3}]',
    )
    move.assert_awaited_once_with(x=5.0, y=6.0)
    status.assert_awaited_once_with()


@pytest.mark.asyncio
async def test_production_static_formation_uses_structured_request(monkeypatch) -> None:
    monkeypatch.setenv("MCP_EXPOSE_LOW_LEVEL_TOOLS", "0")
    execute = AsyncMock(return_value=TASK_RESULT)
    monkeypatch.setattr(RobotAdapter, "create_static_formation", execute)

    app = create_app()
    await app.call_tool(
        "createStaticFormation",
        {
            "request": {
                "formation_type": "line",
                "unit_ids": ["GV1", "GV2"],
                "spacing_m": 1.0,
                "anchor": {"x": 0.0, "y": 0.0},
                "heading_rad": 0.0,
                "tolerance_m": 0.15,
                "timeout_ms": 30000,
            }
        },
    )

    execute.assert_awaited_once_with(
        formation_type="line",
        unit_ids_csv="GV1,GV2",
        spacing_m=1.0,
        anchor_x=0.0,
        anchor_y=0.0,
        heading_rad=0.0,
        tolerance_m=0.15,
        timeout_ms=30000,
    )


@pytest.mark.asyncio
async def test_legacy_formation_tools_require_debug_opt_in(monkeypatch) -> None:
    monkeypatch.setenv("MCP_EXPOSE_LOW_LEVEL_TOOLS", "1")
    tools = {tool.name for tool in await create_app().list_tools()}
    assert "execute_geometric_formation" in tools
    assert "send_follow_formation" in tools
    assert "get_formation_status" in tools
