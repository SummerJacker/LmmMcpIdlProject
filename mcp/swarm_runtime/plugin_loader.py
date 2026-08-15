from __future__ import annotations

import importlib
import json
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Callable

from .context import SwarmContext
from .errors import PluginLoadError
from .plugin import PluginManifest, PluginProfile, ProfilePlugin
from .registration import RegistrationTransaction


EntrypointResolver = Callable[[str], type[Any]]


@dataclass
class _LoadedPlugin:
    manifest: PluginManifest
    plugin: Any
    transaction: RegistrationTransaction


def _default_resolver(entrypoint: str) -> type[Any]:
    if entrypoint.count(":") != 1:
        raise PluginLoadError(f"invalid plugin entrypoint: {entrypoint}")
    module_name, object_name = entrypoint.split(":", 1)
    if not module_name or not object_name:
        raise PluginLoadError(f"invalid plugin entrypoint: {entrypoint}")
    try:
        module = importlib.import_module(module_name)
        value = getattr(module, object_name)
    except (ImportError, AttributeError) as exc:
        raise PluginLoadError(f"cannot resolve plugin entrypoint: {entrypoint}") from exc
    if not isinstance(value, type):
        raise PluginLoadError(f"plugin entrypoint is not a class: {entrypoint}")
    return value


class PluginLoader:
    def __init__(
        self,
        ctx: SwarmContext,
        plugin_root: str | Path,
        *,
        resolver: EntrypointResolver | None = None,
    ) -> None:
        self._ctx = ctx
        self._plugin_root = Path(plugin_root).resolve()
        self._resolver = resolver or _default_resolver
        self._loaded: list[_LoadedPlugin] = []

    @property
    def loaded_plugin_ids(self) -> tuple[str, ...]:
        return tuple(item.manifest.id for item in self._loaded)

    def _discover(self) -> dict[str, PluginManifest]:
        manifests: dict[str, PluginManifest] = {}
        if not self._plugin_root.is_dir():
            raise PluginLoadError(f"plugin root not found: {self._plugin_root}")
        for path in sorted(self._plugin_root.rglob("plugin.json")):
            try:
                payload = json.loads(path.read_text(encoding="utf-8"))
            except (OSError, json.JSONDecodeError) as exc:
                raise PluginLoadError(f"invalid plugin manifest: {path}") from exc
            manifest = PluginManifest.from_dict(payload)
            if manifest.id in manifests:
                raise PluginLoadError(f"duplicate plugin id: {manifest.id}")
            manifests[manifest.id] = manifest
        return manifests

    @staticmethod
    def _read_profile(path: str | Path) -> PluginProfile:
        profile_path = Path(path)
        try:
            payload = json.loads(profile_path.read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError) as exc:
            raise PluginLoadError(f"invalid plugin profile: {profile_path}") from exc
        return PluginProfile.from_dict(payload)

    @staticmethod
    def _load_order(
        profile_entries: tuple[ProfilePlugin, ...],
        manifests: dict[str, PluginManifest],
    ) -> list[str]:
        enabled = {entry.id for entry in profile_entries if entry.enabled}
        for plugin_id in enabled:
            if plugin_id not in manifests:
                raise PluginLoadError(f"enabled plugin not found: {plugin_id}")
            for required in manifests[plugin_id].requires:
                if required not in enabled:
                    raise PluginLoadError(
                        f"required plugin {required} is not enabled for {plugin_id}"
                    )

        colors: dict[str, str] = {}
        order: list[str] = []

        def visit(plugin_id: str) -> None:
            color = colors.get(plugin_id, "unseen")
            if color == "visiting":
                raise PluginLoadError(f"dependency cycle includes {plugin_id}")
            if color == "done":
                return
            colors[plugin_id] = "visiting"
            for required in manifests[plugin_id].requires:
                visit(required)
            colors[plugin_id] = "done"
            order.append(plugin_id)

        for entry in profile_entries:
            if entry.enabled:
                visit(entry.id)
        return order

    def load_profile(self, profile_path: str | Path) -> None:
        if self._loaded:
            raise PluginLoadError("a plugin profile is already loaded")
        manifests = self._discover()
        profile = self._read_profile(profile_path)
        entries = {entry.id: entry for entry in profile.plugins if entry.enabled}
        order = self._load_order(profile.plugins, manifests)

        try:
            for plugin_id in order:
                manifest = manifests[plugin_id]
                plugin_class = self._resolver(manifest.entrypoint)
                plugin = plugin_class()
                if (
                    getattr(plugin, "plugin_id", None) != manifest.id
                    or getattr(plugin, "version", None) != manifest.version
                ):
                    raise PluginLoadError(
                        f"entrypoint identity does not match {manifest.id}"
                    )
                with self._ctx.registration_journal.activate(
                    manifest.id
                ) as transaction:
                    plugin.setup(self._ctx, entries[plugin_id].config)
                    missing = set(manifest.provides) - transaction.provisions
                    if missing:
                        raise PluginLoadError(
                            f"plugin {manifest.id} did not provide: {sorted(missing)}"
                        )
                self._loaded.append(_LoadedPlugin(manifest, plugin, transaction))
        except Exception as exc:
            cleanup_error = self._unload_all(raise_errors=False)
            if isinstance(exc, PluginLoadError):
                raise
            detail = f"plugin profile setup failed: {exc}"
            if cleanup_error:
                detail += f"; cleanup failed: {cleanup_error}"
            raise PluginLoadError(detail) from exc

    def _unload_all(self, *, raise_errors: bool) -> str:
        errors: list[str] = []
        while self._loaded:
            loaded = self._loaded.pop()
            try:
                teardown = getattr(loaded.plugin, "teardown", None)
                if callable(teardown):
                    teardown(self._ctx)
            except Exception as exc:
                errors.append(f"{loaded.manifest.id}: {exc}")
            finally:
                try:
                    loaded.transaction.rollback()
                except Exception as exc:
                    errors.append(f"{loaded.manifest.id} rollback: {exc}")
        message = "; ".join(errors)
        if message and raise_errors:
            raise PluginLoadError(f"plugin teardown failed: {message}")
        return message

    def unload_all(self) -> None:
        self._unload_all(raise_errors=True)
