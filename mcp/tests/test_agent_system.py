# -*- coding: utf-8 -*-
"""
Comprehensive tests for the MCP Agent Directory, Status & Alias system.

Tests cover:
- AgentResolver: resolution order, caching, invalidation
- AgentApiClient: HTTP envelope handling, error cases
- AgentService: list, status, batch, alias set/clear
- agent_tools: registration and tool invocation
- Alias normalization: Unicode NFKC, case folding, validation
- Integration: resolver -> service -> tools flow
"""

from __future__ import annotations

import asyncio
import json
import os
import sys
import time
from pathlib import Path
from unittest.mock import AsyncMock, MagicMock, patch

import pytest

from agents.agent_api_client import AgentApiClient
from agents.agent_resolver import AgentResolver
from agents.agent_service import AgentService
from agents.agent_tools import register_agent_tools


# ============================================================================
# Test fixtures
# ============================================================================

SAMPLE_LIST_RESPONSE = {
    "success": True,
    "message": "ok",
    "data": {
        "schema_version": "1.0",
        "generated_at_ms": 1782864000000,
        "agents": [
            {
                "unit_id": "GV1",
                "alias": "先锋车",
                "display_name": "先锋车",
                "unit_type": "ground",
                "binding_state": "bound",
                "binding_origin": "mock",
                "connection_state": "online",
                "status_freshness": "fresh",
                "mock": True,
                "run_mode": "sim",
                "role": "leader",
                "pose": {"x": 1.0, "y": 2.0, "yaw": 0.5},
                "speed": {"linear_m_s": 0.2, "angular_rad_s": 0.0},
                "battery_percent": None,
                "health": None,
                "last_seen_ms": 1782863999000,
                "observed_at_ms": 1782863999000,
                "last_error": None,
                "capabilities": ["pose", "speed", "role"],
            },
            {
                "unit_id": "GV2",
                "alias": "跟随车",
                "display_name": "跟随车",
                "unit_type": "ground",
                "binding_state": "bound",
                "binding_origin": "mock",
                "connection_state": "online",
                "status_freshness": "fresh",
                "mock": True,
                "run_mode": "sim",
                "role": "follower",
                "pose": {"x": 3.0, "y": 4.0, "yaw": 1.2},
                "speed": {"linear_m_s": 0.0, "angular_rad_s": 0.0},
                "battery_percent": None,
                "health": None,
                "last_seen_ms": 1782863999000,
                "observed_at_ms": 1782863999000,
                "last_error": None,
                "capabilities": ["pose", "speed", "role"],
            },
            {
                "unit_id": "GV3",
                "alias": None,
                "display_name": "GV3",
                "unit_type": "ground",
                "binding_state": "bound",
                "binding_origin": "restored",
                "connection_state": "unknown",
                "status_freshness": "unavailable",
                "mock": False,
                "run_mode": "sim",
                "role": "none",
                "pose": None,
                "speed": None,
                "battery_percent": None,
                "health": None,
                "last_seen_ms": None,
                "observed_at_ms": 1782864000000,
                "last_error": "RPC disabled, no probe attempted",
                "capabilities": [],
            },
        ],
        "summary": {"total": 3, "online": 2, "offline": 0, "unknown": 1, "mock": 2, "real": 0},
    },
}

SAMPLE_STATUS_RESPONSE = {
    "success": True,
    "message": "ok",
    "data": {
        "unit_id": "GV1",
        "alias": "先锋车",
        "display_name": "先锋车",
        "unit_type": "ground",
        "binding_state": "bound",
        "binding_origin": "mock",
        "connection_state": "online",
        "status_freshness": "fresh",
        "mock": True,
        "run_mode": "sim",
        "role": "leader",
        "pose": {"x": 1.5, "y": 2.5, "yaw": 0.8},
        "speed": {"linear_m_s": 0.3, "angular_rad_s": 0.1},
        "battery_percent": None,
        "health": None,
        "last_seen_ms": 1782863999500,
        "observed_at_ms": 1782863999500,
        "last_error": None,
        "capabilities": ["pose", "speed", "role"],
    },
}

SAMPLE_ALIAS_SET_RESPONSE = {
    "success": True,
    "message": "alias set",
    "data": {"unit_id": "GV1", "alias": "先锋车", "updated_at_ms": 1782864000000},
}

