#ifndef LOGGER_H
#define LOGGER_H
#include <string>

class logger
{
protected:
   static logger m_logger;

public:
   static logger& getlogger();
   void log(std::string s);

    ~logger();

private:
    logger();
};

#endif // LOGGER_H
