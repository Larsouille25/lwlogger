#include <iostream>
#include <lwlogger/logger.hpp>

int main()
{
    Larsouille::Logger logger("logs/");

    logger.success("The library work very well!");

    return 0;
}