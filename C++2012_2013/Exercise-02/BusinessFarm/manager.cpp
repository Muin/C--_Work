#include "manager.h"


manager::manager (string M_Name) : employee ( M_Name , 10000 )
    {
        //cout<< "\n\n\tmanager: "<<name<<"\n\tsalary: "<<salary;
    }


void manager::reports()
    {
        cout<< "\n\n\tManager is reporting to the CEO";
    }

