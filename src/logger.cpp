#include <iostream>
#include <ostream>
#include <string>
#include <ctime>

#include "logger.hpp"


Logger::Logger(std::string logsDir) : m_logsDir(logsDir)
{
    m_currentTime = time(NULL);
}

void Logger::printTime()
{
    m_currentTime = time(NULL);
    m_localTime = localtime(&m_currentTime);

    std::cout << "[" << m_localTime->tm_hour << ":" << m_localTime->tm_min << ":" << m_localTime->tm_sec << "] ";
}


void Logger::info(std::string msg)
{
    printTime();
    std::cout << "\033[0;37m[INFO] " << msg << "\033[0m" << std::endl;
}

void Logger::warn(std::string msg)
{
    printTime();
    std::cout << "\033[0;33m[WARN] " << msg << "\033[0m" << std::endl;
}

void Logger::excp(std::string msg)
{
    printTime();
    std::cout << "\033[0;31m[EXCP] " << msg << "\033[0m" << std::endl;
}

void Logger::excp(std::exception e)
{
    printTime();
    std::cout << "\033[0;31m[EXCP] " << e.what() << "\033[0m" << std::endl;
}

void Logger::nice(std::string msg)
{
    printTime();
    std::cout << "\033[0;32m[NICE] " << msg << "\033[0m" << std::endl;
}

void Logger::dbug(std::string msg)
{
    printTime();
    std::cout << "\033[0;36m[DBUG] " << msg << "\033[0m" << std::endl;
}