#include "marketing.h"


marketing::marketing (string m_name) : department ( m_name , "Thuesday" )
    {
        //cout<< "\n\n\tmarketing: "<<d_Name<<"\n\tmeeting: " <<meeting;
    }


void marketing::reports()
    {
        cout<< "\n\n\tThe meeting is on Tuesday" ;
    }
