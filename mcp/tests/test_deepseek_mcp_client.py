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


def test_run_mcp_call_serializes_nested_arguments_with_input_json(monkeypatch):
    import deepseek_mcp_client as client

    captured = {}

    def fake_run(cmd, *, capture_output, text, cwd):
        captured["cmd"] = cmd
        captured["cwd"] = cwd
        return Mock(returncode=0, stdout='{"content": []}', stderr="")

    monkeypatch.setattr(client.subprocess, "run", fake_run)
    args = {
        "request": {
            "leader_id": "GV3",
            "followers": [{"unit_id": "GV1", "distance_m": 0.5}],
        }
    }

    client.run_mcp_call("main.py", "createFollowFormation", args)

    cmd = captured["cmd"]
    input_index = cmd.index("--input-json")
    assert json.loads(cmd[input_index + 1]) == args
    assert not any(part.startswith("request=") for part in cmd)


def test_run_mcp_call_failure_preserves_stdout_and_stderr(monkeypatch):
    import deepseek_mcp_client as client

    monkeypatch.setattr(
        client.subprocess,
        "run",
        lambda *args, **kwargs: Mock(
            returncode=1,
            stdout="Error: Argument request: Expected JSON object",
            stderr="transport cleanup warning",
        ),
    )

    result = json.loads(
        client.run_mcp_call(
            "main.py",
            "createFollowFormation",
            {"request": {"leader_id": "GV3", "followers": []}},
        )
    )

    assert "Expected JSON object" in result["message"]
    assert "transport cleanup warning" in result["message"]

def test_build_system_prompt():
    prompt = build_system_prompt()
    assert "production MCP task API" in prompt
    assert "createStaticFormation" in prompt
    assert "createFollowFormation" in prompt
    assert "Never call raw movement" in prompt
    assert "navigateTo accepts unit_id plus target={x,y}" in prompt


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

    assert allowed_formation_tool("createFollowFormation", follow)
    assert allowed_formation_tool("moveFollowFormation", follow)
    assert not allowed_formation_tool("createStaticFormation", follow)
    assert allowed_formation_tool("createStaticFormation", geometric)
    assert not allowed_formation_tool("createFollowFormation", geometric)
    assert not allowed_formation_tool("moveFollowFormation", geometric)


def test_follow_spacing_must_come_from_user_input():
    state = FormationDialogState(mode=FormationMode.CONSOLE_FOLLOW)
    args = {
        "request": {
            "leader_id": "GV1",
            "followers": [{"unit_id": "GV2", "distance_m": 1.0}],
        },
    }

    assert not follow_spacing_args_are_user_supplied(args, state)

    record_explicit_follow_spacings("GV2 的间距为 0.3 米", state)
    matching = {
        "request": {
            "leader_id": "GV1",
            "followers": [{"unit_id": "GV2", "distance_m": 0.3}],
        },
    }
    assert follow_spacing_args_are_user_supplied(matching, state)
    assert not follow_spacing_args_are_user_supplied(args, state)


def test_follow_spacing_is_bound_to_each_follower():
    state = FormationDialogState(mode=FormationMode.CONSOLE_FOLLOW)
    record_explicit_follow_spacings("GV2 间距 0.3 米，GV3 间距 0.5 米", state)

    matching = {
        "request": {
            "leader_id": "GV1",
            "followers": [
                {"unit_id": "GV2", "distance_m": 0.3},
                {"unit_id": "GV3", "distance_m": 0.5},
            ],
        },
    }
    swapped = {
        "request": {
            "leader_id": "GV1",
            "followers": [
                {"unit_id": "GV2", "distance_m": 0.5},
                {"unit_id": "GV3", "distance_m": 0.3},
            ],
        },
    }

    assert follow_spacing_args_are_user_supplied(matching, state)
    assert not follow_spacing_args_are_user_supplied(swapped, state)


def test_unrelated_meter_value_is_not_accepted_as_multi_follower_spacing():
    state = FormationDialogState(mode=FormationMode.CONSOLE_FOLLOW)
    record_explicit_follow_spacings("目标点距离当前位置 2 米", state)
    args = {
        "request": {
            "leader_id": "GV1",
            "followers": [
                {"unit_id": "GV2", "distance_m": 2.0},
                {"unit_id": "GV3", "distance_m": 2.0},
            ],
        },
    }

    assert not follow_spacing_args_are_user_supplied(args, state)


