#include "employee.h"


employee::employee()
{}


employee::employee (string e_name , unsigned int e_salary )
    {
        name = e_name ;
        salary = e_salary ;      
    }


void employee::works()
{
    cout<<"\n\n\tName of the Employee: "<< name ;
    cout<<"\n\tSalaray of the Employee: "<< salary ;
}


void employee::reports()
{}
