#ifndef MARKETING_H
#define MARKETING_H

#include <department.h>
#include <string>
#include <iostream>


using namespace std;


class marketing : public department
    {
        public:
            marketing( string m_name );
            void reports();
    };

#endif // MARKETING_H
