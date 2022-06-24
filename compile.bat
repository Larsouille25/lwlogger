@echo off

:: t for test the program and r for release the program
set comp-type=%1 

:: r for run and n for no run
set schould-start=%2 

IF "%1"=="t" IF "%2"=="r" (
    echo Compiling the TEST Dll ...

    ::Compile DLL :
    g++ -Wall -shared src/logger.cpp -o builds/compile_test.dll

    echo Dll compiled !

    echo Compiling the test program ...
    ::Compile the test program :
    g++ test/test_main.cpp builds/compile_test.dll -o builds/test_prog

    echo Test program compiled !

    echo Run the test program ... 
    echo:
    echo:

    cd builds
    test_prog.exe
    cd ..
) 

IF NOT "%1"=="t" IF NOT "%2"=="r" (
    echo Compiling the Dll ...

    ::Compile DLL :
    g++ -Wall -shared src/logger.cpp -o builds/lwlogger_v1.0.0-rc.dll

    echo Dll compiled !

) 