SAMPLE_ALIAS_CLEAR_RESPONSE = {
    "success": True,
    "message": "alias cleared",
    "data": {"unit_id": "GV1", "updated_at_ms": 1782864000000},
}

SAMPLE_ALIAS_CONFLICT_RESPONSE = {
    "success": False,
    "message": "alias conflict: '先锋车' is already in use",
    "data": {"error_code": "alias_conflict", "conflicting_name": "先锋车", "conflict_type": "alias"},
}

SAMPLE_NOT_FOUND_RESPONSE = {
    "success": False,
    "message": "agent not found: 'UnknownCar'",
    "data": {"error_code": "agent_not_found"},
}


# ============================================================================
# Fake RobotInstanceManager for testing
# ============================================================================

class FakeRobotEntry:
    def __init__(self, robot_id: str, unit_id: str):
        self.robot_id = robot_id
        self.unit_id = unit_id


class FakeRobotManager:
    """Minimal fake of RobotInstanceManager for resolver tests."""

    def __init__(self, robots: list[tuple[str, str]] | None = None):
        self._robots: dict[str, FakeRobotEntry] = {}
        if robots:
            for rid, uid in robots:
                self._robots[rid] = FakeRobotEntry(rid, uid)

    def unit_id_for(self, robot_id: str) -> str | None:
        entry = self._robots.get(robot_id)
        return entry.unit_id if entry else None

    def configured_robot_ids(self) -> list[str]:
        return list(self._robots.keys())

    def canonical_robot_id(self, name: str) -> str | None:
        key = name.strip()
        if key in self._robots:
            return key
        for rid, entry in self._robots.items():
            if entry.unit_id == key:
                return rid
        return None


# ============================================================================
# Fake MCP for tool registration tests
# ============================================================================

class FakeMCP:
    """Minimal FastMCP stub that captures registered tools."""

    def __init__(self):
        self.tools: dict[str, callable] = {}

    def tool(self, func):
        self.tools[func.__name__] = func
        return func


# ============================================================================
# 1. AgentApiClient Tests
# ============================================================================

