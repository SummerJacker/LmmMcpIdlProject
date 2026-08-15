"""
RobotAdapter 单元测试：Mock HTTP 到主控台的调用。
"""

from __future__ import annotations

import json
from typing import Any
from unittest.mock import AsyncMock, patch

import pytest

from robot_adapter import RobotAdapter
from console_client.console_task_client import ConsoleTaskClient
from config import load_robot_configs
import task_api.contracts as contracts
from task_api.contracts import task_payload_has_contract_shape


def _parse_response(resp: str) -> dict[str, Any]:
    """@param resp: JSON 字符串 @returns: dict"""
    obj = json.loads(resp)
    assert {"success", "message", "data"} <= set(obj.keys())
    assert set(obj.keys()) <= {"success", "message", "data", "error_code"}
    assert isinstance(obj["success"], bool)
    assert isinstance(obj["message"], str)
    return obj


def test_gv3_deployment_intent_is_real() -> None:
    gv3 = next(config for config in load_robot_configs() if config.unit_id == "GV3")
    assert gv3.mode == "real"


@pytest.mark.asyncio
async def test_console_task_client_normalizes_failed_navigate_response() -> None:
    adapter = AsyncMock()
    adapter.navigate_to.return_value = json.dumps(
        {
            "success": False,
            "message": "unit not bound",
            "data": None,
            "error_code": "UNIT_NOT_FOUND",
        }
    )

    result = _parse_response(
        await ConsoleTaskClient(adapter).navigate_to(
            unit_id="GV404",
            x=1.0,
            y=2.0,
            tolerance_m=0.15,
            timeout_ms=1000,
        )
    )

    assert result["success"] is False
    assert task_payload_has_contract_shape(result["data"])
    assert result["data"]["task_type"] == "navigate_to"
    assert result["data"]["state"] == "REJECTED"
    assert result["data"]["error_code"] == "UNIT_NOT_FOUND"


@pytest.mark.asyncio
async def test_console_task_client_normalizes_all_task_method_failures() -> None:
    adapter = AsyncMock()
    failure = json.dumps(
        {
            "success": False,
            "message": "request rejected",
            "data": None,
            "error_code": "SAFETY_REJECTED",
        }
    )
    for method in (
        "follow_path",
        "create_static_formation",
        "move_follow_formation",
        "get_task_status",
        "cancel_task",
        "stop_units",
    ):
        getattr(adapter, method).return_value = failure
    client = ConsoleTaskClient(adapter)

    calls = (
        ("follow_path", client.follow_path(
            unit_id="GV1", points_json='[{"x":1,"y":2}]',
            tolerance_m=0.15, timeout_ms=1000)),
        ("create_static_formation", client.create_static_formation(
            formation_type="line", unit_ids_csv="GV1,GV2", spacing_m=1.0,
            anchor_x=0.0, anchor_y=0.0, heading_rad=0.0,
            tolerance_m=0.15, timeout_ms=1000)),
        ("move_follow_formation", client.move_follow_formation(x=1.0, y=2.0)),
        ("get_task_status", client.get_task_status(task_id="missing")),
        ("cancel_task", client.cancel_task(task_id="missing")),
        ("stop_units", client.stop_units(unit_ids_csv="GV1")),
    )

    for expected_task_type, pending_call in calls:
        result = _parse_response(await pending_call)
        assert result["success"] is False
        assert task_payload_has_contract_shape(result["data"])
        assert result["data"]["task_type"] == expected_task_type
        assert result["data"]["state"] == "REJECTED"


@pytest.mark.asyncio
async def test_console_task_client_normalizes_formation_failure() -> None:
    adapter = AsyncMock()
    adapter.create_follow_formation.return_value = json.dumps(
        {
            "success": False,
            "message": "invalid follower distance",
            "data": None,
            "error_code": "SAFETY_REJECTED",
        }
    )
    result = _parse_response(
        await ConsoleTaskClient(adapter).create_follow_formation(
            leader_id="GV1",
            followers_json='[{"unit_id":"GV2","distance_m":21}]',
        )
    )
    assert result["success"] is False
    assert contracts.formation_payload_has_contract_shape(result["data"])
    assert result["data"]["error_code"] == "SAFETY_REJECTED"


