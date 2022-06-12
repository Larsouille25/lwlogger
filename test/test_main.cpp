#include <iostream>
#include <stdio.h>

#include "../src/logger.hpp"

int main()
{
    Logger log("");

    log.warn("There is a new version of the API, please download it.");

    log.info("Loading 3D models ...");
    log.excp(" the 3D model was not found !");

    std::cout << std::endl;

    log.info("Try connecting to the API with this token '********************' !");
    log.info("Server detected ...");
    log.nice("Successfully connected to the API server !");

    log.warn("Divide a number with zero doesn't work.");
}