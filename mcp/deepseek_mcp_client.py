"""
DeepSeek + MCP 瘦客户端（Thin Client）示例。

职责：
1) 维护 Agent 循环：用户输入 -> LLM 思考 -> 工具调用 -> 观测结果回传 LLM -> 完成。
2) 工具调用通过 MCP 代理（fastmcp cli），本客户端不包含业务编队或几何计算逻辑，彻底下沉至工具层。

修改原因：
剥离原先庞大的正则解析和硬编码模板，将大模型作为真正的Agent来驱动工具的闭环。
补充：相对运动场景增加 NO_GPS_OPEN_LOOP 提示规则，避免在无全局位姿时误用 get_*_status / navigation_hint。
补充：TC-06 越界速度测试时，禁止 LLM 静默截断用户速度；客户端还原原值并强制走适配层 speed_out_of_bounds 拦截。
补充：用户指定绝对坐标 (x,y) 时禁止 plan_* 编队工具，并拦截未执行 send_move 的 premature done。
"""

import argparse
import json
import logging
import math
import os
import re
import subprocess
import sys
import time
from typing import Any

import requests

from config import (
    ANGULAR_VELOCITY_MAX_ABS_RAD_S,
    DEFAULT_TOOL_TIMEOUT_S,
    LINEAR_VELOCITY_MAX_ABS_M_S,
)

logger = logging.getLogger("deepseek_mcp_client")
MCP_PROJECT_ROOT = os.path.dirname(os.path.abspath(__file__))

SILICONFLOW_CHAT_COMPLETIONS_URL = "https://api.siliconflow.cn/v1/chat/completions"
DEFAULT_SILICONFLOW_API_KEY = "sk-XXXXXX"

_USER_LINEAR_SPEED_RE = re.compile(
    r"(?P<val>\d+(?:\.\d+)?)\s*(?:m\s*/\s*s|m/s|米/秒|米每秒|ms(?:\s|$))",
    re.IGNORECASE,
)
_USER_ANGULAR_SPEED_RE = re.compile(
    r"(?P<val>\d+(?:\.\d+)?)\s*(?:rad\s*/\s*s|rad/s|弧度/秒|弧度每秒)",
    re.IGNORECASE,
)
_USER_POINT_GOAL_RE = re.compile(
    r"(?:将\s*)?"
    r"(?:"
    r"(?:小车|机器人|车)\s*(?P<cn_num>\d+)\s*(?:号)?(?:车)?"
    r"|(?P<gv_id>GV\d+)"
    r"|(?P<robot_id>robot_\d+)"
    r")"
    r"\s*(?:移动|移到|移动到|去|开到|前往|到)?\s*"
    r"[（(]\s*(?P<x>-?\d+(?:\.\d+)?)\s*[,，]\s*(?P<y>-?\d+(?:\.\d+)?)\s*[）)]",
    re.IGNORECASE,
)
_FORMATION_PLAN_TOOLS = frozenset({"plan_line_targets", "plan_triangle_targets"})
_DONE_INCOMPLETE_MARKERS = (
    "我将",
    "接下来",
    "需要",
    "应该",
    "will use",
    "need to",
    "should use",
    "instead",
    "而不是",
)


def setup_client_logging() -> None:
    """
    配置客户端日志，将日志记录到 logs/client.log，并在终端输出警告及以上级别信息。
    """
    if logger.handlers:
        return
    log_dir = os.path.join(MCP_PROJECT_ROOT, "logs")
    os.makedirs(log_dir, exist_ok=True)
    log_path = os.path.join(log_dir, "client.log")
    fmt = logging.Formatter("%(asctime)s [%(levelname)s] %(name)s: %(message)s")
    fh = logging.FileHandler(log_path, encoding="utf-8")
    fh.setFormatter(fmt)
    fh.setLevel(logging.INFO)
    sh = logging.StreamHandler(sys.stderr)
    sh.setFormatter(fmt)
    sh.setLevel(logging.WARNING)
    logger.setLevel(logging.INFO)
    logger.addHandler(fh)
    logger.addHandler(sh)


