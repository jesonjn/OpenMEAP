@echo off

call %OPENMEAP_HOME%\build-tools\scripts\setEnv.bat

ant -f %OPENMEAP_HOME%\build-tools\ant_scripts\client_android.xml -Dbasedir "%cd%" %*
