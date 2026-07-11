"""
针对重构后 Agent Client 的测试。
验证 call_llm 对 LLM 输出的 JSON 解析，以及 run_mcp_call 命令构造。
"""

import json
from unittest.mock import Mock
from deepseek_mcp_client import (
    FormationDialogState,
    FormationMode,
    allowed_formation_tool,
    allowed_recovery_tools,
    build_system_prompt,
    call_llm,
    done_message_implies_incomplete,
    enforce_send_move_user_speed,
    extract_user_absolute_point_goals,
    extract_user_speed_intent,
    format_point_goals_hint,
    follow_spacing_args_are_user_supplied,
    record_explicit_follow_spacings,
    recovery_tool_call_is_authorized,
    is_premature_done_for_point_goals,
    is_speed_out_of_bounds_message,
    route_formation_input,
    user_requested_out_of_bounds_speed,
)

class MockResponse:
    def __init__(self, content, status_code=200):
        self.status_code = status_code
        self.text = content
        self._content = content
        
    def json(self):
        return {
            "choices": [
                {
                    "message": {
                        "content": self._content
                    }
                }
            ]
        }


def _wizard_fleet_response():
    return json.dumps({
        "success": True,
        "message": "ok",
        "data": {
            "units": [
                {"unit_id": "GV1", "robot_id": "robot_1", "online": True},
                {"unit_id": "GV2", "robot_id": "robot_2", "online": True},
            ]
        },
    })

def test_build_system_prompt():
    prompt = build_system_prompt()
    assert "Available Tools:" in prompt
    assert "plan_triangle_targets" in prompt
    assert "SPEED SAFETY (TC-06)" in prompt
    assert "ABSOLUTE POINT GOALS" in prompt
    assert "PREMATURE DONE" in prompt


def test_extract_user_absolute_point_goals():
    goals = extract_user_absolute_point_goals("将小车1 移动到（1，1），小车2移动到（2，2）")
    assert len(goals) == 2
    assert goals[0] == {"robot_ref": "GV1", "target_x": 1.0, "target_y": 1.0}
    assert goals[1] == {"robot_ref": "GV2", "target_x": 2.0, "target_y": 2.0}


def test_is_premature_done_for_point_goals():
    goals = extract_user_absolute_point_goals("将小车1 移动到（1，1）")
    assert goals
    assert is_premature_done_for_point_goals(
        user_point_goals=goals,
        send_move_call_count=0,
        done_message="我将使用 compute_navigation_hint",
    )
    assert not is_premature_done_for_point_goals(
        user_point_goals=goals,
        send_move_call_count=2,
        done_message="Task completed",
    )


def test_done_message_implies_incomplete():
    assert done_message_implies_incomplete("我将直接使用 compute_navigation_hint")
    assert not done_message_implies_incomplete("Task completed successfully")


def test_format_point_goals_hint():
    goals = extract_user_absolute_point_goals("GV1到(1,1)")
    assert "GV1→(1.0,1.0)" in format_point_goals_hint(goals)


def test_extract_user_speed_intent_linear():
    intent = extract_user_speed_intent("让小车以1000m/s速度奔跑")
    assert intent["linear_m_s"] == 1000.0
    assert user_requested_out_of_bounds_speed(intent) is True


def test_enforce_send_move_user_speed_restores_clamped_value():
    args = {"robot_id": "GV1", "linear_velocity": 5.0, "angular_velocity": 0.0, "duration_ms": 1000}
    intent = extract_user_speed_intent("100 m/s forward")
    changed = enforce_send_move_user_speed(args, intent)
    assert changed is True
    assert args["linear_velocity"] == 100.0


def test_is_speed_out_of_bounds_message():
    assert is_speed_out_of_bounds_message("speed_out_of_bounds: linear_velocity abs=100.0 exceeds max_safe=5.0 m/s")
    assert not is_speed_out_of_bounds_message("accepted")


