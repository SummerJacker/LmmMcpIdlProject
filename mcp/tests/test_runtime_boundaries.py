from __future__ import annotations

import ast
import hashlib
import json
from pathlib import Path

import pytest


MCP_ROOT = Path(__file__).parents[1]
MAIN_PATH = MCP_ROOT / "main.py"
RUNTIME_ROOT = MCP_ROOT / "swarm_runtime"
PLUGINS_ROOT = MCP_ROOT / "plugins"
CAPABILITY_ROOT = PLUGINS_ROOT / "capabilities"
KISORB_ROOT = PLUGINS_ROOT / "platforms" / "kisorb_sau"
IDL_PATH = MCP_ROOT / "idl" / "mcp_swarm_task.idl"
IDL_SHA256 = "5FC9B1BAB1FC5A1C7A807C9D13E11AA368DC4D5F3577396C783C7F6DCBAD8E63"
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


def _is_mcp_member(node: ast.expr, member: str) -> bool:
    return (
        isinstance(node, ast.Attribute)
        and node.attr == member
        and isinstance(node.value, ast.Name)
        and node.value.id == "mcp"
    )


def _literal_tool_name(node: ast.expr, registration: str) -> str:
    if isinstance(node, ast.Constant) and isinstance(node.value, str):
        if node.value:
            return node.value
    raise AssertionError(f"unresolvable {registration} tool name")


def static_fastmcp_tool_names(path: Path, parent_name: str) -> set[str]:
    tree = ast.parse(path.read_text(encoding="utf-8"), filename=str(path))
    for node in tree.body:
        if (
            isinstance(node, (ast.FunctionDef, ast.AsyncFunctionDef))
            and node.name == parent_name
        ):
            parent = node
            break
    else:
        raise AssertionError(f"function not found: {parent_name}")

    local_function_names = {
        child.name
        for child in ast.walk(parent)
        if child is not parent
        and isinstance(child, (ast.FunctionDef, ast.AsyncFunctionDef))
    }
    decorator_call_ids = {
        id(decorator)
        for child in ast.walk(parent)
        if isinstance(child, (ast.FunctionDef, ast.AsyncFunctionDef))
        for decorator in child.decorator_list
        if isinstance(decorator, ast.Call)
    }
    names: set[str] = set()
    for child in ast.walk(parent):
        if isinstance(child, (ast.FunctionDef, ast.AsyncFunctionDef)):
            for decorator in child.decorator_list:
                if _is_mcp_member(decorator, "tool"):
                    names.add(child.name)
                    continue
                if not (
                    isinstance(decorator, ast.Call)
                    and _is_mcp_member(decorator.func, "tool")
                ):
                    continue
                explicit_name = next(
                    (
                        keyword.value
                        for keyword in decorator.keywords
                        if keyword.arg == "name"
                    ),
                    None,
                )
                if explicit_name is not None:
                    if (
                        isinstance(explicit_name, ast.Constant)
                        and explicit_name.value is None
                    ):
                        names.add(child.name)
                    else:
                        names.add(
                            _literal_tool_name(explicit_name, "@mcp.tool")
                        )
                elif decorator.args:
                    if len(decorator.args) != 1:
                        raise AssertionError(
                            "unresolvable @mcp.tool registration"
                        )
                    positional_name = decorator.args[0]
                    if (
                        isinstance(positional_name, ast.Constant)
                        and positional_name.value is None
                    ):
                        names.add(child.name)
                    else:
                        names.add(
                            _literal_tool_name(
                                positional_name,
                                "@mcp.tool",
                            )
                        )
                else:
                    names.add(child.name)

        if (
            isinstance(child, ast.Call)
            and _is_mcp_member(child.func, "tool")
            and id(child) not in decorator_call_ids
        ):
            explicit_name = next(
                (
                    keyword.value
                    for keyword in child.keywords
                    if keyword.arg == "name"
                ),
                None,
            )
            if not (
                len(child.args) == 1
                and isinstance(child.args[0], ast.Name)
                and child.args[0].id in local_function_names
            ):
                raise AssertionError("unresolvable mcp.tool registration")
            if explicit_name is None or (
                isinstance(explicit_name, ast.Constant)
                and explicit_name.value is None
            ):
                names.add(child.args[0].id)
            else:
                names.add(_literal_tool_name(explicit_name, "mcp.tool"))

        if not (
            isinstance(child, ast.Call)
            and _is_mcp_member(child.func, "add_tool")
        ):
            continue
        explicit_name = next(
            (
                keyword.value
                for keyword in child.keywords
                if keyword.arg == "name"
            ),
            None,
        )
        if explicit_name is not None:
            names.add(_literal_tool_name(explicit_name, "mcp.add_tool"))
        elif (
            len(child.args) == 1
            and isinstance(child.args[0], ast.Name)
            and child.args[0].id in local_function_names
        ):
            names.add(child.args[0].id)
        elif len(child.args) == 1:
            names.add(_literal_tool_name(child.args[0], "mcp.add_tool"))
        else:
            raise AssertionError("unresolvable mcp.add_tool registration")

    return names