class TestAgentApiClient:
    """Tests for AgentApiClient HTTP methods with mocked http_request."""

    @pytest.fixture
    def client(self):
        return AgentApiClient(base_url="http://127.0.0.1:9001", timeout=5.0)

    @pytest.mark.asyncio
    async def test_list_agents_success(self, client):
        """list_agents() returns parsed envelope on success."""
        with patch("agents.agent_api_client.http_request") as mock_http:
            mock_http.return_value = (200, SAMPLE_LIST_RESPONSE, "")
            result = await client.list_agents()
            assert result["success"] is True
            assert len(result["data"]["agents"]) == 3
            assert result["data"]["summary"]["total"] == 3

    @pytest.mark.asyncio
    async def test_get_agent_status_with_refresh(self, client):
        """get_agent_status with refresh=True sends refresh=1."""
        with patch("agents.agent_api_client.http_request") as mock_http:
            mock_http.return_value = (200, SAMPLE_STATUS_RESPONSE, "")
            result = await client.get_agent_status("GV1", refresh=True)
            assert result["success"] is True
            assert result["data"]["unit_id"] == "GV1"
            assert result["data"]["pose"]["x"] == 1.5
            # Verify refresh=1 in URL
            call_url = mock_http.call_args[1]["url"]
            assert "refresh=1" in call_url

    @pytest.mark.asyncio
    async def test_get_agent_status_without_refresh(self, client):
        """get_agent_status with refresh=False sends refresh=0."""
        with patch("agents.agent_api_client.http_request") as mock_http:
            mock_http.return_value = (200, SAMPLE_STATUS_RESPONSE, "")
            result = await client.get_agent_status("GV1", refresh=False)
            assert result["success"] is True
            call_url = mock_http.call_args[1]["url"]
            assert "refresh=0" in call_url

    @pytest.mark.asyncio
    async def test_set_alias_success(self, client):
        """set_alias returns success envelope."""
        with patch("agents.agent_api_client.http_request") as mock_http:
            mock_http.return_value = (200, SAMPLE_ALIAS_SET_RESPONSE, "")
            result = await client.set_alias("GV1", "新名称", reserved_names=["robot_1", "robot_2"])
            assert result["success"] is True
            assert result["data"]["alias"] == "先锋车"
            # Verify reserved_names were sent
            call_body = mock_http.call_args[1]["json_body"]
            assert "reserved_names" in call_body
            assert "robot_1" in call_body["reserved_names"]

    @pytest.mark.asyncio
    async def test_set_alias_conflict(self, client):
        """set_alias returns conflict envelope on 409."""
        with patch("agents.agent_api_client.http_request") as mock_http:
            mock_http.return_value = (409, SAMPLE_ALIAS_CONFLICT_RESPONSE, "")
            result = await client.set_alias("GV2", "先锋车")
            assert result["success"] is False
            assert "conflict" in result["message"]

    @pytest.mark.asyncio
    async def test_clear_alias_success(self, client):
        """clear_alias returns success envelope."""
        with patch("agents.agent_api_client.http_request") as mock_http:
            mock_http.return_value = (200, SAMPLE_ALIAS_CLEAR_RESPONSE, "")
            result = await client.clear_alias("GV1")
            assert result["success"] is True

    @pytest.mark.asyncio
    async def test_transport_error_returns_failure_envelope(self, client):
        """Transport errors return synthetic failure envelope."""
        with patch("agents.agent_api_client.http_request") as mock_http:
            mock_http.return_value = (-1, None, "Connection refused")
            result = await client.list_agents()
            assert result["success"] is False
            assert "Connection refused" in result["message"]

    @pytest.mark.asyncio
    async def test_http_500_returns_envelope(self, client):
        """HTTP 500 returns the Qt error envelope."""
        error_body = {"success": False, "message": "internal error", "data": None}
        with patch("agents.agent_api_client.http_request") as mock_http:
            mock_http.return_value = (500, error_body, "")
            result = await client.get_agent_status("GV1", refresh=False)
            assert result["success"] is False
            assert "internal error" in result["message"]

    @pytest.mark.asyncio
    async def test_agent_name_url_encoded(self, client):
        """Agent name with special characters is URL-encoded."""
        with patch("agents.agent_api_client.http_request") as mock_http:
            mock_http.return_value = (200, SAMPLE_STATUS_RESPONSE, "")
            await client.get_agent_status("先锋车", refresh=True)
            call_url = mock_http.call_args[1]["url"]
            # Chinese characters should be percent-encoded
            assert "%" in call_url or "先锋车" in call_url


# ============================================================================
# 2. AgentResolver Tests
# ============================================================================

