$ErrorActionPreference = "Stop"

$root = Split-Path -Parent $MyInvocation.MyCommand.Path
$iluHome = Join-Path $root "Iluhome"
$demoDir = Join-Path $iluHome "examples\hello-world\WinRel"
$env:ILUHOME = $iluHome
$env:PATH = "$iluHome\bin;$env:PATH"

Set-Location $demoDir

$sbhFile = Join-Path $demoDir "SBHtempfile.tex"
$clientOut = Join-Path $demoDir "client-demo.out.txt"
$clientErr = Join-Path $demoDir "client-demo.err.txt"
Remove-Item -LiteralPath $sbhFile, $clientOut, $clientErr -ErrorAction SilentlyContinue

Write-Host "Starting hello-world server..."
$server = Start-Process -FilePath (Join-Path $demoDir "server.exe") -WorkingDirectory $demoDir -PassThru

Write-Host "Waiting for server address..."
$deadline = (Get-Date).AddSeconds(8)
while ((Get-Date) -lt $deadline -and -not (Test-Path $sbhFile)) {
  Start-Sleep -Milliseconds 250
}

if (-not (Test-Path $sbhFile)) {
  throw "SBHtempfile.tex was not created. Server PID: $($server.Id)"
}

$sbh = (Get-Content $sbhFile | Select-Object -First 1)
Write-Host "Server PID: $($server.Id)"
Write-Host "Server address:"
Write-Host $sbh
Write-Host ""
Write-Host "Calling client with message: hello from Windows"

"hello from Windows`r`nexit`r`n" | & (Join-Path $demoDir "client.exe") $sbh 2> $clientErr | Tee-Object -FilePath $clientOut

Write-Host ""
Write-Host "Demo finished."
Write-Host "To stop the demo server later, run: Stop-Process -Id $($server.Id)"
