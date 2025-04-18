@echo off
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
if not exist build\Win mkdir build\Win
cl /EHsc /c HappyYear.cpp
link HappyYear.obj /OUT:"build\Win\HappyYear.exe"
del HappyYear.obj
if %errorlevel% equ 0 (
    echo Build successful!
) else (
    echo Build failed with error code %errorlevel%.
    exit /b %errorlevel%
)