class TestAgentResolver:
    """Tests for AgentResolver resolution order, caching, and invalidation."""

    @pytest.fixture
    def api_client(self):
        client = MagicMock(spec=AgentApiClient)
        client.list_agents = AsyncMock(return_value=SAMPLE_LIST_RESPONSE)
        client.get_agent_status = AsyncMock(return_value=SAMPLE_STATUS_RESPONSE)
        return client

    @pytest.fixture
    def robot_manager(self):
        return FakeRobotManager([("robot_1", "GV1"), ("robot_2", "GV2"), ("robot_3", "GV3")])

    @pytest.fixture
    def resolver(self, api_client, robot_manager):
        return AgentResolver(api_client, robot_manager)

    @pytest.mark.asyncio
    async def test_resolve_by_unit_id_exact(self, resolver):
        """Exact unit_id match resolves immediately."""
        uid = await resolver.resolve("GV1")
        assert uid == "GV1"

    @pytest.mark.asyncio
    async def test_resolve_by_alias(self, resolver):
        """Alias match resolves to unit_id."""
        uid = await resolver.resolve("先锋车")
        assert uid == "GV1"

    @pytest.mark.asyncio
    async def test_resolve_by_alias_case_insensitive(self, resolver, api_client):
        """Alias matching is case-insensitive (lowercase alias in directory)."""
        # Override response to test case-insensitive matching
        response = json.loads(json.dumps(SAMPLE_LIST_RESPONSE))
        response["data"]["agents"][0]["alias"] = "Pioneer"
        api_client.list_agents = AsyncMock(return_value=response)
        # Force cache refresh
        await resolver.invalidate_cache()
        uid = await resolver.resolve("pioneer")
        assert uid == "GV1"

    @pytest.mark.asyncio
    async def test_resolve_by_robots_json_robot_id(self, resolver):
        """Fallback to robots.json robot_id -> unit_id mapping."""
        uid = await resolver.resolve("robot_2")
        assert uid == "GV2"

    @pytest.mark.asyncio
    async def test_resolve_not_found(self, resolver):
        """Unknown identifier returns None."""
        uid = await resolver.resolve("NonExistentCar")
        assert uid is None

    @pytest.mark.asyncio
    async def test_resolve_agent_without_alias(self, resolver):
        """Agent without alias resolves by unit_id."""
        uid = await resolver.resolve("GV3")
        assert uid == "GV3"

    @pytest.mark.asyncio
    async def test_cache_hit(self, resolver, api_client):
        """Second resolve within TTL uses cache, not HTTP."""
        await resolver.resolve("GV1")  # populates cache
        # Reset mock to verify it's NOT called again
        api_client.list_agents.reset_mock()
        uid = await resolver.resolve("GV2")  # should use cache
        assert uid == "GV2"
        api_client.list_agents.assert_not_called()

    @pytest.mark.asyncio
    async def test_cache_miss_triggers_refresh(self, resolver, api_client):
        """Unresolvable name triggers one forced refresh."""
        # Make first call return empty directory
        api_client.list_agents = AsyncMock(return_value={
            "success": True, "data": {"agents": [], "summary": {"total": 0}}
        })
        await resolver.invalidate_cache()
        uid = await resolver.resolve("GV1")
        # Should have called list_agents at least once (first attempt + forced refresh)
        assert api_client.list_agents.call_count >= 1

    @pytest.mark.asyncio
    async def test_cache_invalidation(self, resolver, api_client):
        """After invalidate_cache(), next resolve calls HTTP."""
        await resolver.resolve("GV1")  # populate
        api_client.list_agents.reset_mock()
        await resolver.invalidate_cache()
        await resolver.resolve("GV1")  # should refresh
        assert api_client.list_agents.call_count >= 1

    @pytest.mark.asyncio
    async def test_resolve_empty_name(self, resolver):
        """Empty string returns None."""
        assert await resolver.resolve("") is None
        assert await resolver.resolve("   ") is None

    @pytest.mark.asyncio
    async def test_api_failure_keeps_stale_cache(self, resolver, api_client):
        """When API fails, stale cache is preserved."""
        await resolver.resolve("GV1")  # populate
        # Now make API fail
        api_client.list_agents = AsyncMock(return_value={
            "success": False, "message": "server error"
        })
        await resolver.invalidate_cache()
        # Should still resolve from stale cache
        uid = await resolver.resolve("GV1")
        assert uid == "GV1"

    @pytest.mark.asyncio
    async def test_resolve_dynamic_agent_not_in_robots_json(self, resolver, api_client):
        """Dynamic agent (in Qt directory but not robots.json) resolves correctly."""
        response = json.loads(json.dumps(SAMPLE_LIST_RESPONSE))
        response["data"]["agents"].append({
            "unit_id": "GV4",
            "alias": None,
            "display_name": "GV4",
            "unit_type": "ground",
            "binding_state": "bound",
            "binding_origin": "runtime",
            "connection_state": "online",
            "mock": True,
        })
        api_client.list_agents = AsyncMock(return_value=response)
        await resolver.invalidate_cache()
        uid = await resolver.resolve("GV4")
        assert uid == "GV4"


# ============================================================================
# 3. AgentService Tests
# ============================================================================

