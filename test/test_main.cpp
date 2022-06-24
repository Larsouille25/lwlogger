#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <ctime>

#include "../src/logger.hpp"

using namespace Larsouille;

int main()
{
    Logger log("logs/", "%Y_%m_%d-%H-%M-%S.log");

    log.warn("There is a new version of the API, please download it.");

    log.info("Loading 3D models ...");
    Sleep(5564);
    log.excp("The 3D model was not found !");
    Sleep(6753);

    log.info("Try connecting to the API with this token '********************' !");
    Sleep(3124);
    log.info("Server detected ...");
    Sleep(2950);
    log.success("Successfully connected to the API server !");

    log.error("There is an error at line 51, column 72 !");

    log.debug("Connecting to the main server ...");
    log.fatal("A fatal error has occurred, we're trying to restart your program ...");

    Sleep(4825);

    log.warn("Divide a number with zero doesn't work.");

    Sleep(1627);

    log.info("Sending the report to the server ...");
    log.fatal("Don't send my data to your servers :)");

    return 0;
}