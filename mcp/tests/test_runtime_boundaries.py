from __future__ import annotations

import ast
import hashlib
import json
from pathlib import Path


MCP_ROOT = Path(__file__).parents[1]
MAIN_PATH = MCP_ROOT / "main.py"
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


def top_level_nested_function_names(path: Path, parent_name: str) -> set[str]:
    tree = ast.parse(path.read_text(encoding="utf-8"), filename=str(path))
    for node in tree.body:
        if (
            isinstance(node, (ast.FunctionDef, ast.AsyncFunctionDef))
            and node.name == parent_name
        ):
            return {
                child.name
                for child in node.body
                if isinstance(child, (ast.FunctionDef, ast.AsyncFunctionDef))
            }
    raise AssertionError(f"function not found: {parent_name}")


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


def test_path_and_stop_are_not_static_main_tools() -> None:
    names = top_level_nested_function_names(MAIN_PATH, "create_app")

    assert "followPath" not in names
    assert "stopUnits" not in names


def test_profiles_enable_motion_but_only_mock_profile_enables_mock_platform() -> None:
    def enabled(name: str) -> set[str]:
        profile = json.loads(
            (MCP_ROOT / "profiles" / name).read_text(encoding="utf-8")
        )
        return {
            item["id"]
            for item in profile["plugins"]
            if item.get("enabled", True)
        }

    default = enabled("default.json")
    mock = enabled("mock-navigation.json")
    assert "capability.motion" in default
    assert "capability.motion" in mock
    assert "platform.mock-navigation" not in default
    assert "platform.mock-navigation" in mock


def test_task_idl_is_unchanged_and_has_no_generic_json_escape_hatch() -> None:
    raw = IDL_PATH.read_bytes()
    normalized = IDL_PATH.read_text(encoding="utf-8").replace(" ", "").casefold()

    assert hashlib.sha256(raw).hexdigest().upper() == IDL_SHA256
    assert "execute(stringoperation,stringjson)" not in normalized
