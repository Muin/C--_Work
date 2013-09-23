#ifndef MANAGER_H
#define MANAGER_H

#include <employee.h>
#include <string>
#include <iostream>
using namespace std;

class manager : public employee
    {
        public:
            manager( string M_Name );
            void reports();
    };

#endif // MANAGER_H