@pytest.mark.asyncio
async def test_move_follow_formation_rejects_out_of_bounds_target() -> None:
    adapter = RobotAdapter()
    with patch("robot_adapter.http_request") as request:
        result = _parse_response(await adapter.move_follow_formation(x=1000.01, y=0.0))
    assert result["success"] is False
    assert result["error_code"] == "TARGET_OUT_OF_BOUNDS"
    request.assert_not_called()


@pytest.mark.asyncio
async def test_create_follow_formation_rejects_distance_above_twenty_metres() -> None:
    adapter = RobotAdapter()
    adapter._resolve_to_unit_id = AsyncMock(side_effect=["GV1", "GV2"])
    with patch("robot_adapter.http_request") as request:
        result = _parse_response(
            await adapter.create_follow_formation(
                leader_id="GV1",
                followers_json='[{"unit_id":"GV2","distance_m":20.01}]',
            )
        )
    assert result["success"] is False
    assert result["error_code"] == "SAFETY_REJECTED"
    request.assert_not_called()


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
async def test_fleet_snapshot_uses_task_route_and_keeps_real_binding_when_rpc_off() -> None:
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
                    "units": [{"mock": False, "unit_id": "GV1", "online": True, "busy": False}],
                },
            },
            "",
        ),
    ) as request:
        obj = _parse_response(await adapter.get_fleet_snapshot())

    assert request.call_args.kwargs["url"].endswith("/api/task/fleet_snapshot")
    unit = obj["data"]["units"][0]
    assert unit["run_mode"] == "real"
    assert unit["rpc_available"] is False


@pytest.mark.asyncio
async def test_capabilities_uses_task_route() -> None:
    adapter = RobotAdapter()
    with patch(
        "robot_adapter.http_request",
        return_value=(200, {"success": True, "message": "ok", "data": {"capabilities": {}}}, ""),
    ) as request:
        obj = _parse_response(await adapter.get_capabilities())

    assert obj["success"] is True
    assert request.call_args.kwargs["url"].endswith("/api/task/capabilities")


@pytest.mark.asyncio
async def test_dynamic_bound_unit_resolves_from_authoritative_console_list() -> None:
    adapter = RobotAdapter()
    assert adapter._manager.canonical_robot_id("GV4") is None
    adapter.list_robots = AsyncMock(
        return_value=json.dumps(
            {
                "success": True,
                "message": "ok",
                "data": {"units": [{"unit_id": "GV4", "online": True, "mock": False}]},
            }
        )
    )
    assert await adapter._resolve_to_unit_id("GV4") == "GV4"


@pytest.mark.asyncio
async def test_http_error_preserves_console_data_without_nested_envelope() -> None:
    adapter = RobotAdapter()
    with patch(
        "robot_adapter.http_request",
        return_value=(
            409,
            {
                "success": False,
                "message": "unit is busy",
                "data": {"error_code": "TASK_CONFLICT", "unit_id": "GV1"},
            },
            "",
        ),
    ):
        obj = _parse_response(
            await adapter.navigate_to(unit_id="GV1", x=1.0, y=2.0, tolerance_m=0.15, timeout_ms=1000)
        )

    assert obj["success"] is False
    assert obj["error_code"] == "TASK_CONFLICT"
    assert obj["data"] == {"error_code": "TASK_CONFLICT", "unit_id": "GV1"}


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


@pytest.mark.asyncio
async def test_send_follow_formation_resolves_ids_and_preserves_spacing() -> None:
    calls = []

    def fake_http_request(**kwargs: Any) -> tuple[int, dict[str, Any], str]:
        calls.append(kwargs)
        return 200, {"success": True, "message": "accepted", "data": {}}, ""

    adapter = RobotAdapter()
    with patch("robot_adapter.http_request", side_effect=fake_http_request):
        response = await adapter.send_follow_formation(
            leader_id="robot_1",
            followers_json='[{"robot_id":"robot_2","distance_m":0.3}]',
        )

    assert _parse_response(response)["success"] is True
    assert calls[0]["url"].endswith("/api/formation/send_follow")
    assert calls[0]["json_body"] == {
        "leader_id": "GV1",
        "followers": [{"unit_id": "GV2", "distance_m": 0.3}],
    }


