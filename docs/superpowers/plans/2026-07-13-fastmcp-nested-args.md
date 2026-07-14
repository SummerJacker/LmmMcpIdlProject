# FastMCP Nested Arguments Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Make every task-level FastMCP call transport flat or nested arguments as valid JSON and preserve useful CLI errors.

**Architecture:** Keep the existing one-shot FastMCP subprocess boundary. Replace per-field Python repr arguments with one `--input-json` payload, and combine stdout/stderr only on subprocess failure.

**Tech Stack:** Python 3.10, FastMCP CLI, pytest, `subprocess.run`.

---

### Task 1: Add command and error regression tests

**Files:**
- Modify: `mcp/tests/test_deepseek_mcp_client.py`

- [x] **Step 1: Test nested JSON command construction**

Patch `deepseek_mcp_client.subprocess.run`, call `run_mcp_call` with the real
`createFollowFormation` request shape, and assert the command contains exactly
one `--input-json` value whose `json.loads` result equals the input mapping.

- [x] **Step 2: Test failure diagnostics**

Return a failed `CompletedProcess` with a FastMCP validation error in stdout and
a cleanup warning in stderr. Assert both appear in the normalized JSON error.

- [x] **Step 3: Verify RED**

Run:

```powershell
Push-Location mcp
python -m pytest tests\test_deepseek_mcp_client.py -q
Pop-Location
```

Expected: the two new tests fail because the command uses `request=<repr>` and
failure handling discards stdout when stderr is non-empty.

### Task 2: Implement JSON transport and complete diagnostics

**Files:**
- Modify: `mcp/deepseek_mcp_client.py:680-705`

- [x] **Step 1: Build one JSON argument payload**

Replace the per-field loop with:

```python
cmd = [
    "fastmcp", "call", server_spec, tool, "--json", "--input-json",
    json.dumps(args, ensure_ascii=False),
]
```

- [x] **Step 2: Preserve stdout and stderr on failure**

Join non-empty `proc.stdout.strip()` and `proc.stderr.strip()` with a newline,
then return it in the existing normalized failure object.

- [x] **Step 3: Verify GREEN and regressions**

Run the focused file, then the repository Python suite excluding manual and
external API scripts. Expected: zero failures.

### Task 3: Safe FastMCP integration check

**Files:**
- No source changes.

- [x] **Step 1: Confirm formation status is IDLE**

Read `GET /api/task/formation/follow/status` and require
`has_active_formation=false`.

- [x] **Step 2: Call a nested tool without vehicle movement**

Invoke `moveFollowFormation` with target `(0,0)`. Because no formation is
active, Console must return `FORMATION_NOT_READY`. A FastMCP return code of zero
and that business response prove nested JSON parsing succeeded without sending
a movement RPC.

No Git step is included because the user manages Git separately.
