"""
RobotAdapter 单元测试：Mock HTTP 到主控台的调用。
"""

from __future__ import annotations

import json
from typing import Any
from unittest.mock import AsyncMock, patch

import pytest

from robot_adapter import RobotAdapter


def _parse_response(resp: str) -> dict[str, Any]:
    """@param resp: JSON 字符串 @returns: dict"""
    obj = json.loads(resp)
    assert set(obj.keys()) == {"success", "message", "data"}
    assert isinstance(obj["success"], bool)
    assert isinstance(obj["message"], str)
    return obj


@pytest.mark.asyncio
async def test_send_move_success() -> None:
    adapter = RobotAdapter()
    with patch(
        "robot_adapter.http_request",
        return_value=(200, {"success": True, "message": "ok", "data": {}}, ""),
    ):
        resp = await adapter.send_move(
            robot_id="robot_1",
            linear_velocity=0.5,
            angular_velocity=0.1,
            duration_ms=500,
        )
    obj = _parse_response(resp)
    assert obj["success"] is True


@pytest.mark.asyncio
async def test_send_move_accepts_unit_id_alias() -> None:
    """@brief GV1 等与 robots.json 中 unit_id 一致时可直接作为 robot_id 传入"""

    adapter = RobotAdapter()
    with patch(
        "robot_adapter.http_request",
        return_value=(200, {"success": True, "message": "ok", "data": {}}, ""),
    ):
        resp = await adapter.send_move(
            robot_id="GV1",
            linear_velocity=0.1,
            angular_velocity=0.0,
            duration_ms=200,
        )
    obj = _parse_response(resp)
    assert obj["success"] is True


@pytest.mark.asyncio
async def test_send_move_robot_not_found() -> None:
    adapter = RobotAdapter()
    resp = await adapter.send_move(
        robot_id="robot_404",
        linear_velocity=0.1,
        angular_velocity=0.0,
    )
    obj = _parse_response(resp)
    assert obj["success"] is False
    assert "unit_not_bound" in obj["message"]


@pytest.mark.asyncio
async def test_send_move_velocity_out_of_range() -> None:
    adapter = RobotAdapter()
    resp = await adapter.send_move(
        robot_id="robot_1",
        linear_velocity=999.0,
        angular_velocity=0.0,
    )
    obj = _parse_response(resp)
    assert obj["success"] is False
    assert "speed_out_of_bounds" in obj["message"]


@pytest.mark.asyncio
async def test_send_move_qt_busy_503() -> None:
    adapter = RobotAdapter()
    with patch(
        "robot_adapter.http_request",
        return_value=(503, {"success": False, "message": "QT server busy", "data": None}, ""),
    ):
        resp = await adapter.send_move(robot_id="robot_1", linear_velocity=0.1, angular_velocity=0.0)
    obj = _parse_response(resp)
    assert obj["success"] is False
    assert "busy" in obj["message"].lower() or "QT" in obj["message"]


@pytest.mark.asyncio
async def test_send_move_http_timeout() -> None:
    adapter = RobotAdapter()
    with patch("robot_adapter.http_request", return_value=(-1, None, "HTTP request timed out")):
        resp = await adapter.send_move(robot_id="robot_1", linear_velocity=0.1, angular_velocity=0.0)
    obj = _parse_response(resp)
    assert obj["success"] is False
    assert "timed out" in obj["message"] or "HTTP" in obj["message"]


@pytest.mark.asyncio
async def test_list_robots_success() -> None:
    adapter = RobotAdapter()
    with patch(
        "robot_adapter.http_request",
        return_value=(
            200,
            {"success": True, "message": "ok", "data": {"units": [{"unit_id": "GV1"}]}},
            "",
        ),
    ):
        resp = await adapter.list_robots()
    obj = _parse_response(resp)
    assert obj["success"] is True


