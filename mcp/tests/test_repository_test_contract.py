import ast
from configparser import ConfigParser
from pathlib import Path

import pytest


MCP_ROOT = Path(__file__).resolve().parents[1]
REPOSITORY_ROOT = MCP_ROOT.parent
LIVE_FILENAMES = ("test_api_v2.py", "test_api_full.py", "test_mcp_tools.py")
ALLOWED_IMPORT_ROOTS = {
    "asyncio",
    "json",
    "os",
    "sys",
    "time",
    "urllib",
    "requests",
    "pytest",
}
COMPILE_COMMAND = (
    "python -m compileall -q swarm_runtime plugins main.py task_api console_client "
    "robot_adapter.py deepseek_mcp_client.py"
)


def _assert_live_console_guard(source):
    module = ast.parse(source)
    allowed_prefixes = (ast.Import, ast.ImportFrom)

    for statement in module.body:
        if isinstance(statement, allowed_prefixes):
            _assert_allowed_import(statement)
            continue
        if isinstance(statement, ast.Expr) and isinstance(statement.value, ast.Constant):
            if isinstance(statement.value.value, str):
                continue
        if _is_live_console_marker_assignment(statement):
            continue
        assert isinstance(statement, ast.If)
        assert _is_live_console_condition(statement.test)
        assert not statement.orelse
        assert _has_module_level_skip(statement)
        return

    raise AssertionError("missing live Console environment guard")


def _is_live_console_marker(value):
    return (
        isinstance(value, ast.Attribute)
        and value.attr == "live_console"
        and isinstance(value.value, ast.Attribute)
        and value.value.attr == "mark"
        and isinstance(value.value.value, ast.Name)
        and value.value.value.id == "pytest"
    )


def _is_live_console_marker_assignment(statement):
    return (
        isinstance(statement, ast.Assign)
        and len(statement.targets) == 1
        and isinstance(statement.targets[0], ast.Name)
        and statement.targets[0].id == "pytestmark"
        and _is_live_console_marker(statement.value)
    )


def _assert_allowed_import(statement):
    if isinstance(statement, ast.Import):
        roots = [alias.name.split(".")[0] for alias in statement.names]
    else:
        assert statement.module is not None
        roots = [statement.module.split(".")[0]]
    assert set(roots) <= ALLOWED_IMPORT_ROOTS


def _assert_live_console_marker(source):
    module = ast.parse(source)
    assert sum(_is_live_console_marker_assignment(statement) for statement in module.body) == 1


def _pytest_marker_names(markers):
    return {
        line.strip().split(":", 1)[0]
        for line in markers.splitlines()
        if line.strip()
    }


def _is_live_console_condition(condition):
    return (
        isinstance(condition, ast.Compare)
        and len(condition.ops) == len(condition.comparators) == 1
        and isinstance(condition.ops[0], ast.NotEq)
        and isinstance(condition.left, ast.Call)
        and isinstance(condition.left.func, ast.Attribute)
        and isinstance(condition.left.func.value, ast.Name)
        and condition.left.func.value.id == "os"
        and condition.left.func.attr == "getenv"
        and len(condition.left.args) == 1
        and not condition.left.keywords
        and isinstance(condition.left.args[0], ast.Constant)
        and condition.left.args[0].value == "RUN_LIVE_CONSOLE_TESTS"
        and isinstance(condition.comparators[0], ast.Constant)
        and condition.comparators[0].value == "1"
    )


def _has_module_level_skip(guard):
    if len(guard.body) != 1:
        return False
    statement = guard.body[0]
    if not (isinstance(statement, ast.Expr) and isinstance(statement.value, ast.Call)):
        return False
    call = statement.value
    if not (
        isinstance(call.func, ast.Attribute)
        and isinstance(call.func.value, ast.Name)
        and call.func.value.id == "pytest"
        and call.func.attr == "skip"
    ):
        return False
    return (
        len(call.args) == 1
        and isinstance(call.args[0], ast.Constant)
        and isinstance(call.args[0].value, str)
        and len(call.keywords) == 1
        and call.keywords[0].arg == "allow_module_level"
        and isinstance(call.keywords[0].value, ast.Constant)
        and call.keywords[0].value.value is True
    )


EXPECTED_WORKFLOW = """name: Python tests

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
      - uses: actions/checkout@v6
      - uses: actions/setup-python@v6
        with:
          python-version: "3.10"
          cache: pip
          cache-dependency-path: mcp/requirements.txt
      - run: python -m pip install -r requirements.txt
      - run: python -m compileall -q swarm_runtime plugins main.py task_api console_client robot_adapter.py deepseek_mcp_client.py
      - run: python -m pytest tests -q
"""


def _assert_offline_workflow(workflow):
    assert workflow == EXPECTED_WORKFLOW


