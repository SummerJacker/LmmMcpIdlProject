$ErrorActionPreference = "Stop"

$root = Split-Path -Parent $MyInvocation.MyCommand.Path
$project = Join-Path $root "modern-ilu-bridge"
$env:PYTHONPATH = "$project;$env:PYTHONPATH"

python -m modern_ilu_bridge.apps.run_demo

