from __future__ import annotations

import ast
import hashlib
import json
from pathlib import Path


MCP_ROOT = Path(__file__).parents[1]
RUNTIME_ROOT = MCP_ROOT / "swarm_runtime"
PLUGINS_ROOT = MCP_ROOT / "plugins"
CAPABILITY_ROOT = PLUGINS_ROOT / "capabilities"
KISORB_ROOT = PLUGINS_ROOT / "platforms" / "kisorb_sau"
IDL_PATH = MCP_ROOT / "idl" / "mcp_swarm_task.idl"
IDL_SHA256 = "2EA71279A5FD8C0AD1157ED38F5EA7E04621EF439DB16E86CBEA65FEDB625F1A"
FORBIDDEN_CORE_IMPORTS = (
    "robot_adapter",
    "console_client",
    "config",
    "plugins.platforms",
    "SAU",
)


def imported_modules(path: Path) -> set[str]:
    tree = ast.parse(path.read_text(encoding="utf-8"), filename=str(path))
    modules: set[str] = set()
    for node in ast.walk(tree):
        if isinstance(node, ast.Import):
            modules.update(alias.name for alias in node.names)
        elif isinstance(node, ast.ImportFrom) and node.module:
            modules.add(node.module)
    return modules


def test_runtime_and_capability_plugins_do_not_import_platform_implementation() -> None:
    offenders: list[str] = []
    for root in (RUNTIME_ROOT, CAPABILITY_ROOT):
        for path in root.rglob("*.py"):
            for module in imported_modules(path):
                if module.startswith(FORBIDDEN_CORE_IMPORTS):
                    offenders.append(f"{path.relative_to(MCP_ROOT)} -> {module}")

    assert offenders == []


def test_only_kisorb_platform_package_imports_legacy_transport_modules() -> None:
    legacy_imports: dict[Path, set[str]] = {}
    for path in PLUGINS_ROOT.rglob("*.py"):
        matches = {
            module
            for module in imported_modules(path)
            if module.startswith(("robot_adapter", "console_client"))
        }
        if matches:
            legacy_imports[path] = matches

    assert legacy_imports
    assert all(path.is_relative_to(KISORB_ROOT) for path in legacy_imports)
    imported = set().union(*legacy_imports.values())
    assert {"robot_adapter", "console_client"} <= imported


def test_live_unit_resolver_keeps_robot_adapter_out_of_runtime_core() -> None:
    kisorb_resolver = KISORB_ROOT / "unit_resolver.py"
    runtime_resolver = RUNTIME_ROOT / "registry" / "unit_resolver.py"

    assert kisorb_resolver.is_file()
    assert "robot_adapter" in imported_modules(kisorb_resolver)
    assert "robot_adapter" not in imported_modules(runtime_resolver)


def test_default_profile_excludes_mock_platform() -> None:
    profile = json.loads(
        (MCP_ROOT / "profiles" / "default.json").read_text(encoding="utf-8")
    )
    enabled = {
        item["id"] for item in profile["plugins"] if item.get("enabled", True)
    }

    assert "platform.mock-navigation" not in enabled


def test_task_idl_is_unchanged_and_has_no_generic_json_escape_hatch() -> None:
    raw = IDL_PATH.read_bytes()
    normalized = IDL_PATH.read_text(encoding="utf-8").replace(" ", "").casefold()

    assert hashlib.sha256(raw).hexdigest().upper() == IDL_SHA256
    assert "execute(stringoperation,stringjson)" not in normalized