def test_default_ci_boundary_excludes_live_console_checks():
    pytest_ini = MCP_ROOT / "pytest.ini"
    assert pytest_ini.exists()

    config = ConfigParser()
    config.read(pytest_ini)
    assert config["pytest"]["testpaths"].split() == ["tests"]
    assert "live_console" in _pytest_marker_names(config["pytest"]["markers"])

    for filename in LIVE_FILENAMES:
        assert not (MCP_ROOT / "tests" / filename).exists()
        manual_test = MCP_ROOT / "manual_tests" / filename
        assert manual_test.exists()
        _assert_live_console_guard(manual_test.read_text(encoding="utf-8"))
    assert {path.name for path in (MCP_ROOT / "manual_tests").glob("test_*.py")} == set(
        LIVE_FILENAMES
    )

    with pytest.raises(AssertionError):
        _assert_live_console_guard(
            '"""RUN_LIVE_CONSOLE_TESTS appears only in a docstring."""\nprint("unsafe")\n'
        )
    with pytest.raises(AssertionError):
        _assert_live_console_guard("# RUN_LIVE_CONSOLE_TESTS\nprint('unsafe')\n")
    with pytest.raises(AssertionError):
        _assert_live_console_guard(
            "import os\n"
            "import pytest\n"
            "import subprocess\n"
            "if os.getenv('RUN_LIVE_CONSOLE_TESTS') != '1':\n"
            "    pytest.skip('unsafe', allow_module_level=True)\n"
        )
    with pytest.raises(AssertionError):
        _assert_live_console_guard(
            "import os\n"
            "import pytest\n"
            "import requests\n"
            "pytestmark = requests.post('http://127.0.0.1:9001')\n"
            "if os.getenv('RUN_LIVE_CONSOLE_TESTS') != '1':\n"
            "    pytest.skip('unsafe', allow_module_level=True)\n"
        )
    with pytest.raises(AssertionError):
        _assert_live_console_guard(
            "import os\n"
            "import pytest\n"
            "import requests\n"
            "if os.getenv('RUN_LIVE_CONSOLE_TESTS') != '1':\n"
            "    requests.post('http://127.0.0.1:9001')\n"
            "    pytest.skip('unsafe', allow_module_level=True)\n"
        )
    with pytest.raises(AssertionError):
        _assert_live_console_guard(
            "import os\n"
            "import pytest\n"
            "import requests\n"
            "if os.getenv('RUN_LIVE_CONSOLE_TESTS') != '1':\n"
            "    pytest.skip(requests.post('http://127.0.0.1:9001'), allow_module_level=True)\n"
        )

    mcp_tools = MCP_ROOT / "manual_tests" / "test_mcp_tools.py"
    mcp_tools_source = mcp_tools.read_text(encoding="utf-8")
    _assert_live_console_marker(mcp_tools_source)
    with pytest.raises(AssertionError):
        _assert_live_console_marker(
            mcp_tools_source.replace(
                "pytestmark = pytest.mark.live_console",
                "# pytestmark = pytest.mark.live_console",
            )
        )

    manual_readme = (MCP_ROOT / "manual_tests" / "README.md").read_text(encoding="utf-8")
    assert "may actuate" in manual_readme
    assert "RUN_LIVE_CONSOLE_TESTS=1" in manual_readme
    assert (
        "try {\n"
        '    $env:RUN_LIVE_CONSOLE_TESTS = "1"\n'
        "    python manual_tests/test_api_v2.py\n"
        "    python manual_tests/test_api_full.py\n"
        "    python -m pytest manual_tests/test_mcp_tools.py -q -m live_console\n"
        "}\n"
        "finally {\n"
        "    Remove-Item Env:RUN_LIVE_CONSOLE_TESTS -ErrorAction SilentlyContinue\n"
        "}\n"
    ) in manual_readme

    workflow = (REPOSITORY_ROOT / ".github" / "workflows" / "python-tests.yml").read_text(
        encoding="utf-8"
    )
    _assert_offline_workflow(workflow)

    with pytest.raises(AssertionError):
        _assert_offline_workflow(
            workflow.replace(
                "    runs-on: ubuntu-latest",
                "    permissions:\n      contents: write\n    runs-on: ubuntu-latest",
            )
        )
    with pytest.raises(AssertionError):
        _assert_offline_workflow(
            workflow.replace("  push:\n", "  push:\n    branches-ignore: [main]\n")
        )
    with pytest.raises(AssertionError):
        _assert_offline_workflow(
            workflow.replace(
                "        working-directory: mcp",
                "        working-directory: mcp\n        shell: echo {0}",
            )
        )
    with pytest.raises(AssertionError):
        _assert_offline_workflow(
            workflow.replace(
                "      - run: python -m pytest tests -q",
                '      - "continue-on-error": true\n        run: python -m pytest tests -q',
            )
        )
    with pytest.raises(AssertionError):
        _assert_offline_workflow(
            workflow.replace(
                "      - run: python -m pytest tests -q",
                "      # - run: python -m pytest tests -q",
            )
        )
    with pytest.raises(AssertionError):
        _assert_offline_workflow(
            workflow.replace(
                "      - run: python -m pytest tests -q",
                "      - uses: actions/checkout@v4\n"
                "        with:\n"
                "          run: python -m pytest tests -q",
            )
        )
    with pytest.raises(AssertionError):
        _assert_offline_workflow(workflow.replace("  push:\n", ""))
    with pytest.raises(AssertionError):
        _assert_offline_workflow(workflow.replace("  pull_request:\n", ""))
    with pytest.raises(AssertionError):
        _assert_offline_workflow(
            workflow.replace("  contents: read", "  contents: write")
        )
    with pytest.raises(AssertionError):
        _assert_offline_workflow(
            workflow.replace(
                "      - run: python -m pytest tests -q",
                "      - if: ${{ false }}\n        run: python -m pytest tests -q",
            )
        )
    with pytest.raises(AssertionError):
        _assert_offline_workflow(
            workflow.replace(
                "      - run: python -m pytest tests -q",
                "      - continue-on-error: true\n        run: python -m pytest tests -q",
            )
        )
    with pytest.raises(AssertionError):
        _assert_offline_workflow(
            workflow.replace(f"      - run: {COMPILE_COMMAND}\n", "")
            + "\n  other-job:\n"
            "    runs-on: ubuntu-latest\n"
            "    steps:\n"
            f"      - run: {COMPILE_COMMAND}\n"
        )
