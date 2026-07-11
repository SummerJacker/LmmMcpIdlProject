"""Deterministic conversational state for Console follow formation."""

from __future__ import annotations

from dataclasses import dataclass, field
from enum import Enum
import json
import math
import re
from typing import Any


class FollowWizardPhase(str, Enum):
    IDLE = "idle"
    DISCOVERING_UNITS = "discovering_units"
    AWAITING_LEADER = "awaiting_leader"
    AWAITING_FOLLOWER_ORDER = "awaiting_follower_order"
    AWAITING_SPACING = "awaiting_spacing"
    AWAITING_SEND_CONFIRMATION = "awaiting_send_confirmation"
    READY_FOR_TARGET = "ready_for_target"


@dataclass
class ConsoleFollowWizardState:
    phase: FollowWizardPhase = FollowWizardPhase.IDLE
    unit_ids: list[str] = field(default_factory=list)
    aliases: dict[str, str] = field(default_factory=dict)
    leader_id: str | None = None
    follower_ids: list[str] = field(default_factory=list)
    spacings_m: dict[str, float] = field(default_factory=dict)
    formation_ready: bool = False
    formation_send_failed: bool = False


@dataclass(frozen=True)
class WizardTurnResult:
    handled: bool = True
    message: str = ""
    tool_name: str | None = None
    tool_args: dict[str, Any] = field(default_factory=dict)


def begin_follow_wizard(
    state: ConsoleFollowWizardState,
    payload: dict[str, Any],
) -> WizardTurnResult:
    """Populate the wizard from a normalized list_robots payload."""

    state.phase = FollowWizardPhase.DISCOVERING_UNITS
    state.unit_ids.clear()
    state.aliases.clear()
    state.leader_id = None
    state.follower_ids.clear()
    state.spacings_m.clear()
    state.formation_ready = False
    state.formation_send_failed = False

    if payload.get("success") is not True:
        state.phase = FollowWizardPhase.IDLE
        return WizardTurnResult(message=f"读取车辆失败：{payload.get('message', 'unknown error')}")

    data = payload.get("data")
    units = data.get("units", []) if isinstance(data, dict) else []
    for unit in units:
        if not isinstance(unit, dict):
            continue
        if "online" in unit and unit.get("online") is not True:
            continue
        unit_id = str(unit.get("unit_id", "")).strip()
        if not unit_id.upper().startswith("GV"):
            continue
        state.unit_ids.append(unit_id)
        state.aliases[unit_id.casefold()] = unit_id
        robot_id = str(unit.get("robot_id", "")).strip()
        if robot_id:
            state.aliases[robot_id.casefold()] = unit_id

    if len(state.unit_ids) < 2:
        state.phase = FollowWizardPhase.IDLE
        return WizardTurnResult(message="Console 跟随编队至少需要两辆在线地面车辆。")

    state.phase = FollowWizardPhase.AWAITING_LEADER
    choices = "、".join(state.unit_ids)
    return WizardTurnResult(message=f"发现在线地面车辆：{choices}。请选择 Leader。")


def handle_follow_wizard_input(
    state: ConsoleFollowWizardState,
    user_text: str,
) -> WizardTurnResult:
    """Handle one user turn for the current deterministic wizard phase."""

    if state.phase is FollowWizardPhase.AWAITING_FOLLOWER_ORDER:
        return _handle_follower_order(state, user_text)
    if state.phase is FollowWizardPhase.AWAITING_SPACING:
        return _handle_spacing(state, user_text)
    if state.phase is FollowWizardPhase.AWAITING_SEND_CONFIRMATION:
        return _handle_send_confirmation(state, user_text)
    if state.phase is FollowWizardPhase.READY_FOR_TARGET:
        return _handle_target(state, user_text)
    if state.phase is not FollowWizardPhase.AWAITING_LEADER:
        return WizardTurnResult(handled=False)

    leader_id = state.aliases.get(user_text.strip().casefold())
    if leader_id is None:
        choices = "、".join(state.unit_ids)
        return WizardTurnResult(message=f"无法识别该 Leader，请从以下车辆中选择：{choices}。")

    state.leader_id = leader_id
    state.follower_ids = [unit_id for unit_id in state.unit_ids if unit_id != leader_id]
    state.spacings_m.clear()
    state.formation_ready = False
    state.formation_send_failed = False
    return WizardTurnResult(
        message=f"正在将 {leader_id} 设置为 Leader。",
        tool_name="set_leader",
        tool_args={"robot_id": leader_id},
    )


