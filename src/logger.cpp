#include <iostream>
#include <ostream>
#include <string>
#include <ctime>
#include <fstream>
#include <sstream>

#include "logger.hpp"


Logger::Logger(std::string logsDir)
{
    char fileName[50];
    m_currentTime = time(NULL);

    time(&m_currentTime);
    m_localTime = localtime(&m_currentTime);

    std::strftime(fileName, 25, "%Y_%m_%d-%H-%M-%S.log", m_localTime); // Format the string with the correct name

    m_logFile = new std::ofstream(logsDir + fileName); // Create the file in the dir and with the correct name
}

Logger::~Logger()
{
    m_logFile->close();
}

std::string Logger::getTime()
{
    m_currentTime = time(NULL);
    m_localTime = localtime(&m_currentTime);

    std::stringstream ss;
    std::string date;

    ss << "[" << m_localTime->tm_hour << ":" << m_localTime->tm_min << ":" << m_localTime->tm_sec << "] ";
    date = ss.str();

    return date;
}

void Logger::info(std::string msg)
{
    std::cout << getTime() << "\033[0;37m[INFO] " << msg << "\033[0m" << std::endl;
    *m_logFile << getTime() << "[INFO] " << msg << std::endl;
}

void Logger::warn(std::string msg)
{
    std::cout << getTime() << "\033[0;33m[WARN] " << msg << "\033[0m" << std::endl;
    *m_logFile << getTime() << "[WARN] " << msg << std::endl;
}

void Logger::excp(std::string msg)
{
    std::cout << getTime() << "\033[0;31m[EXCP] " << msg << "\033[0m" << std::endl;
    *m_logFile << getTime() << "[EXCP] " << msg << std::endl;
}

void Logger::excp(std::exception e)
{
    std::cout << getTime() << "\033[0;31m[EXCP] " << e.what() << "\033[0m" << std::endl;
    *m_logFile << getTime() << "[WARN] " << e.what() << std::endl;
}

void Logger::nice(std::string msg)
{
    std::cout << getTime() << "\033[0;32m[NICE] " << msg << "\033[0m" << std::endl;
    *m_logFile << getTime() << "[NICE] " << msg << std::endl;
}

void Logger::dbug(std::string msg)
{
    std::cout << getTime() << "\033[0;36m[DBUG] " << msg << "\033[0m" << std::endl;
    *m_logFile << getTime() << "[DBUG] " << msg << std::endl;
}