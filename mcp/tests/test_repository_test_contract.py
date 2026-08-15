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


def _active_workflow_lines(workflow):
    return [
        (len(line) - len(line.lstrip(" ")), line.strip())
        for line in workflow.splitlines()
        if line.strip() and not line.lstrip().startswith("#")
    ]


def _block_after(lines, index):
    indent = lines[index][0]
    end = next(
        (
            candidate
            for candidate, (child_indent, _) in enumerate(lines[index + 1 :], index + 1)
            if child_indent <= indent
        ),
        len(lines),
    )
    return lines[index + 1 : end]


def _top_level_block(lines, header):
    index = next(
        (index for index, (indent, text) in enumerate(lines) if indent == 0 and text == header),
        None,
    )
    assert index is not None
    return _block_after(lines, index)


def _direct_indent(lines):
    assert lines
    return min(indent for indent, _ in lines)


def _direct_texts(lines):
    indent = _direct_indent(lines)
    return [text for child_indent, text in lines if child_indent == indent]


def _direct_block(lines, header):
    indent = _direct_indent(lines)
    index = next(
        (
            index
            for index, (child_indent, text) in enumerate(lines)
            if child_indent == indent and text == header
        ),
        None,
    )
    assert index is not None
    return _block_after(lines, index)


def _offline_tests_block(lines):
    return _direct_block(_top_level_block(lines, "jobs:"), "offline-tests:")


def _step_blocks(steps):
    step_indent = _direct_indent(steps)
    starts = [
        index
        for index, (indent, text) in enumerate(steps)
        if indent == step_indent and text.startswith("- ")
    ]
    assert starts
    return [
        steps[start : next_start]
        for start, next_start in zip(starts, [*starts[1:], len(steps)])
    ]


def _is_action_step(step, action):
    step_indent, first_text = step[0]
    return first_text == f"- uses: {action}" or any(
        indent == step_indent + 2 and text == f"uses: {action}" for indent, text in step[1:]
    )


def _has_run_step(step, command):
    step_indent, first_text = step[0]
    return first_text == f"- run: {command}" or any(
        indent == step_indent + 2 and text == f"run: {command}" for indent, text in step[1:]
    )


def _setup_with_values(step):
    return _direct_texts(_direct_block(step[1:], "with:"))


def _assert_offline_workflow(workflow):
    lines = _active_workflow_lines(workflow)
    active_text = "\n".join(text for _, text in lines)
    assert not any(text.startswith("services:") for _, text in lines)
    assert "${{" not in active_text or "secrets." not in active_text.lower()
    assert "RUN_LIVE_CONSOLE_TESTS" not in active_text
    assert "manual_tests" not in active_text

    assert {"push:", "pull_request:"} <= set(_direct_texts(_top_level_block(lines, "on:")))
    assert _direct_texts(_top_level_block(lines, "permissions:")) == ["contents: read"]

    block = _offline_tests_block(lines)
    assert not any(text.lstrip("- ").startswith("if:") for _, text in block)
    assert not any(text.lstrip("- ").startswith("continue-on-error:") for _, text in block)
    assert "runs-on: ubuntu-latest" in _direct_texts(block)
    defaults = _direct_block(block, "defaults:")
    assert "working-directory: mcp" in _direct_texts(_direct_block(defaults, "run:"))

    steps = _step_blocks(_direct_block(block, "steps:"))
    assert any(_is_action_step(step, "actions/checkout@v4") for step in steps)
    setup_step = next(
        (step for step in steps if _is_action_step(step, "actions/setup-python@v5")),
        None,
    )
    assert setup_step is not None
    assert {
        'python-version: "3.10"',
        "cache: pip",
        "cache-dependency-path: mcp/requirements.txt",
    } <= set(_setup_with_values(setup_step))
    for command in (
        "python -m pip install -r requirements.txt",
        COMPILE_COMMAND,
        "python -m pytest tests -q",
    ):
        assert any(_has_run_step(step, command) for step in steps)


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
