#ifndef CAR_H
#define CAR_H


#include <landvehicle.h>
#include <seat.h>
#include <tire.h>


class Car : public LandVehicle
    {
        public:
            Car();
            ~Car();

        private:
        Seat Car_Seat [4];
        Tire Car_Tire [4];
    };


#endif // CAR_H