def test_ambiguous_formation_requires_mode_selection():
    state = FormationDialogState()

    result = route_formation_input("进行编队", state)

    assert result.prompt_only is True
    assert result.mode is None
    assert state.awaiting_mode is True
    assert "1. Console 跟随编队" in result.message
    assert "2. 几何编队" in result.message


def test_numeric_selection_enters_follow_mode():
    state = FormationDialogState(awaiting_mode=True)

    result = route_formation_input("1", state)

    assert result.prompt_only is True
    assert result.mode == FormationMode.CONSOLE_FOLLOW
    assert state.awaiting_mode is False
    assert state.mode == FormationMode.CONSOLE_FOLLOW
    assert "正在读取" in result.message


def test_explicit_triangle_enters_geometric_mode_without_menu():
    state = FormationDialogState()

    result = route_formation_input("让三辆车排成边长2米的三角形", state)

    assert result.mode == FormationMode.GEOMETRIC
    assert result.prompt_only is False


def test_cross_mode_tool_guard():
    follow = FormationDialogState(mode=FormationMode.CONSOLE_FOLLOW)
    geometric = FormationDialogState(mode=FormationMode.GEOMETRIC)

    assert allowed_formation_tool("send_follow_formation", follow)
    assert allowed_formation_tool("goto_follow_formation", follow)
    assert not allowed_formation_tool("execute_geometric_formation", follow)
    assert not allowed_formation_tool("goto_pose_batch", follow)
    assert allowed_formation_tool("execute_geometric_formation", geometric)
    assert not allowed_formation_tool("execute_formation_mission", geometric)
    assert not allowed_formation_tool("send_follow_formation", geometric)


def test_follow_spacing_must_come_from_user_input():
    state = FormationDialogState(mode=FormationMode.CONSOLE_FOLLOW)
    args = {
        "leader_id": "GV1",
        "followers_json": '[{"robot_id":"GV2","distance_m":1.0}]',
    }

    assert not follow_spacing_args_are_user_supplied(args, state)

    record_explicit_follow_spacings("GV2 的间距为 0.3 米", state)
    matching = {
        "leader_id": "GV1",
        "followers_json": '[{"robot_id":"GV2","distance_m":0.3}]',
    }
    assert follow_spacing_args_are_user_supplied(matching, state)
    assert not follow_spacing_args_are_user_supplied(args, state)


def test_follow_spacing_is_bound_to_each_follower():
    state = FormationDialogState(mode=FormationMode.CONSOLE_FOLLOW)
    record_explicit_follow_spacings("GV2 间距 0.3 米，GV3 间距 0.5 米", state)

    matching = {
        "leader_id": "GV1",
        "followers_json": (
            '[{"robot_id":"GV2","distance_m":0.3},'
            '{"robot_id":"GV3","distance_m":0.5}]'
        ),
    }
    swapped = {
        "leader_id": "GV1",
        "followers_json": (
            '[{"robot_id":"GV2","distance_m":0.5},'
            '{"robot_id":"GV3","distance_m":0.3}]'
        ),
    }

    assert follow_spacing_args_are_user_supplied(matching, state)
    assert not follow_spacing_args_are_user_supplied(swapped, state)


def test_unrelated_meter_value_is_not_accepted_as_multi_follower_spacing():
    state = FormationDialogState(mode=FormationMode.CONSOLE_FOLLOW)
    record_explicit_follow_spacings("目标点距离当前位置 2 米", state)
    args = {
        "leader_id": "GV1",
        "followers_json": (
            '[{"robot_id":"GV2","distance_m":2.0},'
            '{"robot_id":"GV3","distance_m":2.0}]'
        ),
    }

    assert not follow_spacing_args_are_user_supplied(args, state)


