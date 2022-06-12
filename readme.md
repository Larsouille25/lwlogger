# lwlogger

Lwlogger is a C++ lightweight logger hence its name. With him you could debug your programs, save a trace of your program and resolve bugs.

## How to use it ?

### Code

Just put the librairie and `logger.hpp` next to your executable. Include `logger.hpp`, where you want to use it. Or there is a test program you can go see it, if you want more details.

#### Example :
```cpp
#include "logger.hpp"

int main()
{
  Logger logger("");
  
  logger.info("This is a test");
  
  return 0;
}

```
### Compile

With G++ you can compile your program like that : `g++ <main_cpp_file> lwlogger.dll -o <name_program>`

## Your way to thank me
If you want to thank me, you can use this program, put a star and tell your friends about lwlogger!