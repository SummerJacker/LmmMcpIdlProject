"""
针对重构后 Agent Client 的测试。
验证 call_llm 对 LLM 输出的 JSON 解析，以及 run_mcp_call 命令构造。
"""

import json
from deepseek_mcp_client import (
    build_system_prompt,
    call_llm,
    done_message_implies_incomplete,
    enforce_send_move_user_speed,
    extract_user_absolute_point_goals,
    extract_user_speed_intent,
    format_point_goals_hint,
    is_premature_done_for_point_goals,
    is_speed_out_of_bounds_message,
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
