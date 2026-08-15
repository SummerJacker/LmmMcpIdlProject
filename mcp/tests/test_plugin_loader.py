from __future__ import annotations

import json
from pathlib import Path
from typing import Any, Mapping

import pytest

from swarm_runtime.context import SwarmContext
from swarm_runtime.errors import PluginLoadError
from swarm_runtime.plugin_loader import PluginLoader


def write_manifest(
    root: Path,
    folder: str,
    *,
    plugin_id: str | None = None,
    entrypoint: str | None = None,
    requires: list[str] | None = None,
    provides: list[str] | None = None,
    api_version: int = 1,
) -> None:
    directory = root / "plugins" / folder
    directory.mkdir(parents=True)
    payload = {
        "api_version": api_version,
        "id": plugin_id or folder,
        "version": "1.0.0",
        "type": "test",
        "entrypoint": entrypoint or f"fake:{folder.title()}",
        "requires": requires or [],
        "provides": provides or [],
    }
    (directory / "plugin.json").write_text(json.dumps(payload), encoding="utf-8")


def write_profile(root: Path, plugins: list[dict[str, Any]]) -> Path:
    path = root / "profile.json"
    path.write_text(
        json.dumps({"profile_api_version": 1, "plugins": plugins}),
        encoding="utf-8",
    )
    return path


def enabled(plugin_id: str, config: Mapping[str, Any] | None = None) -> dict[str, Any]:
    return {"id": plugin_id, "enabled": True, "config": dict(config or {})}


class EnabledPlugin:
    plugin_id = "enabled"
    version = "1.0.0"

    def setup(self, ctx, config) -> None:
        ctx.services.register("enabled", object())


class IgnoredPlugin:
    plugin_id = "ignored"
    version = "1.0.0"

    def setup(self, ctx, config) -> None:
        ctx.services.register("ignored", object())


class BrokenPlugin:
    plugin_id = "broken"
    version = "1.0.0"

    def setup(self, ctx, config) -> None:
        ctx.services.register("temporary", object())
        raise ValueError("setup failed")


class MissingProvisionPlugin:
    plugin_id = "bad-provides"
    version = "1.0.0"

    def setup(self, ctx, config) -> None:
        ctx.services.register("temporary", object())


def test_profile_imports_only_explicitly_enabled_plugins(tmp_path: Path) -> None:
    write_manifest(
        tmp_path,
        "enabled",
        entrypoint="fake:Enabled",
        provides=["service:enabled"],
    )
    write_manifest(
        tmp_path,
        "ignored",
        entrypoint="fake:Ignored",
        provides=["service:ignored"],
    )
    profile = write_profile(tmp_path, [enabled("enabled")])
    resolved: list[str] = []
    classes = {"fake:Enabled": EnabledPlugin, "fake:Ignored": IgnoredPlugin}

    def resolver(entrypoint: str):
        resolved.append(entrypoint)
        return classes[entrypoint]

    loader = PluginLoader(SwarmContext(), tmp_path / "plugins", resolver=resolver)
    loader.load_profile(profile)

    assert resolved == ["fake:Enabled"]


def test_setup_failure_rolls_back_every_registration(tmp_path: Path) -> None:
    write_manifest(tmp_path, "broken", entrypoint="fake:Broken")
    profile = write_profile(tmp_path, [enabled("broken")])
    ctx = SwarmContext()
    loader = PluginLoader(
        ctx, tmp_path / "plugins", resolver=lambda _: BrokenPlugin
    )

    with pytest.raises(PluginLoadError):
        loader.load_profile(profile)

    with pytest.raises(KeyError):
        ctx.services.get("temporary")
    assert loader.loaded_plugin_ids == ()


def test_dependency_cycle_fails_before_setup(tmp_path: Path) -> None:
    write_manifest(tmp_path, "a", requires=["b"])
    write_manifest(tmp_path, "b", requires=["a"])
    profile = write_profile(tmp_path, [enabled("a"), enabled("b")])

    with pytest.raises(PluginLoadError, match="dependency cycle"):
        PluginLoader(SwarmContext(), tmp_path / "plugins").load_profile(profile)


