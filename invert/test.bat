REM
invert.exe input.txt output.txt
IF NOT ERRORLEVEL 1 GOTO err

invert.exe test_successful1.txt
IF ERRORLEVEL 1 GOTO err

invert.exe test_successful2.txt
IF ERRORLEVEL 1 GOTO err

invert.exe test_incorrect1.txt
IF NOT ERRORLEVEL 1 GOTO err

invert.exe test_incorrect2.txt
IF NOT ERRORLEVEL 1 GOTO err

invert.exe test_incorrect3.txt
IF NOT ERRORLEVEL 1 GOTO err

invert.exe test_incorrect4.txt
IF NOT ERRORLEVEL 1 GOTO err


ECHO Tests are finished successfully.
EXIT /B
  
:err
ECHO Tests are unsuccessful.
EXIT /B