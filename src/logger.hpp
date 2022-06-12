#ifndef LOGGER_HPP_INCLUDED
#define LOGGER_HPP_INCLUDED

#include <string>
#include <ostream>
#include <ctime>

class Logger
{
public:

    Logger(std::string logsDir);

    void info(std::string msg);

    void warn(std::string msg);

    void excp(std::string msg);
    void excp(std::exception e);

    void nice(std::string msg);

    void dbug(std::string msg);

private:
    std::string m_logsDir;

    std::time_t m_currentTime;
    std::tm *m_localTime;

    void printTime();
};

#endif