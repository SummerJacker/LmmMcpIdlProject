from pathlib import Path

from modern_ilu_bridge.legacy_hello import (
    LegacyHelloInvoker,
    build_legacy_hello_record,
    extract_hello_response,
    run_legacy_client_process,
)


def test_extract_hello_response_from_legacy_client_stdout():
    stdout = """=== garbled legacy banner
>Hello! hello from Windows
>legacy exit text
"""

    assert extract_hello_response(stdout) == "Hello! hello from Windows"


def test_extract_hello_response_rejects_missing_response():
    try:
        extract_hello_response("no useful response")
    except ValueError as exc:
        assert "Hello!" in str(exc)
    else:
        raise AssertionError("missing legacy response should fail")


def test_build_legacy_hello_record_preserves_multilanguage_metadata():
    record = build_legacy_hello_record(
        name="legacy.hello-world.c",
        language="c",
        sbh="ilusbh:example",
        service_dir=Path("legacy-dir"),
    )

    assert record.name == "legacy.hello-world.c"
    assert record.language == "c"
    assert record.protocol == "ilu-sbh"
    assert record.interface_name == "hello_world.service"
    assert record.endpoint == "ilusbh:example"
    assert record.methods == ("hello_world",)
    assert record.metadata["adapter"] == "legacy-hello-world"
    assert record.metadata["service_dir"] == "legacy-dir"


def test_legacy_invoker_pipes_message_to_client_executable():
    calls = []

    def fake_run(command, input_text, cwd):
        calls.append((command, input_text, cwd))
        return ">Hello! bridged message\n>done\n"

    invoker = LegacyHelloInvoker(
        client_exe=Path("client.exe"),
        run_process=fake_run,
    )

    result = invoker.invoke("ilusbh:test", "bridged message")

    assert result == "Hello! bridged message"
    assert calls == [
        (
            [str(Path("client.exe")), "ilusbh:test"],
            "bridged message\r\nexit\r\n",
            Path("."),
        )
    ]


def test_windows_process_runner_uses_powershell_pipeline_bridge(tmp_path):
    calls = []

    class Completed:
        returncode = 0
        stdout = ">Hello! bridged through powershell\n"
        stderr = ""

    def fake_subprocess_run(command, **kwargs):
        calls.append((command, kwargs))
        return Completed()

    stdout = run_legacy_client_process(
        [str(Path("client.exe")), "ilusbh:test"],
        "bridged through powershell\r\nexit\r\n",
        Path("."),
        subprocess_run=fake_subprocess_run,
        platform_name="nt",
        temp_dir=tmp_path,
    )

    command, kwargs = calls[0]
    assert stdout == ">Hello! bridged through powershell\n"
    assert command[0] == "powershell"
    assert "-File" in command
    assert kwargs["cwd"] == "."
    assert kwargs["timeout"] == 15
    script_path = Path(command[command.index("-File") + 1])
    assert "Get-Content -LiteralPath $InputFile | & $Client $Sbh" in script_path.read_text(
        encoding="utf-8-sig"
    )