def build_system_prompt() -> str:
    """
    构建 Agent 的 System Prompt，告知可用工具和期望的决策链。
    
    @returns {str} Prompt字符串
    """
    return (
        "You are an intelligent Robot Fleet Commander connected to an MCP tool server.\n"
        "Your goal is to understand the user's intent and autonomously orchestrate robots using available tools.\n\n"
        "Available Tools:\n"
        "1. list_robots(): list console-bound units. Each unit has run_mode (sim|real) from console mock flag and rpc_enabled.\n"
        "   NEVER describe runtime using planned_mode alone. If mock=true or rpc_enabled=false, the unit is simulation (sim).\n"
        "2. get_robot_status(robot_id): get specific robot's status (pose, speed). Use unit_id if known.\n"
        "3. get_fleet_status(robot_ids_csv=\"\"): get status of multiple robots.\n"
        "4. plan_triangle_targets(robot_ids_csv, side_length_m): given 3 robots, computes the best target points to form an equilateral triangle.\n"
        "5. plan_line_targets(robot_ids_csv, spacing_m): ONLY for line formation by spacing — NOT for user-specified (x,y) coordinates.\n"
        "6. compute_navigation_hint(robot_id, target_x, target_y, max_linear_m_s, max_angular_rad_s): gives suggested velocities and duration to reach a point.\n"
        "7. send_move(robot_id, linear_velocity, angular_velocity, duration_ms): execute physical movement.\n"
        "8. stop_robot(robot_id): stop a robot.\n"
        "9. emergency_stop_all(): stop all robots.\n\n"
        "Agent Loop Rule:\n"
        "- ID BINDING RULE: If a tool fails with 'unit_not_bound', you MUST call list_robots() first to see the valid unit_id bindings, then use the valid unit_id (like 'GV1') as the robot_id parameter in subsequent tools.\n"
        "- If you need to execute a tool, output a JSON object in this format:\n"
        "  {\"tool\": \"tool_name\", \"args\": {\"arg1\": \"value1\"}}\n"
        "- If you need to execute multiple tools in sequence, output a JSON array of tool calls.\n"
        "- ABSOLUTE POINT GOALS: When the user gives world coordinates such as 'move robot 1 to (1,1)' or '移动到（2，2）', "
        "NEVER call plan_line_targets or plan_triangle_targets. Those tools compute formation geometry from spacing, "
        "not arbitrary absolute (x,y). Flow: get_fleet_status → for EACH robot compute_navigation_hint(robot_id, target_x, target_y) "
        "→ send_move loop until within tolerance → then output done.\n"
        "- PREMATURE DONE: NEVER output {\"done\": true} before executing send_move for requested absolute point goals. "
        "Do not output done with text like 'I will use compute_navigation_hint next' — execute the tools first.\n"
        "- For formation tasks ONLY (e.g. '排成一排相距1m', '三角形编队'): use plan_line_targets or plan_triangle_targets, "
        "then navigate with compute_navigation_hint + send_move.\n"
        "- For absolute position targets (e.g., 'go to 0,0' or explicit (x,y) per robot): 1) call get_fleet_status. "
        "2) use compute_navigation_hint with the user's target_x/target_y (NOT plan_* tools). "
        "3) For each robot, loop compute_navigation_hint then send_move until reached. 4) Output done.\n"
        "- NO_GPS_OPEN_LOOP (relative / blind motion): If the user asks for motion relative to the robot body (forward/back/turn by angle/distance) and there is NO global positioning on the vehicle, you MUST NOT use get_robot_status, get_fleet_status, or compute_navigation_hint to verify pose before or after moves. Pose-based tools assume absolute coordinates (GPS/SLAM); omit them for pure odometry-style commands.\n"
        "  Standard flow without GPS: (1) Optionally call list_robots() once only if you need robot_id/unit_id binding or unit_not_bound recovery — NOT for pose. (2) Emit send_move with velocity×duration_ms matching the requested displacement (e.g. forward 1 m at 0.5 m/s → linear_velocity=0.5, angular_velocity=0.0, duration_ms=2000). (3) After the client waits out duration, output {\"done\": true, \"message\": \"...\"} describing the commanded open-loop motion — do not claim GPS-verified position.\n"
        "- For relative or blind movements (e.g., 'move forward 1m', 'move left 1m then right 1m'): DO NOT use compute_navigation_hint. Instead, directly use send_move with math (e.g., to move forward 1m at 0.5m/s, linear_velocity=0.5, angular_velocity=0.0, duration_ms=2000). Forward means positive linear_velocity. The robots are non-holonomic: 'move left' means first turn left 90 degrees (pi/2 rad), then move forward. For complex relative sequences, output a JSON array containing MULTIPLE send_move tool calls in order (e.g., turn left, move forward, turn right, move forward). Do not call get_fleet_status between these steps; execute the open-loop sequence only.\n"
        "- IMPORTANT TOLERANCE RULE (absolute navigation only): When using compute_navigation_hint toward fixed world targets, do not over-adjust. If distance_m < 0.2m and yaw_error is small, consider the waypoint reached. This rule does NOT apply to NO_GPS_OPEN_LOOP relative sequences where pose is unknown.\n"
        "- EMERGENCY ESCAPE HATCH: If you have executed more than 3 movement cycles (send_move) for the SAME target and the distance is not getting significantly closer, YOU MUST consider the formation 'good enough' and output {\"done\": true, \"message\": \"Task completed (reached steady state)\"}. Do NOT get stuck in an infinite loop of micro-adjustments.\n"
        "- SPEED SAFETY (TC-06): NEVER clamp, cap, or silently reduce linear_velocity or angular_velocity. "
        "Always pass the user's exact numeric speed into send_move. The MCP adapter and Qt console enforce max safe limits "
        f"(linear <= {LINEAR_VELOCITY_MAX_ABS_M_S} m/s, angular <= {ANGULAR_VELOCITY_MAX_ABS_RAD_S} rad/s) and return speed_out_of_bounds. "
        "After speed_out_of_bounds, report rejection in done.message — do NOT retry with a lower speed unless the user explicitly changes the request.\n"
        "- When the task is complete, output a JSON object in this format:\n"
        "  {\"done\": true, \"message\": \"Task completed successfully\"}\n"
        "- ONLY OUTPUT VALID JSON. DO NOT output markdown or explanations outside the JSON."
    )


