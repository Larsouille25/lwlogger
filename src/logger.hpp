#ifndef LOGGER_HPP_INCLUDED
#define LOGGER_HPP_INCLUDED

#include <string>
#include <ostream>
#include <ctime>
#include <fstream>

class Logger
{
public:

    Logger(std::string logsDir);
    ~Logger();

    void info(std::string msg);

    void warn(std::string msg);

    void excp(std::string msg);
    void excp(std::exception e);

    void nice(std::string msg);

    void dbug(std::string msg);

private:
    std::ofstream *m_logFile;

    std::time_t m_currentTime;
    std::tm *m_localTime;

    std::string getTime();
};

#endif