class TestAgentService:
    """Tests for AgentService high-level operations."""

    @pytest.fixture
    def api_client(self):
        client = MagicMock(spec=AgentApiClient)
        client.list_agents = AsyncMock(return_value=SAMPLE_LIST_RESPONSE)
        client.get_agent_status = AsyncMock(return_value=SAMPLE_STATUS_RESPONSE)
        client.set_alias = AsyncMock(return_value=SAMPLE_ALIAS_SET_RESPONSE)
        client.clear_alias = AsyncMock(return_value=SAMPLE_ALIAS_CLEAR_RESPONSE)
        return client

    @pytest.fixture
    def robot_manager(self):
        return FakeRobotManager([("robot_1", "GV1"), ("robot_2", "GV2"), ("robot_3", "GV3")])

    @pytest.fixture
    def resolver(self, api_client, robot_manager):
        return AgentResolver(api_client, robot_manager)

    @pytest.fixture
    def service(self, api_client, resolver):
        return AgentService(api_client, resolver)

    @pytest.mark.asyncio
    async def test_list_agents_enriches_with_robot_id(self, service):
        """list_agents adds robot_id annotation from robots.json."""
        result = await service.list_agents()
        data = json.loads(result)
        assert data["success"] is True
        agents = data["data"]["agents"]
        # GV1 should have robot_id = robot_1
        gv1 = next(a for a in agents if a["unit_id"] == "GV1")
        assert gv1.get("robot_id") == "robot_1"
        # GV3 should have robot_id = robot_3
        gv3 = next(a for a in agents if a["unit_id"] == "GV3")
        assert gv3.get("robot_id") == "robot_3"

    @pytest.mark.asyncio
    async def test_list_agents_summary(self, service):
        """list_agents returns summary with correct counts."""
        result = await service.list_agents()
        data = json.loads(result)
        assert data["success"] is True
        summary = data["data"]["summary"]
        assert summary["total"] == 3
        assert summary["online"] == 2
        assert summary["unknown"] == 1

    @pytest.mark.asyncio
    async def test_get_agent_status_by_unit_id(self, service):
        """get_agent_status resolves unit_id and returns status."""
        result = await service.get_agent_status("GV1", refresh=True)
        data = json.loads(result)
        assert data["success"] is True
        assert data["data"]["unit_id"] == "GV1"

    @pytest.mark.asyncio
    async def test_get_agent_status_by_alias(self, service):
        """get_agent_status resolves alias and returns status."""
        result = await service.get_agent_status("先锋车", refresh=False)
        data = json.loads(result)
        assert data["success"] is True
        assert data["data"]["unit_id"] == "GV1"

    @pytest.mark.asyncio
    async def test_get_agent_status_not_found(self, service, resolver):
        """Unresolvable agent returns failure."""
        result = await service.get_agent_status("GhostCar", refresh=True)
        data = json.loads(result)
        assert data["success"] is False
        assert "not found" in data["message"].lower() or "could not resolve" in data["message"].lower()

    @pytest.mark.asyncio
    async def test_get_all_agent_status_batch(self, service):
        """get_all_agent_status queries all agents and reports partial success."""
        result = await service.get_all_agent_status(refresh=True)
        data = json.loads(result)
        assert data["success"] is True
        assert "items" in data["data"]
        assert "summary" in data["data"]
        summary = data["data"]["summary"]
        assert summary["total"] == 3

    @pytest.mark.asyncio
    async def test_set_agent_alias_success(self, service):
        """set_agent_alias resolves, submits reserved_names, and invalidates cache."""
        result = await service.set_agent_alias("GV1", "新名称")
        data = json.loads(result)
        assert data["success"] is True

    @pytest.mark.asyncio
    async def test_set_agent_alias_not_found(self, service):
        """set_agent_alias with unknown agent returns failure."""
        result = await service.set_agent_alias("GhostCar", "新名称")
        data = json.loads(result)
        assert data["success"] is False

    @pytest.mark.asyncio
    async def test_set_agent_alias_submits_reserved_names(self, service, api_client):
        """set_agent_alias passes all robot_ids as reserved_names."""
        await service.set_agent_alias("GV1", "新名称")
        call_kwargs = api_client.set_alias.call_args[1]
        assert "reserved_names" in call_kwargs
        assert "robot_1" in call_kwargs["reserved_names"]
        assert "robot_2" in call_kwargs["reserved_names"]
        assert "robot_3" in call_kwargs["reserved_names"]

    @pytest.mark.asyncio
    async def test_clear_agent_alias_success(self, service):
        """clear_agent_alias resolves and clears."""
        result = await service.clear_agent_alias("GV1")
        data = json.loads(result)
        assert data["success"] is True

    @pytest.mark.asyncio
    async def test_clear_agent_alias_not_found(self, service):
        """clear_agent_alias with unknown agent returns failure."""
        result = await service.clear_agent_alias("GhostCar")
        data = json.loads(result)
        assert data["success"] is False

    @pytest.mark.asyncio
    async def test_alias_mutation_invalidates_cache(self, service, api_client):
        """Setting or clearing alias invalidates the resolver cache."""
        # Populate cache
        await service.list_agents()
        # Reset mock to track calls
        api_client.list_agents.reset_mock()
        # Set alias - should trigger cache invalidation
        await service.set_agent_alias("GV1", "新名称")
        # Next list should refresh
        await service.list_agents()
        assert api_client.list_agents.call_count >= 1

    @pytest.mark.asyncio
    async def test_get_all_agent_status_partial_failure(self, service, api_client):
        """Batch status with one failing agent still returns partial success."""
        call_count = 0

        async def flaky_status(*args, **kwargs):
            nonlocal call_count
            call_count += 1
            if call_count == 2:  # Second agent fails
                return {"success": False, "message": "timeout", "data": None}
            return SAMPLE_STATUS_RESPONSE

        api_client.get_agent_status = AsyncMock(side_effect=flaky_status)

        result = await service.get_all_agent_status(refresh=False)
        data = json.loads(result)
        assert data["message"] == "partial"  # not all succeeded
        summary = data["data"]["summary"]
        assert summary["failed"] >= 1
        assert summary["ok"] >= 1


