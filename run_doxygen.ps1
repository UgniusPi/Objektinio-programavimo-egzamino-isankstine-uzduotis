#!/usr/bin/env pwsh
# Run Doxygen for this project (PowerShell)

if (-not (Get-Command doxygen -ErrorAction SilentlyContinue)) {
    Write-Error "Doxygen nerastas. Įdiekite doxygen ir pridėkite jį į PATH."
    exit 1
}

doxygen Doxyfile

if ($LASTEXITCODE -eq 0) {
    Write-Host "Doxygen baigė darbą. Peržiūrėkite docs/html/index.html"
    exit 0
} else {
    Write-Error "Doxygen grąžino klaidą (exit code $LASTEXITCODE)."
    exit $LASTEXITCODE
}
