from __future__ import annotations

import deepseek_mcp_client as client
from task_api.contracts import PRODUCTION_TOOL_NAMES


def test_interactive_client_whitelists_exact_production_tools() -> None:
    assert client._PRODUCTION_TASK_TOOLS == PRODUCTION_TOOL_NAMES


def test_system_prompt_exposes_task_level_tools_only() -> None:
    prompt = client.build_system_prompt()
    for name in PRODUCTION_TOOL_NAMES:
        assert name in prompt
    for legacy_name in (
        "send_move",
        "set_leader",
        "set_group_mode",
        "set_task_point",
        "goto_pose",
        "send_follow_formation",
    ):
        assert legacy_name not in prompt


def test_client_has_no_embedded_api_key() -> None:
    assert client.DEFAULT_DEEPSEEK_API_KEY == ""


def test_api_key_is_loaded_from_environment(monkeypatch) -> None:
    monkeypatch.setenv("DEEPSEEK_API_KEY", "env-test-key")
    assert client.configured_deepseek_api_key() == "env-test-key"
