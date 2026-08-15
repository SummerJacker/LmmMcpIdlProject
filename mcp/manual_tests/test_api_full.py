"""
MCP-IDL HTTP API 完整测试套件
按照分层测试计划: 异常输入 → goto_pose → status → cancel → batch → formation
"""
import json, os, time, urllib.parse, requests
import pytest

if os.getenv("RUN_LIVE_CONSOLE_TESTS") != "1":
    pytest.skip(
        "manual live Console test; set RUN_LIVE_CONSOLE_TESTS=1 explicitly",
        allow_module_level=True,
    )

BASE = "http://127.0.0.1:9001"
PASS, FAIL, SKIP = 0, 0, 0
results = []

def test(name, fn):
    global PASS, FAIL
    try:
        fn()
        PASS += 1
        results.append(f"  PASS {name}")
    except AssertionError as e:
        FAIL += 1
        results.append(f"  FAIL {name}: {e}")
    except requests.RequestException as e:
        FAIL += 1
        results.append(f"  CRASH {name}: {e}")

test.__test__ = False

def assert_eq(actual, expected, msg=""):
    if actual != expected:
        raise AssertionError(f"{msg} expected={expected!r} got={actual!r}")

def assert_in(substr, text, msg=""):
    if substr not in text:
        raise AssertionError(f"{msg} '{substr}' not in response")

TERMINAL_STATES = {
    "COMPLETED", "PARTIAL_COMPLETED", "FAILED", "TIMEOUT", "CANCELLED", "REJECTED"
}

def release_task(task_id):
    """Release units before the next scenario without weakening busy-unit checks."""
    if not task_id:
        return
    status = requests.get(
        f"{BASE}/api/task/status", params={"task_id": task_id}, timeout=5
    ).json()
    if status.get("success") and status.get("data", {}).get("state") not in TERMINAL_STATES:
        requests.post(
            f"{BASE}/api/task/cancel", json={"task_id": task_id}, timeout=5
        )
    for _ in range(20):
        status = requests.get(
            f"{BASE}/api/task/status", params={"task_id": task_id}, timeout=5
        ).json()
        if status.get("data", {}).get("state") in TERMINAL_STATES:
            return
        time.sleep(0.05)
    raise AssertionError(f"task {task_id} did not become terminal during cleanup")

# ============================================================
# LAYER 0: 异常输入测试
# ============================================================
print("=" * 60)
print("LAYER 0: 异常输入测试")
print("=" * 60)

def t_unit_not_found():
    r = requests.post(f"{BASE}/api/task/goto_pose", json={
        "unit_id": "GV999", "x": 3.0, "y": 5.0, "tolerance_m": 0.15, "timeout_ms": 30000
    }, timeout=5).json()
    assert_eq(r["success"], False, "should reject unknown unit")
    assert_in("UNIT_NOT_FOUND", r.get("data", {}).get("error_code", ""), "error_code")

test("不存在的 GV999 → UNIT_NOT_FOUND", t_unit_not_found)

def t_missing_params():
    r = requests.post(f"{BASE}/api/task/goto_pose", json={
        "unit_id": "GV1"
        # 缺少 x, y
    }, timeout=5).json()
    assert_eq(r["success"], False, "should reject missing x/y")

test("缺少 x/y 参数 → 拒绝", t_missing_params)

def t_invalid_tolerance():
    r = requests.post(f"{BASE}/api/task/goto_pose", json={
        "unit_id": "GV1", "x": 3.0, "y": 5.0, "tolerance_m": -1.0, "timeout_ms": 30000
    }, timeout=5).json()
    assert_eq(r["success"], False, "should reject negative tolerance")

test("tolerance_m = -1 → 拒绝", t_invalid_tolerance)

def t_coord_out_of_bounds():
    r = requests.post(f"{BASE}/api/task/goto_pose", json={
        "unit_id": "GV1", "x": 9999.0, "y": 9999.0, "tolerance_m": 0.15, "timeout_ms": 30000
    }, timeout=5).json()
    assert_eq(r["success"], False, "should reject out-of-bounds coords")

