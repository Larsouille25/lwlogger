@Echo off

cls

echo Compiling the dll ...
::Compile DLL :
g++ -Wall -shared src/logger.cpp -o builds/lwlogger_v1.0.0-rc.dll

echo Dll compiled !

echo Compiling the test program ...
::Compile the test program :
g++ test/test_main.cpp builds/lwlogger_v1.0.0-rc.dll -o builds/test_prog

echo Test program compiled !

echo Run the test program ... 
echo:

cd builds
test_prog.exe
cd ..