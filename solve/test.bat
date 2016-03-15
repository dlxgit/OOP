REM
solve.exe
IF NOT ERRORLEVEL 1 GOTO err

REM
solve.exe "" "" ""
IF NOT ERRORLEVEL 1 GOTO err

REM
solve.exe 3k 2.z 7.7
IF NOT ERRORLEVEL 1 GOTO err

REM
solve.exe 1. .1 1..1
IF NOT ERRORLEVEL 1 GOTO err

REM
solve.exe a 3 -
IF NOT ERRORLEVEL 1 GOTO err

REM
solve.exe 0.000 1 -1
IF NOT ERRORLEVEL 1 GOTO err

REM
solve.exe 1 2 3
IF ERRORLEVEL 1 GOTO err
FC /b test_empty.txt output.txt
IF ERRORLEVEL 1 GOTO err

REM
solve.exe 5.5 -2.2 3.0
IF ERRORLEVEL 1 GOTO err
FC /b test_empty.txt output.txt
IF ERRORLEVEL 1 GOTO err

REM
solve.exe 4 -2 2.46
IF ERRORLEVEL 1 GOTO err
FC /b test_empty.txt output.txt
IF ERRORLEVEL 1 GOTO err

REM
solve.exe 1 2.3 1.001
IF ERRORLEVEL 1 GOTO err
FC /b test_1.txt output.txt
IF ERRORLEVEL 1 GOTO err

REM
solve.exe -2 1 5
IF ERRORLEVEL 1 GOTO err
FC /b test_2.txt output.txt
IF ERRORLEVEL 1 GOTO err

REM
solve.exe 1 6 9
IF ERRORLEVEL 1 GOTO err
FC /b test_3.txt output.txt
IF ERRORLEVEL 1 GOTO err

ECHO Tests are finished successfully.
EXIT /B
  
:err
ECHO Tests are unsuccessful.
EXIT /B