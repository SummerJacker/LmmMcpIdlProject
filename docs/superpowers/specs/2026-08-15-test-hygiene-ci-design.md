# Test Hygiene and Python 3.10 CI Design

## Context

The `swarm-path-stop-plugin` branch currently completes the default suite with
`328 passed, 3 skipped`. The skipped modules are not offline unit tests: they
are sequential scripts that connect to the Console at `127.0.0.1:9001`, and one
of them can actuate units. Keeping those scripts under `mcp/tests/` makes the
default pytest collection boundary less explicit than the runtime safety
boundary.

This change makes the offline/real-environment distinction structural and adds
a reproducible GitHub Actions gate for the supported Python 3.10 environment.

## Goals

- Make `mcp/tests/` safe to run without Console, credentials, or robot access.
- Preserve the three real-Console checks as explicitly invoked manual tests.
- Run the complete offline suite and a syntax compilation check in GitHub
  Actions on Python 3.10.
- Add a repository-level regression check for the test-layout contract.
- Keep production behavior and the 14-tool MCP surface unchanged.

## Non-goals

- Rewriting the legacy sequential Console scripts as fine-grained pytest tests.
- Adding Python 3.11 or 3.12 compatibility work.
- Starting Console or simulator services in CI.
- Changing production source, IDL, SAU, Console, or cosnaming behavior.
- Removing historical tracked bytecode or log artifacts.

## Considered Approaches

### 1. Ignore live files only in the CI command

This is the smallest change, but it hides the safety boundary in one workflow
command. Local `pytest` and future CI jobs could accidentally use a different
selection.

### 2. Move live checks to a manual-test directory

This is the selected approach. The filesystem makes the boundary visible:
default pytest collection contains only offline tests, while real-Console
checks remain available through explicit commands. It requires only a small
repository reorganization and does not rewrite the test logic.

### 3. Convert all live scripts to standard marked pytest tests

This gives the most uniform test interface, but it would require a broad
rewrite of two top-level sequential scripts and their reporting behavior. That
risk is not justified for the CI bootstrap phase.

## Repository Layout

The following files move without changing their scenarios:

- `mcp/tests/test_api_v2.py` to `mcp/manual_tests/test_api_v2.py`
- `mcp/tests/test_api_full.py` to `mcp/manual_tests/test_api_full.py`
- `mcp/tests/test_mcp_tools.py` to `mcp/manual_tests/test_mcp_tools.py`

`mcp/manual_tests/README.md` will describe prerequisites, the actuation risk,
the `RUN_LIVE_CONSOLE_TESTS=1` opt-in gate, and exact commands. The environment
gate remains in every moved file so direct accidental execution cannot contact
Console.

`mcp/pytest.ini` will set `testpaths = tests` and register the `live_console`
marker. The moved pytest-based MCP tool check will carry that marker for
explicit live runs; the two API files remain manual sequential scripts rather
than being presented as ordinary unit tests.

## CI Workflow

`.github/workflows/python-tests.yml` will run for pushes and pull requests with
read-only repository permissions. It will:

1. Check out the repository.
2. Install CPython 3.10 with pip dependency caching keyed from
   `mcp/requirements.txt`.
3. Install the pinned/runtime test dependencies from that file.
4. Run `python -m compileall -q swarm_runtime plugins main.py task_api
   console_client robot_adapter.py deepseek_mcp_client.py` from `mcp/`.
5. Run `python -m pytest tests -q` from `mcp/`.

The workflow will not set `RUN_LIVE_CONSOLE_TESTS`, provide secrets, start a
Console, or invoke any file below `mcp/manual_tests/`.

## Safety and Failure Behavior

- A default local or CI pytest run cannot collect the live scripts because
  `testpaths` points only to `mcp/tests/`.
- A live check still refuses to run unless the operator explicitly sets
  `RUN_LIVE_CONSOLE_TESTS=1`.
- CI stops on dependency installation, compilation, or test failure and
  publishes a failing check; repository branch protection can require that
  check before merge.
- No fallback converts a failed live connection into an offline success.

## Verification Strategy

A new offline contract test will verify that:

- default pytest collection is rooted at `mcp/tests/`;
- the three named real-Console files are absent from that directory and present
  under `mcp/manual_tests/`;
- the workflow selects Python 3.10 and invokes the default offline suite;
- the workflow does not enable the live-test environment gate.

Implementation will follow red-green-refactor: add the contract test and
observe it fail against the current layout, make the minimal layout/config/CI
changes, then rerun the focused test and the full offline suite. Final
acceptance requires:

- `python -m pytest tests/test_repository_test_contract.py -q` passes;
- `python -m pytest tests -q` reports `328 passed` with no live skips;
- the documented live files remain protected by the opt-in gate;
- the specified `compileall` command exits successfully;
- `git diff --check` and the tracked worktree status are clean after commit.
