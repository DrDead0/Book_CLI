@echo off
echo ===================================
echo   Compiling BOOK CLI...
echo ===================================


cmake --build build

if %ERRORLEVEL% EQU 0 (
    echo.
    echo ===================================
    echo   Build Success! Starting shell...
    echo ===================================
    echo.
    
    .\build\book.exe
) else (
    echo.
    echo ===================================
    echo   BUILD FAILED! Check the errors.
    echo ===================================
)