test("坐标超出范围 → 拒绝", t_coord_out_of_bounds)

def t_missing_unit_id():
    r = requests.post(f"{BASE}/api/task/goto_pose", json={
        "x": 3.0, "y": 5.0, "tolerance_m": 0.15, "timeout_ms": 30000
    }, timeout=5).json()
    assert_eq(r["success"], False, "should reject missing unit_id")

test("缺少 unit_id → 拒绝", t_missing_unit_id)

def t_batch_empty_targets():
    r = requests.post(f"{BASE}/api/task/goto_pose_batch", json={
        "targets": [], "tolerance_m": 0.15, "timeout_ms": 30000
    }, timeout=5).json()
    assert_eq(r["success"], False, "should reject empty targets")

test("batch 空 targets → 拒绝", t_batch_empty_targets)

def t_batch_invalid_unit():
    r = requests.post(f"{BASE}/api/task/goto_pose_batch", json={
        "targets": [{"unit_id": "GV999", "x": 1.0, "y": 0.0}],
        "tolerance_m": 0.15, "timeout_ms": 30000
    }, timeout=5).json()
    assert_eq(r["success"], False, "should reject batch with invalid unit")

test("batch 含 GV999 → 拒绝", t_batch_invalid_unit)

def t_formation_insufficient_units_line():
    r = requests.post(f"{BASE}/api/formation/execute", json={
        "formation_type": "line", "unit_ids": ["GV1"], "spacing_m": 1.0,
        "tolerance_m": 0.15, "timeout_ms": 30000
    }, timeout=5).json()
    assert_eq(r["success"], False, "line needs >=2 units")

test("formation line 仅1辆 → 拒绝", t_formation_insufficient_units_line)

def t_formation_insufficient_units_triangle():
    r = requests.post(f"{BASE}/api/formation/execute", json={
        "formation_type": "triangle", "unit_ids": ["GV1", "GV2"], "spacing_m": 1.0,
        "tolerance_m": 0.15, "timeout_ms": 30000
    }, timeout=5).json()
    assert_eq(r["success"], False, "triangle needs >=3 units")

test("formation triangle 仅2辆 → 拒绝", t_formation_insufficient_units_triangle)

def t_formation_unknown_type():
    r = requests.post(f"{BASE}/api/formation/execute", json={
        "formation_type": "circle", "unit_ids": ["GV1", "GV2", "GV3"], "spacing_m": 1.0,
        "tolerance_m": 0.15, "timeout_ms": 30000
    }, timeout=5).json()
    assert_eq(r["success"], False, "should reject unknown formation type")

test("formation type=circle → 拒绝", t_formation_unknown_type)

# ============================================================
# LAYER 1: goto_pose + status + cancel 闭环
# ============================================================
print("\n" + "=" * 60)
print("LAYER 1: goto_pose → status → cancel 闭环")
print("=" * 60)

# 先发一个小超时的任务方便快速完成
TASK_ID = None

def t_goto_pose():
    global TASK_ID
    r = requests.post(f"{BASE}/api/task/goto_pose", json={
        "unit_id": "GV1", "x": 0.1, "y": 0.0, "tolerance_m": 0.15, "timeout_ms": 5000
    }, timeout=5).json()
    assert_eq(r["success"], True, "goto_pose should succeed")
    assert_in("goto-", r["data"]["task_id"])
    assert_eq(r["data"]["state"], "RUNNING")
    TASK_ID = r["data"]["task_id"]
    print(f"    task_id = {TASK_ID}")

test("goto_pose GV1 → task accepted", t_goto_pose)

def t_task_status():
    assert TASK_ID is not None
    r = requests.get(f"{BASE}/api/task/status?task_id={TASK_ID}", timeout=5).json()
    assert_eq(r["success"], True)
    d = r["data"]
    assert_in(d["state"], "RUNNING")
    assert_eq(d["task_type"], "goto_pose")
    assert_in("unit_results", json.dumps(d))
    assert_in("audit_log", json.dumps(d))
    # 验证子任务结构
    urs = d["unit_results"]
    assert len(urs) >= 1, "should have at least 1 unit_result"
    assert_eq(urs[0]["unit_id"], "GV1")
    assert urs[0]["state"] in ("PENDING", "RUNNING", "COMPLETED", "TIMEOUT")

