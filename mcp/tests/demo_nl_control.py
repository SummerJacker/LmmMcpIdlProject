"""
MCP-IDL 最终闭环演示：自然语言 -> MCP工具 -> HTTP API -> Console -> Mock 集群
"""
import asyncio, json, sys, time
sys.path.insert(0, '.')

from robot_adapter import RobotAdapter
from agents import AgentApiClient, AgentResolver, AgentService
from config import QT_HTTP_BASE

async def demo():
    # 工具层初始化
    adapter = RobotAdapter(tool_timeout_s=12.0)
    api = AgentApiClient(QT_HTTP_BASE)
    resolver = AgentResolver(api, adapter._manager)
    adapter.set_agent_resolver(resolver)
    agent_svc = AgentService(api, resolver)

    j = lambda r: json.loads(r)  # 解析 JSON 响应

    # ========================================================
    # 场景1: "给三辆车起好记的名字"
    # ========================================================
    print(">>> 用户：给三辆车起好记的名字")
    print()

    aliases = {"GV1": "侦察兵1号", "GV2": "侦察兵2号", "GV3": "侦察兵3号"}
    for uid, alias in aliases.items():
        r = j(await agent_svc.set_agent_alias(agent=uid, alias=alias))
        if r["success"]:
            print(f"  {uid} -> {alias}  OK")
        else:
            print(f"  {uid}  x  {r['message']}")

    # 确认别名
    r = j(await agent_svc.list_agents())
    print(f"\n  当前智能体列表：")
    for a in r["data"]["agents"]:
        print(f"    {a['unit_id']} 别名={a.get('alias','无')} mock={a.get('mock')}")

    # ========================================================
    # 场景2: "让侦察兵1号移动到坐标 x=3.0, y=5.0"
    # ========================================================
    print(f"\n>>> 用户：让侦察兵1号移动到坐标 x=3.0, y=5.0")
    print()

    r = j(await adapter.goto_pose(
        robot_id="侦察兵1号", x=3.0, y=5.0,
        tolerance_m=0.15, timeout_ms=3000
    ))
    task_id = r["data"]["task_id"]
    print(f"  任务创建: task_id={task_id}")
    print(f"  状态: {r['data']['state']}")
    print(f"  目标: x=3.0 y=5.0 (mock模式，位置固定在原点)")

    # 轮询直到完成
    for i in range(5):
        await asyncio.sleep(0.8)
        s = j(await adapter.get_task_status(task_id=task_id))
        state = s["data"]["state"]
        progress = s["data"]["progress_pct"]
        elapsed = s["data"]["elapsed_ms"]
        print(f"  ... 轮询 #{i+1}: state={state} progress={progress}% elapsed={elapsed}ms")
        if state in ("COMPLETED", "TIMEOUT", "FAILED", "CANCELLED"):
            break

    print(f"\n  最终状态: {state} ({s['data']['message']})")
    unit_result = s["data"]["unit_results"][0]
    print(f"  单元 {unit_result['unit_id']}: {unit_result['state']}")

    # ========================================================
    # 场景3: "让 GV1、GV2、GV3 组成一字形编队，间距 1 米"
    # ========================================================
    print(f"\n>>> 用户：让侦察兵1号、2号、3号组成一字形编队，间距 1.5 米")
    print()

    r = j(await adapter.execute_formation(
        formation_type="line",
        unit_ids_csv="侦察兵1号,侦察兵2号,侦察兵3号",
        spacing_m=1.5,
        tolerance_m=0.15,
        timeout_ms=5000
    ))
    form_id = r["data"]["task_id"]
    print(f"  编队任务创建: task_id={form_id}")
    print(f"  编队类型: LINE  间距: 1.5m")
    for u in r["data"]["unit_results"]:
        print(f"    {u['unit_id']}: {u['state']}")

    # 查一次然后取消
    s = j(await adapter.get_task_status(task_id=form_id))
    print(f"  轮询: state={s['data']['state']}")
    c = j(await adapter.cancel_task(task_id=form_id))
    print(f"  取消编队: success={c['success']} state={c['data']['state']}")

    # ========================================================
    # 场景4: "让多辆车同时去不同的目标点"
    # ========================================================
    print(f"\n>>> 用户：让三辆车分散到三个目标点")
    print()

    targets_json = json.dumps([
        {"robot_id": "侦察兵1号", "x": 2.0, "y": 0.0},
        {"robot_id": "侦察兵2号", "x": 4.0, "y": 0.0},
        {"robot_id": "侦察兵3号", "x": 6.0, "y": 0.0},
    ])
    r = j(await adapter.goto_pose_batch(
        targets_json=targets_json,
        tolerance_m=0.15, timeout_ms=4000
    ))
    batch_id = r["data"]["task_id"]
    print(f"  Batch 任务: task_id={batch_id}")
    for u in r["data"]["unit_results"]:
        print(f"    {u['unit_id']} -> {u['state']}")

    # 等全部完成/超时
    await asyncio.sleep(5)
    s = j(await adapter.get_task_status(task_id=batch_id))
    print(f"\n  最终 batch 状态: {s['data']['state']}")
    for u in s["data"]["unit_results"]:
        print(f"    {u['unit_id']}: {u['state']}")

    # ========================================================
    # 场景5: "紧急停止所有车辆"
    # ========================================================
    print(f"\n>>> 用户：紧急停止所有车辆！")
    r = j(await adapter.emergency_stop_all())
    print(f"  结果: success={r['success']} msg={r.get('message')}")

    # ========================================================
    # 场景6: 异常处理 — "让不存在的车移动"
    # ========================================================
    print(f"\n>>> 用户：让幽灵号移动到 x=10, y=10")
    r = j(await adapter.goto_pose(
        robot_id="幽灵号", x=10.0, y=10.0,
        tolerance_m=0.15, timeout_ms=5000
    ))
    print(f"  结果: success={r['success']}")
    print(f"  错误: {r.get('message')}")

    # ========================================================
    print("\n" + "=" * 60)
    print("自然语言驱动集群演示完成")
    print("=" * 60)
    print()
    print("验证链路:  自然语言 -> MCP工具(别名解析) -> HTTP API -> Console -> Mock集群")
    print("所有接口:  goto_pose / batch / formation / status / cancel / stop_all")
    print("别名系统:  侦察兵1号 -> GV1  侦察兵2号 -> GV2  侦察兵3号 -> GV3")
    print("异常处理:  幽灵号 -> 'not bound'")

asyncio.run(demo())
