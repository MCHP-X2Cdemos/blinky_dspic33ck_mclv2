@echo off

set PROJECT_ROOT= C:\_projects\blinky_dspic33ck_mclv2
set MPLABX_ROOT=C:\Program Files (x86)\Microchip\MPLABX\v5.40
set DEVICE=33CK256MP508
set TOOL=ICD4
set HEXFILE=/dist/default/production/blinky_dspic33ck_mclv2.X.production.hex

:: log file to current users' desktop
::set BATCHLOG=%USERPROFILE%\Desktop\batchlog.txt
set BATCHLOG=%PROJECT_ROOT%\batchlog.txt
set MAKEFILE=%PROJECT_ROOT%\Makefile


:: make command
set MAKECMD="%MPLABX_ROOT%\gnuBins\GnuWin32\bin\make" -f %PROJECT_ROOT%\Makefile 

date /T > %BATCHLOG%
time /T >> %BATCHLOG%
echo Current directory: %cd% >> %BATCHLOG%
echo Makefile: %MAKEFILE% >> %BATCHLOG%
echo Hexfile: %HEXFILE% >> %BATCHLOG%



cd %PROJECT_ROOT%

ECHO DATE /T
ECHO TIME /T
ECHO *****************************************************
ECHO ** make the project                                **
ECHO *****************************************************
echo Execute make: >> %BATCHLOG%
echo %MAKECMD% >> %BATCHLOG%

%MAKECMD%

echo *****************************************************
echo ** program the device                              **
java -jar "%MPLABX_ROOT%\mplab_platform\mplab_ipe\ipecmd.jar" /P%DEVICE% /"F.%HEXFILE%" /TP%TOOL% /M /OL

::pause
