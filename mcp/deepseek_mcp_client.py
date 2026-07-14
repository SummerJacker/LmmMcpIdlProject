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
from dataclasses import dataclass, field
from enum import Enum
from typing import Any

import requests

from console_follow_wizard import (
    ConsoleFollowWizardState,
    FollowWizardPhase,
    WizardTurnResult,
    apply_follow_tool_result,
    begin_follow_wizard,
    handle_follow_wizard_input,
)

from config import (
    ANGULAR_VELOCITY_MAX_ABS_RAD_S,
    DEFAULT_TOOL_TIMEOUT_S,
    LINEAR_VELOCITY_MAX_ABS_M_S,
)

logger = logging.getLogger("deepseek_mcp_client")
MCP_PROJECT_ROOT = os.path.dirname(os.path.abspath(__file__))

DEEPSEEK_CHAT_COMPLETIONS_URL = "https://api.deepseek.com/v1/chat/completions"
DEFAULT_DEEPSEEK_API_KEY = ""


def configured_deepseek_api_key() -> str:
    """Return the runtime credential without embedding a repository default."""

    return os.getenv("DEEPSEEK_API_KEY", "").strip()

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
_PRODUCTION_TASK_TOOLS = frozenset({
    "getCapabilities", "getFleetSnapshot", "navigateTo", "followPath",
    "createStaticFormation", "createFollowFormation", "moveFollowFormation",
    "getFormationStatus", "disbandFormation", "getTaskStatus", "cancelTask", "stopUnits",
})
_FORMATION_PLAN_TOOLS = frozenset({"createStaticFormation"})
_FORMATION_ENTRY_RE = re.compile(r"编队|队形|formation", re.IGNORECASE)
_FOLLOW_FORMATION_RE = re.compile(
    r"Console\s*跟随|跟随编队|持续跟随|发送队形|车距|间距|Follower|Leader",
    re.IGNORECASE,
)
_GEOMETRIC_FORMATION_RE = re.compile(
    r"几何编队|几何队形|排成|摆成|三角形|直线排列|沿[xyXY]轴|锚点|边长",
    re.IGNORECASE,
)
GEOMETRIC_FORMATION_TOOLS = frozenset({"createStaticFormation"})
FOLLOW_FORMATION_TOOLS = frozenset(
    {"createFollowFormation", "moveFollowFormation", "getFormationStatus", "disbandFormation"}
)
LEGACY_AMBIGUOUS_FORMATION_TOOLS = frozenset()
AUTO_RECOVERY_TOOLS = frozenset({"cancelTask", "stopUnits", "disbandFormation"})
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


class FormationMode(str, Enum):
    CONSOLE_FOLLOW = "console_follow"
    GEOMETRIC = "geometric"


@dataclass
class FormationDialogState:
    awaiting_mode: bool = False
    mode: FormationMode | None = None
    follow_failure_seen: bool = False
    follow_send_seen_this_turn: bool = False
    declared_follow_spacings_m: list[float] = field(default_factory=list)
    declared_follow_spacings_by_robot: dict[str, list[float]] = field(default_factory=dict)


@dataclass(frozen=True)
class FormationRouteResult:
    prompt_only: bool
    message: str = ""
    mode: FormationMode | None = None


_FORMATION_MODE_MENU = (
    "请选择编队类型：\n"
    "1. Console 跟随编队\n"
    "   设置 Leader、每辆跟随车的间距；后续只控制 Leader 前往目标点。\n\n"
    "2. 几何编队\n"
    "   各车辆分别移动到直线、三角形等几何位置，不建立持续跟随关系。"
)


