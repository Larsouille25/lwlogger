#include <iostream>
#include <ostream>
#include <string>
#include <ctime>
#include <fstream>
#include <sstream>
#include <cstdio> 
#include <cstdarg> 

#include <lwlogger/logger.hpp>


namespace Larsouille {

char* convert(unsigned int, int);

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

void Logger::info(std::string format_s, ...)
{
    std::cout << getTime() << "\033[0;37m[INFO] ";

    char* format = const_cast<char*>(format_s.c_str());

    char *traverse; 
    unsigned int i; 
    char *s; 

    //Module 1: Initializing Myprintf's arguments 
    va_list arg; 
    va_start(arg, format_s); 

    for(traverse = format; *traverse != '\0'; traverse++) 
    { 
        while( *traverse != '%' ) 
        { 
            putchar(*traverse);
            traverse++; 
        } 

        traverse++; 

        //Module 2: Fetching and executing arguments
        switch(*traverse) 
        { 
            case 'c' : i = va_arg(arg,int);     //Fetch char argument
                        putchar(i);
                        break; 

            case 'd' : i = va_arg(arg,int);         //Fetch Decimal/Integer argument
                        if(i<0) 
                        { 
                            i = -i;
                            putchar('-'); 
                        } 
                        puts(convert(i,10));
                        break; 

            case 'o': i = va_arg(arg,unsigned int); //Fetch Octal representation
                        puts(convert(i,8));
                        break; 

            case 's': s = va_arg(arg,char *);       //Fetch string
                        puts(s); 
                        break; 

            case 'x': i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
                        puts(convert(i,16));
                        break; 
        }   
    } 

    //Module 3: Closing argument list to necessary clean-up
    va_end(arg); 

    std::cout << "\033[0m" << std::endl;
    *m_logFile << getTime() << "[INFO] " << format_s << std::endl;
}

void Logger::warn(std::string format_s, ...)
{
    std::cout << getTime() << "\033[0;33m[WARN] ";
    
    char* format = const_cast<char*>(format_s.c_str());

    char *traverse; 
    unsigned int i; 
    char *s; 

    //Module 1: Initializing Myprintf's arguments 
    va_list arg; 
    va_start(arg, format_s); 

    for(traverse = format; *traverse != '\0'; traverse++) 
    { 
        while( *traverse != '%' ) 
        { 
            putchar(*traverse);
            traverse++; 
        } 

        traverse++; 

        //Module 2: Fetching and executing arguments
        switch(*traverse) 
        { 
            case 'c' : i = va_arg(arg,int);     //Fetch char argument
                        putchar(i);
                        break; 

            case 'd' : i = va_arg(arg,int);         //Fetch Decimal/Integer argument
                        if(i<0) 
                        { 
                            i = -i;
                            putchar('-'); 
                        } 
                        puts(convert(i,10));
                        break; 

            case 'o': i = va_arg(arg,unsigned int); //Fetch Octal representation
                        puts(convert(i,8));
                        break; 

            case 's': s = va_arg(arg,char *);       //Fetch string
                        puts(s); 
                        break; 

            case 'x': i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
                        puts(convert(i,16));
                        break; 
        }   
    } 

    //Module 3: Closing argument list to necessary clean-up
    va_end(arg); 

    std::cout << "\033[0m" << std::endl;
    *m_logFile << getTime() << "[WARN] " << format_s << std::endl;
}

void Logger::excp(std::string format_s, ...)
{
    std::cout << getTime() << "\033[0;31m[EXCEPTION] ";

    char* format = const_cast<char*>(format_s.c_str());

    char *traverse; 
    unsigned int i; 
    char *s; 

    //Module 1: Initializing Myprintf's arguments 
    va_list arg; 
    va_start(arg, format_s); 

    for(traverse = format; *traverse != '\0'; traverse++) 
    { 
        while( *traverse != '%' ) 
        { 
            putchar(*traverse);
            traverse++; 
        } 

        traverse++; 

        //Module 2: Fetching and executing arguments
        switch(*traverse) 
        { 
            case 'c' : i = va_arg(arg,int);     //Fetch char argument
                        putchar(i);
                        break; 

            case 'd' : i = va_arg(arg,int);         //Fetch Decimal/Integer argument
                        if(i<0) 
                        { 
                            i = -i;
                            putchar('-'); 
                        } 
                        puts(convert(i,10));
                        break; 

            case 'o': i = va_arg(arg,unsigned int); //Fetch Octal representation
                        puts(convert(i,8));
                        break; 

            case 's': s = va_arg(arg,char *);       //Fetch string
                        puts(s); 
                        break; 

            case 'x': i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
                        puts(convert(i,16));
                        break; 
        }   
    } 

    //Module 3: Closing argument list to necessary clean-up
    va_end(arg); 
    
    std::cout << "\033[0m" << std::endl;
    *m_logFile << getTime() << "[EXCEPTION] " << format_s << std::endl;
}

void Logger::excp(std::exception e)
{
    std::cout << getTime() << "\033[0;31m[EXCEPTION] " << e.what() << "\033[0m" << std::endl;
    *m_logFile << getTime() << "[EXCEPTION] " << e.what() << std::endl;
}

void Logger::success(std::string format_s, ...)
{
    std::cout << getTime() << "\033[0;32m[SUCCESS] ";

    char* format = const_cast<char*>(format_s.c_str());

    char *traverse; 
    unsigned int i; 
    char *s; 

    //Module 1: Initializing Myprintf's arguments 
    va_list arg; 
    va_start(arg, format_s); 

    for(traverse = format; *traverse != '\0'; traverse++) 
    { 
        while( *traverse != '%' ) 
        { 
            putchar(*traverse);
            traverse++; 
        } 

        traverse++; 

        //Module 2: Fetching and executing arguments
        switch(*traverse) 
        { 
            case 'c' : i = va_arg(arg,int);     //Fetch char argument
                        putchar(i);
                        break; 

            case 'd' : i = va_arg(arg,int);         //Fetch Decimal/Integer argument
                        if(i<0) 
                        { 
                            i = -i;
                            putchar('-'); 
                        } 
                        puts(convert(i,10));
                        break; 

            case 'o': i = va_arg(arg,unsigned int); //Fetch Octal representation
                        puts(convert(i,8));
                        break; 

            case 's': s = va_arg(arg,char *);       //Fetch string
                        puts(s); 
                        break; 

            case 'x': i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
                        puts(convert(i,16));
                        break; 
        }   
    } 

    //Module 3: Closing argument list to necessary clean-up
    va_end(arg); 
    
    std::cout << "\033[0m" << std::endl;
    *m_logFile << getTime() << "[SUCCESS] " << format_s << std::endl;
}

void Logger::debug(std::string format_s, ...)
{
    std::cout << getTime() << "\033[0;36m[DEBUG] ";

    char* format = const_cast<char*>(format_s.c_str());

    char *traverse; 
    unsigned int i; 
    char *s; 

    //Module 1: Initializing Myprintf's arguments 
    va_list arg; 
    va_start(arg, format_s); 

    for(traverse = format; *traverse != '\0'; traverse++) 
    { 
        while( *traverse != '%' ) 
        { 
            putchar(*traverse);
            traverse++; 
        } 

        traverse++; 

        //Module 2: Fetching and executing arguments
        switch(*traverse) 
        { 
            case 'c' : i = va_arg(arg,int);     //Fetch char argument
                        putchar(i);
                        break; 

            case 'd' : i = va_arg(arg,int);         //Fetch Decimal/Integer argument
                        if(i<0) 
                        { 
                            i = -i;
                            putchar('-'); 
                        } 
                        puts(convert(i,10));
                        break; 

            case 'o': i = va_arg(arg,unsigned int); //Fetch Octal representation
                        puts(convert(i,8));
                        break; 

            case 's': s = va_arg(arg,char *);       //Fetch string
                        puts(s); 
                        break; 

            case 'x': i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
                        puts(convert(i,16));
                        break; 
        }   
    } 

    //Module 3: Closing argument list to necessary clean-up
    va_end(arg); 
    
    std::cout << "\033[0m" << std::endl;
    *m_logFile << getTime() << "[DEBUG] " << format_s << std::endl;
}

void Logger::error(std::string format_s, ...)
{
    std::cout << getTime() << "\033[1;31m[ERROR] ";
    
    char* format = const_cast<char*>(format_s.c_str());

    char *traverse; 
    unsigned int i; 
    char *s; 

    //Module 1: Initializing Myprintf's arguments 
    va_list arg; 
    va_start(arg, format_s); 

    for(traverse = format; *traverse != '\0'; traverse++) 
    { 
        while( *traverse != '%' ) 
        { 
            putchar(*traverse);
            traverse++; 
        } 

        traverse++; 

        //Module 2: Fetching and executing arguments
        switch(*traverse) 
        { 
            case 'c' : i = va_arg(arg,int);     //Fetch char argument
                        putchar(i);
                        break; 

            case 'd' : i = va_arg(arg,int);         //Fetch Decimal/Integer argument
                        if(i<0) 
                        { 
                            i = -i;
                            putchar('-'); 
                        } 
                        puts(convert(i,10));
                        break; 

            case 'o': i = va_arg(arg,unsigned int); //Fetch Octal representation
                        puts(convert(i,8));
                        break; 

            case 's': s = va_arg(arg,char *);       //Fetch string
                        puts(s); 
                        break; 

            case 'x': i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
                        puts(convert(i,16));
                        break; 
        }   
    } 

    //Module 3: Closing argument list to necessary clean-up
    va_end(arg); 
    
    std::cout << "\033[0m" << std::endl;
    *m_logFile << getTime() << "[ERROR] " << format_s << std::endl;
}

void Logger::fatal(std::string format_s, ...)
{
    std::cout << getTime() << "\033[101;31m[FATAL]\033[0m \033[1;31m";

    char* format = const_cast<char*>(format_s.c_str());

    char *traverse; 
    unsigned int i; 
    char *s; 

    //Module 1: Initializing Myprintf's arguments 
    va_list arg; 
    va_start(arg, format_s); 

    for(traverse = format; *traverse != '\0'; traverse++) 
    { 
        while( *traverse != '%' ) 
        { 
            putchar(*traverse);
            traverse++; 
        } 

        traverse++; 

        //Module 2: Fetching and executing arguments
        switch(*traverse) 
        { 
            case 'c' : i = va_arg(arg,int);     //Fetch char argument
                        putchar(i);
                        break; 

            case 'd' : i = va_arg(arg,int);         //Fetch Decimal/Integer argument
                        if(i<0) 
                        { 
                            i = -i;
                            putchar('-'); 
                        } 
                        puts(convert(i,10));
                        break; 

            case 'o': i = va_arg(arg,unsigned int); //Fetch Octal representation
                        puts(convert(i,8));
                        break; 

            case 's': s = va_arg(arg,char *);       //Fetch string
                        puts(s); 
                        break; 

            case 'x': i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
                        puts(convert(i,16));
                        break; 
        }   
    } 

    //Module 3: Closing argument list to necessary clean-up
    va_end(arg); 
    
    std::cout << "\033[0m" << std::endl;
    *m_logFile << getTime() << "[FATAL] " << format_s << std::endl;
}

char *Logger::convert(unsigned int num, int base) 
{ 
    static char Representation[]= "0123456789ABCDEF";
    static char buffer[50]; 
    char *ptr; 

    ptr = &buffer[49]; 
    *ptr = '\0'; 

    do 
    { 
        *--ptr = Representation[num%base]; 
        num /= base; 
    }while(num != 0); 

    return(ptr); 
}

} // namespace Larsouille