@pytest.mark.asyncio
async def test_list_robots_run_mode_all_sim_when_mock_and_rpc_off() -> None:
    """@brief mock=true 且 rpc_enabled=false 时，GV1 的 planned real 仍应为 run_mode sim"""

    adapter = RobotAdapter()
    with patch(
        "robot_adapter.http_request",
        return_value=(
            200,
            {
                "success": True,
                "message": "ok",
                "data": {
                    "rpc_enabled": False,
                    "units": [
                        {"mock": True, "unit_id": "GV1"},
                        {"mock": True, "unit_id": "GV2"},
                    ],
                },
            },
            "",
        ),
    ):
        resp = await adapter.list_robots()
    obj = _parse_response(resp)
    units = obj["data"]["units"]
    gv1 = next(u for u in units if u["unit_id"] == "GV1")
    assert gv1["run_mode"] == "sim"
    assert gv1.get("planned_mode") == "real"
    assert "mode_mismatch" in gv1
    assert "mode" not in gv1
    assert obj["data"]["fleet_summary"]["sim_count"] == 2


@pytest.mark.asyncio
async def test_stop_robot_not_found() -> None:
    adapter = RobotAdapter()
    resp = await adapter.stop_robot(robot_id="robot_404")
    obj = _parse_response(resp)
    assert obj["success"] is False


@pytest.mark.asyncio
async def test_compute_remaining_distance_success() -> None:
    """@brief 通过两车状态计算当前距离与剩余距离"""

    adapter = RobotAdapter()
    with patch.object(
        RobotAdapter,
        "get_robot_status",
        new=AsyncMock(
            side_effect=[
                json.dumps(
                    {
                        "success": True,
                        "message": "ok",
                        "data": {"pose": {"x": 0.0, "y": 0.0}, "unit_id": "GV1", "online": True, "mock": True},
                    }
                ),
                json.dumps(
                    {
                        "success": True,
                        "message": "ok",
                        "data": {"pose": {"x": 0.0, "y": 2.0}, "unit_id": "GV2", "online": True, "mock": True},
                    }
                ),
            ]
        ),
    ):
        resp = await adapter.compute_remaining_distance(robot_a="GV1", robot_b="GV2", target_distance_m=1.0)
    obj = _parse_response(resp)
    assert obj["success"] is True
    assert abs(obj["data"]["current_distance_m"] - 2.0) < 1e-9
    assert abs(obj["data"]["remaining_distance_m"] - 1.0) < 1e-9


@pytest.mark.asyncio
async def test_get_fleet_status_success() -> None:
    """@brief 批量状态查询返回 summary 统计"""

    adapter = RobotAdapter()
    with patch.object(
        RobotAdapter,
        "get_robot_status",
        new=AsyncMock(
            side_effect=[
                json.dumps({"success": True, "message": "ok", "data": {"unit_id": "GV1"}}),
                json.dumps({"success": True, "message": "ok", "data": {"unit_id": "GV2"}}),
            ]
        ),
    ):
        resp = await adapter.get_fleet_status(robot_ids_csv="GV1,GV2")
    obj = _parse_response(resp)
    assert obj["success"] is True
    assert obj["data"]["summary"]["total"] == 2
    assert obj["data"]["summary"]["ok"] == 2


@pytest.mark.asyncio
async def test_compute_relative_pose_success() -> None:
    """@brief 相对位姿应返回距离与航向误差字段"""

    adapter = RobotAdapter()
    with patch.object(
        RobotAdapter,
        "get_robot_status",
        new=AsyncMock(
            side_effect=[
                json.dumps({"success": True, "message": "ok", "data": {"pose": {"x": 0.0, "y": 0.0, "yaw": 0.0}}}),
                json.dumps({"success": True, "message": "ok", "data": {"pose": {"x": 1.0, "y": 1.0, "yaw": 0.0}}}),
            ]
        ),
    ):
        resp = await adapter.compute_relative_pose(robot_from="GV1", robot_to="GV2")
    obj = _parse_response(resp)
    assert obj["success"] is True
    assert abs(obj["data"]["distance_m"] - (2 ** 0.5)) < 1e-9
    assert "yaw_error_rad" in obj["data"]


