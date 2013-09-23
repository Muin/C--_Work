/*          Lecture - 06
        INHERITANCE EXERCISE
        ISLAM,MOHAMMAD MUINUL
      MATRICULATION NO:-2581908
INFORMATION AND AUTOMATION ENGINEERING
        UNIVERSITY OF BREMEN
        CREATED: 01.12.2012

            PROPOSED TASK
1st Part:

    Implement a class LandVehicle that is derived from the class "Vehicle".

    Implement a class Car that is derived from LandVehicle.

    In the standard constructor of each class, print a message naming the class that is called.

    Test the behavior of inheritance in a small test program.

    Draw a UML class diagram (on paper), which illustrates the
    relationship between the classes Vehicle, LandVehicle and
    Car.

2Nd Part:
    Enhance your class Vehicle so that the number of generated objects can be shown.

    Implement in your test program a small ’parking lot’ that
    counts the number of vehicles. In a menu, make sure that
    vehicles can enter and leave the parking lot (use array of
    pointers) and the actual number of vehicles is shown.

    Implement the classes which correspond to the following
    UML class diagram:

*/


#include <iostream>
#include <time.h>
#include <limits>
#include <vehicle.h>
#include <landvehicle.h>
#include <car.h>


using namespace std;


void date();
int iInput();
void Choice();


void date()
    {
        char buff[100];
        time_t now = time (0);
        strftime (buff, 100, "%Y-%m-%d %H:%M:%S.000", localtime (&now));
        cout<<"  "<<buff<<"\n";
    }


int main()
    {
        Choice();
        return 0;
    }


void Choice()
    {

        int iSelect1 ;
        Car MyCar ;
        int Loop_count = 0;
        int *Number_of_Car_enter = new int [100];
        int *Number_of_Car_Left  = new int [100];
        int car_left = 0 ;
        int car_enter = 0 ;

        do
            {

                cout << "\t------------------------------\n";
                cout << "\t      CAR PARKING LOT\n";
                cout<<  "\t";date();
                cout << "\t------------------------------\n";
                cout << "\n\tMAIN MENU\n\n";
                cout << "\tindex\tchoice\n";
                cout << "\t1  \tCar Entering\n";
                cout << "\t2  \tCar Leaving\n";
                cout << "\t3  \tTotal Car\n";
                cout << "\t4  \tTerminate the program\n";

                enum Coffee_Machine { Car_Entry = 1 , Car_Leaving , Total_Car };

                cin.clear();
                cout << "\n\tmake a choice by giving index number: ";
                iSelect1=iInput();
                switch (iSelect1)
                    {
                        case Car_Entry :
                            {
                                cout << "\n\tyou wanted to entry the number of car entered.\n\tentry: ";
                                int itemp = iInput();                               
                                Number_of_Car_enter[ Loop_count ] = MyCar.Vehicle::Enter_parking_lot(itemp);
                                int car_enter_Temp = 0 ;
                                for( int b=0 ; b <= Loop_count ; b++ )
                                    {
                                        car_enter_Temp +=Number_of_Car_enter[b] ;

                                    }
                                car_enter = car_enter_Temp ;
                                cout<<"\n\tTotal Car entered in the parking lot: "<<car_enter<<"\n\n";
                            }
                                break;

                        case Car_Leaving :
                            {
                                cout << "\n\tyou wanted to entry the number of car left.\n\tentry: ";
                                int itemp = iInput();
                                Number_of_Car_Left[ Loop_count ] = MyCar.Vehicle::Leave_parking_lot(itemp);
                                int car_left_Temp = 0 ;
                                for(int b=0 ; b<= Loop_count ;b++)
                                    {
                                        car_left_Temp +=Number_of_Car_Left[b] ;

                                    }
                                car_left = car_left_Temp ;
                                cout<<"\n\tTotal Car left from the parking lot: "<<car_left<<"\n\n";
                            }
                                 break;

                        case Total_Car :
                            {
                                cout << "\n\tyou wanted to see total Number of Car in the parking lot.\n\tTotal: ";                             
                                cout<< car_enter - car_left <<"\n\n";
                            }
                                 break;


                        default:
                            {
                                 if(iSelect1==4);
                                 else
                                 cout<<"\n\tplease give correct number......\n\n";
                            }

                    }

           Loop_count++ ;

        }

        while(iSelect1!=4);
        delete [] Number_of_Car_enter;
        delete [] Number_of_Car_Left;
        cout<<"\n";

    }


int iInput()
    {
        unsigned int iNumber;
        while(!(cin >> iNumber))
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout<<"\n\tplease give correct value: ";
            }
        cout<<"\n\tentered: "<<iNumber<<"\n";
        return (iNumber);
    }

