@echo off
cd /d %~dp0
set curpath=%~dp0

if not exist build md build
cd build
if not exist x86 md x86
cd x86
if not exist windows md windows
cd windows

if exist %curpath%setenv.gitignore.bat call %curpath%setenv.gitignore.bat

cmake -G"Visual Studio 14 2015" -DHOST_PLATFORM=PLATFORM_X86 -DHOST_OS=WINDOWS ../../../src
@pause
