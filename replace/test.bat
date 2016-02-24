REM
replace.exe
IF NOT ERRORLEVEL 1 GOTO err

REM
replace.exe abc zxc
IF NOT ERRORLEVEL 1 GOTO err

REM
replace.exe incorrectName.txt output.txt pa papa
IF NOT ERRORLEVEL 1 GOTO err

REM
replace.exe test_mama_in.txt output.txt ma mama
IF ERRORLEVEL 1 GOTO err
FC /b test_mama_out.txt output.txt
IF ERRORLEVEL 1 GOTO err

REM
replace.exe test_text_in.txt output.txt li QWERTY
IF ERRORLEVEL 1 GOTO err
FC /b test_text_out.txt output.txt
IF ERRORLEVEL 1 GOTO err

REM
replace.exe test_empty.txt output.txt nothing nothing1
IF ERRORLEVEL 1 GOTO err
FC /b test_empty.txt output.txt
IF ERRORLEVEL 1 GOTO err

REM
replace.exe test_12312312345_in.txt output.txt 1231234 mama
IF ERRORLEVEL 1 GOTO err
FC /b test_12312312345_out.txt output.txt
IF ERRORLEVEL 1 GOTO err

REM
replace.exe input.txt output.txt "" papa
IF ERRORLEVEL 1 GOTO err
FC /b input.txt output.txt
IF ERRORLEVEL 1 GOTO err

ECHO Tests are finished successfully.
EXIT /B
  
:err
ECHO Tests are unsuccessful.
EXIT /B