def test_static_fastmcp_tool_names_honors_aliases_and_nested_registration(
    tmp_path: Path,
) -> None:
    source = tmp_path / "sample.py"
    source.write_text(
        """
def create_app():
    @mcp.tool
    async def directTool():
        pass

    if enabled:
        @mcp.tool(name="followPath")
        async def implementation_name():
            pass
""",
        encoding="utf-8",
    )

    assert static_fastmcp_tool_names(source, "create_app") == {
        "directTool",
        "followPath",
    }


def test_static_fastmcp_tool_names_uses_function_name_for_none_decorator(
    tmp_path: Path,
) -> None:
    source = tmp_path / "sample.py"
    source.write_text(
        """
def create_app():
    @mcp.tool(None)
    async def stopUnits():
        pass
""",
        encoding="utf-8",
    )

    assert static_fastmcp_tool_names(source, "create_app") == {"stopUnits"}


def test_static_fastmcp_tool_names_detects_direct_tool_call(tmp_path: Path) -> None:
    source = tmp_path / "sample.py"
    source.write_text(
        """
def create_app():
    async def stopUnits():
        pass

    if enabled:
        mcp.tool(stopUnits)
""",
        encoding="utf-8",
    )

    assert static_fastmcp_tool_names(source, "create_app") == {"stopUnits"}


def test_static_fastmcp_tool_names_rejects_unresolvable_direct_tool_call(
    tmp_path: Path,
) -> None:
    source = tmp_path / "sample.py"
    source.write_text(
        """
def create_app():
    dynamic_tool = build_tool()
    mcp.tool(dynamic_tool)
""",
        encoding="utf-8",
    )

    with pytest.raises(AssertionError, match="unresolvable mcp.tool"):
        static_fastmcp_tool_names(source, "create_app")


def test_static_fastmcp_tool_names_detects_direct_add_tool(tmp_path: Path) -> None:
    source = tmp_path / "sample.py"
    source.write_text(
        """
def create_app():
    async def stopUnits():
        pass

    if enabled:
        mcp.add_tool(stopUnits)
""",
        encoding="utf-8",
    )

    assert static_fastmcp_tool_names(source, "create_app") == {"stopUnits"}


def test_static_fastmcp_tool_names_rejects_unresolvable_direct_registration(
    tmp_path: Path,
) -> None:
    source = tmp_path / "sample.py"
    source.write_text(
        """
def create_app():
    dynamic_tool = build_tool()
    mcp.add_tool(dynamic_tool)
""",
        encoding="utf-8",
    )

    with pytest.raises(AssertionError, match="unresolvable mcp.add_tool"):
        static_fastmcp_tool_names(source, "create_app")


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


def test_main_does_not_statically_register_path_or_stop_tools() -> None:
    names = static_fastmcp_tool_names(MAIN_PATH, "create_app")

    assert "followPath" not in names
    assert "stopUnits" not in names


def test_default_does_not_enable_mock_but_mock_navigation_profile_does() -> None:
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