def test_recovery_authorization_is_action_specific():
    assert allowed_recovery_tools("停止编队") == {"stop_active_formation"}
    assert allowed_recovery_tools("重试发送队形") == {"send_follow_formation"}
    assert allowed_recovery_tools("重置编队关系") == {"reset_unit_relations"}
    assert "send_follow_formation" not in allowed_recovery_tools("停止编队")
    assert recovery_tool_call_is_authorized("stop_robot", {"robot_id": "GV1"}, "停止GV1")
    assert not recovery_tool_call_is_authorized("stop_robot", {"robot_id": "GV2"}, "停止GV1")
    assert recovery_tool_call_is_authorized("emergency_stop_all", {}, "紧急停止所有车辆")
    assert recovery_tool_call_is_authorized(
        "cancel_task", {"task_id": "task_123"}, "取消任务 task_123"
    )
    assert not recovery_tool_call_is_authorized(
        "cancel_task", {"task_id": "task_456"}, "取消任务 task_123"
    )
    assert recovery_tool_call_is_authorized(
        "set_group_mode", {"mode": "none"}, "设置编队模式为无模式"
    )
    assert not recovery_tool_call_is_authorized(
        "set_group_mode", {"mode": "follow"}, "设置编队模式为无模式"
    )
    state = FormationDialogState(mode=FormationMode.CONSOLE_FOLLOW, follow_failure_seen=True)
    routed = route_formation_input("停止编队", state)
    assert routed.prompt_only is False
    assert routed.mode == FormationMode.CONSOLE_FOLLOW


def test_ambiguous_formation_menu_calls_no_llm(monkeypatch, capsys):
    import deepseek_mcp_client as client
    import sys

    monkeypatch.setattr(sys, "argv", ["deepseek_mcp_client.py"])
    inputs = iter(["进行编队", "exit"])
    monkeypatch.setattr("builtins.input", lambda prompt="": next(inputs))
    llm = Mock(side_effect=AssertionError("LLM must not run before mode selection"))
    monkeypatch.setattr(client, "call_llm", llm)

    client.main()

    llm.assert_not_called()
    out = capsys.readouterr().out
    assert "1. Console 跟随编队" in out
    assert "2. 几何编队" in out


def test_console_follow_wizard_replays_reported_transcript_without_llm(monkeypatch, capsys):
    import deepseek_mcp_client as client
    import sys

    monkeypatch.setattr(sys, "argv", ["deepseek_mcp_client.py"])
    inputs = iter([
        "进行编队",
        "1",
        "GV1",
        "每架都设置成0.5米",
        "发送队形",
        "exit",
    ])
    monkeypatch.setattr("builtins.input", lambda prompt="": next(inputs))
    llm = Mock(side_effect=AssertionError("Console follow wizard must not call LLM"))
    monkeypatch.setattr(client, "call_llm", llm)
    calls = []

    def fake_mcp(server, tool, args):
        calls.append((tool, args))
        if tool == "list_robots":
            return json.dumps({
                "success": True,
                "message": "ok",
                "data": {
                    "units": [
                        {"unit_id": "GV1", "robot_id": "robot_1", "online": True},
                        {"unit_id": "GV2", "robot_id": "robot_2", "online": True},
                    ]
                },
            })
        return json.dumps({"success": True, "message": "accepted", "data": {}})

    monkeypatch.setattr(client, "run_mcp_call", fake_mcp)

    client.main()

    llm.assert_not_called()
    assert calls == [
        ("list_robots", {}),
        ("set_leader", {"robot_id": "GV1"}),
        (
            "send_follow_formation",
            {
                "leader_id": "GV1",
                "followers_json": '[{"robot_id":"GV2","distance_m":0.5}]',
            },
        ),
    ]
    out = capsys.readouterr().out
    assert "请选择 Leader" in out
    assert "请输入间距" in out
    assert "输入“发送队形”确认" in out


def test_wizard_parses_real_fastmcp_content_text_envelope():
    import deepseek_mcp_client as client

    raw = json.dumps({
        "content": [
            {
                "type": "text",
                "text": json.dumps({
                    "success": True,
                    "message": "ok",
                    "data": {"units": [{"unit_id": "GV1"}, {"unit_id": "GV2"}]},
                }),
            }
        ],
        "is_error": False,
    })

    payload = client._parse_wizard_tool_payload(raw)

    assert payload["success"] is True
    assert [unit["unit_id"] for unit in payload["data"]["units"]] == ["GV1", "GV2"]