def test_recovery_authorization_is_action_specific():
    assert allowed_recovery_tools("停止编队") == {"stopUnits"}
    assert allowed_recovery_tools("重试发送队形") == {"createFollowFormation"}
    assert allowed_recovery_tools("解散编队") == {"disbandFormation"}
    assert "createFollowFormation" not in allowed_recovery_tools("停止编队")
    assert recovery_tool_call_is_authorized("stopUnits", {"unit_ids": ["GV1"]}, "停止GV1")
    assert not recovery_tool_call_is_authorized("stopUnits", {"unit_ids": ["GV2"]}, "停止GV1")
    assert recovery_tool_call_is_authorized("stopUnits", {"unit_ids": ["GV1", "GV2"]}, "紧急停止所有车辆")
    assert recovery_tool_call_is_authorized(
        "cancelTask", {"task_id": "task-123"}, "取消任务 task-123"
    )
    assert not recovery_tool_call_is_authorized(
        "cancelTask", {"task_id": "task-456"}, "取消任务 task-123"
    )
    assert recovery_tool_call_is_authorized("disbandFormation", {}, "解散编队")
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
        if tool == "getFleetSnapshot":
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
        ("getFleetSnapshot", {}),
        (
            "createFollowFormation",
            {
                "request": {
                    "leader_id": "GV1",
                    "followers": [{"unit_id": "GV2", "distance_m": 0.5}],
                },
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
        if tool == "getFleetSnapshot":
            return _wizard_fleet_response()
        return json.dumps({"success": True, "message": "ok", "data": {}})

    monkeypatch.setattr(client, "run_mcp_call", fake_mcp)

    client.main()

    assert calls.count("getFleetSnapshot") == 2
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
        if tool == "getFleetSnapshot":
            return _wizard_fleet_response()
        return json.dumps({"success": True, "message": "ok", "data": {}})

    monkeypatch.setattr(client, "run_mcp_call", fake_mcp)
    client.main()

    assert "createFollowFormation" not in calls
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
        if tool == "getFleetSnapshot":
            return _wizard_fleet_response()
        return json.dumps({"success": True, "message": "ok", "data": {}})

    monkeypatch.setattr(client, "run_mcp_call", fake_mcp)

    client.main()

    assert "createStaticFormation" not in calls
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
        if tool == "getFleetSnapshot":
            return _wizard_fleet_response()
        if tool == "createFollowFormation":
            return json.dumps({"success": False, "message": "GV2 RPC failed", "data": None})
        return json.dumps({"success": True, "message": "ok", "data": {}})

    monkeypatch.setattr(client, "run_mcp_call", fake_mcp)

    client.main()

    assert calls.count("createFollowFormation") == 1
    assert "stopUnits" not in calls
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
        {"tool": "stopUnits", "args": {"unit_ids": ["GV1", "GV2"]}},
        {"done": True, "message": "已按要求停止编队。"},
    ])
    monkeypatch.setattr(client, "call_llm", lambda *args: next(llm_results))
    calls = []

    def fake_mcp(server, tool, args):
        calls.append(tool)
        if tool == "getFleetSnapshot":
            return _wizard_fleet_response()
        if tool == "createFollowFormation":
            return json.dumps({"success": False, "message": "GV2 RPC failed", "data": None})
        return json.dumps({"success": True, "message": "ok", "data": {}})

    monkeypatch.setattr(client, "run_mcp_call", fake_mcp)

    client.main()

    assert calls.count("createFollowFormation") == 1
    assert calls.count("stopUnits") == 1


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
        if tool == "getFleetSnapshot":
            return _wizard_fleet_response()
        if tool == "createFollowFormation" and sum(
            name == "createFollowFormation" for name, _ in calls
        ) == 1:
            return json.dumps({"success": False, "message": "GV2 RPC failed", "data": None})
        return json.dumps({"success": True, "message": "ok", "data": {}})

    monkeypatch.setattr(client, "run_mcp_call", fake_mcp)

    client.main()

    send_calls = [args for tool, args in calls if tool == "createFollowFormation"]
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
        if tool == "getFleetSnapshot":
            return _wizard_fleet_response()
        return json.dumps({"success": True, "message": "ok", "data": {}})

    monkeypatch.setattr(client, "run_mcp_call", fake_mcp)

    client.main()

    assert calls.count("moveFollowFormation") == 1
    assert "navigateTo" not in calls
    assert "followPath" not in calls
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
    mock_resp = MockResponse('```json\n{"tool": "getFleetSnapshot", "args": {}}\n```')
    import requests
    monkeypatch.setattr(requests, "Session", lambda: MockSession(mock_resp))

    res = call_llm([], "dummy_key", "dummy_model")
    assert isinstance(res, dict)
    assert res.get("tool") == "getFleetSnapshot"


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


def test_normalize_task_arguments_preserves_structured_request():
    import deepseek_mcp_client as client

    args = {"request": {"leader_id": "GV1", "followers": []}}
    assert client.normalize_tool_call_args("createFollowFormation", args) == args


