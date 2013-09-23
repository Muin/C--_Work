#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

using namespace std;

class employee
    {

        public:
            employee();
            employee ( string e_name , unsigned int e_salary );
            void works();
            void reports();

        protected:
            string name;
            unsigned int salary;

    };

#endif // EMPLOYEE_H
