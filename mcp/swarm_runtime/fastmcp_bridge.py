from __future__ import annotations

from fastmcp import FastMCP

from .errors import RuntimeRegistrationError
from .registry import ToolRegistry


def install_runtime_tools(mcp: FastMCP, registry: ToolRegistry) -> None:
    for tool in registry.list():
        if tool.callable.__name__ != tool.name:
            raise RuntimeRegistrationError(
                f"tool callable name {tool.callable.__name__} does not match {tool.name}"
            )
        mcp.add_tool(tool.callable)
