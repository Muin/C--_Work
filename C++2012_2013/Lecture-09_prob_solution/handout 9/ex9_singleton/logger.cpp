#include "logger.h"
#include <iostream>

    logger logger::m_logger;

    logger& logger::getlogger()
    {
        return m_logger;
    }

    void logger::log(std::string s)
    {
        std::cout << "Logger address: " << this << " Message: " << s << std::endl;
    }

    logger::~logger()
    {}

    logger::logger()
    {}
