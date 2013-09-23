#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include <iostream>

using namespace std;

class department
    {

        public:
            department( string d_name , string d_meeting );
            void reports();

        protected:
            string d_Name;
            string meeting;

    };

#endif // DEPARTMENT_H
