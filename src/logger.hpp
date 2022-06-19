#ifndef LWLOGGER_LOGGER_HPP
#define LWLOGGER_LOGGER_HPP

#include <string>
#include <ostream>
#include <ctime>
#include <fstream>

class Logger
{
public:

    Logger(std::string logsDir);
    ~Logger();

    void success(std::string msg);

    void debug(std::string msg);

    void info(std::string msg);

    void warn(std::string msg);

    void excp(std::string msg);
    void excp(std::exception e);

    void error(std::string msg);

    void fatal(std::string msg);

private:
    std::ofstream *m_logFile;

    std::time_t m_currentTime;
    std::tm *m_localTime;

    std::string getTime();
};

#endif