def extract_user_speed_intent(user_text: str) -> dict[str, float | None]:
    """
    从用户自然语言中提取显式声明的线/角速度（m/s、rad/s）。

    @param user_text: 用户本轮输入
    @returns: linear_m_s 与 angular_rad_s，未识别则为 None
    """

    linear: float | None = None
    angular: float | None = None
    for match in _USER_LINEAR_SPEED_RE.finditer(user_text):
        linear = float(match.group("val"))
    for match in _USER_ANGULAR_SPEED_RE.finditer(user_text):
        angular = float(match.group("val"))
    return {"linear_m_s": linear, "angular_rad_s": angular}


def user_requested_out_of_bounds_speed(user_speed_intent: dict[str, float | None]) -> bool:
    """
    @param user_speed_intent: extract_user_speed_intent 的返回值
    @returns: 用户是否明确要求超过安全阈值的速度
    """

    linear = user_speed_intent.get("linear_m_s")
    angular = user_speed_intent.get("angular_rad_s")
    if linear is not None and abs(linear) > LINEAR_VELOCITY_MAX_ABS_M_S:
        return True
    if angular is not None and abs(angular) > ANGULAR_VELOCITY_MAX_ABS_RAD_S:
        return True
    return False


def is_speed_out_of_bounds_message(message: str) -> bool:
    """
    @param message: 工具返回 message 字段
    @returns: 是否为越界拦截语义
    """

    return "speed_out_of_bounds" in message


