
$ErrorActionPreference = "Stop"

$installDir = "$env:USERPROFILE\.bookcli\bin"
$exePath = "$installDir\book.exe"
$repoUrl = "https://github.com/DrDead0/Book_CLI/releases/download/v0.2/book.exe"

Write-Host "Installing Book CLI v0.2.0..." -ForegroundColor Cyan


if (!(Test-Path $installDir)) {
    New-Item -ItemType Directory -Force -Path $installDir | Out-Null
}


Write-Host "Downloading release binary..." -ForegroundColor Cyan
Invoke-WebRequest -Uri $repoUrl -OutFile $exePath


$userPath = [Environment]::GetEnvironmentVariable("PATH", "User")
if ($userPath -notmatch [regex]::Escape($installDir)) {
    [Environment]::SetEnvironmentVariable("PATH", "$userPath;$installDir", "User")
    Write-Host "Added $installDir to your PATH." -ForegroundColor Green
}

Write-Host "Installation complete! Please restart your terminal and run 'book'." -ForegroundColor Green