def route_formation_input(
    user_text: str,
    state: FormationDialogState,
) -> FormationRouteResult:
    """识别编队入口；模糊请求只显示选择菜单，不执行工具。"""

    text = user_text.strip()
    if state.awaiting_mode:
        normalized = text.lower().replace(" ", "")
        if normalized in {"1", "一", "console", "console跟随编队", "跟随编队"}:
            state.awaiting_mode = False
            state.mode = FormationMode.CONSOLE_FOLLOW
            state.follow_failure_seen = False
            state.declared_follow_spacings_m.clear()
            state.declared_follow_spacings_by_robot.clear()
            return FormationRouteResult(
                prompt_only=True,
                message=(
                    "已选择 Console 跟随编队，正在读取在线车辆。"
                ),
                mode=state.mode,
            )
        if normalized in {"2", "二", "几何", "几何编队"}:
            state.awaiting_mode = False
            state.mode = FormationMode.GEOMETRIC
            return FormationRouteResult(
                prompt_only=True,
                message="已选择几何编队。请指定形状、参与车辆以及间距或边长。",
                mode=state.mode,
            )
        return FormationRouteResult(
            prompt_only=True,
            message=f"无法识别该选择。\n{_FORMATION_MODE_MENU}",
            mode=None,
        )

    has_formation_entry = bool(_FORMATION_ENTRY_RE.search(text))
    explicit_follow = bool(_FOLLOW_FORMATION_RE.search(text))
    explicit_geometric = bool(_GEOMETRIC_FORMATION_RE.search(text))

    if state.mode is not None and allowed_recovery_tools(text):
        return FormationRouteResult(prompt_only=False, mode=state.mode)
    if explicit_follow and not explicit_geometric:
        state.mode = FormationMode.CONSOLE_FOLLOW
        return FormationRouteResult(prompt_only=False, mode=state.mode)
    if explicit_geometric and not explicit_follow:
        state.mode = FormationMode.GEOMETRIC
        return FormationRouteResult(prompt_only=False, mode=state.mode)
    if has_formation_entry:
        state.awaiting_mode = True
        state.mode = None
        state.declared_follow_spacings_m.clear()
        state.declared_follow_spacings_by_robot.clear()
        return FormationRouteResult(
            prompt_only=True,
            message=_FORMATION_MODE_MENU,
            mode=None,
        )
    return FormationRouteResult(prompt_only=False, mode=state.mode)


def allowed_formation_tool(tool_name: str, state: FormationDialogState) -> bool:
    if tool_name in LEGACY_AMBIGUOUS_FORMATION_TOOLS:
        return False
    if state.awaiting_mode:
        return tool_name not in GEOMETRIC_FORMATION_TOOLS | FOLLOW_FORMATION_TOOLS
    if state.mode is FormationMode.CONSOLE_FOLLOW:
        return tool_name not in GEOMETRIC_FORMATION_TOOLS
    if state.mode is FormationMode.GEOMETRIC:
        return tool_name not in FOLLOW_FORMATION_TOOLS
    return True


def user_explicitly_requested_recovery(user_text: str) -> bool:
    return bool(allowed_recovery_tools(user_text))


def allowed_recovery_tools(user_text: str) -> set[str]:
    """Authorize only production task-level recovery operations explicitly requested."""

    text = user_text.strip()
    allowed: set[str] = set()
    if re.search(r"重试|再试|重新发送|retry", text, re.IGNORECASE):
        allowed.add("createFollowFormation")
    if re.search(r"取消编队|解散编队|cancel\s+formation|disband", text, re.IGNORECASE):
        allowed.add("disbandFormation")
    if re.search(r"(?:停止|停下|stop|急停)", text, re.IGNORECASE):
        allowed.add("stopUnits")
    if re.search(r"(?:取消任务|cancel\s+task)\s*[A-Za-z0-9_-]+", text, re.IGNORECASE):
        allowed.add("cancelTask")
    return allowed


def recovery_tool_call_is_authorized(
    tool_name: str,
    tool_args: dict[str, Any],
    user_text: str,
) -> bool:
    """校验恢复工具及其关键参数确实对应用户本轮的明确指令。"""

    if tool_name not in allowed_recovery_tools(user_text):
        return False
    if tool_name == "stopUnits":
        requested = {
            item.casefold()
            for item in re.findall(r"(?:GV\d+|AV\d+|robot_\d+)", user_text, re.IGNORECASE)
        }
        outgoing = {
            str(item).casefold() for item in tool_args.get("unit_ids", [])
        }
        return not requested or (bool(outgoing) and outgoing <= requested)
    if tool_name == "cancelTask":
        requested = {
            item.casefold()
            for item in re.findall(r"[A-Za-z]+-[A-Za-z0-9_-]+", user_text, re.IGNORECASE)
        }
        return not requested or str(tool_args.get("task_id", "")).casefold() in requested
    return True


def extract_explicit_follow_spacings(user_text: str) -> list[float]:
    """提取用户明确写出的米制间距；车辆编号和目标坐标不会被当成间距。"""

    values: list[float] = []
    for match in re.finditer(r"(?<![\d.])(\d+(?:\.\d+)?)\s*(?:米|m)(?![a-z/])", user_text, re.IGNORECASE):
        values.append(float(match.group(1)))
    return values


