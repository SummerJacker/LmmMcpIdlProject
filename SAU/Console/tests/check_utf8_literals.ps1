param(
    [string]$ConsoleDir = (Resolve-Path (Join-Path $PSScriptRoot '..')).Path
)

$consoleCpp = Join-Path $ConsoleDir 'console.cpp'
$consolePro = Join-Path $ConsoleDir 'console.pro'

if (-not (Test-Path -LiteralPath $consoleCpp)) {
    throw "console.cpp not found: $consoleCpp"
}

if (-not (Test-Path -LiteralPath $consolePro)) {
    throw "console.pro not found: $consolePro"
}

$badLiterals = Select-String `
    -LiteralPath $consoleCpp `
    -Pattern 'QStringLiteral\("[^"]*[\u4e00-\u9fff]' `
    -Encoding UTF8

if ($badLiterals.Count -gt 0) {
    $badLiterals | Select-Object -First 20 | ForEach-Object {
        Write-Error ("{0}:{1}: {2}" -f $_.Path, $_.LineNumber, $_.Line.Trim())
    }
    throw "Chinese runtime text in console.cpp must use QString::fromUtf8, not QStringLiteral."
}

$utf8Flags = Select-String `
    -LiteralPath $consolePro `
    -Pattern 'QMAKE_(C|CXX)FLAGS\s*\+=\s*/utf-8' `
    -Encoding UTF8

if ($utf8Flags.Count -lt 2) {
    throw "console.pro must keep /utf-8 in both QMAKE_CFLAGS and QMAKE_CXXFLAGS."
}

Write-Output "UTF-8 literal checks passed."
