@echo off
rem Compile the C++ files
g++ generator.cpp -o generator.exe
if errorlevel 1 goto error

g++ bruteforce.cpp -o bruteforce.exe
if errorlevel 1 goto error

g++ check.cpp -o check.exe
if errorlevel 1 goto error

g++ checker.cpp -o checker.exe
if errorlevel 1 goto error

rem Run the checker executable
checker.exe

goto end

:error
echo Compilation failed.
pause

:end