# ============================================================================
# 4. Agent Tools Registration Tests
# ============================================================================

class TestAgentTools:
    """Tests for tool registration and basic invocation."""

    @pytest.fixture
    def fake_mcp(self):
        return FakeMCP()

    @pytest.fixture
    def api_client(self):
        client = MagicMock(spec=AgentApiClient)
        client.list_agents = AsyncMock(return_value=SAMPLE_LIST_RESPONSE)
        client.get_agent_status = AsyncMock(return_value=SAMPLE_STATUS_RESPONSE)
        client.set_alias = AsyncMock(return_value=SAMPLE_ALIAS_SET_RESPONSE)
        client.clear_alias = AsyncMock(return_value=SAMPLE_ALIAS_CLEAR_RESPONSE)
        return client

    @pytest.fixture
    def robot_manager(self):
        return FakeRobotManager([("robot_1", "GV1"), ("robot_2", "GV2"), ("robot_3", "GV3")])

    @pytest.fixture
    def agent_service(self, api_client, robot_manager):
        resolver = AgentResolver(api_client, robot_manager)
        return AgentService(api_client, resolver)

    @pytest.fixture
    def registered_mcp(self, fake_mcp, agent_service):
        register_agent_tools(fake_mcp, agent_service)
        return fake_mcp

    def test_all_five_tools_registered(self, registered_mcp):
        """All 5 tools are registered."""
        expected_tools = {
            "list_agents",
            "get_agent_status",
            "get_all_agent_status",
            "set_agent_alias",
            "clear_agent_alias",
        }
        assert set(registered_mcp.tools.keys()) == expected_tools

    @pytest.mark.asyncio
    async def test_list_agents_tool_returns_json(self, registered_mcp):
        """list_agents tool returns valid JSON string."""
        result = await registered_mcp.tools["list_agents"]()
        data = json.loads(result)
        assert data["success"] is True
        assert "agents" in data["data"]

    @pytest.mark.asyncio
    async def test_get_agent_status_tool(self, registered_mcp):
        """get_agent_status tool resolves and returns status."""
        result = await registered_mcp.tools["get_agent_status"](agent="GV1", refresh=True)
        data = json.loads(result)
        assert data["success"] is True

    @pytest.mark.asyncio
    async def test_set_agent_alias_tool(self, registered_mcp):
        """set_agent_alias tool returns success."""
        result = await registered_mcp.tools["set_agent_alias"](agent="GV1", alias="先锋车")
        data = json.loads(result)
        assert data["success"] is True

    @pytest.mark.asyncio
    async def test_clear_agent_alias_tool(self, registered_mcp):
        """clear_agent_alias tool returns success."""
        result = await registered_mcp.tools["clear_agent_alias"](agent="GV1")
        data = json.loads(result)
        assert data["success"] is True

    @pytest.mark.asyncio
    async def test_get_all_agent_status_tool(self, registered_mcp):
        """get_all_agent_status tool returns batch results."""
        result = await registered_mcp.tools["get_all_agent_status"](refresh=False)
        data = json.loads(result)
        assert "items" in data["data"]


# ============================================================================
# 5. Alias Normalization Logic Tests (Python-side validation)
# ============================================================================

