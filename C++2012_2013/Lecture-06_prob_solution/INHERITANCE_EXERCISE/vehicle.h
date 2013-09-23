#ifndef VEHICLE_H
#define VEHICLE_H


#include <vector>
using namespace std;


class Vehicle
    {
        public:
            Vehicle();
            ~Vehicle();
            int Enter_parking_lot(int A);
            int Leave_parking_lot(int A);

            static int m_iNumber;

        protected:

            int Number;
            Vehicle *Number_of_Vehicle_enter;
            Vehicle *Number_of_Vehicle_Left;

    };


#endif // VEHICLE_H
