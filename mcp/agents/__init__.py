"""
Agent capability module (Member 3).

Exposes the agent directory, status, and alias management tools
backed by the Qt Console HTTP API (/api/agent/*).
"""

from __future__ import annotations

from agents.agent_api_client import AgentApiClient
from agents.agent_resolver import AgentResolver
from agents.agent_service import AgentService
from agents.agent_tools import register_agent_tools

__all__ = [
    "AgentApiClient",
    "AgentResolver",
    "AgentService",
    "register_agent_tools",
]