_FOLLOWER_SPACING_BINDING_RE = re.compile(
    r"(?P<robot>(?:GV|AV)\d+|robot_\d+)\s*(?:的\s*)?"
    r"(?:(?:相对前车的?\s*)?(?:间距|车距)|与前车相距)\s*(?:为|是|=|:|：)?\s*"
    r"(?P<value>\d+(?:\.\d+)?)\s*(?:米|m)(?![a-z/])",
    re.IGNORECASE,
)


def record_explicit_follow_spacings(
    user_text: str,
    state: FormationDialogState,
) -> None:
    """记录有间距语义的输入；多车值必须绑定到明确的 Follower。"""

    bound_value_spans: list[tuple[int, int]] = []
    for match in _FOLLOWER_SPACING_BINDING_RE.finditer(user_text):
        robot_id = match.group("robot").casefold()
        state.declared_follow_spacings_by_robot[robot_id] = [float(match.group("value"))]
        bound_value_spans.append(match.span("value"))

    if not re.search(r"间距|车距|两车之间|相距", user_text, re.IGNORECASE):
        return
    unbound_values: list[float] = []
    for match in re.finditer(
        r"(?<![\d.])(\d+(?:\.\d+)?)\s*(?:米|m)(?![a-z/])",
        user_text,
        re.IGNORECASE,
    ):
        value_span = match.span(1)
        if any(start <= value_span[0] and value_span[1] <= end for start, end in bound_value_spans):
            continue
        unbound_values.append(float(match.group(1)))
    if unbound_values:
        state.declared_follow_spacings_m[:] = unbound_values


def follow_spacing_args_are_user_supplied(
    tool_args: dict[str, Any],
    state: FormationDialogState,
) -> bool:
    """要求 createFollowFormation 的每个距离逐一匹配用户明确输入。"""

    request = tool_args.get("request")
    if isinstance(request, dict):
        followers = request.get("followers")
    else:
        try:
            followers = json.loads(str(tool_args.get("followers_json", "")))
        except json.JSONDecodeError:
            return False
    if not isinstance(followers, list) or not followers:
        return False
    outgoing: list[tuple[str, float]] = []
    for item in followers:
        if not isinstance(item, dict):
            return False
        try:
            value = float(item["distance_m"])
        except (KeyError, TypeError, ValueError):
            return False
        robot_id = str(item.get("unit_id", item.get("robot_id", ""))).strip().casefold()
        if not robot_id:
            return False
        outgoing.append((robot_id, value))
    available_unbound = list(state.declared_follow_spacings_m)
    available_bound = {
        robot_id: list(values)
        for robot_id, values in state.declared_follow_spacings_by_robot.items()
    }
    for robot_id, value in outgoing:
        available = available_bound.get(robot_id, [])
        match_index = next(
            (index for index, declared in enumerate(available) if abs(declared - value) <= 1e-9),
            None,
        )
        if match_index is not None:
            available.pop(match_index)
            continue
        if len(outgoing) != 1:
            return False
        unbound_index = next(
            (
                index
                for index, declared in enumerate(available_unbound)
                if abs(declared - value) <= 1e-9
            ),
            None,
        )
        if unbound_index is None:
            return False
        available_unbound.pop(unbound_index)
    return True


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
        "You are an intelligent Robot Fleet Commander connected to the production MCP task API.\n"
        "Use only these task-level tools: getCapabilities, getFleetSnapshot, navigateTo, followPath, "
        "createStaticFormation, createFollowFormation, moveFollowFormation, getFormationStatus, "
        "disbandFormation, getTaskStatus, cancelTask, stopUnits.\n\n"
        "Never call raw movement, role, group-mode, task-point, task-path, trap, or reset tools.\n"
        "navigateTo accepts unit_id plus target={x,y}; final yaw and navigation speed are unsupported.\n"
        "createStaticFormation accepts request={formation_type,unit_ids,spacing_m,anchor,heading_rad,...}; "
        "it places vehicles geometrically and does not create follow relationships.\n"
        "createFollowFormation accepts request={leader_id,followers:[{unit_id,distance_m}]}; require every "
        "follower distance from the user. moveFollowFormation accepts target={x,y} and moves only the leader.\n"
        "Use getTaskStatus for asynchronous tasks. cancelTask reports CANCEL_CONFIRMED, STOP_REQUESTED, or "
        "STATE_ONLY_CANCELLED; never claim immediate physical stop unless the result confirms it.\n"
        "Use getCapabilities before relying on optional real-RPC or follow behavior, and getFleetSnapshot for valid unit IDs.\n\n"
        "=== OUTPUT FORMAT ===\n"
        "- Tool call: {\"tool\": \"tool_name\", \"args\": {\"arg1\": \"value1\"}}\n"
        "- Multiple calls: [{\"tool\": \"...\", \"args\": {...}}, ...]\n"
        "- Task done: {\"done\": true, \"message\": \"...\"}\n"
        "- ONLY output valid JSON. NEVER output markdown or explanations outside JSON."
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
    @param {str} api_key DeepSeek API key
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
    session = requests.Session()
    session.trust_env = False  # bypass system proxy to avoid SSL/proxy errors
    resp = session.post(DEEPSEEK_CHAT_COMPLETIONS_URL, headers=headers, json=payload, timeout=60)
    if resp.status_code >= 400:
        raise RuntimeError(f"API error {resp.status_code}: {resp.text}")

    data = resp.json()
    content = data["choices"][0]["message"]["content"].strip()
    original_content = content
    
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
        if original_content:
            return {"done": True, "message": original_content}
        raise RuntimeError(f"LLM output is not JSON: {content}") from e