def apply_follow_tool_result(
    state: ConsoleFollowWizardState,
    tool_name: str,
    payload: dict[str, Any],
) -> WizardTurnResult:
    """Advance wizard state after a deterministic MCP tool call."""

    success = payload.get("success") is True
    message = str(payload.get("message", ""))
    if tool_name == "set_leader" and not success:
        state.phase = FollowWizardPhase.AWAITING_LEADER
        return WizardTurnResult(message=f"Leader 设置失败：{message or 'unknown error'}")
    if tool_name == "set_leader":
        if len(state.follower_ids) == 1:
            state.phase = FollowWizardPhase.AWAITING_SPACING
            return WizardTurnResult(
                message=(
                    f"{state.leader_id} 已设为 Leader，{state.follower_ids[0]} 自动作为 Follower。"
                    "请输入间距，例如 0.5。"
                )
            )
        state.phase = FollowWizardPhase.AWAITING_FOLLOWER_ORDER
        choices = "、".join(state.follower_ids)
        return WizardTurnResult(message=f"Leader 设置成功。请按跟随顺序输入：{choices}。")
    if tool_name == "send_follow_formation" and not success:
        state.phase = FollowWizardPhase.AWAITING_SEND_CONFIRMATION
        state.formation_ready = False
        state.formation_send_failed = True
        return WizardTurnResult(message=f"队形发送失败：{message or 'unknown error'}")
    if tool_name == "send_follow_formation":
        state.phase = FollowWizardPhase.READY_FOR_TARGET
        state.formation_ready = True
        state.formation_send_failed = False
        details: list[str] = []
        data = payload.get("data")
        followers = data.get("followers", []) if isinstance(data, dict) else []
        if isinstance(followers, list):
            for follower in followers:
                if not isinstance(follower, dict):
                    continue
                unit_id = str(follower.get("unit_id", "Follower"))
                requested = follower.get("requested_distance_m")
                effective = follower.get("effective_distance_m")
                if requested is not None and effective is not None:
                    details.append(f"{unit_id}: 请求 {requested:g} 米，实际 {effective:g} 米")
        spacing_message = f"（{'；'.join(details)}）" if details else ""
        return WizardTurnResult(
            message=f"队形发送成功{spacing_message}。请输入目标点，例如 (5,6)。"
        )
    if tool_name == "goto_follow_formation":
        if success:
            return WizardTurnResult(message="目标点已发送给当前 Leader。")
        return WizardTurnResult(message=f"目标点发送失败：{message or 'unknown error'}")
    raise ValueError(f"unsupported wizard tool result: {tool_name}")


def _handle_follower_order(
    state: ConsoleFollowWizardState,
    user_text: str,
) -> WizardTurnResult:
    tokens = [token for token in re.split(r"[,，;；\s]+", user_text.strip()) if token]
    resolved = [state.aliases.get(token.casefold()) for token in tokens]
    expected = set(state.follower_ids)
    if (
        not tokens
        or any(unit_id is None for unit_id in resolved)
        or len(set(resolved)) != len(resolved)
        or set(resolved) != expected
    ):
        choices = "、".join(state.follower_ids)
        return WizardTurnResult(message=f"Follower 顺序无效，请完整且不重复地排列：{choices}。")
    state.follower_ids = [unit_id for unit_id in resolved if unit_id is not None]
    state.phase = FollowWizardPhase.AWAITING_SPACING
    return WizardTurnResult(
        message="Follower 顺序已记录。请输入统一间距，或分别指定每辆 Follower 的间距。"
    )


_BARE_DISTANCE_RE = re.compile(r"^\s*(\d+(?:\.\d+)?)\s*(?:米|m)?\s*$", re.IGNORECASE)
_UNIFORM_DISTANCE_RE = re.compile(
    r"(?:都|全部|每(?:辆|架)|统一).*?(\d+(?:\.\d+)?)\s*(?:米|m)?",
    re.IGNORECASE,
)
_BOUND_DISTANCE_RE = re.compile(
    r"((?:GV|AV)\d+|robot_\d+)\D{0,12}?(\d+(?:\.\d+)?)\s*(?:米|m)",
    re.IGNORECASE,
)
_ANY_DISTANCE_RE = re.compile(r"(\d+(?:\.\d+)?)\s*(?:米|m)?", re.IGNORECASE)


def _valid_distance(value: float) -> bool:
    return math.isfinite(value) and value > 0.0