def enforce_send_move_user_speed(
    tool_args: dict[str, Any],
    user_speed_intent: dict[str, float | None],
) -> bool:
    """
    若用户明确要求越界速度而 LLM 静默截断，还原为用户原值以触发适配层校验。

    @param tool_args: send_move 参数字典（就地修改）
    @param user_speed_intent: extract_user_speed_intent 结果
    @returns: 是否发生了还原
    """

    changed = False
    linear_req = user_speed_intent.get("linear_m_s")
    if linear_req is not None and abs(linear_req) > LINEAR_VELOCITY_MAX_ABS_M_S:
        passed = float(tool_args.get("linear_velocity", 0))
        if abs(passed - linear_req) > 1e-6:
            print(
                f"[Agent] [GUARDRAIL] LLM 将用户线速度 {linear_req} m/s 截断为 {passed} m/s，"
                f"已还原原值以触发适配层越界校验（TC-06）"
            )
            tool_args["linear_velocity"] = linear_req
            changed = True

    angular_req = user_speed_intent.get("angular_rad_s")
    if angular_req is not None and abs(angular_req) > ANGULAR_VELOCITY_MAX_ABS_RAD_S:
        passed = float(tool_args.get("angular_velocity", 0))
        if abs(passed - angular_req) > 1e-6:
            print(
                f"[Agent] [GUARDRAIL] LLM 将用户角速度 {angular_req} rad/s 截断为 {passed} rad/s，"
                f"已还原原值以触发适配层越界校验（TC-06）"
            )
            tool_args["angular_velocity"] = angular_req
            changed = True
    return changed


def extract_user_absolute_point_goals(user_text: str) -> list[dict[str, Any]]:
    """
    从用户自然语言中提取「某车 → 绝对坐标 (x,y)」目标列表。

    @param user_text: 用户本轮输入
    @returns: 每项含 robot_ref、target_x、target_y
    """

    goals: list[dict[str, Any]] = []
    for match in _USER_POINT_GOAL_RE.finditer(user_text):
        cn_num = match.group("cn_num")
        gv_id = match.group("gv_id")
        robot_id = match.group("robot_id")
        if cn_num:
            robot_ref = f"GV{cn_num}"
        elif gv_id:
            robot_ref = gv_id.upper()
        elif robot_id:
            robot_ref = robot_id
        else:
            continue
        goals.append(
            {
                "robot_ref": robot_ref,
                "target_x": float(match.group("x")),
                "target_y": float(match.group("y")),
            }
        )
    return goals


def done_message_implies_incomplete(message: str) -> bool:
    """
    @param message: LLM done 文案
    @returns: 是否表达「尚未执行、接下来再做」
    """

    text = message.strip()
    lower = text.lower()
    return any(marker in text or marker in lower for marker in _DONE_INCOMPLETE_MARKERS)


def is_premature_done_for_point_goals(
    *,
    user_point_goals: list[dict[str, Any]],
    send_move_call_count: int,
    done_message: str,
) -> bool:
    """
    @param user_point_goals: extract_user_absolute_point_goals 结果
    @param send_move_call_count: 本轮已调用 send_move 次数
    @param done_message: LLM done 文案
    @returns: 是否属于未执行移动就提前结束
    """

    if not user_point_goals:
        return False
    if send_move_call_count == 0:
        return True
    return done_message_implies_incomplete(done_message)


def format_point_goals_hint(goals: list[dict[str, Any]]) -> str:
    """@param goals: 绝对坐标目标列表 @returns: 供 LLM 重试的简要说明"""

    parts = [
        f"{g['robot_ref']}→({g['target_x']},{g['target_y']})"
        for g in goals
    ]
    return "; ".join(parts)


def unwrap_tool_payload(res_obj: Any) -> dict[str, Any]:
    """
    将 fastmcp/MCP 工具返回解析为内层 success/message/data 字典。

    @param res_obj: json.loads 后的对象
    @returns: 内层业务 JSON 字典
    """

    if isinstance(res_obj, dict) and "success" in res_obj:
        return res_obj
    if isinstance(res_obj, dict) and "content" in res_obj:
        for item in res_obj.get("content") or []:
            if isinstance(item, dict) and item.get("type") == "text":
                text = item.get("text", "")
                if isinstance(text, str) and text.startswith("{"):
                    try:
                        inner = json.loads(text)
                        if isinstance(inner, dict):
                            return inner
                    except json.JSONDecodeError:
                        pass
    return res_obj if isinstance(res_obj, dict) else {}