def run_mcp_call(server_spec: str, tool: str, args: dict[str, Any]) -> str:
    """
    通过 fastmcp 命令行工具调用本地 MCP 服务。
    
    @param {str} server_spec 服务器入口文件，例如 main.py
    @param {str} tool 调用的工具名
    @param {dict} args 参数字典
    @returns {str} 包含执行结果的 JSON 字符串
    """
    cmd = [
        "fastmcp",
        "call",
        server_spec,
        tool,
        "--json",
        "--input-json",
        json.dumps(args, ensure_ascii=False),
    ]

    logger.info("Executing tool: %s with args %s", tool, args)
    proc = subprocess.run(cmd, capture_output=True, text=True, cwd=MCP_PROJECT_ROOT)
    if proc.returncode != 0:
        diagnostics = "\n".join(
            output.strip()
            for output in (proc.stdout, proc.stderr)
            if output and output.strip()
        )
        if not diagnostics:
            diagnostics = f"process exited with code {proc.returncode}"
        return json.dumps(
            {"success": False, "message": f"fastmcp failed: {diagnostics}"},
            ensure_ascii=False,
        )

    out = proc.stdout.strip()
    first = out.find("{")
    if first < 0:
        return json.dumps({"success": False, "message": f"Cannot parse fastmcp output: {out}"})
    return out[first:]


def normalize_tool_call_args(tool_name: str, args: dict[str, Any]) -> dict[str, Any]:
    """Return production task arguments without legacy alias rewriting."""

    del tool_name
    return dict(args)


def _parse_wizard_tool_payload(raw_result: str) -> dict[str, Any]:
    try:
        parsed = json.loads(raw_result)
    except json.JSONDecodeError:
        return {"success": False, "message": f"Invalid MCP response: {raw_result}"}
    return unwrap_tool_payload(parsed)


def start_console_follow_wizard(
    server_spec: str,
    state: ConsoleFollowWizardState,
) -> WizardTurnResult:
    """Discover vehicles and enter the deterministic Console-follow wizard."""

    state.phase = FollowWizardPhase.DISCOVERING_UNITS
    print("[Agent] Calling tool: getFleetSnapshot({})")
    raw_result = run_mcp_call(server_spec, "getFleetSnapshot", {})
    payload = _parse_wizard_tool_payload(raw_result)
    print_list_robots_runtime_summary(payload)
    return begin_follow_wizard(state, payload)


def run_console_follow_wizard_turn(
    server_spec: str,
    state: ConsoleFollowWizardState,
    user_text: str,
) -> WizardTurnResult:
    """Process one wizard input and execute at most one deterministic MCP call."""

    result = handle_follow_wizard_input(state, user_text)
    if not result.tool_name:
        return result
    print(f"[Agent] Calling tool: {result.tool_name}({result.tool_args})")
    raw_result = run_mcp_call(server_spec, result.tool_name, result.tool_args)
    payload = _parse_wizard_tool_payload(raw_result)
    return apply_follow_tool_result(state, result.tool_name, payload)


