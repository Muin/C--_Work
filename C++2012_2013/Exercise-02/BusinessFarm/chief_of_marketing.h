#ifndef CHIEF_OF_MARKETING_H
#define CHIEF_OF_MARKETING_H

#include <marketing.h>
#include <manager.h>
#include <string>

using namespace std;

class chief_of_marketing : public manager , public marketing
    {

        public:
            chief_of_marketing( string C_O_M_name);

    };

#endif // CHIEF_OF_MARKETING_H
