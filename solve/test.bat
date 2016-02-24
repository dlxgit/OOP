REM
solve.exe
IF NOT ERRORLEVEL 1 GOTO err

REM
solve.exe "" "" ""
IF NOT ERRORLEVEL 1 GOTO err

REM
solve.exe 0 1 -1
IF NOT ERRORLEVEL 1 GOTO err

REM
solve.exe 1 2 3
IF ERRORLEVEL 1 GOTO err

REM
solve.exe 1.5 -2.2 3.0
IF ERRORLEVEL 1 GOTO err

REM
solve.exe 1 2 1
IF ERRORLEVEL 1 GOTO err

REM
solve.exe 1 -2 2.46
IF ERRORLEVEL 1 GOTO err

REM
solve.exe 1 2 3
IF ERRORLEVEL 1 GOTO err

ECHO Tests are finished successfully.
EXIT /B
  
:err
ECHO Tests are unsuccessful.
EXIT /B