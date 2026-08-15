from __future__ import annotations

from dataclasses import dataclass, field
from typing import Any, Mapping, Protocol

from .errors import PluginLoadError


def _require_string(payload: Mapping[str, Any], key: str) -> str:
    value = payload.get(key)
    if not isinstance(value, str) or not value.strip():
        raise PluginLoadError(f"{key} must be a non-empty string")
    return value.strip()


def _string_tuple(payload: Mapping[str, Any], key: str) -> tuple[str, ...]:
    value = payload.get(key, [])
    if not isinstance(value, list) or any(
        not isinstance(item, str) or not item.strip() for item in value
    ):
        raise PluginLoadError(f"{key} must be a list of non-empty strings")
    return tuple(item.strip() for item in value)


@dataclass(frozen=True)
class PluginManifest:
    api_version: int
    id: str
    version: str
    plugin_type: str
    entrypoint: str
    requires: tuple[str, ...] = ()
    provides: tuple[str, ...] = ()

    @classmethod
    def from_dict(cls, payload: Any) -> "PluginManifest":
        if not isinstance(payload, dict):
            raise PluginLoadError("plugin manifest must be an object")
        api_version = payload.get("api_version")
        if api_version != 1:
            raise PluginLoadError(f"unsupported plugin api_version: {api_version}")
        return cls(
            api_version=api_version,
            id=_require_string(payload, "id"),
            version=_require_string(payload, "version"),
            plugin_type=_require_string(payload, "type"),
            entrypoint=_require_string(payload, "entrypoint"),
            requires=_string_tuple(payload, "requires"),
            provides=_string_tuple(payload, "provides"),
        )


@dataclass(frozen=True)
class ProfilePlugin:
    id: str
    enabled: bool
    config: Mapping[str, Any] = field(default_factory=dict)

    @classmethod
    def from_dict(cls, payload: Any) -> "ProfilePlugin":
        if not isinstance(payload, dict):
            raise PluginLoadError("profile plugin entry must be an object")
        config = payload.get("config", {})
        if not isinstance(config, dict):
            raise PluginLoadError("profile plugin config must be an object")
        enabled = payload.get("enabled", True)
        if not isinstance(enabled, bool):
            raise PluginLoadError("profile plugin enabled must be a boolean")
        return cls(
            id=_require_string(payload, "id"),
            enabled=enabled,
            config=dict(config),
        )


@dataclass(frozen=True)
class PluginProfile:
    profile_api_version: int
    plugins: tuple[ProfilePlugin, ...]

    @classmethod
    def from_dict(cls, payload: Any) -> "PluginProfile":
        if not isinstance(payload, dict):
            raise PluginLoadError("plugin profile must be an object")
        api_version = payload.get("profile_api_version")
        if api_version != 1:
            raise PluginLoadError(f"unsupported profile_api_version: {api_version}")
        plugins = payload.get("plugins")
        if not isinstance(plugins, list):
            raise PluginLoadError("profile plugins must be a list")
        parsed = tuple(ProfilePlugin.from_dict(item) for item in plugins)
        ids = [item.id for item in parsed]
        if len(ids) != len(set(ids)):
            raise PluginLoadError("profile contains duplicate plugin ids")
        return cls(profile_api_version=api_version, plugins=parsed)


class SwarmPlugin(Protocol):
    plugin_id: str
    version: str

    def setup(self, ctx: Any, config: Mapping[str, Any]) -> None:
        ...
