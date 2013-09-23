#include "vehicle.h"
#include <iostream>


using namespace std;

int Vehicle::m_iNumber = 0 ;


Vehicle::Vehicle()
    {

        //cout<< "\n\nThe Vehicle Class has been Called\n\n";
        m_iNumber++;
        Number=0;

    }


int Vehicle::Enter_parking_lot( int A )
    {

        Number = A - 1 ;
        Number_of_Vehicle_enter = new Vehicle [Number];
        cout << "\n\tNumber of Car Entered = " << m_iNumber << "\n\n";
        int iTemp = m_iNumber ;
        delete[] Number_of_Vehicle_enter ;
        return (iTemp);

    }



int Vehicle::Leave_parking_lot(int A)
    {

        Number = A - 1 ;
        Number_of_Vehicle_Left = new Vehicle [Number];
        cout << "\n\tNumber of Car Left = " << m_iNumber << "\n\n";
        int iTemp = m_iNumber;
        delete[] Number_of_Vehicle_Left ;
        return (iTemp);

    }


Vehicle::~Vehicle()
    {
        m_iNumber--;
    }
