"""
MCP 工具层测试 — 直接调用 RobotAdapter 方法
MCP tool → RobotAdapter → HTTP → Console 的完整路径
"""
import asyncio, json, sys
sys.path.insert(0, '.')

from robot_adapter import RobotAdapter
from agents import AgentApiClient, AgentResolver, AgentService
from config import QT_HTTP_BASE

async def test_all():
    adapter = RobotAdapter(tool_timeout_s=12.0)
    api = AgentApiClient(base_url=QT_HTTP_BASE)
    resolver = AgentResolver(api, adapter._manager)
    adapter.set_agent_resolver(resolver)
    agent_svc = AgentService(api, resolver)

    results = []
    def check(name, ok, detail=""):
        results.append((name, ok, detail))

    # ================================================================
    # 1. list_robots
    # ================================================================
    print("=== 1. list_robots ===")
    r = await adapter.list_robots()
    d = json.loads(r)
    check("list_robots success", d.get("success"))
    print(f"    success={d['success']} units={len(d.get('data',{}).get('units',[]))}")

    # ================================================================
    # 2. set_agent_alias
    # ================================================================
    print("\n=== 2. set_agent_alias ===")
    r = await agent_svc.set_agent_alias(agent="GV1", alias="scout1")
    d = json.loads(r)
    check("set_alias scout1->GV1", d.get("success"), d.get("message", ""))
    print(f"    success={d['success']} msg={d.get('message')}")

    # ================================================================
    # 3. list_agents (verify alias)
    # ================================================================
    print("\n=== 3. list_agents ===")
    r = await agent_svc.list_agents()
    d = json.loads(r)
    check("list_agents success", d.get("success"))
    agents = d.get("data", {}).get("agents", [])
    gv1 = [a for a in agents if a.get("unit_id") == "GV1"]
    alias = gv1[0].get("alias") if gv1 else None
    check(f"GV1 alias='{alias}'", alias == "scout1")
    print(f"    agents={len(agents)} GV1.alias={alias}")

    # ================================================================
    # 4. goto_pose with alias (the key test!)
    # ================================================================
    print("\n=== 4. goto_pose via alias ===")
    r = await adapter.goto_pose(
        robot_id="scout1", x=0.5, y=0.0, tolerance_m=0.15, timeout_ms=3000
    )
    d = json.loads(r)
    check("goto_pose(alias='scout1') accepted", d.get("success"), d.get("message", ""))
    task_id = d.get("data", {}).get("task_id", "")
    print(f"    success={d['success']} task_id={task_id}")

    # ================================================================
    # 5. get_task_status
    # ================================================================
    print("\n=== 5. get_task_status ===")
    r = await adapter.get_task_status(task_id=task_id)
    d = json.loads(r)
    check("get_task_status success", d.get("success"))
    state = d.get("data", {}).get("state", "")
    check(f"state={state}", state in ("RUNNING", "COMPLETED", "TIMEOUT"))
    print(f"    state={state} progress={d['data'].get('progress_pct')}%")

    # wait for timeout
    print("    waiting 4s for timeout...")
    await asyncio.sleep(4)
    r = await adapter.get_task_status(task_id=task_id)
    d = json.loads(r)
    state = d["data"]["state"]
    check(f"timeout complete -> {state}", state in ("TIMEOUT", "COMPLETED"), state)
    print(f"    state={state}")

    # ================================================================
    # 6. goto_pose_batch
    # ================================================================
    print("\n=== 6. goto_pose_batch ===")
    r = await adapter.goto_pose_batch(
        targets_json='[{"robot_id":"GV1","x":1,"y":0},{"robot_id":"GV2","x":2,"y":0},{"robot_id":"GV3","x":3,"y":0}]',
        tolerance_m=0.15, timeout_ms=5000
    )
    d = json.loads(r)
    check("goto_pose_batch accepted", d.get("success"), d.get("message", ""))
    batch_id = d.get("data", {}).get("task_id", "")
    n_units = len(d.get("data", {}).get("unit_results", []))
    check(f"3 subtasks", n_units == 3, f"got {n_units}")
    print(f"    success={d['success']} task_id={batch_id} subtasks={n_units}")

    # cancel batch
    r = await adapter.cancel_task(task_id=batch_id)
    d = json.loads(r)
    check("cancel batch -> CANCELLED", d.get("success"), d.get("message", ""))
    print(f"    cancel: success={d['success']}")

    # ================================================================
    # 7. execute_formation
    # ================================================================
    print("\n=== 7. execute_formation ===")
    for ft in ["line", "column", "triangle"]:
        ids = "GV1,GV2,GV3" if ft != "column" else "GV1,GV2"
        r = await adapter.execute_formation(
            formation_type=ft, unit_ids_csv=ids, spacing_m=1.0,
            tolerance_m=0.15, timeout_ms=5000
        )
        d = json.loads(r)
        check(f"formation {ft}", d.get("success"), d.get("message", ""))
        if d.get("success"):
            ftid = d["data"]["task_id"]
            await adapter.cancel_task(task_id=ftid)
        await asyncio.sleep(1)

    # ================================================================
    # 8. emergency_stop_all
    # ================================================================
    print("\n=== 8. emergency_stop_all ===")
    r = await adapter.emergency_stop_all()
    d = json.loads(r)
    check("emergency_stop_all", d.get("success"), d.get("message", ""))
    print(f"    success={d['success']}")

    # ================================================================
    # 9. clear_alias cleanup
    # ================================================================
    print("\n=== 9. clear_alias ===")
    r = await agent_svc.clear_agent_alias(agent="GV1")
    d = json.loads(r)
    check("clear_alias GV1", d.get("success"), d.get("message", ""))
    print(f"    success={d['success']}")

    # ================================================================
    print("\n" + "=" * 60)
    passed = sum(1 for _, ok, _ in results if ok)
    failed = sum(1 for _, ok, _ in results if not ok)
    print(f"MCP TOOL RESULTS: {passed}/{len(results)} passed, {failed} failed")
    for name, ok, detail in results:
        print(f"  {'PASS' if ok else 'FAIL'}: {name} {detail}")

asyncio.run(test_all())