def test_cancelled_follow_wizard_returns_to_normal_agent_mode(monkeypatch):
    import deepseek_mcp_client as client
    import sys

    monkeypatch.setattr(sys, "argv", ["deepseek_mcp_client.py"])
    inputs = iter(["进行编队", "1", "GV1", "0.5", "取消编队", "查看状态", "exit"])
    monkeypatch.setattr("builtins.input", lambda prompt="": next(inputs))
    llm = Mock(return_value={"done": True, "message": "状态查询结束。"})
    monkeypatch.setattr(client, "call_llm", llm)
    calls = []

    def fake_mcp(server, tool, args):
        calls.append(tool)
        if tool == "list_robots":
            return _wizard_fleet_response()
        return json.dumps({"success": True, "message": "ok", "data": {}})

    monkeypatch.setattr(client, "run_mcp_call", fake_mcp)

    client.main()

    assert calls.count("list_robots") == 1
    assert llm.call_count == 1


def test_follow_send_without_user_spacing_is_rejected(monkeypatch, capsys):
    import deepseek_mcp_client as client
    import sys

    monkeypatch.setattr(sys, "argv", ["deepseek_mcp_client.py"])
    inputs = iter(["进行编队", "1", "GV1", "发送队形", "exit"])
    monkeypatch.setattr("builtins.input", lambda prompt="": next(inputs))
    monkeypatch.setattr(
        client,
        "call_llm",
        Mock(side_effect=AssertionError("wizard must not call LLM")),
    )
    calls = []

    def fake_mcp(server, tool, args):
        calls.append(tool)
        if tool == "list_robots":
            return _wizard_fleet_response()
        return json.dumps({"success": True, "message": "ok", "data": {}})

    monkeypatch.setattr(client, "run_mcp_call", fake_mcp)
    client.main()

    assert "send_follow_formation" not in calls
    assert "间距无效" in capsys.readouterr().out


def test_follow_mode_blocks_geometric_tool_call(monkeypatch, capsys):
    import deepseek_mcp_client as client
    import sys

    monkeypatch.setattr(sys, "argv", ["deepseek_mcp_client.py"])
    inputs = iter(["进行编队", "1", "GV1", "几何编队", "exit"])
    monkeypatch.setattr("builtins.input", lambda prompt="": next(inputs))
    monkeypatch.setattr(
        client,
        "call_llm",
        Mock(side_effect=AssertionError("wizard must not call LLM")),
    )
    calls = []

    def fake_mcp(server, tool, args):
        calls.append(tool)
        if tool == "list_robots":
            return _wizard_fleet_response()
        return json.dumps({"success": True, "message": "ok", "data": {}})

    monkeypatch.setattr(client, "run_mcp_call", fake_mcp)

    client.main()

    assert "execute_geometric_formation" not in calls
    assert "间距无效" in capsys.readouterr().out


def test_failed_follow_send_blocks_automatic_recovery(monkeypatch, capsys):
    import deepseek_mcp_client as client
    import sys

    monkeypatch.setattr(sys, "argv", ["deepseek_mcp_client.py"])
    inputs = iter(["进行编队", "1", "GV1", "0.5", "发送队形", "exit"])
    monkeypatch.setattr("builtins.input", lambda prompt="": next(inputs))
    monkeypatch.setattr(
        client,
        "call_llm",
        Mock(side_effect=AssertionError("wizard must not call LLM")),
    )
    calls = []

    def fake_mcp(server, tool, args):
        calls.append(tool)
        if tool == "list_robots":
            return _wizard_fleet_response()
        if tool == "send_follow_formation":
            return json.dumps({"success": False, "message": "GV2 RPC failed", "data": None})
        return json.dumps({"success": True, "message": "ok", "data": {}})

    monkeypatch.setattr(client, "run_mcp_call", fake_mcp)

    client.main()

    assert calls.count("send_follow_formation") == 1
    assert "stop_active_formation" not in calls
    assert "队形发送失败" in capsys.readouterr().out


