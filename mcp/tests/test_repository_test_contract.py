from configparser import ConfigParser
from pathlib import Path


MCP_ROOT = Path(__file__).resolve().parents[1]
REPOSITORY_ROOT = MCP_ROOT.parent
LIVE_FILENAMES = ("test_api_v2.py", "test_api_full.py", "test_mcp_tools.py")


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
        assert "RUN_LIVE_CONSOLE_TESTS" in manual_test.read_text(encoding="utf-8")

    mcp_tools = MCP_ROOT / "manual_tests" / "test_mcp_tools.py"
    assert "pytestmark = pytest.mark.live_console" in mcp_tools.read_text(encoding="utf-8")

    manual_readme = (MCP_ROOT / "manual_tests" / "README.md").read_text(encoding="utf-8")
    assert "may actuate" in manual_readme
    assert "RUN_LIVE_CONSOLE_TESTS=1" in manual_readme

    workflow = (REPOSITORY_ROOT / ".github" / "workflows" / "python-tests.yml").read_text(
        encoding="utf-8"
    )
    assert 'python-version: "3.10"' in workflow
    assert "python -m pytest tests -q" in workflow
    assert (
        "python -m compileall -q swarm_runtime plugins main.py task_api console_client "
        "robot_adapter.py deepseek_mcp_client.py" in workflow
    )
    assert "RUN_LIVE_CONSOLE_TESTS" not in workflow
