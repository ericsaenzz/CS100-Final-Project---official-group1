@echo off
echo Compiling Task Scheduler...
g++ -std=c++17 -Wall -Iinclude -o task_scheduler.exe src/TaskManager.cpp src/main.cpp

if %errorlevel% equ 0 (
    echo.
    echo Compilation successful!
    echo Run: .\task_scheduler.exe
    echo.
    pause
) else (
    echo.
    echo Compilation failed. Check errors above.
    echo.
    pause
)