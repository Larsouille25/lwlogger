#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <ctime>

#include "../src/logger.hpp"

int main()
{
    
    Logger log("logs/");

    log.dbug("Debug has been activated !");

    std::cout << std::endl;

    log.warn("There is a new version of the API, please download it.");


    log.info("Loading 3D models ...");
    Sleep(5564);
    log.excp("The 3D model was not found !");

    std::cout << std::endl;
    Sleep(6753);

    log.info("Try connecting to the API with this token '********************' !");
    Sleep(3124);
    log.info("Server detected ...");
    Sleep(2950);
    log.nice("Successfully connected to the API server !");

    Sleep(4825);

    log.warn("Divide a number with zero doesn't work.");


    // char fileName[50];
    // std::time_t currentTime = time(NULL);
    // std::tm * localTime;

    // time(&currentTime);
    // localTime = localtime(&currentTime);

    // std::strftime(fileName, 50, "%Y_%m_%d-%H-%M-%S.log", localTime);

    // std::cout << fileName;
    return 0;
}