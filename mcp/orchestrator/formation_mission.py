"""
FormationMissionOrchestrator: 编队任务编排器。

负责将"进行集群编队"这一句自然语言指令转换成完整的 Console 操作流程:

    CHECK_FLEET → SELECT_LEADER → SET_LEADER → SET_FOLLOWERS
    → SET_FORMATION → VERIFY → READY

编队建立后，后续移动只控制领航者 (leader)，跟随者由 Console 原有编队逻辑自动协同。

失败时自动回滚已执行步骤。
"""

from __future__ import annotations

import asyncio
import json
import math
import time
import uuid
from dataclasses import dataclass, field
from enum import Enum
from typing import Any, Callable, Awaitable

from orchestrator.task_manager import (
    TaskManager, TaskState, SubStepState, task_manager,
)
from orchestrator.active_formation import (
    ActiveFormation, FormationState, active_formation_registry,
)


# =============================================================================
# 编队任务状态机（内部编排器状态，比 MCP 层 TaskState 更细粒度）
# =============================================================================

class FormationMissionState(str, Enum):
    """编队任务编排器内部状态"""
    IDLE = "IDLE"
    CHECKING_FLEET = "CHECKING_FLEET"        # 查询集群状态
    SELECTING_LEADER = "SELECTING_LEADER"     # 自动选择领航者
    SETTING_LEADER = "SETTING_LEADER"         # 设置领航者到 Console
    SETTING_FOLLOWERS = "SETTING_FOLLOWERS"   # 设置跟随者关系
    SETTING_FORMATION = "SETTING_FORMATION"   # 下发队形参数
    VERIFYING = "VERIFYING"                   # 验证编队建立成功
    READY = "READY"                           # 编队就绪
    MOVING = "MOVING"                         # 编队移动中

    # 失败状态
    FAILED_NO_ENOUGH_UNITS = "FAILED_NO_ENOUGH_UNITS"
    FAILED_UNIT_OFFLINE = "FAILED_UNIT_OFFLINE"
    FAILED_LEADER_SET_FAILED = "FAILED_LEADER_SET_FAILED"
    FAILED_FOLLOWER_SET_FAILED = "FAILED_FOLLOWER_SET_FAILED"
    FAILED_FORMATION_SET_FAILED = "FAILED_FORMATION_SET_FAILED"
    FAILED_VERIFY_TIMEOUT = "FAILED_VERIFY_TIMEOUT"
    FAILED_INTERNAL_ERROR = "FAILED_INTERNAL_ERROR"
    CANCELLED = "CANCELLED"

    @property
    def is_terminal(self) -> bool:
        """是否为终态"""
        return self in (
            FormationMissionState.READY,
            FormationMissionState.FAILED_NO_ENOUGH_UNITS,
            FormationMissionState.FAILED_UNIT_OFFLINE,
            FormationMissionState.FAILED_LEADER_SET_FAILED,
            FormationMissionState.FAILED_FOLLOWER_SET_FAILED,
            FormationMissionState.FAILED_FORMATION_SET_FAILED,
            FormationMissionState.FAILED_VERIFY_TIMEOUT,
            FormationMissionState.FAILED_INTERNAL_ERROR,
            FormationMissionState.CANCELLED,
        )

    @property
    def is_failed(self) -> bool:
        """是否为失败状态"""
        return self.value.startswith("FAILED")


# =============================================================================
# 编队任务执行结果
# =============================================================================

@dataclass
class FormationMissionResult:
    """编队任务执行结果"""
    success: bool
    task_id: str = ""
    formation_id: str = ""
    state: str = ""
    leader_id: str = ""
    follower_ids: list[str] = field(default_factory=list)
    formation_type: str = ""
    message: str = ""
    error_code: str = ""
    failed_step: str = ""
    failed_unit: str = ""
    details: dict[str, Any] = field(default_factory=dict)

    def to_json(self) -> str:
        return json.dumps({
            "success": self.success,
            "task_id": self.task_id,
            "formation_id": self.formation_id,
            "state": self.state,
            "leader_id": self.leader_id,
            "follower_ids": self.follower_ids,
            "formation_type": self.formation_type,
            "message": self.message,
            "error_code": self.error_code,
            "failed_step": self.failed_step,
            "failed_unit": self.failed_unit,
            "data": self.details,
        }, ensure_ascii=False)


# =============================================================================
# 编队任务编排器
# =============================================================================