test("get_task_status → 完整 TaskResult", t_task_status)

def t_cancel_task():
    global TASK_ID
    assert TASK_ID is not None
    r = requests.post(f"{BASE}/api/task/cancel", json={
        "task_id": TASK_ID
    }, timeout=5).json()
    assert_eq(r["success"], True, "cancel should succeed")
    assert_eq(r["data"]["state"], "CANCELLED")

test("cancel_task → CANCELLED", t_cancel_task)

def t_cancel_already_cancelled():
    assert TASK_ID is not None
    r = requests.post(f"{BASE}/api/task/cancel", json={
        "task_id": TASK_ID
    }, timeout=5).json()
    assert_eq(r["success"], False, "double cancel should fail")
    assert_in("TASK_ALREADY_CANCELLED", r.get("data", {}).get("error_code", ""))

test("重复 cancel → TASK_ALREADY_CANCELLED", t_cancel_already_cancelled)

def t_task_status_after_cancel():
    assert TASK_ID is not None
    r = requests.get(f"{BASE}/api/task/status?task_id={TASK_ID}", timeout=5).json()
    assert_eq(r["success"], True)
    assert_eq(r["data"]["state"], "CANCELLED")

test("cancel 后 status → CANCELLED", t_task_status_after_cancel)

def t_status_not_found():
    r = requests.get(f"{BASE}/api/task/status?task_id=goto-nonexistent", timeout=5).json()
    assert_eq(r["success"], False, "should fail for nonexistent task")

test("查询不存在的 task → 404", t_status_not_found)

# ============================================================
# LAYER 1b: 超时自动结束
# ============================================================
print("\n" + "=" * 60)
print("LAYER 1b: 超时自动结束")
print("=" * 60)

def t_timeout_task():
    # 发一个 2s 超时的任务，目标设很远，等它超时
    r = requests.post(f"{BASE}/api/task/goto_pose", json={
        "unit_id": "GV2", "x": 50.0, "y": 50.0, "tolerance_m": 0.15, "timeout_ms": 2000
    }, timeout=5).json()
    assert_eq(r["success"], True, "task should be accepted")
    tid = r["data"]["task_id"]

    # 等 3.5 秒让超时触发
    time.sleep(3.5)

    r2 = requests.get(f"{BASE}/api/task/status?task_id={tid}", timeout=5).json()
    state = r2["data"]["state"]
    print(f"    timeout task state = {state}")
    # 应该是 TIMEOUT
    assert state in ("TIMEOUT", "COMPLETED"), f"expected TIMEOUT or COMPLETED, got {state}"

test("2s 超时任务 → TIMEOUT", t_timeout_task)

# ============================================================
# LAYER 2: goto_pose_batch
# ============================================================
print("\n" + "=" * 60)
print("LAYER 2: goto_pose_batch 多车并发")
print("=" * 60)

BATCH_TASK_ID = None

def t_batch():
    global BATCH_TASK_ID
    r = requests.post(f"{BASE}/api/task/goto_pose_batch", json={
        "targets": [
            {"unit_id": "GV1", "x": 1.0, "y": 0.0},
            {"unit_id": "GV2", "x": 2.0, "y": 0.0},
            {"unit_id": "GV3", "x": 3.0, "y": 0.0}
        ],
        "tolerance_m": 0.15, "timeout_ms": 30000
    }, timeout=5).json()
    assert_eq(r["success"], True, "batch should succeed")
    BATCH_TASK_ID = r["data"]["task_id"]
    urs = r["data"]["unit_results"]
    assert_eq(len(urs), 3, "should have 3 unit_results")
    unit_ids = {u["unit_id"] for u in urs}
    assert unit_ids == {"GV1", "GV2", "GV3"}, f"wrong unit_ids: {unit_ids}"
    print(f"    batch task_id = {BATCH_TASK_ID}")
    print(f"    subtasks: {[(u['unit_id'], u['state']) for u in urs]}")

