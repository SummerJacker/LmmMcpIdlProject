from __future__ import annotations

from unittest.mock import AsyncMock

import pytest

from main import create_app
from robot_adapter import RobotAdapter


@pytest.mark.asyncio
async def test_follow_formation_tools_delegate_to_console_adapter(monkeypatch) -> None:
    send = AsyncMock(return_value='{"success":true,"message":"ok","data":{}}')
    goto = AsyncMock(return_value='{"success":true,"message":"ok","data":{}}')
    status = AsyncMock(return_value='{"success":true,"message":"ok","data":{"state":"READY"}}')
    monkeypatch.setattr(RobotAdapter, "send_follow_formation", send)
    monkeypatch.setattr(RobotAdapter, "goto_follow_formation", goto)
    monkeypatch.setattr(RobotAdapter, "get_follow_formation_status", status)

    app = create_app()
    await app.call_tool(
        "send_follow_formation",
        {
            "leader_id": "GV1",
            "followers_json": '[{"robot_id":"GV2","distance_m":0.3}]',
        },
    )
    await app.call_tool("goto_follow_formation", {"x": 5.0, "y": 6.0})
    await app.call_tool("get_formation_status", {})

    send.assert_awaited_once_with(
        leader_id="GV1",
        followers_json='[{"robot_id":"GV2","distance_m":0.3}]',
    )
    goto.assert_awaited_once_with(x=5.0, y=6.0)
    status.assert_awaited_once_with()


@pytest.mark.asyncio
async def test_geometric_formation_has_unambiguous_tool_name(monkeypatch) -> None:
    execute = AsyncMock(return_value='{"success":true,"message":"ok","data":{}}')
    monkeypatch.setattr(RobotAdapter, "execute_formation", execute)

    app = create_app()
    await app.call_tool(
        "execute_geometric_formation",
        {"formation_type": "line", "unit_ids_csv": "GV1,GV2", "spacing_m": 1.0},
    )

    execute.assert_awaited_once_with(
        formation_type="line",
        unit_ids_csv="GV1,GV2",
        spacing_m=1.0,
        anchor_json="",
        heading_rad=0.0,
        tolerance_m=0.15,
        timeout_ms=30000,
    )


@pytest.mark.asyncio
async def test_legacy_formation_mission_is_geometry_only_compatibility_wrapper(monkeypatch) -> None:
    execute = AsyncMock(return_value='{"success":true,"message":"ok","data":{}}')
    set_leader = AsyncMock(side_effect=AssertionError("legacy wrapper must not mutate follow relations"))
    monkeypatch.setattr(RobotAdapter, "execute_formation", execute)
    monkeypatch.setattr(RobotAdapter, "set_leader", set_leader)

    app = create_app()
    await app.call_tool(
        "execute_formation_mission",
        {
            "formation_type": "line",
            "unit_ids_csv": "GV1,GV2",
            "leader_id": "GV1",
            "spacing_m": 1.0,
        },
    )

    execute.assert_awaited_once_with(
        formation_type="line",
        unit_ids_csv="GV1,GV2",
        spacing_m=1.0,
        anchor_json="",
        heading_rad=0.0,
        tolerance_m=0.15,
        timeout_ms=30000,
    )
    set_leader.assert_not_awaited()