def main() -> int:
    """
    入口函数，循环读取用户输入，并跑 Agent Loop。
    
    @returns {int} 退出码
    """
    parser = argparse.ArgumentParser(description="Thin DeepSeek MCP client")
    parser.add_argument("--server-spec", default="main.py", help="MCP server spec, default: main.py")
    parser.add_argument("--model", default="deepseek-v4-flash", help="Model name (deepseek-v4-flash, deepseek-v4-pro)")
    args = parser.parse_args()

    setup_client_logging()
    api_key = configured_deepseek_api_key()
    
    print("Thin DeepSeek MCP Client started. Type 'exit' to quit.")
    
    messages = [{"role": "system", "content": build_system_prompt()}]
    formation_state = FormationDialogState()
    follow_wizard_state = ConsoleFollowWizardState()
    
    while True:
        try:
            user_text = input("\nUser> ").strip()
            if not user_text:
                continue
            if user_text.lower() in {"exit", "quit"}:
                break

            requested_recovery_tools = allowed_recovery_tools(user_text)
            deterministic_follow_retry = (
                follow_wizard_state.formation_send_failed
                and requested_recovery_tools == {"createFollowFormation"}
            )
            explicit_follow_recovery = (
                follow_wizard_state.formation_send_failed
                and bool(requested_recovery_tools)
                and not deterministic_follow_retry
            )
            if (
                follow_wizard_state.phase is not FollowWizardPhase.IDLE
                and not re.search(r"^(?:重新|再次)?进行编队$|^重新编队$", user_text)
                and not explicit_follow_recovery
            ):
                wizard_result = run_console_follow_wizard_turn(
                    args.server_spec,
                    follow_wizard_state,
                    user_text,
                )
                print(f"\n[Agent] {wizard_result.message}")
                if follow_wizard_state.phase is FollowWizardPhase.IDLE:
                    formation_state.mode = None
                    formation_state.follow_failure_seen = False
                continue
            if explicit_follow_recovery:
                formation_state.follow_failure_seen = True
            if follow_wizard_state.phase is not FollowWizardPhase.IDLE:
                if not explicit_follow_recovery:
                    follow_wizard_state = ConsoleFollowWizardState()

            formation_route = route_formation_input(user_text, formation_state)
            if formation_route.prompt_only:
                print(f"\n[Agent] {formation_route.message}")
                messages.append({"role": "user", "content": user_text})
                messages.append({"role": "assistant", "content": formation_route.message})
                if formation_route.mode is FormationMode.CONSOLE_FOLLOW:
                    wizard_result = start_console_follow_wizard(
                        args.server_spec,
                        follow_wizard_state,
                    )
                    print(f"\n[Agent] {wizard_result.message}")
                continue
            if (
                formation_route.mode is FormationMode.CONSOLE_FOLLOW
                and follow_wizard_state.phase is FollowWizardPhase.IDLE
            ):
                wizard_result = start_console_follow_wizard(
                    args.server_spec,
                    follow_wizard_state,
                )
                print(f"\n[Agent] {wizard_result.message}")
                continue
            if formation_state.mode is FormationMode.CONSOLE_FOLLOW:
                record_explicit_follow_spacings(user_text, formation_state)
            formation_state.follow_send_seen_this_turn = False

            messages.append({"role": "user", "content": user_text})
            user_speed_intent = extract_user_speed_intent(user_text)
            user_oob_speed = user_requested_out_of_bounds_speed(user_speed_intent)
            user_point_goals = extract_user_absolute_point_goals(user_text)
            speed_rejection_seen = False
            send_move_call_count = 0
            follow_target_call_count = 0
            
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
                    if user_oob_speed:
                        print(
                            "\n[Agent] Task Rejected: 任务级 navigateTo 不支持导航速度参数，"
                            "未调用低层 send_move，未向车辆下发速度指令"
                        )
                    elif (
                        not (
                            formation_state.mode is FormationMode.CONSOLE_FOLLOW
                            and follow_target_call_count > 0
                        )
                        and is_premature_done_for_point_goals(
                        user_point_goals=user_point_goals,
                        send_move_call_count=send_move_call_count,
                        done_message=str(parsed.get("message", "")),
                        )
                    ):
                        print(
                            "\n[Agent] [GUARDRAIL] 用户指定绝对坐标，但尚未执行 navigateTo，"
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
                                    "Use getFleetSnapshot to resolve IDs, then call navigateTo with "
                                    "target={x,y} for each requested robot and poll getTaskStatus before done."
                                ),
                            }
                        )
                        continue
                    else:
                        print(f"\n[Agent] Task Done: {parsed.get('message', 'OK')}")
                    
                    print("[Agent] 正在获取各车辆最终状态...")
                    final_res = run_mcp_call(args.server_spec, "getFleetSnapshot", {})
                    print_list_robots_runtime_summary(_parse_wizard_tool_payload(final_res))
                        
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
                    if tool_name not in _PRODUCTION_TASK_TOOLS:
                        guard_msg = f"Production MCP rejects non-task tool: {tool_name}"
                        print(f"[Agent] [GUARDRAIL] {guard_msg}")
                        all_results.append({
                            "tool": tool_name,
                            "result": {"success": False, "message": guard_msg, "data": None},
                        })
                        continue
                    try:
                        tool_args = normalize_tool_call_args(tool_name, tool_args)
                    except (TypeError, ValueError) as exc:
                        guard_msg = f"Tool arguments rejected: {exc}"
                        print(f"[Agent] [GUARDRAIL] 工具参数已拒绝: {guard_msg}")
                        all_results.append({
                            "tool": tool_name,
                            "result": {"success": False, "message": guard_msg, "data": None},
                        })
                        continue
                        
                    robot_id = tool_args.get("unit_id") or tool_args.get("robot_id")

                    if not allowed_formation_tool(tool_name, formation_state):
                        guard_msg = f"Cross-mode tool rejected: {tool_name}"
                        print(f"[Agent] [GUARDRAIL] 跨模式工具调用已拒绝: {tool_name}")
                        all_results.append({
                            "tool": tool_name,
                            "result": {"success": False, "message": guard_msg, "data": None},
                        })
                        continue

                    if (
                        tool_name == "createFollowFormation"
                        and not follow_spacing_args_are_user_supplied(tool_args, formation_state)
                    ):
                        guard_msg = "Follow spacing rejected: every distance must come from explicit user input"
                        print("[Agent] [GUARDRAIL] 间距并非来自用户明确输入，已拒绝发送队形")
                        all_results.append({
                            "tool": tool_name,
                            "result": {"success": False, "message": guard_msg, "data": None},
                        })
                        continue

                    recovery_authorized = recovery_tool_call_is_authorized(
                        tool_name,
                        tool_args,
                        user_text,
                    )
                    recovery_forbidden = (
                        formation_state.mode is FormationMode.CONSOLE_FOLLOW
                        and formation_state.follow_failure_seen
                        and (tool_name in AUTO_RECOVERY_TOOLS or tool_name in FOLLOW_FORMATION_TOOLS)
                        and not recovery_authorized
                    )
                    repeated_follow_send = (
                        tool_name == "createFollowFormation"
                        and formation_state.follow_send_seen_this_turn
                        and not recovery_authorized
                    )
                    if recovery_forbidden or repeated_follow_send:
                        guard_msg = f"Automatic recovery rejected after follow formation result: {tool_name}"
                        print(f"[Agent] [GUARDRAIL] 自动恢复已拒绝: {tool_name}")
                        all_results.append({
                            "tool": tool_name,
                            "result": {"success": False, "message": guard_msg, "data": None},
                        })
                        continue

                    if tool_name in _FORMATION_PLAN_TOOLS and user_point_goals:
                        goals_hint = format_point_goals_hint(user_point_goals)
                        guard_msg = (
                            f"Guardrail rejected: {tool_name} does not accept absolute (x,y) goals ({goals_hint}). "
                            "Use navigateTo(unit_id, target={x,y}) for each absolute point goal."
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
                    if tool_name == "navigateTo":
                        send_move_call_count += 1
                    if tool_name == "createFollowFormation":
                        formation_state.follow_send_seen_this_turn = True
                    try:
                        requests.post("http://127.0.0.1:9001/api/monitor/mcp_log", json={"func": tool_name, "params": tool_args}, timeout=0.5)
                    except Exception:
                        pass
                    res = run_mcp_call(args.server_spec, tool_name, tool_args)
                    res_obj = json.loads(res) if res.startswith("{") else {"result": res}
                    inner_payload = unwrap_tool_payload(res_obj)
                    if tool_name == "getFleetSnapshot":
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

                    if tool_name == "createFollowFormation":
                        formation_state.follow_failure_seen = not bool(inner_payload.get("success"))
                    if tool_name == "moveFollowFormation" and inner_payload.get("success"):
                        follow_target_call_count += 1

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
                    final_res = run_mcp_call(args.server_spec, "getFleetSnapshot", {})
                    print_list_robots_runtime_summary(_parse_wizard_tool_payload(final_res))
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
