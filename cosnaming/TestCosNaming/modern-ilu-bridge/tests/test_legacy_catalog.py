from pathlib import Path

from modern_ilu_bridge.legacy_catalog import (
    build_default_hello_world_catalog,
    summarize_catalog,
)


def test_default_catalog_contains_all_legacy_languages():
    catalog = build_default_hello_world_catalog(Path("repo"))

    assert [entry.language for entry in catalog] == ["c", "java", "python", "lisp"]
    assert [entry.name for entry in catalog] == [
        "legacy.hello-world.c",
        "legacy.hello-world.java",
        "legacy.hello-world.python",
        "legacy.hello-world.lisp",
    ]
    assert all(entry.interface_name == "hello_world.service" for entry in catalog)
    assert all(entry.methods == ("hello_world",) for entry in catalog)


def test_catalog_marks_c_available_when_executables_exist():
    existing = {
        Path("repo/Iluhome/examples/hello-world/WinRel/server.exe"),
        Path("repo/Iluhome/examples/hello-world/WinRel/client.exe"),
    }

    summary = summarize_catalog(
        build_default_hello_world_catalog(Path("repo")),
        file_exists=lambda path: path in existing,
        command_exists=lambda command: False,
    )

    c_entry = next(item for item in summary if item.language == "c")
    java_entry = next(item for item in summary if item.language == "java")

    assert c_entry.ready is True
    assert c_entry.reason == "ready"
    assert java_entry.ready is False
    assert "missing command: java" in java_entry.reason


def test_catalog_marks_python_and_lisp_ready_when_expected_runtime_exists():
    existing = {
        Path("repo/Iluhome/examples/hello-world/server.py"),
        Path("repo/Iluhome/examples/hello-world/client.py"),
        Path("repo/Iluhome/examples/hello-world/server.lisp"),
        Path("repo/Iluhome/examples/hello-world/client.lisp"),
    }

    summary = summarize_catalog(
        build_default_hello_world_catalog(Path("repo")),
        file_exists=lambda path: path in existing,
        command_exists=lambda command: command in {"python2", "clisp"},
    )

    python_entry = next(item for item in summary if item.language == "python")
    lisp_entry = next(item for item in summary if item.language == "lisp")

    assert python_entry.ready is True
    assert lisp_entry.ready is True

