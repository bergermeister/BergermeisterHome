@echo off

REM Add texlive to the environment path
set path=C:\texlive\2018\bin\win32;%path%

REM Execute Doxygen
( type doxyfile & echo PROJECT_NAME=%1 & echo PROJECT_NUMBER=%2 & echo PROJECT_BRIEF=%3 ) | doxygen -

REM Execute latex
cd .\latex\
call make.bat
cd ..