@pytest.mark.asyncio
async def test_compute_navigation_hint_success() -> None:
    """@brief 导航提示应返回建议 rotate/move 参数"""

    adapter = RobotAdapter()
    with patch.object(
        RobotAdapter,
        "get_robot_status",
        new=AsyncMock(
            return_value=json.dumps(
                {"success": True, "message": "ok", "data": {"pose": {"x": 0.0, "y": 0.0, "yaw": 0.0}}}
            )
        ),
    ):
        resp = await adapter.compute_navigation_hint(robot_id="GV1", target_x=1.0, target_y=0.0)
    obj = _parse_response(resp)
    assert obj["success"] is True
    assert obj["data"]["distance_m"] >= 0.0
    assert "suggested" in obj["data"]
    assert "rotate" in obj["data"]["suggested"]
    assert "move" in obj["data"]["suggested"]


@pytest.mark.asyncio
async def test_plan_line_targets_success() -> None:
    """@brief 直线位点规划应输出每车目标点"""

    adapter = RobotAdapter()
    fleet = {
        "success": True,
        "message": "ok",
        "data": {
            "items": [
                {"robot_id_input": "GV1", "success": True, "message": "ok", "data": {"unit_id": "GV1", "pose": {"x": 0.0, "y": 0.0, "yaw": 0.0}}},
                {"robot_id_input": "GV2", "success": True, "message": "ok", "data": {"unit_id": "GV2", "pose": {"x": 0.5, "y": 0.0, "yaw": 0.0}}},
                {"robot_id_input": "GV3", "success": True, "message": "ok", "data": {"unit_id": "GV3", "pose": {"x": -0.5, "y": 0.0, "yaw": 0.0}}},
            ]
        },
    }
    with patch.object(RobotAdapter, "get_fleet_status", new=AsyncMock(return_value=json.dumps(fleet))):
        resp = await adapter.plan_line_targets(robot_ids_csv="GV1,GV2,GV3", spacing_m=1.0)
    obj = _parse_response(resp)
    assert obj["success"] is True
    assert len(obj["data"]["targets"]) == 3


@pytest.mark.asyncio
async def test_set_leader_posts_unit_id() -> None:
    calls = []

    def fake_http_request(**kwargs: Any) -> tuple[int, dict[str, Any], str]:
        calls.append(kwargs)
        return 200, {"success": True, "message": "accepted", "data": {"unit_id": "GV1"}}, ""

    adapter = RobotAdapter()
    with patch("robot_adapter.http_request", side_effect=fake_http_request):
        resp = await adapter.set_leader(robot_id="robot_1")

    obj = _parse_response(resp)
    assert obj["success"] is True
    assert calls[0]["method"] == "POST"
    assert calls[0]["url"].endswith("/api/formation/set_leader")
    assert calls[0]["json_body"] == {"unit_id": "GV1"}


@pytest.mark.asyncio
async def test_set_group_mode_normalizes_alias() -> None:
    calls = []

    def fake_http_request(**kwargs: Any) -> tuple[int, dict[str, Any], str]:
        calls.append(kwargs)
        return 200, {"success": True, "message": "accepted", "data": {"mode": "follow"}}, ""

    adapter = RobotAdapter()
    with patch("robot_adapter.http_request", side_effect=fake_http_request):
        resp = await adapter.set_group_mode(mode="跟随")

    obj = _parse_response(resp)
    assert obj["success"] is True
    assert calls[0]["url"].endswith("/api/formation/set_group_mode")
    assert calls[0]["json_body"] == {"mode": "follow"}


@pytest.mark.asyncio
async def test_set_group_minor_mode_normalizes_track_alias() -> None:
    calls = []

    def fake_http_request(**kwargs: Any) -> tuple[int, dict[str, Any], str]:
        calls.append(kwargs)
        return 200, {"success": True, "message": "accepted", "data": {"minor_mode": "track"}}, ""

    adapter = RobotAdapter()
    with patch("robot_adapter.http_request", side_effect=fake_http_request):
        resp = await adapter.set_group_minor_mode(mode="route")

    obj = _parse_response(resp)
    assert obj["success"] is True
    assert calls[0]["url"].endswith("/api/formation/set_group_minor_mode")
    assert calls[0]["json_body"] == {"minor_mode": "track"}


