from __future__ import annotations

import shutil
from dataclasses import dataclass
from pathlib import Path
from typing import Callable


@dataclass(frozen=True)
class LegacyCatalogEntry:
    name: str
    language: str
    interface_name: str
    methods: tuple[str, ...]
    service_dir: Path
    server_path: Path
    client_path: Path
    required_commands: tuple[str, ...] = ()


@dataclass(frozen=True)
class LegacyCatalogSummary:
    name: str
    language: str
    interface_name: str
    methods: tuple[str, ...]
    ready: bool
    reason: str
    service_dir: Path


FileExists = Callable[[Path], bool]
CommandExists = Callable[[str], bool]


def build_default_hello_world_catalog(repo_root: Path) -> list[LegacyCatalogEntry]:
    hello_root = repo_root / "Iluhome" / "examples" / "hello-world"
    winrel = hello_root / "WinRel"
    return [
        LegacyCatalogEntry(
            name="legacy.hello-world.c",
            language="c",
            interface_name="hello_world.service",
            methods=("hello_world",),
            service_dir=winrel,
            server_path=winrel / "server.exe",
            client_path=winrel / "client.exe",
        ),
        LegacyCatalogEntry(
            name="legacy.hello-world.java",
            language="java",
            interface_name="hello_world.service",
            methods=("hello_world",),
            service_dir=hello_root,
            server_path=hello_root / "Server.java",
            client_path=hello_root / "Client.java",
            required_commands=("java",),
        ),
        LegacyCatalogEntry(
            name="legacy.hello-world.python",
            language="python",
            interface_name="hello_world.service",
            methods=("hello_world",),
            service_dir=hello_root,
            server_path=hello_root / "server.py",
            client_path=hello_root / "client.py",
            required_commands=("python2",),
        ),
        LegacyCatalogEntry(
            name="legacy.hello-world.lisp",
            language="lisp",
            interface_name="hello_world.service",
            methods=("hello_world",),
            service_dir=hello_root,
            server_path=hello_root / "server.lisp",
            client_path=hello_root / "client.lisp",
            required_commands=("clisp",),
        ),
    ]


def summarize_catalog(
    catalog: list[LegacyCatalogEntry],
    file_exists: FileExists | None = None,
    command_exists: CommandExists | None = None,
) -> list[LegacyCatalogSummary]:
    file_exists = file_exists or Path.exists
    command_exists = command_exists or (lambda command: shutil.which(command) is not None)
    return [_summarize_entry(entry, file_exists, command_exists) for entry in catalog]


def _summarize_entry(
    entry: LegacyCatalogEntry,
    file_exists: FileExists,
    command_exists: CommandExists,
) -> LegacyCatalogSummary:
    missing: list[str] = []
    for path in (entry.server_path, entry.client_path):
        if not file_exists(path):
            missing.append(f"missing file: {path}")
    for command in entry.required_commands:
        if not command_exists(command):
            missing.append(f"missing command: {command}")

    return LegacyCatalogSummary(
        name=entry.name,
        language=entry.language,
        interface_name=entry.interface_name,
        methods=entry.methods,
        ready=not missing,
        reason="ready" if not missing else "; ".join(missing),
        service_dir=entry.service_dir,
    )

