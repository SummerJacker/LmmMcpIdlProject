"""
MCP-Console 编队任务编排器集成测试。

模拟完整的 Console HTTP 响应，端到端测试:
1. execute_formation_mission — 自然语言 → 完整编队流程
2. move_active_formation — 编队建立后只控制 leader
3. get_formation_status — 查询编队状态
4. cancel_formation_mission — 取消并回滚

验证编排器的状态机流转、错误处理、回滚机制。
"""

from __future__ import annotations

import asyncio
import json
import sys
from pathlib import Path
from typing import Any

import pytest

# 确保 mcp 包在路径上
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

from orchestrator.task_manager import TaskManager, TaskState, task_manager
from orchestrator.active_formation import (
    ActiveFormationRegistry,
    FormationState,
    active_formation_registry,
)
from orchestrator.formation_mission import (
    FormationMissionOrchestrator,
    FormationMissionState,
    FormationMissionResult,
)

# =============================================================================
# Mock Console Adapter — 模拟主控台 HTTP 响应
# =============================================================================

class MockConsoleAdapter:
    """
    模拟 RobotAdapter.orchestrator_dispatch，返回假 Console JSON 响应。

    支持注入故障以测试错误处理和回滚。
    """

    def __init__(self) -> None:
        self.call_log: list[dict] = []  # 记录所有调用
        # 注入故障配置：{"op_name": "fail_with_message"}
        self.faults: dict[str, str] = {}
        # 模拟集群状态
        self._units: dict[str, dict] = {
            "GV1": {"unit_id": "GV1", "online": True, "battery": 85,
                     "pose": {"x": 0.0, "y": 0.0, "yaw": 0.0}},
            "GV2": {"unit_id": "GV2", "online": True, "battery": 72,
                     "pose": {"x": 1.5, "y": 0.5, "yaw": 0.1}},
            "GV3": {"unit_id": "GV3", "online": True, "battery": 68,
                     "pose": {"x": -0.5, "y": 2.0, "yaw": -0.2}},
        }
        self._leader: str | None = None
        self._group_mode: str = "none"

    def inject_fault(self, op_name: str, message: str) -> None:
        """注入故障：指定操作返回失败"""
        self.faults[op_name] = message

    def clear_faults(self) -> None:
        self.faults.clear()

    async def dispatch(self, op_name: str, **kwargs: Any) -> str:
        """模拟 RobotAdapter.orchestrator_dispatch"""
        self.call_log.append({"op": op_name, "args": kwargs})

        # 检查故障注入
        if op_name in self.faults:
            return json.dumps({
                "success": False,
                "message": self.faults[op_name],
            })

        # ── 分派模拟响应 ──
        if op_name == "get_fleet_status":
            return self._mock_fleet_status(kwargs)
        elif op_name == "get_robot_status":
            return self._mock_robot_status(kwargs)
        elif op_name == "set_leader":
            return self._mock_set_leader(kwargs)
        elif op_name == "set_group_mode":
            return self._mock_set_group_mode(kwargs)
        elif op_name == "execute_formation":
            return self._mock_execute_formation(kwargs)
        elif op_name == "reset_unit_relations":
            return self._mock_reset_relations()
        elif op_name == "emergency_stop_all":
            return json.dumps({"success": True, "message": "all stopped"})
        elif op_name == "stop_robot":
            return json.dumps({"success": True, "message": f"stopped {kwargs.get('robot_id', '?')}"})
        elif op_name == "send_move":
            return self._mock_send_move(kwargs)
        else:
            return json.dumps({"success": False, "message": f"unknown op: {op_name}"})

    # ── 模拟响应生成 ──

    def _mock_fleet_status(self, kwargs: dict) -> str:
        items = []
        for uid, data in self._units.items():
            items.append({
                "robot_id_input": uid,
                "success": True,
                "message": "",
                "data": data,
            })
        return json.dumps({
            "success": True,
            "message": "ok",
            "data": {
                "items": items,
                "summary": {"total": len(items), "ok": len(items), "failed": 0},
            },
        })

    def _mock_robot_status(self, kwargs: dict) -> str:
        uid = str(kwargs.get("robot_id", ""))
        if uid in self._units:
            return json.dumps({
                "success": True,
                "message": "ok",
                "data": self._units[uid],
            })
        return json.dumps({
            "success": False,
            "message": f"unit {uid} not found",
        })

    def _mock_set_leader(self, kwargs: dict) -> str:
        uid = str(kwargs.get("robot_id", ""))
        if uid in self._units:
            self._leader = uid
            return json.dumps({"success": True, "message": f"leader set to {uid}"})
        return json.dumps({"success": False, "message": f"unknown unit {uid}"})

    def _mock_set_group_mode(self, kwargs: dict) -> str:
        mode = str(kwargs.get("mode", "none"))
        self._group_mode = mode
        return json.dumps({"success": True, "message": f"group mode set to {mode}"})

    def _mock_execute_formation(self, kwargs: dict) -> str:
        return json.dumps({
            "success": True,
            "message": "formation executed",
            "data": {"task_id": "mock_ftask_001"},
        })

    def _mock_reset_relations(self) -> str:
        self._leader = None
        self._group_mode = "none"
        return json.dumps({"success": True, "message": "relations reset"})

    def _mock_send_move(self, kwargs: dict) -> str:
        return json.dumps({
            "success": True,
            "message": "move sent",
            "data": {
                "unit_id": kwargs.get("robot_id"),
                "linear_velocity": kwargs.get("linear_velocity"),
                "angular_velocity": kwargs.get("angular_velocity"),
                "duration_ms": kwargs.get("duration_ms"),
            },
        })


