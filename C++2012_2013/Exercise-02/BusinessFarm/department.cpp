#include "department.h"


department::department( string d_name , string d_meeting )
    {
        d_Name = d_name ;
        meeting = d_meeting ;
        //cout<< "\n\n\tdepartment: "<<d_Name<<"\n\tmeeting: "<<meeting;
    }


void department::reports()
    {
        cout<< "\n\n\tDepartment is reporting to the Marketing dpartment";
    }
