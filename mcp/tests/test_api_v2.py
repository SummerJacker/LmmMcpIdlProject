"""
MCP-IDL HTTP API test suite — clean, sequential, with proper timing.
"""
import json, time, requests

BASE = "http://127.0.0.1:9001"
pass_count = fail_count = 0

def check(name, condition, detail=""):
    global pass_count, fail_count
    if condition:
        pass_count += 1
        print(f"  PASS: {name}")
    else:
        fail_count += 1
        print(f"  FAIL: {name} -- {detail}")

print("=" * 60)
print("EXCEPTION TESTS")
print("=" * 60)

# --- unknown unit ---
r = requests.post(f"{BASE}/api/task/goto_pose", json={
    "unit_id": "GV999", "x": 3.0, "y": 5.0, "tolerance_m": 0.15, "timeout_ms": 30000
}, timeout=5).json()
check("unknown unit GV999 rejected", not r["success"])
check("  error_code=UNIT_NOT_FOUND", r.get("data", {}).get("error_code") == "UNIT_NOT_FOUND")

# --- missing params ---
r = requests.post(f"{BASE}/api/task/goto_pose", json={"unit_id": "GV1"}, timeout=5).json()
check("missing x/y rejected", not r["success"])

# --- negative tolerance ---
r = requests.post(f"{BASE}/api/task/goto_pose", json={
    "unit_id": "GV1", "x": 3.0, "y": 5.0, "tolerance_m": -1.0, "timeout_ms": 30000
}, timeout=5).json()
check("negative tolerance rejected", not r["success"])

# --- out of bounds ---
r = requests.post(f"{BASE}/api/task/goto_pose", json={
    "unit_id": "GV1", "x": 9999.0, "y": 9999.0, "tolerance_m": 0.15, "timeout_ms": 30000
}, timeout=5).json()
check("out-of-bounds rejected", not r["success"])

# --- empty batch ---
r = requests.post(f"{BASE}/api/task/goto_pose_batch", json={
    "targets": [], "tolerance_m": 0.15, "timeout_ms": 30000
}, timeout=5).json()
check("empty batch rejected", not r["success"])

# --- batch with bad unit ---
r = requests.post(f"{BASE}/api/task/goto_pose_batch", json={
    "targets": [{"unit_id": "GV999", "x": 1.0, "y": 0.0}],
    "tolerance_m": 0.15, "timeout_ms": 30000
}, timeout=5).json()
check("batch bad unit rejected", not r["success"])

# --- formation: line needs >=2 ---
r = requests.post(f"{BASE}/api/formation/execute", json={
    "formation_type": "line", "unit_ids": ["GV1"], "spacing_m": 1.0,
    "tolerance_m": 0.15, "timeout_ms": 30000
}, timeout=5).json()
check("formation line 1 unit rejected", not r["success"])

# --- formation: triangle needs >=3 ---
r = requests.post(f"{BASE}/api/formation/execute", json={
    "formation_type": "triangle", "unit_ids": ["GV1", "GV2"], "spacing_m": 1.0,
    "tolerance_m": 0.15, "timeout_ms": 30000
}, timeout=5).json()
check("formation triangle 2 unit rejected", not r["success"])

# --- formation: unknown type ---
r = requests.post(f"{BASE}/api/formation/execute", json={
    "formation_type": "circle", "unit_ids": ["GV1", "GV2", "GV3"], "spacing_m": 1.0,
    "tolerance_m": 0.15, "timeout_ms": 30000
}, timeout=5).json()
check("formation circle rejected", not r["success"])

# --- cancel nonexistent ---
r = requests.post(f"{BASE}/api/task/cancel", json={"task_id": "nonexistent"}, timeout=5).json()
check("cancel nonexistent rejected", not r["success"])

# --- status nonexistent ---
r = requests.get(f"{BASE}/api/task/status?task_id=nonexistent", timeout=5).json()
check("status nonexistent rejected", not r["success"])

print("\n" + "=" * 60)
print("HAPPY-PATH TESTS (with timing)")
print("=" * 60)

# --- goto_pose with short timeout ---
r = requests.post(f"{BASE}/api/task/goto_pose", json={
    "unit_id": "GV1", "x": 50.0, "y": 50.0, "tolerance_m": 0.15, "timeout_ms": 2000
}, timeout=5).json()
check("goto_pose GV1 accepted", r["success"], r.get("message"))
task1 = r["data"]["task_id"] if r["success"] else None
check("  returns task_id", task1 and "goto-" in task1)
check("  state=RUNNING", r["data"].get("state") == "RUNNING")