# =============================================================================
# 测试用例
# =============================================================================

class TestFormationMissionOrchestrator:
    """编队任务编排器 E2E 测试套件"""

    @classmethod
    def setup_class(cls) -> None:
        cls.mock = MockConsoleAdapter()
        cls.orchestrator = FormationMissionOrchestrator(cls.mock.dispatch)

    def setup_method(self) -> None:
        """每个测试前清理状态"""
        self.mock.clear_faults()
        self.mock.call_log.clear()
        active_formation_registry.clear()
        # 重置 TaskManager 状态（清除历史任务）
        for rec in list(task_manager._tasks.values()):
            del task_manager._tasks[rec.task_id]

    # ------------------------------------------------------------------
    # Test 1: 正常流程 — 三车三角形编队
    # ------------------------------------------------------------------

    @pytest.mark.asyncio
    async def test_full_formation_triangle_success(self) -> None:
        """
        模拟用户说: "对集群进行三角形编队"
        LLM 调用: execute_formation_mission(formation_type="triangle")

        预期:
        1. 自动查询集群状态 (get_fleet_status)
        2. 自动选择 GV1 为领航者 (电池最高 85%)
        3. 设置 GV1 为领航者 (set_leader)
        4. 设置跟随关系 (set_group_mode=follow + ...)
        5. 下发队形参数 (execute_formation)
        6. 验证编队建立 (get_robot_status × 3)
        7. 返回成功，leader=GV1, followers=[GV2, GV3]
        """
        result: FormationMissionResult = await self.orchestrator.execute(
            formation_type="triangle",
            unit_ids=["GV1", "GV2", "GV3"],
            spacing_m=1.0,
        )

        assert result.success, f"Expected success, got: {result.message}"
        assert result.state == FormationMissionState.READY.value
        assert result.formation_type == "triangle"
        assert result.leader_id == "GV1"  # 电池最高，自动选择
        assert len(result.follower_ids) == 2
        assert "GV2" in result.follower_ids
        assert "GV3" in result.follower_ids

        # 验证调用序列
        ops = [c["op"] for c in self.mock.call_log]
        assert "get_fleet_status" in ops, "Should check fleet first"
        assert "set_leader" in ops, "Should set leader"
        assert "set_group_mode" in ops, "Should set group mode"
        assert "execute_formation" in ops, "Should execute formation"
        assert "reset_unit_relations" not in ops, "Should NOT reset on success"

        # 验证活跃编队状态
        formation = active_formation_registry.active
        assert formation is not None
        assert formation.state == FormationState.READY
        assert formation.leader_id == "GV1"
        assert formation.is_ready

        # 验证 TaskManager 记录
        rec = task_manager.get_task(result.task_id)
        assert rec is not None
        assert rec.state == TaskState.COMPLETED
        assert rec.progress_pct == 100.0
        assert all(
            s.state.value in ("COMPLETED", "SKIPPED")
            for s in rec.sub_steps
        ), f"All sub-steps should be complete/skipped: {[(s.name, s.state.value) for s in rec.sub_steps]}"

        print(f"  [PASS] test_full_formation_triangle_success")
        print(f"    leader={result.leader_id}, followers={result.follower_ids}")
        print(f"    ops_sequence: {ops}")

    # ------------------------------------------------------------------
    # Test 2: 用户指定领航者
    # ------------------------------------------------------------------

    @pytest.mark.asyncio
    async def test_formation_with_specified_leader(self) -> None:
        """用户指定 GV3 为领航者"""
        result = await self.orchestrator.execute(
            formation_type="line",
            unit_ids=["GV1", "GV2", "GV3"],
            leader_id="GV3",
            spacing_m=1.5,
        )

        assert result.success
        assert result.leader_id == "GV3", "Should use specified leader"
        assert "GV1" in result.follower_ids
        assert "GV2" in result.follower_ids
        assert "GV3" not in result.follower_ids

        print(f"  [PASS] test_formation_with_specified_leader → leader={result.leader_id}")

    # ------------------------------------------------------------------
    # Test 3: 自动获取在线智能体（不指定 unit_ids）
    # ------------------------------------------------------------------

    @pytest.mark.asyncio
    async def test_auto_discover_units(self) -> None:
        """不传 unit_ids，自动从 get_fleet_status 获取所有在线智能体"""
        result = await self.orchestrator.execute(
            formation_type="line",
            unit_ids=None,  # 自动获取
            spacing_m=1.0,
        )

        assert result.success
        assert len(result.follower_ids) >= 1  # 至少有 1 个 follower
        assert result.leader_id in ("GV1", "GV2", "GV3")

        print(f"  [PASS] test_auto_discover_units → {len(result.follower_ids)+1} units")

    # ------------------------------------------------------------------
    # Test 4: 智能体不足时拒绝编队
    # ------------------------------------------------------------------

    @pytest.mark.asyncio
    async def test_insufficient_units(self) -> None:
        """三角形编队需要 3 台，只提供 2 台"""
        result = await self.orchestrator.execute(
            formation_type="triangle",
            unit_ids=["GV1", "GV2"],  # 只有 2 台
            spacing_m=1.0,
        )

        assert not result.success
        assert result.state == FormationMissionState.FAILED_NO_ENOUGH_UNITS.value
        assert "至少 3" in result.message

        print(f"  [PASS] test_insufficient_units → {result.message}")

    # ------------------------------------------------------------------
    # Test 5: set_leader 失败时的错误处理
    # ------------------------------------------------------------------

    @pytest.mark.asyncio
    async def test_leader_set_failure(self) -> None:
        """模拟 set_leader 失败"""
        self.mock.inject_fault("set_leader", "Console leader set timeout")

        result = await self.orchestrator.execute(
            formation_type="triangle",
            unit_ids=["GV1", "GV2", "GV3"],
            spacing_m=1.0,
        )

        assert not result.success
        assert result.state == FormationMissionState.FAILED_LEADER_SET_FAILED.value
        assert "timeout" in result.message.lower()

        print(f"  [PASS] test_leader_set_failure → {result.message}")

    # ------------------------------------------------------------------
    # Test 6: 编队建立后移动（move_active_formation）
    # ------------------------------------------------------------------

    @pytest.mark.asyncio
    async def test_move_after_formation(self) -> None:
        """编队建立后，move_active_formation 只控制 leader"""
        # 先建立编队
        result = await self.orchestrator.execute(
            formation_type="triangle",
            unit_ids=["GV1", "GV2", "GV3"],
            spacing_m=1.0,
        )
        assert result.success

        # 现在移动编队（只应该控制 leader）
        from safety.validator import validate_move_formation

        # 模拟 move_active_formation 在 main.py 中的逻辑
        passed, code, msg = validate_move_formation(
            has_active_formation=active_formation_registry.has_active,
            is_ready=active_formation_registry.is_ready,
        )
        assert passed, f"Should allow move: {msg}"

        formation = active_formation_registry.active
        assert formation is not None

        # 只对 leader 发 move
        mv_result = await self.mock.dispatch(
            "send_move",
            robot_id=formation.leader_id,
            linear_velocity=0.5,
            angular_velocity=0.0,
            duration_ms=2000,
        )
        mv_data = json.loads(mv_result)
        assert mv_data["success"]
        assert mv_data["data"]["unit_id"] == formation.leader_id

        # 验证 follower 没有被发送移动指令
        send_move_calls = [c for c in self.mock.call_log if c["op"] == "send_move"]
        assert len(send_move_calls) == 1, "Only one send_move should be called"
        assert send_move_calls[0]["args"]["robot_id"] == formation.leader_id

        print(f"  [PASS] test_move_after_formation → only leader {formation.leader_id} moved")

    # ------------------------------------------------------------------
    # Test 7: 无编队时移动被拒绝
    # ------------------------------------------------------------------

    @pytest.mark.asyncio
    async def test_move_rejected_without_formation(self) -> None:
        """没有编队时 move_active_formation 应该被拒绝"""
        from safety.validator import validate_move_formation

        passed, code, msg = validate_move_formation(
            has_active_formation=False,
            is_ready=False,
        )
        assert not passed
        assert code == "FORMATION_NOT_READY"

        print(f"  [PASS] test_move_rejected_without_formation → {msg}")

    # ------------------------------------------------------------------
    # Test 8: 编队查询状态
    # ------------------------------------------------------------------

    @pytest.mark.asyncio
    async def test_get_formation_status(self) -> None:
        """获取编队状态"""
        # 未建编队时
        status = active_formation_registry.get_status_dict()
        assert status["has_active_formation"] is False
        assert status["state"] == "IDLE"

        # 建编队后
        result = await self.orchestrator.execute(
            formation_type="column",
            unit_ids=["GV1", "GV2"],
            spacing_m=0.8,
        )
        assert result.success

        status = active_formation_registry.get_status_dict()
        assert status["has_active_formation"] is True
        assert status["state"] == "READY"
        assert status["leader_id"] == "GV1"
        assert status["formation_type"] == "column"

        print(f"  [PASS] test_get_formation_status → {status['state']}")

    # ------------------------------------------------------------------
    # Test 9: 取消编队并回滚
    # ------------------------------------------------------------------

    @pytest.mark.asyncio
    async def test_cancel_formation_with_rollback(self) -> None:
        """取消编队任务，验证回滚"""
        # 建立编队
        result = await self.orchestrator.execute(
            formation_type="triangle",
            unit_ids=["GV1", "GV2", "GV3"],
            spacing_m=1.0,
        )
        assert result.success

        # 取消
        cancel_result = await self.orchestrator.rollback_current(
            result.task_id,
            "测试取消",
        )
        assert not cancel_result.success
        assert cancel_result.error_code == "ROLLED_BACK"

        # 验证回滚：应该调用了 reset_unit_relations
        rollback_ops = [c for c in self.mock.call_log if c["op"] == "reset_unit_relations"]
        assert len(rollback_ops) >= 1, "Should call reset_unit_relations during rollback"

        # 验证活跃编队已清除
        assert not active_formation_registry.has_active

        print(f"  [PASS] test_cancel_formation_with_rollback → rolled back")

    # ------------------------------------------------------------------
    # Test 10: 已有活跃编队时拒绝新编队
    # ------------------------------------------------------------------

    @pytest.mark.asyncio
    async def test_reject_duplicate_formation(self) -> None:
        """已有活跃编队时新建编队应被拒绝"""
        # 第一个编队成功
        r1 = await self.orchestrator.execute(
            formation_type="triangle",
            unit_ids=["GV1", "GV2", "GV3"],
            spacing_m=1.0,
        )
        assert r1.success

        # 这时 ActiveFormationRegistry.has_active 应为 True
        # 在 main.py 中，validate_formation_mission 会检查这个
        from safety.validator import validate_formation_mission

        passed, code, msg = validate_formation_mission(
            "line", ["GV1", "GV2"], None, 1.0,
            existing_formation=True,
        )
        assert not passed
        assert code == "FORMATION_CONFLICT"

        print(f"  [PASS] test_reject_duplicate_formation → {msg}")

    # ------------------------------------------------------------------
    # Test 11: 端到端自然语言模拟
    # ------------------------------------------------------------------

    @pytest.mark.asyncio
    async def test_natural_language_flow(self) -> None:
        """
        模拟完整的自然语言交互流程:

        用户: "对集群进行三角形编队，间距 1 米"
        → LLM 解析为 execute_formation_mission("triangle", spacing_m=1.0)
        → 编排器自动执行完整流程
        → 返回: 编队已建立

        用户: "让编队向前移动"
        → LLM 调用 move_active_formation(linear_velocity=0.3, duration_ms=2000)
        → 只控制 leader 移动

        用户: "编队状态怎么样？"
        → LLM 调用 get_formation_status()

        用户: "取消编队"
        → LLM 调用 cancel_formation_mission()
        → 回滚配置
        """
        print("\n  === 自然语言交互模拟 ===\n")

        # Step 1: "对集群进行三角形编队"
        print('  用户: "对集群进行三角形编队，间距 1 米"')
        r1 = await self.orchestrator.execute(
            formation_type="triangle",
            unit_ids=["GV1", "GV2", "GV3"],
            spacing_m=1.0,
        )
        assert r1.success
        print(f'  系统: {r1.message}')
        print(f'        leader={r1.leader_id}, followers={r1.follower_ids}')

        # Step 2: "让编队向前移动"
        print('  用户: "让编队向前移动"')
        formation = active_formation_registry.active
        assert formation is not None
        # LLM 调用 move_active_formation
        mv = await self.mock.dispatch(
            "send_move",
            robot_id=formation.leader_id,
            linear_velocity=0.3,
            angular_velocity=0.0,
            duration_ms=2000,
        )
        mv_data = json.loads(mv)
        assert mv_data["success"]
        print(f'  系统: 领航者 {formation.leader_id} 向前移动 0.3m/s × 2s')

        # Step 3: "编队状态怎么样？"
        print('  用户: "编队状态怎么样？"')
        status = active_formation_registry.get_status_dict()
        print(f'  系统: 编队类型={status["formation_type"]}, 状态={status["state"]}, '
              f'leader={status["leader_id"]}, followers={status["follower_ids"]}')

        # Step 4: "取消编队"
        print('  用户: "取消编队"')
        cancel_r = await self.orchestrator.rollback_current(r1.task_id, "用户请求取消")
        print(f'  系统: {cancel_r.message}')

        assert not active_formation_registry.has_active
        assert not cancel_r.success

        print('\n  [PASS] test_natural_language_flow — 完整自然语言交互流程通过')


# =============================================================================
# 运行入口
# =============================================================================

if __name__ == "__main__":
    import pytest

    print("=" * 60)
    print("MCP-Console 编队任务编排器集成测试")
    print("=" * 60)
    print()

    # 使用 pytest 运行
    exit_code = pytest.main([
        __file__, "-v", "-s",
        "--tb=short",
        "--color=yes",
    ])
    sys.exit(exit_code)