@pytest.mark.asyncio
async def test_set_task_point_posts_canonical_unit() -> None:
    calls = []

    def fake_http_request(**kwargs: Any) -> tuple[int, dict[str, Any], str]:
        calls.append(kwargs)
        return 200, {"success": True, "message": "accepted", "data": {"unit_id": "GV2"}}, ""

    adapter = RobotAdapter()
    with patch("robot_adapter.http_request", side_effect=fake_http_request):
        resp = await adapter.set_task_point(robot_id="robot_2", x=1.25, y=-0.5)

    obj = _parse_response(resp)
    assert obj["success"] is True
    assert calls[0]["url"].endswith("/api/task/set_point")
    assert calls[0]["json_body"] == {"unit_id": "GV2", "x": 1.25, "y": -0.5}


@pytest.mark.asyncio
async def test_set_task_path_accepts_json_points() -> None:
    calls = []

    def fake_http_request(**kwargs: Any) -> tuple[int, dict[str, Any], str]:
        calls.append(kwargs)
        return 200, {"success": True, "message": "accepted", "data": {"unit_id": "GV3"}}, ""

    adapter = RobotAdapter()
    points_json = '[{"x": 0, "y": 0}, {"x": 1.5, "y": 2.0}]'
    with patch("robot_adapter.http_request", side_effect=fake_http_request):
        resp = await adapter.set_task_path(robot_id="GV3", points_json=points_json)

    obj = _parse_response(resp)
    assert obj["success"] is True
    assert calls[0]["url"].endswith("/api/task/set_path")
    assert calls[0]["json_body"] == {
        "unit_id": "GV3",
        "points": [{"x": 0.0, "y": 0.0}, {"x": 1.5, "y": 2.0}],
    }


@pytest.mark.asyncio
async def test_set_task_path_rejects_more_than_ten_points() -> None:
    adapter = RobotAdapter()
    points_json = json.dumps([{"x": i, "y": i} for i in range(11)])

    resp = await adapter.set_task_path(robot_id="GV1", points_json=points_json)

    obj = _parse_response(resp)
    assert obj["success"] is False
    assert "1..10" in obj["message"]


@pytest.mark.asyncio
async def test_add_and_clear_trap_routes() -> None:
    calls = []

    def fake_http_request(**kwargs: Any) -> tuple[int, dict[str, Any], str]:
        calls.append(kwargs)
        return 200, {"success": True, "message": "accepted", "data": {}}, ""

    adapter = RobotAdapter()
    with patch("robot_adapter.http_request", side_effect=fake_http_request):
        add_resp = await adapter.add_trap_point(x=2.0, y=3.0, radius=0.4)
        clear_resp = await adapter.clear_traps()

    assert _parse_response(add_resp)["success"] is True
    assert _parse_response(clear_resp)["success"] is True
    assert calls[0]["url"].endswith("/api/trap/add")
    assert calls[0]["json_body"] == {"x": 2.0, "y": 3.0, "radius": 0.4}
    assert calls[1]["url"].endswith("/api/trap/clear")
    assert calls[1]["json_body"] == {}


@pytest.mark.asyncio
async def test_reset_unit_relations_route() -> None:
    calls = []

    def fake_http_request(**kwargs: Any) -> tuple[int, dict[str, Any], str]:
        calls.append(kwargs)
        return 200, {"success": True, "message": "accepted", "data": {}}, ""

    adapter = RobotAdapter()
    with patch("robot_adapter.http_request", side_effect=fake_http_request):
        resp = await adapter.reset_unit_relations()

    obj = _parse_response(resp)
    assert obj["success"] is True
    assert calls[0]["url"].endswith("/api/system/reset_relations")
    assert calls[0]["json_body"] == {}