def test_normalize_task_arguments_does_not_rewrite_unit_ids():
    import deepseek_mcp_client as client

    args = {"unit_id": "GV1", "target": {"x": 1.0, "y": 2.0}}
    assert client.normalize_tool_call_args("navigateTo", args) == args


def test_generic_agent_rejects_low_level_tool_before_fastmcp(monkeypatch, capsys):
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

    assert all(tool != "set_leader" for tool, _ in calls)
    assert "Production MCP rejects non-task tool: set_leader" in capsys.readouterr().out

def test_guardrail_blocks_legacy_planner_and_requires_navigate_to(monkeypatch, capsys):
    """绝对坐标任务拒绝旧规划工具，并要求任务级 navigateTo。"""
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
            return [
                {"tool": "navigateTo", "args": {"unit_id": "GV1", "target": {"x": 1.0, "y": 1.0}}},
                {"tool": "navigateTo", "args": {"unit_id": "GV2", "target": {"x": 2.0, "y": 2.0}}},
            ]
        return {"done": True, "message": "moves executed"}

    monkeypatch.setattr(deepseek_mcp_client, "call_llm", mock_call_llm)

    def mock_run_mcp(*args, **kwargs):
        if args[1] == "getFleetSnapshot":
            return json.dumps({"success": True, "data": {"units": []}})
        if args[1] == "navigateTo":
            return json.dumps({"success": True, "message": "accepted", "data": {"state": "COMPLETED"}})
        return json.dumps({"success": True, "data": {}})

    monkeypatch.setattr(deepseek_mcp_client, "run_mcp_call", mock_run_mcp)

    import time

    monkeypatch.setattr(time, "sleep", lambda x: None)

    deepseek_mcp_client.main()

    out = capsys.readouterr().out
    assert "Production MCP rejects non-task tool: plan_line_targets" in out
    assert "premature done" in out.lower() or "Premature done" in out or "禁止 premature done" in out


def test_guardrail_rejects_low_level_speed_tool(monkeypatch, capsys):
    """生产客户端不把导航速度降级为低层 send_move。"""
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
    assert "Production MCP rejects non-task tool: send_move" in out
    assert "navigateTo 不支持导航速度参数" in out
    assert "Task Done: Task completed successfully" not in out


def test_guardrail_rejects_legacy_navigation_helpers(monkeypatch, capsys):
    """旧导航提示与原始移动工具均不得进入生产 MCP。"""
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
    assert "Production MCP rejects non-task tool: compute_navigation_hint" in out
    assert "Production MCP rejects non-task tool: send_move" in out

def test_guardrail_rejects_repeated_low_level_move_without_dispatch(monkeypatch, capsys):
    """低层移动被拒绝后不会调用 MCP，LLM 可结束当前轮次。"""
    import deepseek_mcp_client
    
    import sys
    monkeypatch.setattr(sys, "argv", ["deepseek_mcp_client.py"])
    inputs = ["start", "exit"]
    def mock_input(prompt=""):
        return inputs.pop(0)
    monkeypatch.setattr("builtins.input", mock_input)
    
    llm_count = [0]
    def mock_call_llm(*args, **kwargs):
        llm_count[0] += 1
        if llm_count[0] == 1:
            return {"tool": "send_move", "args": {"robot_id": "GV2", "duration_ms": 100}}
        return {"done": True, "message": "legacy move rejected"}
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
    assert "Production MCP rejects non-task tool: send_move" in out
    assert call_count[0] == 1

def test_guardrail_allows_task_status_tool(monkeypatch, capsys):
    """测试位置停滞检测护栏拦截"""
    import deepseek_mcp_client
    
    import sys
    monkeypatch.setattr(sys, "argv", ["deepseek_mcp_client.py"])
    inputs = ["start", "exit"]
    def mock_input(prompt=""):
        return inputs.pop(0)
    monkeypatch.setattr("builtins.input", mock_input)
    
    llm_count = [0]
    def mock_call_llm(*args, **kwargs):
        llm_count[0] += 1
        if llm_count[0] == 1:
            return {"tool": "getTaskStatus", "args": {"task_id": "task-123"}}
        return {"done": True, "message": "status checked"}
    monkeypatch.setattr(deepseek_mcp_client, "call_llm", mock_call_llm)
    
    # 模拟 MCP 返回原地不动的位姿
    calls = []
    def mock_run_mcp(*args, **kwargs):
        calls.append(args[1])
        return json.dumps({
            "success": True, 
            "data": {"task_id": "task-123", "state": "COMPLETED"}
        })
    monkeypatch.setattr(deepseek_mcp_client, "run_mcp_call", mock_run_mcp)
    
    import time
    monkeypatch.setattr(time, "sleep", lambda x: None)
    
    deepseek_mcp_client.main()
    
    out = capsys.readouterr().out
    assert "Calling tool: getTaskStatus" in out
    assert calls[0] == "getTaskStatus"
