import sys
import io
import json
from unittest.mock import patch

# Mock input to return a single command and then "exit"
inputs = [
    "让七号车移动",
    "exit"
]

def mock_input(prompt=""):
    if inputs:
        return inputs.pop(0)
    raise KeyboardInterrupt

# Mocks for deepseek_mcp_client
mock_llm_responses = [
    # 第一轮: 发送一个无限接近目标的导航提示 (测距容差)
    {"tool": "compute_navigation_hint", "args": {"robot_id": "GV1"}},
    # 第二轮: 发送多次 send_move 测试迭代上限
    {"tool": "send_move", "args": {"robot_id": "GV2", "duration_ms": 100}},
    {"tool": "send_move", "args": {"robot_id": "GV2", "duration_ms": 100}},
    {"tool": "send_move", "args": {"robot_id": "GV2", "duration_ms": 100}},
    {"tool": "send_move", "args": {"robot_id": "GV2", "duration_ms": 100}},
]

def mock_call_llm(*args, **kwargs):
    if mock_llm_responses:
        return mock_llm_responses.pop(0)
    return {"done": True, "message": "finished by llm"}

def mock_run_mcp_call(server_spec, tool_name, tool_args):
    if tool_name == "compute_navigation_hint":
        # Simulate Distance < 0.15m (护栏 1)
        return json.dumps({
            "success": True, 
            "data": {
                "distance_m": 0.10,
                "current_pose": {"x": 1.0, "y": 1.0}
            }
        })
    if tool_name == "send_move":
        # Simulate stuck: no movement (护栏 3)
        return json.dumps({
            "success": True, 
            "data": {
                "current_pose": {"x": 2.0, "y": 2.0}
            }
        })
    return "{}"

def test_guardrails():
    print("=== Testing Stage B Guardrails ===")
    import deepseek_mcp_client
    
    # 替换标准输入
    # 替换 LLM 和工具执行
    with patch.object(deepseek_mcp_client, "input", mock_input, create=True), \
         patch("deepseek_mcp_client.call_llm", side_effect=mock_call_llm), \
         patch("deepseek_mcp_client.run_mcp_call", side_effect=mock_run_mcp_call), \
         patch("deepseek_mcp_client.time.sleep", return_value=None), \
         patch.object(sys, "argv", ["deepseek_mcp_client.py"]):
         
         deepseek_mcp_client.main()

if __name__ == "__main__":
    test_guardrails()
