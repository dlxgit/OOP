REM
invert.exe input.txt output.txt
IF NOT ERRORLEVEL 1 GOTO err

REM
Debug\invert.exe test_successful1.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt test_successful1_out.txt
IF NOT ERRORLEVEL 0 GOTO err

REM
Debug\invert.exe test_successful2.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt test_successful2_out.txt
IF NOT ERRORLEVEL 0 GOTO err

REM
Debug\invert.exe test_incorrect1.txt
IF NOT ERRORLEVEL 3 GOTO err

REM
Debug\invert.exe test_incorrect2.txt
IF NOT ERRORLEVEL 3 GOTO err

REM
Debug\invert.exe test_incorrect3.txt
IF NOT ERRORLEVEL 3 GOTO err

REM
Debug\invert.exe test_incorrect_empty.txt
IF NOT ERRORLEVEL 1 GOTO err

REM
Debug\invert.exe test_zero_det.txt
IF NOT ERRORLEVEL 2 GOTO err

ECHO Tests are finished successfully.
EXIT /B

:err
ECHO Tests are unsuccessful.
EXIT /B