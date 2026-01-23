@echo off
echo Running all tests...

REM Build first
call build.bat

REM Create output directory if not exists
if not exist tests\output mkdir tests\output

REM Run test cases
echo.
echo === Running Test Case 01 ===
build\main.exe tests\input\tc_01.txt "TC01"

echo.
echo === Running Test Case 02 ===
build\main.exe tests\input\tc_02.txt "TC02"

echo.
echo All tests complete!
echo Check results in tests\output\
pause