def test_failed_follow_send_allows_explicit_stop_recovery(monkeypatch):
    import deepseek_mcp_client as client
    import sys

    monkeypatch.setattr(sys, "argv", ["deepseek_mcp_client.py"])
    inputs = iter([
        "进行编队", "1", "GV1", "0.5", "发送队形", "停止编队", "exit"
    ])
    monkeypatch.setattr("builtins.input", lambda prompt="": next(inputs))
    llm_results = iter([
        {"tool": "stop_active_formation", "args": {}},
        {"done": True, "message": "已按要求停止编队。"},
    ])
    monkeypatch.setattr(client, "call_llm", lambda *args: next(llm_results))
    calls = []

    def fake_mcp(server, tool, args):
        calls.append(tool)
        if tool == "list_robots":
            return _wizard_fleet_response()
        if tool == "send_follow_formation":
            return json.dumps({"success": False, "message": "GV2 RPC failed", "data": None})
        return json.dumps({"success": True, "message": "ok", "data": {}})

    monkeypatch.setattr(client, "run_mcp_call", fake_mcp)

    client.main()

    assert calls.count("send_follow_formation") == 1
    assert calls.count("stop_active_formation") == 1


def test_failed_follow_send_retries_deterministically_when_explicitly_requested(monkeypatch):
    import deepseek_mcp_client as client
    import sys

    monkeypatch.setattr(sys, "argv", ["deepseek_mcp_client.py"])
    inputs = iter([
        "进行编队", "1", "GV1", "0.5", "发送队形", "重试发送队形", "exit"
    ])
    monkeypatch.setattr("builtins.input", lambda prompt="": next(inputs))
    llm = Mock(side_effect=AssertionError("explicit retry must remain deterministic"))
    monkeypatch.setattr(client, "call_llm", llm)
    calls = []

    def fake_mcp(server, tool, args):
        calls.append((tool, args))
        if tool == "list_robots":
            return _wizard_fleet_response()
        if tool == "send_follow_formation" and sum(
            name == "send_follow_formation" for name, _ in calls
        ) == 1:
            return json.dumps({"success": False, "message": "GV2 RPC failed", "data": None})
        return json.dumps({"success": True, "message": "ok", "data": {}})

    monkeypatch.setattr(client, "run_mcp_call", fake_mcp)

    client.main()

    send_calls = [args for tool, args in calls if tool == "send_follow_formation"]
    assert len(send_calls) == 2
    assert send_calls[0] == send_calls[1]
    llm.assert_not_called()


def test_follow_target_uses_leader_only_tool_without_premature_done(monkeypatch, capsys):
    import deepseek_mcp_client as client
    import sys

    monkeypatch.setattr(sys, "argv", ["deepseek_mcp_client.py"])
    inputs = iter(["进行编队", "1", "GV1", "0.5", "发送队形", "前往(5,6)", "exit"])
    monkeypatch.setattr("builtins.input", lambda prompt="": next(inputs))
    monkeypatch.setattr(
        client,
        "call_llm",
        Mock(side_effect=AssertionError("wizard must not call LLM")),
    )
    calls = []

    def fake_mcp(server, tool, args):
        calls.append(tool)
        if tool == "list_robots":
            return _wizard_fleet_response()
        return json.dumps({"success": True, "message": "ok", "data": {}})

    monkeypatch.setattr(client, "run_mcp_call", fake_mcp)

    client.main()

    assert calls.count("goto_follow_formation") == 1
    assert "goto_pose" not in calls
    assert "goto_pose_batch" not in calls
    assert "禁止 premature done" not in capsys.readouterr().out