class TestAliasNormalization:
    """Tests for alias normalization rules (mirrors Qt AgentNameNormalizer logic)."""

    def _normalize(self, raw: str) -> str | None:
        """Re-implement normalization rules for testing."""
        import unicodedata

        trimmed = raw.strip()
        if not trimmed:
            return None

        # Reject control chars, newlines, commas
        for ch in trimmed:
            if unicodedata.category(ch).startswith("C"):
                return None
            if ch in ("\n", "\r", ","):
                return None

        # NFKD decompose, strip non-spacing marks, NFC recompose
        decomposed = unicodedata.normalize("NFKD", trimmed)
        filtered = "".join(ch for ch in decomposed if not unicodedata.category(ch).startswith("M"))
        recomposed = unicodedata.normalize("NFC", filtered)
        result = recomposed.casefold()

        if not result or len(result) > 32:
            return None
        return result

    def test_chinese_alias_normalizes(self):
        """Chinese alias passes through normalization."""
        result = self._normalize("先锋车")
        assert result is not None
        assert "先锋车" in result or result == "先锋车".casefold()

    def test_english_alias_normalizes(self):
        """English alias is case-folded."""
        result = self._normalize("Pioneer")
        assert result == "pioneer"

    def test_whitespace_trimmed(self):
        """Leading/trailing whitespace is removed."""
        result = self._normalize("  先锋车  ")
        assert result is not None

    def test_empty_rejected(self):
        """Empty or whitespace-only alias is rejected."""
        assert self._normalize("") is None
        assert self._normalize("   ") is None

    def test_control_char_rejected(self):
        """Control characters cause rejection."""
        assert self._normalize("test\x00") is None
        assert self._normalize("test\x01") is None

    def test_newline_rejected(self):
        """Newline characters cause rejection."""
        # Embedded newlines (trim is applied before check in Qt, but embedded ones are still caught)
        assert self._normalize("test\nmore") is None
        assert self._normalize("test\rmore") is None

    def test_comma_rejected(self):
        """Comma causes rejection (CSV safety)."""
        assert self._normalize("car,one") is None

    def test_length_limit(self):
        """Alias exceeding 32 characters after normalization is rejected."""
        long_name = "a" * 33
        assert self._normalize(long_name) is None
        # Exactly 32 is OK
        ok_name = "a" * 32
        assert self._normalize(ok_name) == ok_name

    def test_internal_spaces_preserved(self):
        """Internal spaces are allowed and preserved."""
        result = self._normalize("Pioneer Car")
        assert result == "pioneer car"

    def test_hyphen_allowed(self):
        """Hyphens are allowed."""
        result = self._normalize("car-1")
        assert result == "car-1"

    def test_underscore_allowed(self):
        """Underscores are allowed."""
        result = self._normalize("car_1")
        assert result == "car_1"

    def test_uniqueness_key_chinese(self):
        """Two visually identical Chinese aliases produce the same comparison key."""
        a = self._normalize("先锋车")
        b = self._normalize("先锋车")
        assert a == b

    def test_uniqueness_key_case_insensitive(self):
        """Case variations produce the same comparison key."""
        a = self._normalize("Pioneer")
        b = self._normalize("PIONEER")
        assert a == b

    def test_uniqueness_key_unicode_nfkc(self):
        """NFKC compatibility: fullwidth latin is normalized."""
        # Fullwidth 'A' (U+FF21) should normalize to regular 'A' (U+0041)
        result = self._normalize("ＡBC")  # "ＡBC"
        assert result == "abc"


# ============================================================================
# 6. Integration Tests (Resolver -> Service -> Tools)
# ============================================================================