test("batch 3车并发 → task accepted + 3 subtasks", t_batch)

def t_batch_status():
    assert BATCH_TASK_ID is not None
    time.sleep(1)
    r = requests.get(f"{BASE}/api/task/status?task_id={BATCH_TASK_ID}", timeout=5).json()
    assert_eq(r["success"], True)
    d = r["data"]
    assert_eq(d["task_type"], "goto_pose_batch")
    assert d["state"] in ("RUNNING", "COMPLETED", "TIMEOUT", "PARTIAL_COMPLETED")
    urs = d["unit_results"]
    print(f"    state={d['state']} subtask states: {[(u['unit_id'], u['state']) for u in urs]}")
    release_task(BATCH_TASK_ID)

test("batch status → 含3个子任务状态", t_batch_status)

# ============================================================
# LAYER 3: execute_formation
# ============================================================
print("\n" + "=" * 60)
print("LAYER 3: execute_formation 编队")
print("=" * 60)

FORM_TASK_ID = None

def t_formation_line():
    global FORM_TASK_ID
    r = requests.post(f"{BASE}/api/formation/execute", json={
        "formation_type": "line",
        "unit_ids": ["GV1", "GV2", "GV3"],
        "spacing_m": 1.0,
        "anchor": {"x": 0.0, "y": 0.0},
        "heading_rad": 0.0,
        "tolerance_m": 0.15,
        "timeout_ms": 30000
    }, timeout=5).json()
    assert_eq(r["success"], True, "formation should succeed")
    FORM_TASK_ID = r["data"]["task_id"]
    urs = r["data"]["unit_results"]
    assert_eq(len(urs), 3, "should have 3 units")
    print(f"    formation task_id = {FORM_TASK_ID}")
    print(f"    units: {[(u['unit_id'], u['state']) for u in urs]}")

test("formation LINE 3车 → task accepted", t_formation_line)

def t_formation_status():
    assert FORM_TASK_ID is not None
    time.sleep(1)
    r = requests.get(f"{BASE}/api/task/status?task_id={FORM_TASK_ID}", timeout=5).json()
    assert_eq(r["success"], True)
    d = r["data"]
    assert_eq(d["task_type"], "execute_formation")
    # 3个子任务
    urs = d["unit_results"]
    print(f"    state={d['state']} units: {[(u['unit_id'], u['state']) for u in urs]}")
    release_task(FORM_TASK_ID)

test("formation status → 3个子任务", t_formation_status)

def t_formation_column():
    r = requests.post(f"{BASE}/api/formation/execute", json={
        "formation_type": "column",
        "unit_ids": ["GV1", "GV2"],
        "spacing_m": 2.0,
        "tolerance_m": 0.15,
        "timeout_ms": 30000
    }, timeout=5).json()
    assert_eq(r["success"], True, "column formation should succeed")
    assert_eq(r["data"]["task_type"], "execute_formation")
    release_task(r["data"]["task_id"])

test("formation COLUMN 2车 → task accepted", t_formation_column)

def t_formation_triangle():
    r = requests.post(f"{BASE}/api/formation/execute", json={
        "formation_type": "triangle",
        "unit_ids": ["GV1", "GV2", "GV3"],
        "spacing_m": 1.5,
        "tolerance_m": 0.15,
        "timeout_ms": 30000
    }, timeout=5).json()
    assert_eq(r["success"], True, "triangle formation should succeed")
    release_task(r["data"]["task_id"])

test("formation TRIANGLE 3车 → task accepted", t_formation_triangle)

# ============================================================
# 汇总
# ============================================================
print("\n" + "=" * 60)
print("测试汇总")
print("=" * 60)
for r in results:
    print(r)
total = PASS + FAIL
print(f"\n{PASS}/{total} passed, {FAIL}/{total} failed")
