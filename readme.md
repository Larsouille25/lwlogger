# lwlogger

Lwlogger is a C++ lightweight logger hence its name. With it you could debug your programs, save a trace of your programs and resolve bugs.

## How to use it ?

### Code

Just put the librairie and `logger.hpp` next to your executable. Include `logger.hpp`, where you want to use it. Or there is a test program you can go see it, if you want more details. When you initialize the logger, you just put the folder name followed by a `/`.

#### Example :
```cpp
#include "logger.hpp"

int main()
{
  Logger logger("logs/");
  
  logger.info("This is a test");
  
  return 0;
}
```

### Result

In the terminal, the result is ...
```

[11:26:15] [INFO] This is a test

```

And in the folder you have a file named with the following schematic `dd/mm/yyyy_hh:mm:ss.log`.

### Compile

With G++ you can compile your program like that : `g++ <main_cpp_file> lwlogger.dll -o <name_program>`

You can compile the lib if you want with this command `g++ -Wall -shared src/logger.cpp -o lwlogger.dll` at the root of the project !

## Your way to thank me
If you want to thank me, you can use this program, put a star and tell your friends about lwlogger!