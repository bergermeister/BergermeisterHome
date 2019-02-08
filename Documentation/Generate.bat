@echo off

REM Add texlive and graphviz to the environment path
set path=C:\texlive\2018\bin\win32;C:\Program Files (x86)\Graphviz2.38\bin;%path%


REM Move to the Input directory
cd .\Input

REM Execute Doxygen
REM ( type doxyfile & echo PROJECT_NAME=%1 & echo PROJECT_NUMBER=%2 & echo PROJECT_BRIEF=%3 ) | doxygen -
( type doxyfile & echo PROJECT_NAME="Home Automation" & echo PROJECT_NUMBER="Dev. 1" & echo PROJECT_BRIEF="Bergermeister Home Automation Project" ) | doxygen -

REM Execute latex
call MakeTex.bat

REM Return to the Documentation directory
cd ..