def test_geometric_mode_selection_is_preserved_in_llm_history(monkeypatch):
    import deepseek_mcp_client as client
    import sys

    monkeypatch.setattr(sys, "argv", ["deepseek_mcp_client.py"])
    inputs = iter(["进行编队", "2", "将GV1和GV2排成直线", "exit"])
    monkeypatch.setattr("builtins.input", lambda prompt="": next(inputs))

    selection_seen = []

    def fake_llm(messages, api_key, model):
        contents = [str(item.get("content", "")) for item in messages]
        selection_seen.append(any("已选择几何编队" in content for content in contents))
        return {"done": True, "message": "参数已收到。"}

    monkeypatch.setattr(client, "call_llm", fake_llm)
    monkeypatch.setattr(
        client,
        "run_mcp_call",
        lambda *args: json.dumps({"success": True, "message": "ok", "data": {"items": []}}),
    )

    client.main()
    assert selection_seen == [True]

class MockSession:
    """Mock requests.Session that bypasses proxy and returns canned responses."""
    trust_env = False

    def __init__(self, response):
        self._response = response

    def post(self, *args, **kwargs):
        return self._response


def test_call_llm_json_parsing(monkeypatch):
    mock_resp = MockResponse('```json\n{"tool": "get_fleet_status", "args": {"robot_ids_csv": ""}}\n```')
    import requests
    monkeypatch.setattr(requests, "Session", lambda: MockSession(mock_resp))

    res = call_llm([], "dummy_key", "dummy_model")
    assert isinstance(res, dict)
    assert res.get("tool") == "get_fleet_status"


def test_call_llm_done_parsing(monkeypatch):
    mock_resp = MockResponse('{"done": true, "message": "OK"}')
    import requests
    monkeypatch.setattr(requests, "Session", lambda: MockSession(mock_resp))

    res = call_llm([], "dummy_key", "dummy_model")
    assert isinstance(res, dict)
    assert res.get("done") is True


def test_call_llm_wraps_nonempty_prose_as_done(monkeypatch):
    mock_resp = MockResponse("请指定 Leader。")
    import requests
    monkeypatch.setattr(requests, "Session", lambda: MockSession(mock_resp))

    assert call_llm([], "dummy_key", "dummy_model") == {
        "done": True,
        "message": "请指定 Leader。",
    }


def test_normalize_set_leader_unit_id_alias():
    import deepseek_mcp_client as client

    assert client.normalize_tool_call_args("set_leader", {"unit_id": "GV1"}) == {
        "robot_id": "GV1"
    }


def test_conflicting_set_leader_alias_is_rejected():
    import deepseek_mcp_client as client
    import pytest

    with pytest.raises(ValueError):
        client.normalize_tool_call_args(
            "set_leader", {"robot_id": "GV1", "unit_id": "GV2"}
        )


def test_generic_agent_normalizes_set_leader_unit_id_before_fastmcp(monkeypatch):
    import deepseek_mcp_client as client
    import sys

    monkeypatch.setattr(sys, "argv", ["deepseek_mcp_client.py"])
    inputs = iter(["将一号车设为队长", "exit"])
    monkeypatch.setattr("builtins.input", lambda prompt="": next(inputs))
    llm_results = iter([
        {"tool": "set_leader", "args": {"unit_id": "GV1"}},
        {"done": True, "message": "已设置。"},
    ])
    monkeypatch.setattr(client, "call_llm", lambda *args: next(llm_results))
    calls = []

    def fake_mcp(server, tool, args):
        calls.append((tool, args))
        return json.dumps({"success": True, "message": "ok", "data": {}})

    monkeypatch.setattr(client, "run_mcp_call", fake_mcp)

    client.main()

    assert ("set_leader", {"robot_id": "GV1"}) in calls
    assert ("set_leader", {"unit_id": "GV1"}) not in calls