@pytest.mark.asyncio
async def test_send_follow_formation_rejects_duplicate_followers_without_http() -> None:
    adapter = RobotAdapter()
    with patch("robot_adapter.http_request") as request:
        response = await adapter.send_follow_formation(
            leader_id="GV1",
            followers_json=(
                '[{"robot_id":"GV2","distance_m":0.3},'
                '{"robot_id":"GV2","distance_m":0.4}]'
            ),
        )

    assert _parse_response(response)["success"] is False
    request.assert_not_called()


@pytest.mark.asyncio
async def test_goto_follow_formation_posts_target_without_robot_id() -> None:
    calls = []

    def fake_http_request(**kwargs: Any) -> tuple[int, dict[str, Any], str]:
        calls.append(kwargs)
        return 200, {
            "success": True,
            "message": "accepted",
            "data": {"leader_id": "GV1"},
        }, ""

    adapter = RobotAdapter()
    with patch("robot_adapter.http_request", side_effect=fake_http_request):
        response = await adapter.goto_follow_formation(x=5.0, y=6.0)

    assert _parse_response(response)["success"] is True
    assert calls[0]["url"].endswith("/api/formation/goto_target")
    assert calls[0]["json_body"] == {"x": 5.0, "y": 6.0}


@pytest.mark.asyncio
async def test_get_follow_formation_status_uses_console_endpoint() -> None:
    calls = []

    def fake_http_request(**kwargs: Any) -> tuple[int, dict[str, Any], str]:
        calls.append(kwargs)
        return 200, {"success": True, "message": "ok", "data": {"state": "READY"}}, ""

    adapter = RobotAdapter()
    with patch("robot_adapter.http_request", side_effect=fake_http_request):
        response = await adapter.get_follow_formation_status()

    assert _parse_response(response)["success"] is True
    assert calls[0]["method"] == "GET"
    assert calls[0]["url"].endswith("/api/formation/status")


@pytest.mark.asyncio
async def test_navigate_to_posts_only_supported_execution_fields() -> None:
    calls = []

    def fake_http_request(**kwargs: Any) -> tuple[int, dict[str, Any], str]:
        calls.append(kwargs)
        return 200, {
            "success": True,
            "message": "task accepted",
            "data": {
                "task_id": "goto-1",
                "task_type": "navigate_to",
                "state": "RUNNING",
                "progress_pct": 0.0,
                "unit_results": [],
                "elapsed_ms": 0,
                "started_at_ms": 1,
                "cancellation_effect": "NOT_APPLICABLE",
            },
        }, ""

    adapter = RobotAdapter()
    with patch("robot_adapter.http_request", side_effect=fake_http_request):
        response = await adapter.navigate_to(
            unit_id="GV1", x=3.0, y=-2.0, tolerance_m=0.2, timeout_ms=5000
        )

    assert _parse_response(response)["success"] is True
    assert calls[0]["url"].endswith("/api/task/navigate")
    assert calls[0]["json_body"] == {
        "unit_id": "GV1",
        "x": 3.0,
        "y": -2.0,
        "tolerance_m": 0.2,
        "timeout_ms": 5000,
    }
    assert "yaw" not in calls[0]["json_body"]
    assert "linear_speed_m_s" not in calls[0]["json_body"]
    assert "angular_speed_rad_s" not in calls[0]["json_body"]