def print_list_robots_runtime_summary(payload: dict[str, Any]) -> None:
    """
    在终端打印与主控台一致的运行态摘要，避免 LLM/用户误读 planned_mode。

    @param payload: unwrap 后的 list_robots JSON
    """

    data = payload.get("data")
    if not isinstance(data, dict):
        return
    rpc = bool(data.get("rpc_enabled", False))
    units = data.get("units")
    if not isinstance(units, list):
        return
    parts: list[str] = []
    for u in units:
        if not isinstance(u, dict):
            continue
        uid = u.get("unit_id", "?")
        rm = u.get("run_mode", "sim" if u.get("mock") else "?")
        label = "模拟" if rm == "sim" else "真实"
        parts.append(f"{uid}({label})")
    summary = data.get("fleet_summary")
    extra = ""
    if isinstance(summary, dict):
        extra = f" rpc_enabled={summary.get('rpc_enabled', rpc)}"
    print(f"[Agent] 车队运行态: {', '.join(parts) or '无'}{extra}")


def print_final_fleet_poses(final_res: str) -> None:
    """
    @param final_res: get_fleet_status 返回的 JSON 字符串
    """

    try:
        payload = json.loads(final_res)
        f_data = payload.get("data", {}).get("items", [])
        for item in f_data:
            if not item.get("success"):
                continue
            uid = item.get("robot_id_input", "?")
            d = item.get("data") or {}
            rm = d.get("run_mode")
            if rm is None:
                rm = "sim" if d.get("mock") else "real"
            label = "模拟" if rm == "sim" else "真实"
            p = d.get("pose", {})
            print(
                f"  - {uid} [{label}]: x={p.get('x', 0):.2f}, y={p.get('y', 0):.2f}, yaw={p.get('yaw', 0):.2f}"
            )
    except Exception:
        pass


def call_llm(messages: list[dict[str, Any]], api_key: str, model: str) -> dict[str, Any] | list[dict[str, Any]]:
    """
    调用 LLM 接口，获取 Agent 意图。
    
    @param {list} messages 对话历史
    @param {str} api_key SiliconFlow API key
    @param {str} model 模型名称
    @returns {dict|list} 返回解析后的 JSON 字典或列表
    """
    payload = {
        "model": model,
        "messages": messages,
        "temperature": 0,
    }
    headers = {"Authorization": f"Bearer {api_key}", "Content-Type": "application/json"}
    logger.info("Calling LLM...")
    resp = requests.post(SILICONFLOW_CHAT_COMPLETIONS_URL, headers=headers, json=payload, timeout=60)
    if resp.status_code >= 400:
        raise RuntimeError(f"API error {resp.status_code}: {resp.text}")

    data = resp.json()
    content = data["choices"][0]["message"]["content"].strip()
    
    # 清理可能包含 markdown block 的 JSON 格式
    if content.startswith("```"):
        m = re.search(r"```(?:json)?\s*([\s\S]*?)\s*```", content, flags=re.IGNORECASE)
        if m:
            content = m.group(1).strip()
    if content and content[0] not in "{[":
        first_obj = content.find("{")
        first_arr = content.find("[")
        cand = [i for i in (first_obj, first_arr) if i >= 0]
        if cand:
            content = content[min(cand):]
            
    logger.info("LLM Response: %s", content)
    try:
        return json.loads(content)
    except json.JSONDecodeError as e:
        raise RuntimeError(f"LLM output is not JSON: {content}") from e


def run_mcp_call(server_spec: str, tool: str, args: dict[str, Any]) -> str:
    """
    通过 fastmcp 命令行工具调用本地 MCP 服务。
    
    @param {str} server_spec 服务器入口文件，例如 main.py
    @param {str} tool 调用的工具名
    @param {dict} args 参数字典
    @returns {str} 包含执行结果的 JSON 字符串
    """
    cmd = ["fastmcp", "call", server_spec, tool, "--json"]
    for k, v in args.items():
        cmd.append(f"{k}={v}")

    logger.info("Executing tool: %s with args %s", tool, args)
    proc = subprocess.run(cmd, capture_output=True, text=True, cwd=MCP_PROJECT_ROOT)
    if proc.returncode != 0:
        return json.dumps({"success": False, "message": f"fastmcp failed: {proc.stderr or proc.stdout}"})

    out = proc.stdout.strip()
    first = out.find("{")
    if first < 0:
        return json.dumps({"success": False, "message": f"Cannot parse fastmcp output: {out}"})
    return out[first:]