def test_guardrail_blocks_plan_line_for_absolute_goals(monkeypatch, capsys):
    """绝对坐标任务禁止 plan_line_targets，且 premature done 被驳回"""
    import deepseek_mcp_client
    import sys

    monkeypatch.setattr(sys, "argv", ["deepseek_mcp_client.py"])
    inputs = ["将小车1 移动到（1，1），小车2移动到（2，2）", "exit"]

    def mock_input(prompt=""):
        return inputs.pop(0)

    monkeypatch.setattr("builtins.input", mock_input)

    call_count = [0]

    def mock_call_llm(*args, **kwargs):
        call_count[0] += 1
        if call_count[0] == 1:
            return [
                {"tool": "get_fleet_status", "args": {"robot_ids_csv": "GV1,GV2"}},
                {"tool": "plan_line_targets", "args": {"robot_ids_csv": "GV1,GV2", "spacing_m": 1.414}},
            ]
        if call_count[0] == 2:
            return {
                "done": True,
                "message": "plan_line_targets 不符，我将直接使用 compute_navigation_hint",
            }
        if call_count[0] == 3:
            return {
                "tool": "send_move",
                "args": {
                    "robot_id": "GV1",
                    "linear_velocity": 0.5,
                    "angular_velocity": 0.0,
                    "duration_ms": 1000,
                },
            }
        return {"done": True, "message": "moves executed"}

    monkeypatch.setattr(deepseek_mcp_client, "call_llm", mock_call_llm)

    def mock_run_mcp(*args, **kwargs):
        if args[1] == "get_fleet_status":
            return json.dumps({"success": True, "data": {"items": []}})
        if args[1] == "send_move":
            return json.dumps({"success": True, "message": "accepted", "data": {"duration_ms": 1000}})
        return json.dumps({"success": True, "data": {}})

    monkeypatch.setattr(deepseek_mcp_client, "run_mcp_call", mock_run_mcp)

    import time

    monkeypatch.setattr(time, "sleep", lambda x: None)

    deepseek_mcp_client.main()

    out = capsys.readouterr().out
    assert "禁止调用 plan_line_targets" in out
    assert "premature done" in out.lower() or "Premature done" in out or "禁止 premature done" in out


def test_guardrail_oob_speed_rejection(monkeypatch, capsys):
    """TC-06：用户越界速度被 LLM 截断时，客户端还原原值并中止任务"""
    import deepseek_mcp_client
    import sys

    monkeypatch.setattr(sys, "argv", ["deepseek_mcp_client.py"])
    inputs = ["让小车以1000m/s速度奔跑", "exit"]

    def mock_input(prompt=""):
        return inputs.pop(0)

    monkeypatch.setattr("builtins.input", mock_input)

    call_count = [0]

    def mock_call_llm(*args, **kwargs):
        call_count[0] += 1
        if call_count[0] == 1:
            return {
                "tool": "send_move",
                "args": {
                    "robot_id": "GV1",
                    "linear_velocity": 5.0,
                    "angular_velocity": 0.0,
                    "duration_ms": 1000,
                },
            }
        return {"done": True, "message": "Task completed successfully"}

    monkeypatch.setattr(deepseek_mcp_client, "call_llm", mock_call_llm)

    def mock_run_mcp(*args, **kwargs):
        if args[1] == "send_move":
            return json.dumps(
                {
                    "success": False,
                    "message": "speed_out_of_bounds: linear_velocity abs=1000.0 exceeds max_safe=5.0 m/s",
                    "data": None,
                }
            )
        return json.dumps({"success": True, "data": {"items": []}})

    monkeypatch.setattr(deepseek_mcp_client, "run_mcp_call", mock_run_mcp)

    import time

    monkeypatch.setattr(time, "sleep", lambda x: None)

    deepseek_mcp_client.main()

    out = capsys.readouterr().out
    assert "还原原值以触发适配层越界校验" in out
    assert "越界速度已在适配层拦截" in out
    assert "Task Rejected" in out
    assert "Task completed successfully" not in out