@pytest.mark.asyncio
async def test_execute_motion_task_posts_typed_command() -> None:
    calls = []

    def fake_http_request(**kwargs: Any) -> tuple[int, dict[str, Any], str]:
        calls.append(kwargs)
        return 200, {
            "success": True,
            "message": "task completed",
            "data": {
                "task_id": "motion-1",
                "task_type": "execute_motion",
                "state": "COMPLETED",
                "progress_pct": 100.0,
                "unit_results": [],
                "elapsed_ms": 1,
                "started_at_ms": 1,
                "cancellation_effect": "NOT_APPLICABLE",
            },
        }, ""

    adapter = RobotAdapter()
    with patch("robot_adapter.http_request", side_effect=fake_http_request):
        response = await adapter.execute_motion_task(
            unit_id="GV1",
            linear_velocity=0.2,
            angular_velocity=0.0,
            duration_ms=100,
        )

    result = _parse_response(response)
    assert result["success"] is True
    assert calls[0]["url"].endswith("/api/task/motion")
    assert calls[0]["json_body"] == {
        "unit_id": "GV1",
        "linear_velocity": 0.2,
        "angular_velocity": 0.0,
        "duration_ms": 100,
    }


@pytest.mark.asyncio
async def test_benchmark_mode_adds_python_timing_without_overwriting_console_timing(
    monkeypatch,
) -> None:
    monkeypatch.setenv("SAU_BENCHMARK_TIMINGS", "1")
    task = {
        "task_id": "motion-timing",
        "task_type": "execute_motion",
        "state": "COMPLETED",
        "progress_pct": 100.0,
        "unit_results": [],
        "elapsed_ms": 1,
        "started_at_ms": 1,
        "cancellation_effect": "NOT_APPLICABLE",
        "_benchmark_timing": {"task_contract_ms": 0.1},
    }
    adapter = RobotAdapter()
    with patch(
        "robot_adapter.http_request",
        return_value=(200, {"success": True, "message": "ok", "data": task}, ""),
    ):
        result = _parse_response(
            await adapter.execute_motion_task(
                unit_id="GV1",
                linear_velocity=0.2,
                angular_velocity=0.0,
                duration_ms=1,
            )
        )

    timing = result["data"]["_benchmark_timing"]
    assert timing["task_contract_ms"] == 0.1
    assert timing["python_console_roundtrip_ms"] >= 0.0
    assert timing["python_contract_ms"] >= 0.0


@pytest.mark.asyncio
async def test_production_mode_does_not_add_benchmark_timing(monkeypatch) -> None:
    monkeypatch.delenv("SAU_BENCHMARK_TIMINGS", raising=False)
    task = {
        "task_id": "motion-production",
        "task_type": "execute_motion",
        "state": "COMPLETED",
        "progress_pct": 100.0,
        "unit_results": [],
        "elapsed_ms": 1,
        "started_at_ms": 1,
        "cancellation_effect": "NOT_APPLICABLE",
    }
    adapter = RobotAdapter()
    with patch(
        "robot_adapter.http_request",
        return_value=(200, {"success": True, "message": "ok", "data": task}, ""),
    ):
        result = _parse_response(
            await adapter.execute_motion_task(
                unit_id="GV1",
                linear_velocity=0.2,
                angular_velocity=0.0,
                duration_ms=1,
            )
        )

    assert "_benchmark_timing" not in result["data"]


@pytest.mark.asyncio
async def test_mock_and_real_task_results_keep_the_same_contract_shape() -> None:
    common = {
        "task_id": "goto-1",
        "task_type": "navigate_to",
        "state": "RUNNING",
        "progress_pct": 0.0,
        "unit_results": [],
        "elapsed_ms": 0,
        "started_at_ms": 1,
        "cancellation_effect": "NOT_APPLICABLE",
    }
    responses = [
        (200, {"success": True, "message": "ok", "data": {**common, "mock": True}}, ""),
        (200, {"success": True, "message": "ok", "data": {**common, "mock": False}}, ""),
    ]
    adapter = RobotAdapter()
    with patch("robot_adapter.http_request", side_effect=responses):
        mock_result = _parse_response(
            await adapter.navigate_to(
                unit_id="GV1", x=1.0, y=1.0, tolerance_m=0.15, timeout_ms=1000
            )
        )
        real_result = _parse_response(
            await adapter.navigate_to(
                unit_id="GV1", x=1.0, y=1.0, tolerance_m=0.15, timeout_ms=1000
            )
        )

    assert set(mock_result["data"]) == set(real_result["data"])
    assert mock_result["data"]["mock"] is True
    assert real_result["data"]["mock"] is False
