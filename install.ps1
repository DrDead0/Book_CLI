$installDir = "$env:USERPROFILE\.bookcli\bin"
$exePath = "$installDir\book.exe"
$repoUrl = "https://github.com/drdead0/Book_CLI/releases/latest/download/book.exe"

Write-Host "Installing Book CLI..." -ForegroundColor Cyan


if (!(Test-Path $installDir)) {
    New-Item -ItemType Directory -Force -Path $installDir | Out-Null
}


Write-Host "Downloading latest release..."
Invoke-WebRequest -Uri $repoUrl -OutFile $exePath


$userPath = [Environment]::GetEnvironmentVariable("PATH", "User")
if ($userPath -notmatch [regex]::Escape($installDir)) {
    [Environment]::SetEnvironmentVariable("PATH", "$userPath;$installDir", "User")
    Write-Host "Added $installDir to your PATH." -ForegroundColor Green
}

Write-Host "Installation complete. Please restart your terminal and type 'book'." -ForegroundColor Green