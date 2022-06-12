#include <iostream>
#include <stdio.h>
//#include <windows.h>

#include "../src/logger.hpp"

int main()
{
    Logger log("");

    log.dbug("Debug mode was activated !");

    std::cout << std::endl;

    log.warn("There is a new version of the API, please download it.");


    log.info("Loading 3D models ...");
    //Sleep(5564);
    log.excp(" the 3D model was not found !");

    std::cout << std::endl;
    //Sleep(6753);

    log.info("Try connecting to the API with this token '********************' !");
    //Sleep(3124);
    log.info("Server detected ...");
    //Sleep(2950);
    log.nice("Successfully connected to the API server !");

    //Sleep(4825);

    log.warn("Divide a number with zero doesn't work.");

    return 0;
}