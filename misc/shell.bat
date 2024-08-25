@echo off
:: Day 001 in misc\shell.bat there is no path


call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x64

set PATH="C:\Program Files\CMake\bin\";%PATH%