class FormationMissionOrchestrator:
    """
    编队任务编排器。

    将用户自然语言（经 LLM 解析为 formation_type + unit_ids）翻译为
    完整的 Console 编队操作序列。

    使用方式:
        orchestrator = FormationMissionOrchestrator(adapter_call)
        result = await orchestrator.execute(
            formation_type="triangle",
            unit_ids=["GV1", "GV2", "GV3"],
            spacing_m=1.0,
        )
    """

    # 编队所需最少智能体数
    MIN_UNITS: dict[str, int] = {
        "line": 2,
        "triangle": 3,
        "column": 2,
    }

    # 子步骤定义 (step_name, description)
    SUB_STEPS: list[tuple[str, str]] = [
        ("check_fleet", "查询集群状态，确认可用智能体"),
        ("select_leader", "自动选择最适合的领航者"),
        ("set_leader", "设置领航者为指定智能体"),
        ("set_followers", "设置跟随者关系"),
        ("set_formation", "下发队形参数到 Console"),
        ("verify", "验证编队建立成功"),
    ]

    def __init__(
        self,
        adapter_call: Callable[..., Awaitable[str]],
    ) -> None:
        """
        @param adapter_call: RobotAdapter 的方法引用，用于调用底层 Console。
                             签名: async def(op_name: str, **kwargs) -> str (JSON)
        """
        self._call = adapter_call
        self._current: FormationMissionState = FormationMissionState.IDLE
        self._result: FormationMissionResult | None = None
        self._cancel_requested: bool = False

    # ------------------------------------------------------------------
    # 主入口
    # ------------------------------------------------------------------

    async def execute(
        self,
        formation_type: str,
        unit_ids: list[str] | None = None,
        leader_id: str | None = None,
        spacing_m: float = 1.0,
        heading_rad: float = 0.0,
        tolerance_m: float = 0.15,
        timeout_ms: int = 30000,
    ) -> FormationMissionResult:
        """
        执行完整编队任务流程。

        @param formation_type: 编队类型 (line/triangle/column)
        @param unit_ids:   参与智能体 unit_id 列表，None 表示自动获取全部在线
        @param leader_id:  指定领航者，None 表示自动选择
        @param spacing_m:  间距（米）
        @param heading_rad: 编队朝向（弧度）
        @param tolerance_m: 到达容差
        @param timeout_ms:  超时
        @returns: FormationMissionResult
        """
        self._cancel_requested = False
        ftype = formation_type.strip().lower()

        # 1. 在 TaskManager 中创建任务
        task_rec = task_manager.create_task(
            task_type="formation_mission",
            sub_step_names=self.SUB_STEPS,
        )
        task_manager.start_task(task_rec.task_id)

        # 2. 创建 ActiveFormation 记录
        formation = ActiveFormation(
            formation_id=f"fm_{uuid.uuid4().hex[:8]}",
            formation_type=ftype,
            leader_id="",  # 待确定
            follower_ids=[],
            state=FormationState.IDLE,
            spacing_m=spacing_m,
            heading_rad=heading_rad,
            task_id=task_rec.task_id,
        )
        active_formation_registry.register(formation)

        # 3. 执行状态机流程
        try:
            result = await self._run_state_machine(
                task_rec.task_id,
                ftype=ftype,
                unit_ids=unit_ids,
                leader_id=leader_id,
                spacing_m=spacing_m,
                heading_rad=heading_rad,
                tolerance_m=tolerance_m,
                timeout_ms=timeout_ms,
            )
            task_manager.complete_task(task_rec.task_id, result.message)
            return result
        except _OrchestratorError as oe:
            # 编排器内部流程错误：保留原始状态和失败步骤信息
            task_manager.fail_task(task_rec.task_id, oe.state.value, oe.message)
            return FormationMissionResult(
                success=False,
                task_id=task_rec.task_id,
                formation_id=formation.formation_id,
                state=oe.state.value,
                formation_type=ftype,
                message=oe.message,
                error_code=oe.state.value,
                failed_step=oe.failed_step,
                failed_unit=oe.failed_unit,
            )
        except Exception as exc:
            error_msg = f"Formation orchestrator internal error: {exc}"
            task_manager.fail_task(task_rec.task_id, "FAILED_INTERNAL_ERROR", error_msg)
            active_formation_registry.set_error(error_msg, "internal", "")
            return FormationMissionResult(
                success=False,
                task_id=task_rec.task_id,
                formation_id=formation.formation_id,
                state=FormationMissionState.FAILED_INTERNAL_ERROR.value,
                formation_type=ftype,
                message=error_msg,
                error_code="FAILED_INTERNAL_ERROR",
            )

    # ------------------------------------------------------------------
    # 状态机驱动
    # ------------------------------------------------------------------

    async def _run_state_machine(
        self,
        task_id: str,
        ftype: str,
        unit_ids: list[str] | None,
        leader_id: str | None,
        spacing_m: float,
        heading_rad: float,
        tolerance_m: float,
        timeout_ms: int,
    ) -> FormationMissionResult:
        """按状态机顺序推进"""

        # ── Step 1: CHECK_FLEET ──
        if self._cancel_requested:
            return await self._handle_cancel(task_id, ftype)
        await self._check_fleet(task_id, unit_ids)
        resolved_ids = active_formation_registry.active.follower_ids  # 此时已暂存

        # ── Step 2: SELECT_LEADER ──
        if self._cancel_requested:
            return await self._handle_cancel(task_id, ftype)
        chosen_leader = await self._select_leader(task_id, resolved_ids, leader_id)

        # ── Step 3: SET_LEADER ──
        if self._cancel_requested:
            return await self._handle_cancel(task_id, ftype)
        await self._set_leader(task_id, chosen_leader)

        # ── Step 4: SET_FOLLOWERS ──
        if self._cancel_requested:
            return await self._handle_rollback_and_cancel(task_id, ftype, chosen_leader, resolved_ids)
        followers = [u for u in resolved_ids if u != chosen_leader]
        await self._set_followers(task_id, chosen_leader, followers)

        # ── Step 5: SET_FORMATION ──
        if self._cancel_requested:
            return await self._handle_rollback_and_cancel(task_id, ftype, chosen_leader, resolved_ids)
        await self._set_formation_params(task_id, ftype, chosen_leader, followers, spacing_m, heading_rad, tolerance_m, timeout_ms)

        # ── Step 6: VERIFY ──
        if self._cancel_requested:
            return await self._handle_rollback_and_cancel(task_id, ftype, chosen_leader, resolved_ids)
        await self._verify_formation(task_id, chosen_leader, followers)

        # ── SUCCESS ──
        formation = active_formation_registry.active
        formation.state = FormationState.READY
        formation.leader_id = chosen_leader
        formation.follower_ids = followers
        formation.updated_at = time.time()

        self._current = FormationMissionState.READY
        task_manager.set_result_data(task_id, {
            "leader_id": chosen_leader,
            "follower_ids": followers,
            "formation_type": ftype,
            "hint": f"编队已建立，后续移动请使用 move_active_formation 控制领航者 {chosen_leader}",
        })

        return FormationMissionResult(
            success=True,
            task_id=task_id,
            formation_id=formation.formation_id,
            state=FormationMissionState.READY.value,
            leader_id=chosen_leader,
            follower_ids=followers,
            formation_type=ftype,
            message=f"{ftype} 编队已建立: leader={chosen_leader}, followers={followers}",
        )

    # ------------------------------------------------------------------
    # Step 1: 查询集群状态
    # ------------------------------------------------------------------

    async def _check_fleet(
        self, task_id: str, unit_ids: list[str] | None,
    ) -> None:
        """检查集群中可用智能体的数量和状态"""
        self._current = FormationMissionState.CHECKING_FLEET
        active_formation_registry.update_state(FormationState.CHECKING_FLEET)
        task_manager.start_sub_step(task_id, "check_fleet")

        # 获取所有在线 unit
        resp = await self._call("get_fleet_status", robot_ids_csv="")
        data = json.loads(resp)

        available_units: list[str] = []
        if data.get("success") and data.get("data"):
            items = data["data"].get("items", [])
            for item in items:
                if item.get("success"):
                    inner = item.get("data") or {}
                    uid = inner.get("unit_id", "")
                    if uid:
                        available_units.append(uid)

        # 如果传入了 unit_ids，取交集
        if unit_ids:
            specified = [u.strip() for u in unit_ids if u.strip()]
            resolved = [u for u in specified if u in available_units]
            missing = [u for u in specified if u not in available_units]
            if missing:
                msg = f"部分指定智能体不在线或不存在: {missing}"
                task_manager.fail_sub_step(task_id, "check_fleet", msg)
                active_formation_registry.set_error(msg, "check_fleet", missing[0])
                raise _OrchestratorError(
                    FormationMissionState.FAILED_UNIT_OFFLINE,
                    msg, "check_fleet", missing[0],
                )
            available_units = resolved

        # 暂存到 active formation（leader 待选）
        formation = active_formation_registry.active
        formation.follower_ids = available_units  # 暂存，选完 leader 后移除

        min_required = self.MIN_UNITS.get(
            active_formation_registry.active.formation_type, 2
        )
        if len(available_units) < min_required:
            msg = (
                f"可用智能体数量不足: 需要至少 {min_required} 台，"
                f"当前 {len(available_units)} 台 ({available_units})"
            )
            task_manager.fail_sub_step(task_id, "check_fleet", msg)
            active_formation_registry.set_error(msg, "check_fleet", "")
            raise _OrchestratorError(
                FormationMissionState.FAILED_NO_ENOUGH_UNITS,
                msg, "check_fleet", "",
            )

        task_manager.complete_sub_step(task_id, "check_fleet")

    # ------------------------------------------------------------------
    # Step 2: 自动选择领航者
    # ------------------------------------------------------------------

    async def _select_leader(
        self, task_id: str, unit_ids: list[str], specified_leader: str | None,
    ) -> str:
        """
        选择领航者:
        1. 如果用户指定了 leader_id，直接使用
        2. 否则自动选择（按编号最小 / 电量最高 / 位姿最靠前）
        """
        self._current = FormationMissionState.SELECTING_LEADER
        active_formation_registry.update_state(FormationState.SELECTING_LEADER)
        task_manager.start_sub_step(task_id, "select_leader")

        if specified_leader and specified_leader.strip() in unit_ids:
            leader = specified_leader.strip()
            task_manager.skip_sub_step(
                task_id, "select_leader",
                f"使用用户指定的领航者: {leader}"
            )
            return leader

        # 自动选择：查询每个 unit 的状态，选择最合适的
        best_leader = unit_ids[0]  # 默认第一个
        best_score = -1.0

        for uid in unit_ids:
            resp = await self._call("get_robot_status", robot_id=uid)
            try:
                sdata = json.loads(resp)
            except json.JSONDecodeError:
                continue

            if not sdata.get("success"):
                continue

            inner = sdata.get("data") or {}
            score = self._compute_leader_score(inner)
            if score > best_score:
                best_score = score
                best_leader = uid

        task_manager.complete_sub_step(task_id, "select_leader")
        return best_leader

    def _compute_leader_score(self, unit_data: dict) -> float:
        """
        计算智能体作为领航者的评分。

        评估因子：
        - 在线状态 (online → +100)
        - 电量 (越高越好，0-100)
        - 位姿数据正常 (有 x,y → +50)
        - 当前无任务 (no active mission → +30)
        - 通信延迟低 (latency < 100ms → +20)
        """
        score = 0.0

        # 在线
        if unit_data.get("online", False) or unit_data.get("unit_id"):
            score += 100.0

        # 电量
        battery = float(unit_data.get("battery", unit_data.get("battery_pct", 50)))
        score += min(battery, 100.0)

        # 位姿
        pose = unit_data.get("pose") or {}
        if isinstance(pose.get("x"), (int, float)) and isinstance(pose.get("y"), (int, float)):
            score += 50.0

        # 任务状态
        task_active = unit_data.get("task_active", unit_data.get("mission_active", False))
        if not task_active:
            score += 30.0

        # 通信延迟
        latency = float(unit_data.get("latency_ms", unit_data.get("delay_ms", 999)))
        if latency < 100:
            score += 20.0

        return score

    # ------------------------------------------------------------------
    # Step 3: 设置领航者
    # ------------------------------------------------------------------

    async def _set_leader(self, task_id: str, leader_id: str) -> None:
        """调用 Console set_leader API"""
        self._current = FormationMissionState.SETTING_LEADER
        active_formation_registry.update_state(FormationState.SETTING_LEADER)
        task_manager.start_sub_step(task_id, "set_leader")

        resp = await self._call("set_leader", robot_id=leader_id)
        data = json.loads(resp)

        if not data.get("success"):
            msg = f"设置领航者 {leader_id} 失败: {data.get('message', '未知错误')}"
            task_manager.fail_sub_step(task_id, "set_leader", msg)
            active_formation_registry.set_error(msg, "set_leader", leader_id)
            raise _OrchestratorError(
                FormationMissionState.FAILED_LEADER_SET_FAILED,
                msg, "set_leader", leader_id,
            )

        # 记录回滚操作
        task_manager.push_rollback(task_id, f"clear_leader:{leader_id}")

        # 更新 active formation
        active_formation_registry.active.leader_id = leader_id
        task_manager.complete_sub_step(task_id, "set_leader")

    # ------------------------------------------------------------------
    # Step 4: 设置跟随者关系
    # ------------------------------------------------------------------

    async def _set_followers(
        self, task_id: str, leader_id: str, follower_ids: list[str],
    ) -> None:
        """为每个跟随者设置跟随关系"""
        self._current = FormationMissionState.SETTING_FOLLOWERS
        active_formation_registry.update_state(FormationState.SETTING_FOLLOWERS)
        task_manager.start_sub_step(task_id, "set_followers")

        # 设置编队模式为 follow
        # 注意：Console 的 setToLeader() (在 Step 3 已调用) 已遍历所有单元
        # 将非 leader 单元设为 follower 角色。这里只需激活编队模式。
        # 不需要再对每个 follower 调 set_leader —— 那会覆盖 currentLeaderUID！
        resp = await self._call("set_group_mode", mode="follow")
        try:
            data = json.loads(resp)
            if not data.get("success"):
                msg = f"设置编队模式失败: {data.get('message', '未知')}"
                task_manager.fail_sub_step(task_id, "set_followers", msg)
                active_formation_registry.set_error(msg, "set_followers", "")
                raise _OrchestratorError(
                    FormationMissionState.FAILED_FOLLOWER_SET_FAILED,
                    msg, "set_followers", "",
                )
        except json.JSONDecodeError:
            pass  # 非 JSON 响应时忽略，后续 verify 会发现问题

        # 记录回滚操作
        task_manager.push_rollback(task_id, "reset_unit_relations")

        active_formation_registry.active.follower_ids = follower_ids
        task_manager.complete_sub_step(task_id, "set_followers")

    # ------------------------------------------------------------------
    # Step 5: 下发队形参数
    # ------------------------------------------------------------------

    async def _set_formation_params(
        self,
        task_id: str,
        ftype: str,
        leader_id: str,
        follower_ids: list[str],
        spacing_m: float,
        heading_rad: float,
        tolerance_m: float,
        timeout_ms: int,
    ) -> None:
        """下发队形参数到 Console（通过 execute_formation API）"""
        self._current = FormationMissionState.SETTING_FORMATION
        active_formation_registry.update_state(FormationState.SETTING_FORMATION)
        task_manager.start_sub_step(task_id, "set_formation")

        all_units = [leader_id] + follower_ids
        unit_csv = ",".join(all_units)

        resp = await self._call(
            "execute_formation",
            formation_type=ftype,
            unit_ids_csv=unit_csv,
            spacing_m=spacing_m,
            heading_rad=heading_rad,
            tolerance_m=tolerance_m,
            timeout_ms=timeout_ms,
        )
        data = json.loads(resp)

        if not data.get("success"):
            msg = f"下发队形参数失败: {data.get('message', '未知错误')}"
            task_manager.fail_sub_step(task_id, "set_formation", msg)
            active_formation_registry.set_error(msg, "set_formation", "")
            raise _OrchestratorError(
                FormationMissionState.FAILED_FORMATION_SET_FAILED,
                msg, "set_formation", "",
            )

        # 记录回滚
        task_manager.push_rollback(task_id, "reset_unit_relations")

        # 保存 formation_task_id（如果 Console 返回了异步 task_id）
        formation_task_id = (data.get("data") or {}).get("task_id", "")
        if formation_task_id:
            task_manager.set_result_data(task_id, {"formation_task_id": formation_task_id})

        task_manager.complete_sub_step(task_id, "set_formation")

    # ------------------------------------------------------------------
    # Step 6: 验证编队建立
    # ------------------------------------------------------------------

    async def _verify_formation(
        self, task_id: str, leader_id: str, follower_ids: list[str],
    ) -> None:
        """验证编队是否成功建立"""
        self._current = FormationMissionState.VERIFYING
        active_formation_registry.update_state(FormationState.VERIFYING)
        task_manager.start_sub_step(task_id, "verify")

        # 查询所有参与者的状态，确认编队关系
        all_units = [leader_id] + follower_ids
        all_ok = True
        errors: list[str] = []

        for uid in all_units:
            resp = await self._call("get_robot_status", robot_id=uid)
            try:
                sdata = json.loads(resp)
            except json.JSONDecodeError:
                errors.append(f"{uid}: 状态查询返回无效 JSON")
                all_ok = False
                continue

            if not sdata.get("success"):
                errors.append(f"{uid}: {sdata.get('message', '状态查询失败')}")
                all_ok = False

        if not all_ok:
            msg = f"编队验证失败: {'; '.join(errors)}"
            task_manager.fail_sub_step(task_id, "verify", msg)
            active_formation_registry.set_error(msg, "verify", "")
            raise _OrchestratorError(
                FormationMissionState.FAILED_VERIFY_TIMEOUT,
                msg, "verify", "",
            )

        task_manager.complete_sub_step(task_id, "verify")

    # ------------------------------------------------------------------
    # 取消 & 回滚
    # ------------------------------------------------------------------

    def request_cancel(self) -> None:
        """请求取消当前编队任务"""
        self._cancel_requested = True

    async def _handle_cancel(
        self, task_id: str, ftype: str,
    ) -> FormationMissionResult:
        """处理取消（在关键步骤之前）"""
        self._current = FormationMissionState.CANCELLED
        active_formation_registry.update_state(FormationState.CANCELLED)
        task_manager.cancel_task(task_id, "编队任务已取消")
        return FormationMissionResult(
            success=False,
            task_id=task_id,
            state=FormationMissionState.CANCELLED.value,
            formation_type=ftype,
            message="编队任务已被取消",
            error_code="CANCELLED",
        )

    async def _handle_rollback_and_cancel(
        self, task_id: str, ftype: str, leader_id: str, all_units: list[str],
    ) -> FormationMissionResult:
        """取消并回滚已执行步骤"""
        self._current = FormationMissionState.CANCELLED
        active_formation_registry.update_state(FormationState.CANCELLED)

        # 执行回滚
        await self._rollback(task_id)

        task_manager.cancel_task(task_id, "编队任务已取消，已回滚配置")
        return FormationMissionResult(
            success=False,
            task_id=task_id,
            state=FormationMissionState.CANCELLED.value,
            formation_type=ftype,
            leader_id=leader_id,
            message="编队任务已取消，集群关系已重置",
            error_code="CANCELLED",
        )

    async def rollback_current(self, task_id: str, reason: str) -> FormationMissionResult:
        """
        回滚当前编队任务的所有步骤。

        按 LIFO 顺序撤销: 队形 → 跟随关系 → 领航者 → 模式重置
        """
        formation = active_formation_registry.active
        await self._rollback(task_id)

        self._current = FormationMissionState.CANCELLED
        active_formation_registry.clear()
        task_manager.cancel_task(task_id, reason)

        return FormationMissionResult(
            success=False,
            task_id=task_id,
            formation_id=formation.formation_id if formation else "",
            state=FormationMissionState.CANCELLED.value,
            formation_type=formation.formation_type if formation else "",
            message=f"编队已回滚: {reason}",
            error_code="ROLLED_BACK",
        )

    async def _rollback(self, task_id: str) -> None:
        """
        执行回滚操作（LIFO 顺序）。

        回滚步骤:
        1. reset_unit_relations (清除所有编队关系)
        2. 恢复默认模式 (none)
        """
        rollback_actions = task_manager.get_rollback_actions(task_id)

        for action in rollback_actions:
            try:
                if action == "reset_unit_relations":
                    await self._call("reset_unit_relations")
                elif action.startswith("clear_leader:"):
                    # 清除编队关系时一次性 reset
                    pass  # reset_unit_relations 已处理
                elif action.startswith("reset_follower:"):
                    pass  # reset_unit_relations 已处理
            except Exception:
                pass  # 回滚时忽略错误，尽力而为

        # 最终清理：重置编队关系和模式
        try:
            await self._call("reset_unit_relations")
            await self._call("set_group_mode", mode="none")
        except Exception:
            pass


# =============================================================================
# 内部错误
# =============================================================================

class _OrchestratorError(Exception):
    """编排器内部流程错误，用于状态机跳转"""

    def __init__(
        self,
        state: FormationMissionState,
        message: str,
        failed_step: str = "",
        failed_unit: str = "",
    ) -> None:
        super().__init__(message)
        self.state = state
        self.message = message
        self.failed_step = failed_step
        self.failed_unit = failed_unit


# =============================================================================
# 全局实例工厂
# =============================================================================

_global_orchestrator: FormationMissionOrchestrator | None = None


def get_formation_mission_orchestrator(
    adapter_call: Callable[..., Awaitable[str]],
) -> FormationMissionOrchestrator:
    """获取/创建全局编排器实例"""
    global _global_orchestrator
    if _global_orchestrator is None:
        _global_orchestrator = FormationMissionOrchestrator(adapter_call)
    return _global_orchestrator


# 延迟初始化（由 main.py 注入 adapter）
formation_mission_orchestrator: FormationMissionOrchestrator | None = None
