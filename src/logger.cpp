#include <iostream>
#include <ostream>
#include <string>
#include <ctime>
#include <fstream>
#include <sstream>

#include <lwlogger/logger.hpp>


namespace Larsouille {

Logger::Logger(std::string logsDir) : Logger(logsDir, "%Y_%m_%d-%H-%M-%S.log")
{}

Logger::Logger(std::string logsDir, const char* format)
{
    char fileName[50];
    m_currentTime = time(NULL);

    time(&m_currentTime);
    m_localTime = localtime(&m_currentTime);

    std::strftime(fileName, 25, format, m_localTime); // Format the string with the correct name

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

    if(m_localTime->tm_hour < 10)
        ss << "[" << "0" << m_localTime->tm_hour << ":";
    else
        ss << "[" << m_localTime->tm_hour << ":";

    

    if(m_localTime->tm_min < 10)
        ss << "0" << m_localTime->tm_min << ":";
    else
        ss << m_localTime->tm_min << ":";



    if(m_localTime->tm_sec < 10)
        ss << "0" << m_localTime->tm_sec << "] ";
    else
        ss << m_localTime->tm_sec << "] ";

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
    std::cout << getTime() << "\033[0;31m[EXCEPTION] " << msg << "\033[0m" << std::endl;
    *m_logFile << getTime() << "[EXCEPTION] " << msg << std::endl;
}

void Logger::excp(std::exception e)
{
    std::cout << getTime() << "\033[0;31m[EXCEPTION] " << e.what() << "\033[0m" << std::endl;
    *m_logFile << getTime() << "[EXCEPTION] " << e.what() << std::endl;
}

void Logger::success(std::string msg)
{
    std::cout << getTime() << "\033[0;32m[SUCCESS] " << msg << "\033[0m" << std::endl;
    *m_logFile << getTime() << "[SUCCESS] " << msg << std::endl;
}

void Logger::debug(std::string msg)
{
    std::cout << getTime() << "\033[0;36m[DEBUG] " << msg << "\033[0m" << std::endl;
    *m_logFile << getTime() << "[DEBUG] " << msg << std::endl;
}

void Logger::error(std::string msg)
{
    std::cout << getTime() << "\033[1;31m[ERROR] " << msg << "\033[0m" << std::endl;
    *m_logFile << getTime() << "[ERROR] " << msg << std::endl;
}

void Logger::fatal(std::string msg)
{
    std::cout << getTime() << "\033[101;31m[FATAL]\033[0m \033[1;31m" << msg << "\033[0m" << std::endl;
    *m_logFile << getTime() << "[FATAL] " << msg << std::endl;
}

} // namespace Larsouille