def main() -> int:
    """
    入口函数，循环读取用户输入，并跑 Agent Loop。
    
    @returns {int} 退出码
    """
    parser = argparse.ArgumentParser(description="Thin DeepSeek MCP client")
    parser.add_argument("--server-spec", default="main.py", help="MCP server spec, default: main.py")
    parser.add_argument("--model", default="deepseek-ai/DeepSeek-V3.2", help="Model name")
    args = parser.parse_args()

    setup_client_logging()
    api_key = os.getenv("SILICONFLOW_API_KEY", DEFAULT_SILICONFLOW_API_KEY)
    
    print("Thin DeepSeek MCP Client started. Type 'exit' to quit.")
    
    messages = [{"role": "system", "content": build_system_prompt()}]
    
    while True:
        try:
            user_text = input("\nUser> ").strip()
            if not user_text:
                continue
            if user_text.lower() in {"exit", "quit"}:
                break
                
            messages.append({"role": "user", "content": user_text})
            user_speed_intent = extract_user_speed_intent(user_text)
            user_oob_speed = user_requested_out_of_bounds_speed(user_speed_intent)
            user_point_goals = extract_user_absolute_point_goals(user_text)
            speed_rejection_seen = False
            send_move_call_count = 0
            
            # Agent Loop variables for guardrails
            robot_iteration_counts = {}
            robot_last_pose = {}
            robot_stuck_counts = {}
            robot_targets = {}
            robot_last_distance = {}
            robot_moved = {}
            MAX_ITERATIONS = 12
            DISTANCE_TOLERANCE_M = 0.15
            STUCK_TOLERANCE_M = 0.02
            MAX_STUCK_COUNTS = 2
            
            # Agent Loop
            while True:
                parsed = call_llm(messages, api_key, args.model)
                
                # 如果 LLM 判断完成
                if isinstance(parsed, dict) and parsed.get("done"):
                    if user_oob_speed and not speed_rejection_seen:
                        print(
                            "\n[Agent] [SECURITY] 用户请求含越界速度，但未触发适配层 speed_out_of_bounds 拦截，"
                            "禁止以成功结束"
                        )
                        messages.append(
                            {
                                "role": "assistant",
                                "content": json.dumps(parsed, ensure_ascii=False),
                            }
                        )
                        messages.append(
                            {
                                "role": "user",
                                "content": (
                                    "Security violation: user requested out-of-bounds speed but no "
                                    "speed_out_of_bounds rejection occurred. Call send_move with the "
                                    "exact user speed; do NOT clamp to the safe limit."
                                ),
                            }
                        )
                        continue

                    if user_oob_speed and speed_rejection_seen:
                        print(
                            "\n[Agent] Task Rejected: 越界速度指令已被 MCP 适配层拦截，"
                            "未下发至主控（TC-06）"
                        )
                    elif is_premature_done_for_point_goals(
                        user_point_goals=user_point_goals,
                        send_move_call_count=send_move_call_count,
                        done_message=str(parsed.get("message", "")),
                    ):
                        print(
                            "\n[Agent] [GUARDRAIL] 用户指定绝对坐标，但尚未执行 send_move，"
                            "禁止 premature done"
                        )
                        messages.append(
                            {
                                "role": "assistant",
                                "content": json.dumps(parsed, ensure_ascii=False),
                            }
                        )
                        goals_hint = format_point_goals_hint(user_point_goals)
                        messages.append(
                            {
                                "role": "user",
                                "content": (
                                    f"Premature done rejected. User absolute point goals: {goals_hint}. "
                                    "Do NOT use plan_line_targets/plan_triangle_targets. "
                                    "Execute get_fleet_status → compute_navigation_hint(target_x,target_y) "
                                    "→ send_move for EACH robot until reached, then output done."
                                ),
                            }
                        )
                        continue
                    else:
                        print(f"\n[Agent] Task Done: {parsed.get('message', 'OK')}")
                    
                    print("[Agent] 正在获取各车辆最终状态...")
                    final_res = run_mcp_call(args.server_spec, "get_fleet_status", {"robot_ids_csv": ""})
                    print_final_fleet_poses(final_res)
                        
                    messages.append({"role": "assistant", "content": json.dumps(parsed, ensure_ascii=False)})
                    break
                    
                # 处理工具调用
                tool_calls = parsed if isinstance(parsed, list) else [parsed]
                
                all_results = []
                max_duration_ms = 0
                abort_task_reason = None
                
                for call in tool_calls:
                    tool_name = call.get("tool")
                    tool_args = call.get("args", {})
                    if not tool_name:
                        continue
                        
                    robot_id = tool_args.get("robot_id")

                    if tool_name in _FORMATION_PLAN_TOOLS and user_point_goals:
                        goals_hint = format_point_goals_hint(user_point_goals)
                        guard_msg = (
                            f"Guardrail rejected: {tool_name} does not accept absolute (x,y) goals ({goals_hint}). "
                            "Use compute_navigation_hint(robot_id, target_x, target_y) then send_move."
                        )
                        print(f"[Agent] [GUARDRAIL] 用户指定绝对坐标，禁止调用 {tool_name}")
                        res_obj = {"success": False, "message": guard_msg, "data": None}
                        all_results.append({"tool": tool_name, "result": res_obj})
                        continue
                    
                    # 如果查询了新目标，重置该车的护栏计数
                    if tool_name == "compute_navigation_hint" and robot_id:
                        tx, ty = tool_args.get("target_x"), tool_args.get("target_y")
                        if tx is not None and ty is not None:
                            target = (float(tx), float(ty))
                            if robot_targets.get(robot_id) != target:
                                robot_targets[robot_id] = target
                                robot_iteration_counts[robot_id] = 0
                                robot_stuck_counts[robot_id] = 0

                    # 护栏 1: 距离容差 (如果已经到达，拒绝下发真实的物理动作，但不终止整个任务)
                    if tool_name == "send_move" and robot_id:
                        enforce_send_move_user_speed(tool_args, user_speed_intent)

                        if robot_last_distance.get(robot_id, 999.0) < DISTANCE_TOLERANCE_M:
                            print(f"[Agent] [GUARDRAIL] {robot_id} 已到达目标，跳过移动。")
                            res_obj = {"success": False, "message": f"Guardrail rejected: {robot_id} already within tolerance ({DISTANCE_TOLERANCE_M}m)."}
                            all_results.append({"tool": tool_name, "result": res_obj})
                            continue
                            
                        # 护栏 2: 最大迭代轮次限制
                        robot_iteration_counts[robot_id] = robot_iteration_counts.get(robot_id, 0) + 1
                        if robot_iteration_counts[robot_id] > MAX_ITERATIONS:
                            abort_task_reason = f"车 {robot_id} 达到最大迭代轮次({MAX_ITERATIONS})，判定为无法收敛"
                            break

                    print(f"[Agent] Calling tool: {tool_name}({tool_args})")
                    if tool_name == "send_move":
                        send_move_call_count += 1
                    try:
                        requests.post("http://127.0.0.1:9001/api/monitor/mcp_log", json={"func": tool_name, "params": tool_args}, timeout=0.5)
                    except Exception:
                        pass
                    res = run_mcp_call(args.server_spec, tool_name, tool_args)
                    res_obj = json.loads(res) if res.startswith("{") else {"result": res}
                    inner_payload = unwrap_tool_payload(res_obj)
                    if tool_name == "list_robots":
                        print_list_robots_runtime_summary(inner_payload)

                    if tool_name == "send_move":
                        inner_message = str(inner_payload.get("message", ""))
                        if not inner_payload.get("success") and is_speed_out_of_bounds_message(inner_message):
                            speed_rejection_seen = True
                            print(f"[Agent] [SECURITY] 越界速度已在适配层拦截: {inner_message}")
                            if user_oob_speed:
                                abort_task_reason = (
                                    "恶意/越界速度指令已被 MCP 适配层拦截（TC-06），任务拒绝执行"
                                )
                                all_results.append({"tool": tool_name, "result": res_obj})
                                break

                    if tool_name == "send_move" and robot_id and inner_payload.get("success"):
                        robot_moved[robot_id] = True
                    
                    # 解析结果进行护栏检查
                    if inner_payload.get("success") and isinstance(inner_payload.get("data"), dict):
                        data = inner_payload["data"]
                        
                        if tool_name == "compute_navigation_hint" and "distance_m" in data and robot_id:
                            robot_last_distance[robot_id] = float(data["distance_m"])
                                
                        # 护栏 3: 位置停滞检测 (仅在尝试过发送移动指令后，获取到新位姿时进行对比)
                        if "current_pose" in data and robot_id:
                            pose = data["current_pose"]
                            if "x" in pose and "y" in pose:
                                current_pos = (float(pose["x"]), float(pose["y"]))
                                if robot_id in robot_last_pose:
                                    if robot_moved.get(robot_id, False):
                                        last_pos = robot_last_pose[robot_id]
                                        move_dist = math.hypot(current_pos[0] - last_pos[0], current_pos[1] - last_pos[1])
                                        if move_dist < STUCK_TOLERANCE_M:
                                            robot_stuck_counts[robot_id] = robot_stuck_counts.get(robot_id, 0) + 1
                                            if robot_stuck_counts[robot_id] >= MAX_STUCK_COUNTS:
                                                abort_task_reason = f"车 {robot_id} 物理卡死或打滑（连续 {MAX_STUCK_COUNTS} 次指令后位移 < {STUCK_TOLERANCE_M}m）"
                                                break
                                        else:
                                            robot_stuck_counts[robot_id] = 0
                                        robot_moved[robot_id] = False
                                robot_last_pose[robot_id] = current_pos

                    all_results.append({
                        "tool": tool_name,
                        "result": res_obj
                    })
                    
                    # 记录最大运动时长，以同步物理世界
                    if (
                        tool_name == "send_move"
                        and inner_payload.get("success")
                        and "duration_ms" in tool_args
                    ):
                        dur = float(tool_args["duration_ms"])
                        if dur > max_duration_ms:
                            max_duration_ms = dur
                            
                # 阻塞等待运动完成，保证下次观测准确
                if max_duration_ms > 0 and not abort_task_reason:
                    # 等待：执行时间 + 物理引擎 settle_s（1.0秒缓冲），维持物理同步
                    wait_s = max_duration_ms / 1000.0 + 1.0
                    print(f"[Agent] [WAIT] Waiting {wait_s:.2f}s for physical movement to complete...")
                    time.sleep(wait_s)
                    
                # 记录 LLM 这一轮发出的工具调用
                messages.append({
                    "role": "assistant", 
                    "content": json.dumps(tool_calls, ensure_ascii=False)
                })
                
                # 如果触发严重硬护栏（死循环、卡死或 TC-06 越界拦截），退出 Agent 循环并如实报告
                if abort_task_reason:
                    if "TC-06" in abort_task_reason:
                        print(f"\n[Agent] Task Rejected: {abort_task_reason}")
                    else:
                        print(f"\n[Agent] [ABORT] 任务已中止：{abort_task_reason}")
                    print("[Agent] 正在获取各车辆最终状态...")
                    final_res = run_mcp_call(args.server_spec, "get_fleet_status", {"robot_ids_csv": ""})
                    print_final_fleet_poses(final_res)
                    break
                    
                # 将观测结果回传给 LLM
                observation = json.dumps(all_results, ensure_ascii=False)
                print(f"[Observation] {observation[:200]}...")
                messages.append({
                    "role": "user",
                    "content": f"Tool Execution Observation:\n{observation}"
                })
                
        except KeyboardInterrupt:
            break
        except Exception as e:
            print(f"[Error] {e}")
            logger.exception("Agent loop error")
            
    print("Bye.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