# --- get_task_status ---
if task1:
    r = requests.get(f"{BASE}/api/task/status?task_id={task1}", timeout=5).json()
    check("status returns success", r["success"])
    d = r["data"]
    check("  has task_type", d.get("task_type") == "goto_pose")
    check("  has unit_results", len(d.get("unit_results", [])) >= 1)
    check("  has audit_log", "audit_log" in d)
    check("  unit_id in result", d["unit_results"][0]["unit_id"] == "GV1")

# --- wait for timeout ---
print("  (waiting 3s for timeout...)")
time.sleep(3)
if task1:
    r = requests.get(f"{BASE}/api/task/status?task_id={task1}", timeout=5).json()
    state = r["data"]["state"]
    check(f"timeout complete -> {state}", state in ("TIMEOUT", "COMPLETED"),
          f"got state={state}")

# --- goto_pose_batch ---
print("  (waiting 2s for unit cleanup...)")
time.sleep(2)  # let cleanup timer release units
r = requests.post(f"{BASE}/api/task/goto_pose_batch", json={
    "targets": [
        {"unit_id": "GV1", "x": 1.0, "y": 0.0},
        {"unit_id": "GV2", "x": 2.0, "y": 0.0},
        {"unit_id": "GV3", "x": 3.0, "y": 0.0}
    ],
    "tolerance_m": 0.15, "timeout_ms": 30000
}, timeout=5).json()
check("batch 3 units accepted", r["success"], r.get("message"))
batch_id = r["data"]["task_id"] if r["success"] else None
if r["success"]:
    urs = r["data"]["unit_results"]
    check("  3 subtasks created", len(urs) == 3)
    check("  correct unit_ids", {u["unit_id"] for u in urs} == {"GV1", "GV2", "GV3"})

# --- batch status ---
if batch_id:
    r = requests.get(f"{BASE}/api/task/status?task_id={batch_id}", timeout=5).json()
    check("batch status success", r["success"])
    check("  task_type=gotoposebatch", r["data"]["task_type"] == "goto_pose_batch")
    urs = r["data"]["unit_results"]
    all_running = all(u["state"] == "RUNNING" for u in urs)
    check(f"  all subtasks RUNNING", all_running,
          f"states: {[(u['unit_id'], u['state']) for u in urs]}")

# --- cancel batch ---
if batch_id:
    r = requests.post(f"{BASE}/api/task/cancel", json={"task_id": batch_id}, timeout=5).json()
    check("cancel batch succeeded", r["success"], r.get("message"))
    if r["success"]:
        check("  state=CANCELLED", r["data"]["state"] == "CANCELLED")

# --- unit busy check ---
print("\n" + "=" * 60)
print("UNIT BUSY CHECK")
print("=" * 60)

# Create a task to occupy GV1
r = requests.post(f"{BASE}/api/task/goto_pose", json={
    "unit_id": "GV1", "x": 10.0, "y": 10.0, "tolerance_m": 0.15, "timeout_ms": 10000
}, timeout=5).json()
busy_task = r["data"]["task_id"] if r["success"] else None
check("create task on GV1", r["success"])

# Try to use GV1 in another task
r = requests.post(f"{BASE}/api/task/goto_pose", json={
    "unit_id": "GV1", "x": 5.0, "y": 5.0, "tolerance_m": 0.15, "timeout_ms": 5000
}, timeout=5).json()
check("double-book GV1 rejected", not r["success"],
      r.get("message"))
check("  error_code=UNIT_BUSY", r.get("data", {}).get("error_code") == "UNIT_BUSY",
      r.get("data", {}))

# Clean up
if busy_task:
    requests.post(f"{BASE}/api/task/cancel", json={"task_id": busy_task}, timeout=5)

# --- formation ---
print("\n" + "=" * 60)
print("FORMATION")
print("=" * 60)

time.sleep(2)  # cleanup
for ftype, ids, min_units in [("line", ["GV1", "GV2", "GV3"], 2),
                                ("column", ["GV1", "GV2"], 2),
                                ("triangle", ["GV1", "GV2", "GV3"], 3)]:
    r = requests.post(f"{BASE}/api/formation/execute", json={
        "formation_type": ftype, "unit_ids": ids, "spacing_m": 1.0,
        "tolerance_m": 0.15, "timeout_ms": 30000
    }, timeout=5).json()
    check(f"{ftype} {len(ids)}u accepted", r["success"], r.get("message"))
    if r["success"]:
        check(f"  {len(ids)} subtasks", len(r["data"]["unit_results"]) == len(ids))
        # cancel to free units
        tid = r["data"]["task_id"]
        requests.post(f"{BASE}/api/task/cancel", json={"task_id": tid}, timeout=5)

# ============================================================
print("\n" + "=" * 60)
total = pass_count + fail_count
print(f"RESULTS: {pass_count}/{total} passed, {fail_count}/{total} failed")