def _handle_spacing(
    state: ConsoleFollowWizardState,
    user_text: str,
) -> WizardTurnResult:
    values: dict[str, float] = {}
    bare_match = _BARE_DISTANCE_RE.fullmatch(user_text)
    uniform_match = _UNIFORM_DISTANCE_RE.search(user_text)
    bound_matches = list(_BOUND_DISTANCE_RE.finditer(user_text))
    bound_values: dict[str, float] = {}
    binding_invalid = False
    for match in bound_matches:
        raw_id = match.group(1)
        follower_id = state.aliases.get(raw_id.casefold(), raw_id.upper())
        if follower_id not in state.follower_ids or follower_id in bound_values:
            binding_invalid = True
            continue
        bound_values[follower_id] = float(match.group(2))

    if len(state.follower_ids) == 1:
        if bound_matches:
            if not binding_invalid and set(bound_values) == set(state.follower_ids):
                values = bound_values
        else:
            match = bare_match or uniform_match or _ANY_DISTANCE_RE.search(user_text)
            if match:
                values[state.follower_ids[0]] = float(match.group(1))
    elif uniform_match and not bound_matches:
        uniform_value = float(uniform_match.group(1))
        values = {follower_id: uniform_value for follower_id in state.follower_ids}
    elif not bare_match and not binding_invalid:
        values = bound_values

    if set(values) != set(state.follower_ids) or any(
        not _valid_distance(value) for value in values.values()
    ):
        return WizardTurnResult(
            message="间距无效：单辆 Follower 可输入 0.5；多辆请说明统一间距或分别绑定车辆。"
        )

    state.spacings_m = values
    state.phase = FollowWizardPhase.AWAITING_SEND_CONFIRMATION
    summary = "，".join(
        f"{follower_id}={state.spacings_m[follower_id]:g}米"
        for follower_id in state.follower_ids
    )
    return WizardTurnResult(
        message=f"已记录：Leader={state.leader_id}，{summary}。输入“发送队形”确认。"
    )


_SEND_CONFIRMATIONS = frozenset({
    "发送",
    "发送队形",
    "确认",
    "是",
    "yes",
    "重试发送队形",
    "重新发送队形",
})


def _handle_send_confirmation(
    state: ConsoleFollowWizardState,
    user_text: str,
) -> WizardTurnResult:
    normalized = user_text.strip().casefold().replace(" ", "")
    if re.search(r"取消|退出|放弃|cancel", normalized, re.IGNORECASE):
        state.phase = FollowWizardPhase.IDLE
        state.leader_id = None
        state.follower_ids.clear()
        state.spacings_m.clear()
        state.formation_ready = False
        state.formation_send_failed = False
        return WizardTurnResult(message="已取消本次 Console 跟随编队设置。")
    if re.search(r"(?:重新|更换|修改|重选).*leader|leader.*(?:重新|更换|修改|重选)", normalized, re.IGNORECASE):
        state.phase = FollowWizardPhase.AWAITING_LEADER
        state.leader_id = None
        state.follower_ids.clear()
        state.spacings_m.clear()
        state.formation_ready = False
        state.formation_send_failed = False
        choices = "、".join(state.unit_ids)
        return WizardTurnResult(message=f"请重新选择 Leader：{choices}。")
    if normalized not in _SEND_CONFIRMATIONS:
        edited = _handle_spacing(state, user_text)
        if state.phase is FollowWizardPhase.AWAITING_SEND_CONFIRMATION and state.spacings_m:
            return edited
        state.phase = FollowWizardPhase.AWAITING_SEND_CONFIRMATION
        return WizardTurnResult(message="队形尚未发送。请输入“发送队形”确认，或重新输入间距。")
    followers_payload = [
        {"robot_id": follower_id, "distance_m": state.spacings_m[follower_id]}
        for follower_id in state.follower_ids
    ]
    return WizardTurnResult(
        message="正在发送 Console 跟随队形。",
        tool_name="send_follow_formation",
        tool_args={
            "leader_id": state.leader_id,
            "followers_json": json.dumps(
                followers_payload,
                ensure_ascii=False,
                separators=(",", ":"),
            ),
        },
    )


_TARGET_RE = re.compile(
    r"\(?\s*(-?\d+(?:\.\d+)?)\s*[,，]\s*(-?\d+(?:\.\d+)?)\s*\)?"
)


def _handle_target(
    state: ConsoleFollowWizardState,
    user_text: str,
) -> WizardTurnResult:
    numeric_tokens = re.findall(r"(?<![A-Za-z_])[-+]?\d+(?:\.\d+)?", user_text)
    match = _TARGET_RE.search(user_text)
    if not match or len(numeric_tokens) != 2:
        return WizardTurnResult(message="目标点格式无效，请输入例如 (5,6)。")
    x, y = float(match.group(1)), float(match.group(2))
    if not math.isfinite(x) or not math.isfinite(y):
        return WizardTurnResult(message="目标点必须是有限数值，请重新输入。")
    return WizardTurnResult(
        message=f"正在将目标点 ({x:g},{y:g}) 发送给 Leader。",
        tool_name="goto_follow_formation",
        tool_args={"x": x, "y": y},
    )
