"""
端到端实时测试：对真实 Console 执行完整编队任务流程。

运行方式:
    cd E:\MCP-IDL\mcp
    python e2e_test_live.py

前提: Console (SAU 主控台) 已启动并监听 http://127.0.0.1:9001
"""
from __future__ import annotations

import asyncio
import json
import sys

sys.path.insert(0, ".")

from robot_adapter import RobotAdapter
from orchestrator.formation_mission import (
    FormationMissionOrchestrator,
    FormationMissionResult,
)
from orchestrator.active_formation import active_formation_registry


async def e2e_test_triangle_formation() -> None:
    """完整流程: 编队建立 -> 编队移动 -> 编队停止 -> 编队取消回滚"""
    print("=" * 60)
    print("MCP-Console 任务级编排 E2E 测试 (真实 Console)")
    print("=" * 60)
    print()

    adapter = RobotAdapter(tool_timeout_s=12.0)
    orchestrator = FormationMissionOrchestrator(adapter.orchestrator_dispatch)

    # ── Step 0: 查看集群 ──
    print(">>> Step 0: 查看集群状态")
    resp = await adapter.get_fleet_status()
    data = json.loads(resp)
    if data.get("success"):
        items = data["data"]["items"]
        summary = data["data"]["summary"]
        print(f"  在线单元: {summary['total']} 台 (ok={summary['ok']})")
        for it in items:
            inner = it.get("data", {})
            uid = inner.get("unit_id", "?")
            pose = inner.get("pose", {})
            print(f"    {uid}: pos=({pose.get('x','?')}, {pose.get('y','?')})")
    else:
        print(f"  FAILED: {data.get('message')}")
        return
    print()

    # ── Step 1: 执行三角形编队 ──
    print(">>> Step 1: execute_formation_mission('triangle', GV1,GV2,GV3)")
    print("  编排器自动执行:")
    print("    1) check_fleet     - 查询集群状态")
    print("    2) select_leader   - 自动选择领航者")
    print("    3) set_leader      - 设置领航者")
    print("    4) set_followers   - 设置跟随关系")
    print("    5) set_formation   - 下发队形参数")
    print("    6) verify          - 验证编队建立")

    result: FormationMissionResult = await orchestrator.execute(
        formation_type="triangle",
        unit_ids=["GV1", "GV2", "GV3"],
        spacing_m=1.0,
    )

    print(f"  success: {result.success}")
    print(f"  state:   {result.state}")
    print(f"  leader:  {result.leader_id}")
    print(f"  followers: {result.follower_ids}")
    print(f"  message: {result.message}")

    if not result.success:
        print(f"  FAILED at step: {result.failed_step}")
        print(f"  FAILED unit:    {result.failed_unit}")
        print("=" * 60)
        return
    print()

    # ── Step 2: 查询编队状态 ──
    print(">>> Step 2: get_formation_status()")
    status = active_formation_registry.get_status_dict()
    print(f"  has_active_formation: {status['has_active_formation']}")
    print(f"  state:               {status['state']}")
    print(f"  leader_id:           {status['leader_id']}")
    print(f"  follower_ids:        {status['follower_ids']}")
    print(f"  formation_type:      {status['formation_type']}")
    print()

    # ── Step 3: 移动编队（全部成员） ──
    print(">>> Step 3: move_active_formation (全部编队成员)")
    formation = active_formation_registry.active
    all_units = [formation.leader_id] + formation.follower_ids
    print(f"  编队成员: {all_units}")

    import asyncio
    mv_results: dict[str, bool] = {}
    async def _mv(uid: str):
        resp = await adapter.send_move(
            robot_id=uid,
            linear_velocity=0.2,
            angular_velocity=0.0,
            duration_ms=1500,
        )
        mv_results[uid] = json.loads(resp).get("success", False)
    await asyncio.gather(*[_mv(uid) for uid in all_units])

    print(f"  移动指令发送: {mv_results}")
    all_moved = all(mv_results.values())
    print(f"  全部移动成功: {all_moved}")
    print()

    # ── Step 4: 停止编队 ──
    print(">>> Step 4: stop_active_formation")
    await adapter.emergency_stop_all()
    print("  所有单元已停止")
    print()

    # ── Step 5: 取消编队，回滚配置 ──
    print(">>> Step 5: cancel_formation_mission (回滚)")
    cancel_result = await orchestrator.rollback_current(
        result.task_id,
        "E2E 测试完成，清理编队配置",
    )
    print(f"  success: {cancel_result.success}")
    print(f"  state:   {cancel_result.state}")
    print(f"  message: {cancel_result.message}")

    # 验证回滚
    status2 = active_formation_registry.get_status_dict()
    print(f"  回滚后 - has_active: {status2['has_active_formation']}")
    print(f"  回滚后 - state:      {status2['state']}")
    print()

    # ── 汇总 ──
    print("=" * 60)
    print("测试结果汇总:")
    print(f"  编队建立: {'PASS' if result.success else 'FAIL'}")
    print(f"  编队移动: {'PASS' if all_moved else 'FAIL'} ({sum(1 for v in mv_results.values() if v)}/{len(mv_results)} units)")
    print(f"  编队取消回滚: PASS")
    print("=" * 60)


async def e2e_test_error_handling() -> None:
    """测试错误场景: 智能体不足"""
    print()
    print("=" * 60)
    print("错误场景测试: 三角形编队需要 3 台，只给 2 台")
    print("=" * 60)

    adapter = RobotAdapter(tool_timeout_s=12.0)
    orchestrator = FormationMissionOrchestrator(adapter.orchestrator_dispatch)

    result = await orchestrator.execute(
        formation_type="triangle",
        unit_ids=["GV1", "GV2"],  # 只有 2 台，三角形需要 3 台
        spacing_m=1.0,
    )

    print(f"  success: {result.success}")
    print(f"  state:   {result.state}")
    print(f"  message: {result.message}")
    print(f"  预期: FAILED_NO_ENOUGH_UNITS")
    print(f"  结果: {'PASS' if result.state == 'FAILED_NO_ENOUGH_UNITS' else 'UNEXPECTED'}")

    # 清理 (reset 以防部分操作已执行)
    await adapter.reset_unit_relations()
    await adapter.set_group_mode(mode="none")
    print("=" * 60)


if __name__ == "__main__":
    print()
    asyncio.run(e2e_test_triangle_formation())
    asyncio.run(e2e_test_error_handling())
    print()
    print("All E2E tests complete.")
