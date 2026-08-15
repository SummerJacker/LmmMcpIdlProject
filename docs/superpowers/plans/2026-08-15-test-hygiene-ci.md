# Test Hygiene and Python 3.10 CI Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Make the default MCP pytest suite entirely offline-safe and add a GitHub Actions gate on Python 3.10 while preserving explicit access to the three real-Console checks.

**Architecture:** The filesystem is the primary safety boundary: ordinary tests remain in `mcp/tests/`, while live checks move to `mcp/manual_tests/` behind their existing environment opt-in. A repository contract test locks the layout, pytest configuration, and workflow invariants together; GitHub Actions then runs only the offline directory plus a syntax compilation gate.

**Tech Stack:** Python 3.10, pytest, pytest-asyncio, GitHub Actions, INI configuration, PowerShell verification commands.

---

## File Map

- Create `mcp/tests/test_repository_test_contract.py`: one offline regression test for the collection, manual-test, and CI safety boundary.
- Create `mcp/pytest.ini`: restrict default collection to `mcp/tests/` and register the live marker.
- Move `mcp/tests/test_api_v2.py` to `mcp/manual_tests/test_api_v2.py`: preserve the sequential live API scenarios.
- Move `mcp/tests/test_api_full.py` to `mcp/manual_tests/test_api_full.py`: preserve the full sequential live API scenarios.
- Move and modify `mcp/tests/test_mcp_tools.py` to `mcp/manual_tests/test_mcp_tools.py`: preserve the live MCP-to-Console test and mark it `live_console`.
- Create `mcp/manual_tests/README.md`: document the opt-in risk boundary and exact invocation commands.
- Create `.github/workflows/python-tests.yml`: run compilation and the offline suite on CPython 3.10.

### Task 1: Lock the offline CI boundary with a failing repository contract

**Files:**

- Create: `mcp/tests/test_repository_test_contract.py`
- Test: `mcp/tests/test_repository_test_contract.py`

- [ ] **Step 1: Write the failing contract test**

Create `mcp/tests/test_repository_test_contract.py` with this complete content:

```python
from __future__ import annotations

from configparser import ConfigParser
from pathlib import Path


MCP_ROOT = Path(__file__).resolve().parents[1]
REPOSITORY_ROOT = MCP_ROOT.parent
LIVE_FILENAMES = (
    "test_api_v2.py",
    "test_api_full.py",
    "test_mcp_tools.py",
)


def test_default_ci_boundary_excludes_live_console_checks():
    pytest_config_path = MCP_ROOT / "pytest.ini"
    assert pytest_config_path.is_file()

    config = ConfigParser()
    config.read(pytest_config_path, encoding="utf-8")
    assert config.get("pytest", "testpaths").split() == ["tests"]
    assert "live_console" in config.get("pytest", "markers")

    manual_root = MCP_ROOT / "manual_tests"
    for filename in LIVE_FILENAMES:
        assert not (MCP_ROOT / "tests" / filename).exists()
        manual_file = manual_root / filename
        assert manual_file.is_file()
        assert "RUN_LIVE_CONSOLE_TESTS" in manual_file.read_text(encoding="utf-8")

    mcp_tools = (manual_root / "test_mcp_tools.py").read_text(encoding="utf-8")
    assert "pytestmark = pytest.mark.live_console" in mcp_tools

    manual_readme = (manual_root / "README.md").read_text(encoding="utf-8")
    assert "may actuate" in manual_readme
    assert "RUN_LIVE_CONSOLE_TESTS=1" in manual_readme

    workflow = (
        REPOSITORY_ROOT / ".github" / "workflows" / "python-tests.yml"
    ).read_text(encoding="utf-8")
    assert 'python-version: "3.10"' in workflow
    assert "python -m pytest tests -q" in workflow
    assert (
        "python -m compileall -q swarm_runtime plugins main.py task_api "
        "console_client robot_adapter.py deepseek_mcp_client.py"
    ) in workflow
    assert "RUN_LIVE_CONSOLE_TESTS" not in workflow
```

- [ ] **Step 2: Run the contract test and verify RED**

Run from `mcp/`:

```powershell
$env:PYTHONDONTWRITEBYTECODE='1'
python -m pytest tests/test_repository_test_contract.py -q
```

Expected: `1 failed`; the first failure says that `mcp/pytest.ini` does not
exist. This proves the current repository does not yet satisfy the approved
boundary contract.

### Task 2: Establish the manual-test boundary and Python 3.10 workflow

**Files:**

- Create: `mcp/pytest.ini`
- Move: `mcp/tests/test_api_v2.py` to `mcp/manual_tests/test_api_v2.py`
- Move: `mcp/tests/test_api_full.py` to `mcp/manual_tests/test_api_full.py`
- Move and modify: `mcp/tests/test_mcp_tools.py` to `mcp/manual_tests/test_mcp_tools.py`
- Create: `mcp/manual_tests/README.md`
- Create: `.github/workflows/python-tests.yml`
- Test: `mcp/tests/test_repository_test_contract.py`

- [ ] **Step 1: Add the pytest collection configuration**

Create `mcp/pytest.ini`:

```ini
[pytest]
testpaths = tests
markers =
    live_console: requires an explicitly enabled real Console and may actuate units
```

- [ ] **Step 2: Move the three live files without changing their scenarios**

Move the files while preserving history:

```powershell
New-Item -ItemType Directory -Path 'mcp\manual_tests' -Force | Out-Null
git mv -- 'mcp/tests/test_api_v2.py' 'mcp/manual_tests/test_api_v2.py'
git mv -- 'mcp/tests/test_api_full.py' 'mcp/manual_tests/test_api_full.py'
git mv -- 'mcp/tests/test_mcp_tools.py' 'mcp/manual_tests/test_mcp_tools.py'
```

