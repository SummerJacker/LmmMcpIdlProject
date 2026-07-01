# -*- coding: utf-8 -*-
"""
对 console.pro.user 中「Desktop Qt 5.15.2 MSVC2019 32bit」目标（Target 0）写入：
- 全部 Make 步骤使用 jom（避免 Qt Creator 4.9 + CustomToolChain 无法推断 make）
- UserEnvironmentChanges：INCLUDE / LIB / RC / PATH+=（RC 为 rc.exe 全路径，供 link 解决 LNK1158；PATH+= 避免 %PATH% 在 Qt Creator 4.9 中未展开）

用法：在本机安装路径下执行
  python tools_apply_msvc_qtcreator_env.py
可编辑脚本内 PATHS 列表增删副本。

注意：Qt Creator 构建设置摘要有时只列出 INCLUDE/LIB；RC 与 PATH+= 仍在 console.pro.user 中，
可在「构建环境」展开详情核对，或用手动「添加」补全。
"""
from __future__ import annotations

import re
from pathlib import Path

PATHS = [
    Path(__file__).resolve().parent / "console.pro.user",
    Path(r"C:\qtpro\SAU\Console\console.pro.user"),
]

INCLUDE = (
    r"C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Tools\MSVC\14.29.30133\include;"
    r"C:\Program Files (x86)\Windows Kits\10\include\10.0.19041.0\ucrt;"
    r"C:\Program Files (x86)\Windows Kits\10\include\10.0.19041.0\shared;"
    r"C:\Program Files (x86)\Windows Kits\10\include\10.0.19041.0\um;"
    r"C:\Program Files (x86)\Windows Kits\10\include\10.0.19041.0\winrt;"
    r"C:\Program Files (x86)\Windows Kits\10\include\10.0.19041.0\cppwinrt"
)
LIB = (
    r"C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Tools\MSVC\14.29.30133\lib\x86;"
    r"C:\Program Files (x86)\Windows Kits\10\lib\10.0.19041.0\ucrt\x86;"
    r"C:\Program Files (x86)\Windows Kits\10\lib\10.0.19041.0\um\x86"
)
SDK_BIN_X86 = r"C:\Program Files (x86)\Windows Kits\10\bin\10.0.19041.0\x86"
RC_EXE = SDK_BIN_X86 + r"\rc.exe"
VC_BIN_X86 = (
    r"C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86"
)
JOM = "C:/qTT/Tools/QtCreator/bin/jom/jom.exe"

ENV_BLOCK = (
    '    <valuelist type="QVariantList" key="ProjectExplorer.BuildConfiguration.UserEnvironmentChanges">\n'
    f'     <value type="QString">INCLUDE={INCLUDE}</value>\n'
    f'     <value type="QString">LIB={LIB}</value>\n'
    f'     <value type="QString">RC={RC_EXE}</value>\n'
    f'     <value type="QString">PATH+={SDK_BIN_X86}</value>\n'
    f'     <value type="QString">PATH+={VC_BIN_X86}</value>\n'
    "    </valuelist>"
)

EMPTY_ENV = (
    '    <valuelist type="QVariantList" key="ProjectExplorer.BuildConfiguration.UserEnvironmentChanges"/>'
)
MAKE_RE = re.compile(
    r'<value type="QString" key="Qt4ProjectManager\.MakeStep\.MakeCommand">[^<]*</value>'
)


def patch_file(path: Path) -> None:
    if not path.is_file():
        print(f"skip (missing): {path}")
        return
    text = path.read_text(encoding="utf-8")
    t0 = "<variable>ProjectExplorer.Project.Target.0</variable>"
    t1 = "<variable>ProjectExplorer.Project.Target.1</variable>"
    tc = "<variable>ProjectExplorer.Project.TargetCount</variable>"
    if t0 not in text:
        print(f"skip (no Target 0): {path}")
        return
    i0 = text.index(t0)
    i1 = text.index(t1) if t1 in text else text.index(tc)
    head, seg, tail = text[:i0], text[i0:i1], text[i1:]

    if "Desktop Qt 5.15.2 MSVC2019 32bit" not in seg:
        print(f"skip (no MSVC2019 kit in Target 0): {path}")
        return

    seg = seg.replace(
        "C:/qtpro/SAU1122/SAU/build-console-Desktop_Qt_5_12_4_MSVC2017_32bit-Profile",
        "C:/qtpro/SAU1122/SAU/build-console-Desktop_Qt_5_15_2_MSVC2019_32bit-Debug",
    )
    seg = seg.replace(
        "C:/qtpro/SAU1122/SAU/build-console-Desktop_Qt_5_12_4_MSVC2017_32bit-debug",
        "C:/qtpro/SAU1122/SAU/build-console-Desktop_Qt_5_15_2_MSVC2019_32bit-Debug",
    )

    n_empty = seg.count(EMPTY_ENV)
    if n_empty != 3:
        print(f"warn {path}: expected 3 empty UserEnvironmentChanges in Target 0, got {n_empty}")
    else:
        seg = seg.replace(EMPTY_ENV, ENV_BLOCK)

    def _jom(_m: re.Match) -> str:
        return f'<value type="QString" key="Qt4ProjectManager.MakeStep.MakeCommand">{JOM}</value>'

    seg, n_make = MAKE_RE.subn(_jom, seg)
    if n_make != 6:
        print(f"warn {path}: expected 6 MakeCommand in Target 0, got {n_make}")

    path.write_text(head + seg + tail, encoding="utf-8", newline="\n")
    print(f"ok: {path}")


def main() -> None:
    for p in PATHS:
        patch_file(p)


if __name__ == "__main__":
    main()