def test_missing_declared_provision_rolls_back_plugin(tmp_path: Path) -> None:
    write_manifest(
        tmp_path,
        "bad-provides",
        entrypoint="fake:Missing",
        provides=["tool:navigateTo"],
    )
    profile = write_profile(tmp_path, [enabled("bad-provides")])
    ctx = SwarmContext()
    loader = PluginLoader(
        ctx, tmp_path / "plugins", resolver=lambda _: MissingProvisionPlugin
    )

    with pytest.raises(PluginLoadError, match="tool:navigateTo"):
        loader.load_profile(profile)

    with pytest.raises(KeyError):
        ctx.services.get("temporary")


@pytest.mark.parametrize(
    ("setup", "message"),
    [
        ("unsupported_api", "api_version"),
        ("duplicate_id", "duplicate plugin id"),
        ("missing_dependency", "required plugin"),
    ],
)
def test_invalid_manifest_or_dependency_fails_startup(
    tmp_path: Path, setup: str, message: str
) -> None:
    if setup == "unsupported_api":
        write_manifest(tmp_path, "a", api_version=2)
        profile = write_profile(tmp_path, [enabled("a")])
    elif setup == "duplicate_id":
        write_manifest(tmp_path, "a", plugin_id="same")
        write_manifest(tmp_path, "b", plugin_id="same")
        profile = write_profile(tmp_path, [enabled("same")])
    else:
        write_manifest(tmp_path, "a", requires=["missing"])
        profile = write_profile(tmp_path, [enabled("a")])

    with pytest.raises(PluginLoadError, match=message):
        PluginLoader(SwarmContext(), tmp_path / "plugins").load_profile(profile)


def test_config_is_delivered_and_dependencies_load_first(tmp_path: Path) -> None:
    calls: list[tuple[str, dict[str, Any]]] = []

    class APlugin:
        plugin_id = "a"
        version = "1.0.0"

        def setup(self, ctx, config) -> None:
            calls.append(("a", dict(config)))
            ctx.services.register("a", object())

    class BPlugin:
        plugin_id = "b"
        version = "1.0.0"

        def setup(self, ctx, config) -> None:
            calls.append(("b", dict(config)))
            ctx.services.register("b", object())

    write_manifest(tmp_path, "a", entrypoint="fake:A", provides=["service:a"])
    write_manifest(
        tmp_path,
        "b",
        entrypoint="fake:B",
        requires=["a"],
        provides=["service:b"],
    )
    profile = write_profile(
        tmp_path,
        [enabled("b", {"value": 2}), enabled("a", {"value": 1})],
    )
    classes = {"fake:A": APlugin, "fake:B": BPlugin}

    PluginLoader(
        SwarmContext(),
        tmp_path / "plugins",
        resolver=lambda entrypoint: classes[entrypoint],
    ).load_profile(profile)

    assert calls == [("a", {"value": 1}), ("b", {"value": 2})]


def test_unload_rolls_back_when_teardown_raises(tmp_path: Path) -> None:
    class TeardownPlugin:
        plugin_id = "teardown"
        version = "1.0.0"

        def setup(self, ctx, config) -> None:
            ctx.services.register("teardown", object())

        def teardown(self, ctx) -> None:
            raise ValueError("teardown failed")

    write_manifest(
        tmp_path,
        "teardown",
        entrypoint="fake:Teardown",
        provides=["service:teardown"],
    )
    profile = write_profile(tmp_path, [enabled("teardown")])
    ctx = SwarmContext()
    loader = PluginLoader(
        ctx, tmp_path / "plugins", resolver=lambda _: TeardownPlugin
    )
    loader.load_profile(profile)

    with pytest.raises(PluginLoadError, match="teardown"):
        loader.unload_all()

    with pytest.raises(KeyError):
        ctx.services.get("teardown")
    assert loader.loaded_plugin_ids == ()
