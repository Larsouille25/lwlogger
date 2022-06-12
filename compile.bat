@Echo off

echo Compiling the dll ...
::Compile DLL :
g++ -Wall -shared src/logger.cpp -o lwlogger.dll

echo Dll compiled !

echo Compiling the test program ...
::Compile the test program :
g++ test/test_main.cpp lwlogger.dll -o test_prog

echo Test program compiled !