#include "logger.h"

int main ()
{
    logger &l = logger::getlogger();
    l.log("first");

    logger &m = logger::getlogger();
    m.log("second");

    logger::getlogger().log("third");

    return 0;
}