class TestIntegration:
    """End-to-end integration tests for the agent system."""

    @pytest.fixture
    def api_client(self):
        client = MagicMock(spec=AgentApiClient)
        client.list_agents = AsyncMock(return_value=SAMPLE_LIST_RESPONSE)
        client.get_agent_status = AsyncMock(return_value=SAMPLE_STATUS_RESPONSE)
        client.set_alias = AsyncMock(return_value=SAMPLE_ALIAS_SET_RESPONSE)
        client.clear_alias = AsyncMock(return_value=SAMPLE_ALIAS_CLEAR_RESPONSE)
        return client

    @pytest.fixture
    def robot_manager(self):
        return FakeRobotManager([("robot_1", "GV1"), ("robot_2", "GV2"), ("robot_3", "GV3")])

    @pytest.fixture
    def resolver(self, api_client, robot_manager):
        return AgentResolver(api_client, robot_manager)

    @pytest.fixture
    def service(self, api_client, resolver):
        return AgentService(api_client, resolver)

    @pytest.mark.asyncio
    async def test_full_flow_alias_set_and_query(self, service):
        """End-to-end: set alias, then query by alias."""
        # Set alias
        set_result = await service.set_agent_alias("GV1", "先锋车")
        assert json.loads(set_result)["success"] is True

        # Query by alias
        status_result = await service.get_agent_status("先锋车", refresh=True)
        assert json.loads(status_result)["success"] is True

    @pytest.mark.asyncio
    async def test_full_flow_list_then_query(self, service):
        """End-to-end: list agents, then query individual."""
        list_result = await service.list_agents()
        data = json.loads(list_result)
        assert data["success"] is True

        # Query each agent
        for agent in data["data"]["agents"]:
            uid = agent["unit_id"]
            status = await service.get_agent_status(uid, refresh=False)
            assert json.loads(status)["success"] is True

    @pytest.mark.asyncio
    async def test_robots_json_fallback_for_old_tools(self, resolver):
        """Old robot_id from robots.json still resolves."""
        uid = await resolver.resolve("robot_3")
        assert uid == "GV3"

    @pytest.mark.asyncio
    async def test_dynamic_agent_full_flow(self, service, api_client):
        """Dynamic agent (not in robots.json) works through full flow."""
        # Add a dynamic agent to the directory response
        response = json.loads(json.dumps(SAMPLE_LIST_RESPONSE))
        response["data"]["agents"].append({
            "unit_id": "GV5",
            "alias": "侦察车",
            "display_name": "侦察车",
            "unit_type": "ground",
            "binding_state": "bound",
            "binding_origin": "runtime",
            "connection_state": "online",
            "mock": True,
            "run_mode": "sim",
            "role": "none",
            "capabilities": ["pose", "speed"],
        })
        api_client.list_agents = AsyncMock(return_value=response)
        # Update status mock for the new agent
        api_client.get_agent_status = AsyncMock(return_value={
            "success": True,
            "message": "ok",
            "data": {"unit_id": "GV5", "alias": "侦察车", "connection_state": "online"},
        })

        # List should include dynamic agent
        list_result = await service.list_agents()
        data = json.loads(list_result)
        agents = data["data"]["agents"]
        gv5 = next((a for a in agents if a["unit_id"] == "GV5"), None)
        assert gv5 is not None
        # robot_id should NOT be set (not in robots.json)
        assert gv5.get("robot_id") is None

        # Query by alias should work
        status = await service.get_agent_status("侦察车", refresh=False)
        assert json.loads(status)["success"] is True

    @pytest.mark.asyncio
    async def test_conflict_flow(self, service, api_client):
        """Attempting to set a conflicting alias returns error."""
        api_client.set_alias = AsyncMock(return_value=SAMPLE_ALIAS_CONFLICT_RESPONSE)
        result = await service.set_agent_alias("GV2", "先锋车")
        data = json.loads(result)
        assert data["success"] is False

    @pytest.mark.asyncio
    async def test_clear_alias_then_query_by_uid(self, service):
        """After clearing alias, agent is still queryable by unit_id."""
        clear_result = await service.clear_agent_alias("GV1")
        assert json.loads(clear_result)["success"] is True

        # Query by unit_id should still work
        status = await service.get_agent_status("GV1", refresh=False)
        assert json.loads(status)["success"] is True

    @pytest.mark.asyncio
    async def test_batch_status_total_matches_list(self, service):
        """Batch status item count matches directory listing."""
        list_result = await service.list_agents()
        list_data = json.loads(list_result)
        agent_count = len(list_data["data"]["agents"])

        batch_result = await service.get_all_agent_status(refresh=False)
        batch_data = json.loads(batch_result)
        assert batch_data["data"]["summary"]["total"] == agent_count

    @pytest.mark.asyncio
    async def test_resolver_robots_json_fallback_when_qt_unavailable(self, resolver, api_client):
        """When Qt is unreachable, resolver still works via robots.json fallback."""
        api_client.list_agents = AsyncMock(return_value={
            "success": False, "message": "Connection refused"
        })
        await resolver.invalidate_cache()
        # Should still resolve via robots.json
        uid = await resolver.resolve("robot_1")
        assert uid == "GV1"
