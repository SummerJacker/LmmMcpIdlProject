"""Production FastMCP entry point for the task-level swarm contract.

By default only methods declared by mcp/idl/mcp_swarm_task.idl are exposed.
Set MCP_EXPOSE_LOW_LEVEL_TOOLS=1 to opt into legacy/debug tools.
"""

from __future__ import annotations

from pathlib import Path

from fastmcp import FastMCP

from config import LOG_FILE, expose_low_level_tools
from debug_tools import register_low_level_tools
from swarm_runtime.context import SwarmContext
from swarm_runtime.fastmcp_bridge import install_runtime_tools
from swarm_runtime.plugin_loader import PluginLoader
from utils.logging_setup import setup_logging


MCP_ROOT = Path(__file__).resolve().parent
DEFAULT_PROFILE = MCP_ROOT / "profiles" / "default.json"
PLUGIN_ROOT = MCP_ROOT / "plugins"


def create_runtime(profile_path: str | Path | None = None) -> SwarmContext:
    ctx = SwarmContext()
    loader = PluginLoader(ctx, PLUGIN_ROOT)
    loader.load_profile(Path(profile_path) if profile_path else DEFAULT_PROFILE)
    ctx.plugin_loader = loader
    return ctx


def create_app(profile_path: str | Path | None = None) -> FastMCP:
    mcp = FastMCP(name="mcp-swarm-task-server")
    ctx = create_runtime(profile_path)
    adapter = ctx.services.get("legacy.robot_adapter")

    install_runtime_tools(mcp, ctx.tools)

    if expose_low_level_tools():
        register_low_level_tools(mcp, adapter)

    return mcp


app = create_app()


if __name__ == "__main__":
    setup_logging(log_file=LOG_FILE, level="INFO")
    app.run()