Do not remove or weaken the existing module-level
`RUN_LIVE_CONSOLE_TESTS != "1"` guards.

- [ ] **Step 3: Mark the pytest-based live MCP test**

In `mcp/manual_tests/test_mcp_tools.py`, add the module marker immediately
after `import pytest` and before the environment guard:

```python
import pytest

pytestmark = pytest.mark.live_console

if os.getenv("RUN_LIVE_CONSOLE_TESTS") != "1":
    pytest.skip(
        "manual live Console test may actuate units; set RUN_LIVE_CONSOLE_TESTS=1 explicitly",
        allow_module_level=True,
    )
```

- [ ] **Step 4: Document explicit manual execution**

Create `mcp/manual_tests/README.md`:

````markdown
# Manual Console Tests

These checks connect to the real Console at `127.0.0.1:9001`. Some scenarios
may actuate units. Run them only against an intentionally prepared and
supervised environment.

All commands must be run from `mcp/`, and every live run requires the explicit
`RUN_LIVE_CONSOLE_TESTS=1` opt-in.

PowerShell:

```powershell
$env:RUN_LIVE_CONSOLE_TESTS='1'
python manual_tests/test_api_v2.py
python manual_tests/test_api_full.py
python -m pytest manual_tests/test_mcp_tools.py -q -m live_console
Remove-Item Env:RUN_LIVE_CONSOLE_TESTS
```

Bash:

```bash
RUN_LIVE_CONSOLE_TESTS=1 python manual_tests/test_api_v2.py
RUN_LIVE_CONSOLE_TESTS=1 python manual_tests/test_api_full.py
RUN_LIVE_CONSOLE_TESTS=1 python -m pytest manual_tests/test_mcp_tools.py -q -m live_console
```
````

- [ ] **Step 5: Add the GitHub Actions workflow**

Create `.github/workflows/python-tests.yml`:

```yaml
name: Python tests

on:
  push:
  pull_request:

permissions:
  contents: read

jobs:
  offline-tests:
    runs-on: ubuntu-latest
    defaults:
      run:
        working-directory: mcp
    steps:
      - name: Check out repository
        uses: actions/checkout@v4

      - name: Set up Python 3.10
        uses: actions/setup-python@v5
        with:
          python-version: "3.10"
          cache: pip
          cache-dependency-path: mcp/requirements.txt

      - name: Install dependencies
        run: python -m pip install -r requirements.txt

      - name: Compile Python sources
        run: python -m compileall -q swarm_runtime plugins main.py task_api console_client robot_adapter.py deepseek_mcp_client.py

      - name: Run offline tests
        run: python -m pytest tests -q
```

- [ ] **Step 6: Run the focused test and verify GREEN**

Run from `mcp/`:

```powershell
$env:PYTHONDONTWRITEBYTECODE='1'
python -m pytest tests/test_repository_test_contract.py -q
```

Expected: `1 passed`.

- [ ] **Step 7: Run the complete offline suite**

Run from `mcp/`:

```powershell
$env:PYTHONDONTWRITEBYTECODE='1'
python -m pytest tests -q
```

Expected: `329 passed` with no skips and no Console connection attempts.

- [ ] **Step 8: Commit the implemented boundary**

Run from the repository root:

```powershell
git add -- .github/workflows/python-tests.yml mcp/pytest.ini mcp/manual_tests mcp/tests/test_repository_test_contract.py mcp/tests/test_api_v2.py mcp/tests/test_api_full.py mcp/tests/test_mcp_tools.py
git commit -m "ci: isolate live tests and add Python 3.10 gate"
```

Expected: one commit containing only the test-layout, documentation, and CI
files listed above.

### Task 3: Verify safety, repository cleanliness, and the remote branch

**Files:**

- Verify only; no intended source changes.

- [ ] **Step 1: Prove the manual directory remains opt-in**

Run from `mcp/` with the live gate explicitly absent:

```powershell
Remove-Item Env:RUN_LIVE_CONSOLE_TESTS -ErrorAction SilentlyContinue
$env:PYTHONDONTWRITEBYTECODE='1'
python -m pytest manual_tests -q
```

Expected: `3 skipped`; there must be no connection error from
`127.0.0.1:9001`, which proves each module stops before live work.

- [ ] **Step 2: Run fresh compilation and offline tests**

Run from `mcp/`:

```powershell
python -m compileall -q swarm_runtime plugins main.py task_api console_client robot_adapter.py deepseek_mcp_client.py
$env:PYTHONDONTWRITEBYTECODE='1'
python -m pytest tests -q
```

Expected: compilation exits `0`; pytest reports `329 passed` and no skips.

- [ ] **Step 3: Restore only tracked generated artifacts and check the diff**

Run from the repository root:

```powershell
git restore -- ':(glob)mcp/**/__pycache__/**' mcp/logs/client.log
git diff --check
git status --short --branch
```

Expected: `git diff --check` emits nothing. Status shows no uncommitted files
and shows `swarm-path-stop-plugin` ahead of its upstream only by the new local
commits.

- [ ] **Step 4: Push the verified branch and compare remote HEAD**

Run from the repository root:

```powershell
git push origin swarm-path-stop-plugin
$localHead = git rev-parse HEAD
$remoteHead = (git ls-remote origin refs/heads/swarm-path-stop-plugin).Split()[0]
if ($localHead -ne $remoteHead) { throw "remote branch does not match local HEAD" }
git status --short --branch
```

Expected: push succeeds, local and remote hashes match, and status is clean
with no ahead/behind count.
