from __future__ import annotations

import os
import subprocess
import tempfile
import time
from pathlib import Path
from typing import Callable

from modern_ilu_bridge.registry_store import ServiceRecordData


RunProcess = Callable[[list[str], str, Path], str]


def extract_hello_response(stdout: str) -> str:
    for raw_line in stdout.splitlines():
        line = raw_line.strip()
        if "Hello!" in line:
            return line[line.index("Hello!") :]
    raise ValueError("Legacy client output did not contain a Hello! response")


def build_legacy_hello_record(
    name: str,
    language: str,
    sbh: str,
    service_dir: Path,
) -> ServiceRecordData:
    return ServiceRecordData(
        name=name,
        language=language,
        protocol="ilu-sbh",
        interface_name="hello_world.service",
        endpoint=sbh,
        methods=("hello_world",),
        metadata={
            "adapter": "legacy-hello-world",
            "service_dir": str(service_dir),
        },
    )


class LegacyHelloInvoker:
    def __init__(
        self,
        client_exe: Path,
        run_process: RunProcess | None = None,
    ):
        self._client_exe = client_exe
        self._run_process = run_process or self._default_run_process

    def invoke(self, sbh: str, message: str) -> str:
        input_text = f"{message}\r\nexit\r\n"
        stdout = self._run_process(
            [str(self._client_exe), sbh],
            input_text,
            self._client_exe.parent,
        )
        return extract_hello_response(stdout)

    @staticmethod
    def _default_run_process(command: list[str], input_text: str, cwd: Path) -> str:
        return run_legacy_client_process(command, input_text, cwd)


class LegacyHelloRunner:
    def __init__(
        self,
        service_dir: Path,
        server_exe: Path | None = None,
        sbh_file: Path | None = None,
    ):
        self.service_dir = service_dir
        self.server_exe = server_exe or service_dir / "server.exe"
        self.sbh_file = sbh_file or service_dir / "SBHtempfile.tex"
        self.process: subprocess.Popen | None = None

    def start(self, timeout_seconds: float = 8.0) -> str:
        self.sbh_file.unlink(missing_ok=True)
        env = self._legacy_env()
        self.process = subprocess.Popen(
            [str(self.server_exe)],
            cwd=str(self.service_dir),
            env=env,
            stdout=subprocess.DEVNULL,
            stderr=subprocess.DEVNULL,
            creationflags=getattr(subprocess, "CREATE_NO_WINDOW", 0),
        )

        deadline = time.time() + timeout_seconds
        while time.time() < deadline:
            if self.sbh_file.exists():
                sbh = self.sbh_file.read_text(errors="replace").strip().splitlines()[0]
                if sbh:
                    return sbh
            if self.process.poll() is not None:
                raise RuntimeError(f"Legacy server exited with code {self.process.returncode}")
            time.sleep(0.2)
        raise TimeoutError(f"Legacy server did not write {self.sbh_file}")

    def stop(self) -> None:
        if self.process is None or self.process.poll() is not None:
            return
        self.process.terminate()
        try:
            self.process.wait(timeout=3)
        except subprocess.TimeoutExpired:
            self.process.kill()

    def _legacy_env(self) -> dict[str, str]:
        env = os.environ.copy()
        ilu_home = self._infer_ilu_home()
        if ilu_home is not None:
            env["ILUHOME"] = str(ilu_home)
            env["PATH"] = f"{ilu_home / 'bin'};{env.get('PATH', '')}"
        return env

    def _infer_ilu_home(self) -> Path | None:
        current = self.service_dir.resolve()
        for parent in [current, *current.parents]:
            if (parent / "bin" / "ILUCosNaming.exe").exists():
                return parent
        return None


def run_legacy_client_process(
    command: list[str],
    input_text: str,
    cwd: Path,
    subprocess_run=subprocess.run,
    platform_name: str = os.name,
    temp_dir: Path | None = None,
) -> str:
    if platform_name == "nt":
        return _run_legacy_client_with_powershell(command, input_text, cwd, subprocess_run, temp_dir)

    completed = subprocess_run(
        command,
        input=input_text,
        cwd=str(cwd),
        text=True,
        capture_output=True,
        errors="replace",
        timeout=15,
    )
    return _checked_stdout(completed)


def _run_legacy_client_with_powershell(
    command: list[str],
    input_text: str,
    cwd: Path,
    subprocess_run,
    temp_dir: Path | None,
) -> str:
    if len(command) < 2:
        raise ValueError("legacy client command must include executable and SBH")
    temp_root = temp_dir or Path(tempfile.gettempdir())
    temp_root.mkdir(parents=True, exist_ok=True)
    input_file = tempfile.NamedTemporaryFile(
        "w",
        delete=False,
        suffix=".txt",
        encoding="utf-8",
        dir=str(temp_root),
    )
    script_file = tempfile.NamedTemporaryFile(
        "w",
        delete=False,
        suffix=".ps1",
        encoding="utf-8-sig",
        dir=str(temp_root),
    )
    try:
        with input_file:
            input_file.write(input_text.replace("\r\n", "\n"))
        with script_file:
            script_file.write(
                "param([string]$Client, [string]$Sbh, [string]$InputFile)\n"
                "Get-Content -LiteralPath $InputFile | & $Client $Sbh\n"
            )
        completed = subprocess_run(
            [
                "powershell",
                "-NoProfile",
                "-ExecutionPolicy",
                "Bypass",
                "-File",
                script_file.name,
                command[0],
                command[1],
                input_file.name,
            ],
            cwd=str(cwd),
            text=True,
            capture_output=True,
            errors="replace",
            timeout=15,
        )
        return _checked_stdout(completed)
    finally:
        if temp_dir is None:
            Path(input_file.name).unlink(missing_ok=True)
            Path(script_file.name).unlink(missing_ok=True)


def _checked_stdout(completed) -> str:
    if completed.returncode != 0:
        raise RuntimeError(
            "Legacy client failed with exit code "
            f"{completed.returncode}: {completed.stderr.strip()}"
        )
    return completed.stdout