def test_guardrail_distance_tolerance(monkeypatch, capsys):
    """测试距离容差护栏拦截（单车到达后拒绝其移动指令）"""
    import deepseek_mcp_client
    import sys
    monkeypatch.setattr(sys, "argv", ["deepseek_mcp_client.py"])
    inputs = ["start", "exit"]
    def mock_input(prompt=""):
        return inputs.pop(0)
    monkeypatch.setattr("builtins.input", mock_input)
    
    call_count = [0]
    def mock_call_llm(*args, **kwargs):
        call_count[0] += 1
        if call_count[0] == 1:
            return {"tool": "compute_navigation_hint", "args": {"robot_id": "GV1"}}
        elif call_count[0] == 2:
            return {"tool": "send_move", "args": {"robot_id": "GV1"}}
        else:
            return {"done": True, "message": "finished"}
            
    monkeypatch.setattr(deepseek_mcp_client, "call_llm", mock_call_llm)
    
    def mock_run_mcp(*args, **kwargs):
        return json.dumps({
            "success": True, 
            "data": {"distance_m": 0.10, "current_pose": {"x": 1.0, "y": 1.0}}
        })
    monkeypatch.setattr(deepseek_mcp_client, "run_mcp_call", mock_run_mcp)
    
    import time
    monkeypatch.setattr(time, "sleep", lambda x: None)
    
    deepseek_mcp_client.main()
    
    out = capsys.readouterr().out
    assert "已到达目标，跳过移动" in out

def test_guardrail_max_iterations(monkeypatch, capsys):
    """测试最大迭代轮次护栏拦截"""
    import deepseek_mcp_client
    
    import sys
    monkeypatch.setattr(sys, "argv", ["deepseek_mcp_client.py"])
    inputs = ["start", "exit"]
    def mock_input(prompt=""):
        return inputs.pop(0)
    monkeypatch.setattr("builtins.input", mock_input)
    
    # 模拟 LLM 疯狂发送 send_move
    def mock_call_llm(*args, **kwargs):
        return {"tool": "send_move", "args": {"robot_id": "GV2", "duration_ms": 100}}
    monkeypatch.setattr(deepseek_mcp_client, "call_llm", mock_call_llm)
    
    # 模拟 MCP 返回正常的位移，但是 LLM 依旧发 send_move
    call_count = [0]
    def mock_run_mcp(*args, **kwargs):
        call_count[0] += 1
        return json.dumps({
            "success": True, 
            "data": {"current_pose": {"x": call_count[0], "y": 0.0}}
        })
    monkeypatch.setattr(deepseek_mcp_client, "run_mcp_call", mock_run_mcp)
    
    import time
    monkeypatch.setattr(time, "sleep", lambda x: None)
    
    deepseek_mcp_client.main()
    
    out = capsys.readouterr().out
    assert "达到最大迭代轮次(12)" in out
    assert "任务已中止" in out

def test_guardrail_stuck_detection(monkeypatch, capsys):
    """测试位置停滞检测护栏拦截"""
    import deepseek_mcp_client
    
    import sys
    monkeypatch.setattr(sys, "argv", ["deepseek_mcp_client.py"])
    inputs = ["start", "exit"]
    def mock_input(prompt=""):
        return inputs.pop(0)
    monkeypatch.setattr("builtins.input", mock_input)
    
    def mock_call_llm(*args, **kwargs):
        return {"tool": "send_move", "args": {"robot_id": "GV3", "duration_ms": 100}}
    monkeypatch.setattr(deepseek_mcp_client, "call_llm", mock_call_llm)
    
    # 模拟 MCP 返回原地不动的位姿
    def mock_run_mcp(*args, **kwargs):
        return json.dumps({
            "success": True, 
            "data": {"current_pose": {"x": 5.0, "y": 5.0}}
        })
    monkeypatch.setattr(deepseek_mcp_client, "run_mcp_call", mock_run_mcp)
    
    import time
    monkeypatch.setattr(time, "sleep", lambda x: None)
    
    deepseek_mcp_client.main()
    
    out = capsys.readouterr().out
    assert "物理卡死或打滑" in out
    assert "任务已中止" in out
