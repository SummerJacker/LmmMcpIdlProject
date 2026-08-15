import ast
from configparser import ConfigParser
from pathlib import Path

import pytest


MCP_ROOT = Path(__file__).resolve().parents[1]
REPOSITORY_ROOT = MCP_ROOT.parent
LIVE_FILENAMES = ("test_api_v2.py", "test_api_full.py", "test_mcp_tools.py")
COMPILE_COMMAND = (
    "python -m compileall -q swarm_runtime plugins main.py task_api console_client "
    "robot_adapter.py deepseek_mcp_client.py"
)


def _assert_live_console_guard(source):
    module = ast.parse(source)
    allowed_prefixes = (ast.Import, ast.ImportFrom)

    for statement in module.body:
        if isinstance(statement, allowed_prefixes):
            continue
        if isinstance(statement, ast.Expr) and isinstance(statement.value, ast.Constant):
            if isinstance(statement.value.value, str):
                continue
        if (
            isinstance(statement, ast.Assign)
            and len(statement.targets) == 1
            and isinstance(statement.targets[0], ast.Name)
            and statement.targets[0].id == "pytestmark"
        ):
            continue
        assert isinstance(statement, ast.If)
        assert _is_live_console_condition(statement.test)
        assert _has_module_level_skip(statement)
        return

    raise AssertionError("missing live Console environment guard")


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
    for statement in guard.body:
        if not (isinstance(statement, ast.Expr) and isinstance(statement.value, ast.Call)):
            continue
        call = statement.value
        if not (
            isinstance(call.func, ast.Attribute)
            and isinstance(call.func.value, ast.Name)
            and call.func.value.id == "pytest"
            and call.func.attr == "skip"
        ):
            continue
        if any(
            keyword.arg == "allow_module_level"
            and isinstance(keyword.value, ast.Constant)
            and keyword.value.value is True
            for keyword in call.keywords
        ):
            return True
    return False


def _active_workflow_lines(workflow):
    return [
        (len(line) - len(line.lstrip(" ")), line.strip())
        for line in workflow.splitlines()
        if line.strip() and not line.lstrip().startswith("#")
    ]


def _offline_tests_block(lines):
    jobs_index = next(
        (index for index, (indent, text) in enumerate(lines) if indent == 0 and text == "jobs:"),
        None,
    )
    assert jobs_index is not None
    jobs_indent = lines[jobs_index][0]
    jobs_end = next(
        (
            index
            for index, (indent, _) in enumerate(lines[jobs_index + 1 :], jobs_index + 1)
            if indent <= jobs_indent
        ),
        len(lines),
    )
    child_indent = min(indent for indent, _ in lines[jobs_index + 1 : jobs_end])
    job_index = next(
        (
            index
            for index, (indent, text) in enumerate(lines[jobs_index + 1 : jobs_end], jobs_index + 1)
            if indent == child_indent and text == "offline-tests:"
        ),
        None,
    )
    assert job_index is not None
    job_indent = lines[job_index][0]
    end_index = next(
        (
            index
            for index, (indent, _) in enumerate(lines[job_index + 1 :], job_index + 1)
            if indent <= job_indent
        ),
        len(lines),
    )
    return [text for _, text in lines[job_index + 1 : end_index]]


def _assert_offline_workflow(workflow):
    lines = _active_workflow_lines(workflow)
    active_text = "\n".join(text for _, text in lines)
    assert not any(text.startswith("services:") for _, text in lines)
    assert "${{" not in active_text or "secrets." not in active_text.lower()
    assert "RUN_LIVE_CONSOLE_TESTS" not in active_text
    assert "manual_tests" not in active_text

    block = _offline_tests_block(lines)
    for expected in (
        "runs-on: ubuntu-latest",
        "working-directory: mcp",
        "uses: actions/checkout@v4",
        "uses: actions/setup-python@v5",
        'python-version: "3.10"',
        "cache: pip",
        "cache-dependency-path: mcp/requirements.txt",
    ):
        assert any(text in (expected, f"- {expected}") for text in block)
    for command in (
        "python -m pip install -r requirements.txt",
        COMPILE_COMMAND,
        "python -m pytest tests -q",
    ):
        assert any(text in (f"- run: {command}", f"run: {command}") for text in block)


def test_default_ci_boundary_excludes_live_console_checks():
    pytest_ini = MCP_ROOT / "pytest.ini"
    assert pytest_ini.exists()

    config = ConfigParser()
    config.read(pytest_ini)
    assert config["pytest"]["testpaths"].split() == ["tests"]
    assert "live_console" in config["pytest"]["markers"]

    for filename in LIVE_FILENAMES:
        assert not (MCP_ROOT / "tests" / filename).exists()
        manual_test = MCP_ROOT / "manual_tests" / filename
        assert manual_test.exists()
        _assert_live_console_guard(manual_test.read_text(encoding="utf-8"))

    with pytest.raises(AssertionError):
        _assert_live_console_guard(
            '"""RUN_LIVE_CONSOLE_TESTS appears only in a docstring."""\nprint("unsafe")\n'
        )
    with pytest.raises(AssertionError):
        _assert_live_console_guard("# RUN_LIVE_CONSOLE_TESTS\nprint('unsafe')\n")

    mcp_tools = MCP_ROOT / "manual_tests" / "test_mcp_tools.py"
    assert "pytestmark = pytest.mark.live_console" in mcp_tools.read_text(encoding="utf-8")

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
                "      - run: python -m pytest tests -q",
                "      # - run: python -m pytest tests -q",
            )
        )
    with pytest.raises(AssertionError):
        _assert_offline_workflow(
            workflow.replace(f"      - run: {COMPILE_COMMAND}\n", "")
            + f"\n- run: {COMPILE_COMMAND}\n"
        )
