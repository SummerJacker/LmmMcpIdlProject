# Manual live Console tests

These scenarios require a real Console at `127.0.0.1:9001` and may actuate
units. Run them only in a prepared, supervised environment. Run the commands
from `mcp`; each command requires `RUN_LIVE_CONSOLE_TESTS=1` explicitly.

## PowerShell

```powershell
$env:RUN_LIVE_CONSOLE_TESTS = "1"
python manual_tests/test_api_v2.py
python manual_tests/test_api_full.py
python -m pytest manual_tests/test_mcp_tools.py -q -m live_console
Remove-Item env:RUN_LIVE_CONSOLE_TESTS
```

## Bash

```bash
RUN_LIVE_CONSOLE_TESTS=1 python manual_tests/test_api_v2.py
RUN_LIVE_CONSOLE_TESTS=1 python manual_tests/test_api_full.py
RUN_LIVE_CONSOLE_TESTS=1 python -m pytest manual_tests/test_mcp_tools.py -q -m live_console
```
