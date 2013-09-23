/*      Exercise-02, Number-02
           COFFEE MACHINE
        ISLAM,MOHAMMAD MUINUL
      MATRICULATION NO:-2581908
INFORMATION AND AUTOMATION ENGINEERING
        UNIVERSITY OF BREMEN
        CREATED: 29.11.2012

            PROPOSED TASK

Making coffee seems to be very simple since (almost) everybody knows how to do it. However, to train
thinking in an object-oriented way, a coffee machine class shall be designed that provides some smart
behavior. Probably, after finishing this exercise, we become aware that the coffee cooking procedure is
not as simple as initially assumed.
Create a class IntelligentCoffeeMachine that fulfills the following requirements:

(1) R01 Prerequisites: For simplification we assume that we have a coffee machine with fixed water
and coffee reservoir and the coffee jug is not used for water insertion, but some external jug.

(2) R02 User interaction: The user (coffee drinker) shall be able to interact with the coffee machine
(IntelligentCoffeeMachine class) as follows:

     Open lid
     Insert filter
     Insert coffee
     Insert water
     Close lid
     Start cooking
     Take coffee
     Switch off

(3) R03 Intelligence in general: The "intelligence" of the coffee machine prevents wrong actions. In
general the internal states have to be checked before action execution (E.g. Opening the lid is only
possible in case the lid is not already open). In case of wrong user interaction the user is informed
with a respective text message. See subsequent requirements for special status requirements that
depend on each other.

(4) R04 Intelligent coffee insertion: Coffee can only be inserted in case the lid is open and the filter
is inserted. Respect the maximum content of the coffee reservoir (class related constant).

(5) R05 Intelligent water insertion: Water can only be inserted in case the lid is open. Respect the
maximum content of the water reservoir (class related constant).

(6) R06 Intelligent cooking: Coffee can only be cooked when minimum amount of water and coffee
are in the reservoirs. When the user switches the coffee machine on to start cooking, a power LED
is lighted (boolean attribute of the class).

Since we do not want to have parallel threads here, the coffee cooking is simulated by a timer or a
loop (blocking behavior). Visualization of the cooking progress could be helpful. After finishing of
the cooking procedure the coffee jug is filled and the water reservoir is empty.

(7) R07 Intelligent coffee taking: The user is only allowed to take the coffee when the cooking
procedure is finished. This means the coffee jug is filled and the water reservoir is empty. Before
taking the coffee he must switch off the coffee machine to assure no danger of a coffee machine still
switched on. (We assume that the user does not want to keep the coffee heated - and probably
drinks all the coffee at once, or has some friends/colleagues to share the coffee with ...)

(8) R08 Commenting: Comment all entities of your class using C++ style comments (//).

(9) R09 Intelligent clean up: After the coffee has been cooked, the old filter must be taken out and
a new one inserted before filling in new coffee.

Write a test application with a menu for using the coffee machine.

*/


#include <iostream>
#include <limits>
#include <time.h>
#include <intelligentcoffeemachine.h>


using namespace std;


void Choice(IntelligentCoffeeMachine test);
void date();
int iInput();
float fInput();


void date()
    {
        char buff[100];
        time_t now = time (0);
        strftime (buff, 100, "%Y-%m-%d %H:%M:%S.000", localtime (&now));
        cout<<"  "<<buff<<"\n";
    }


int main()
    {
        IntelligentCoffeeMachine test;
        Choice(test);
        return 0;
    }


void Choice(IntelligentCoffeeMachine test)
    {


        int iSelect1;
        do
            {
                cout << "\t------------------------------\n";
                cout << "\t   XXXXXX COFFEE MACHINE\n";
                cout<<  "\t";date();
                cout << "\t------------------------------\n";
                cout << "\n\tIf you want to drink coffee do the following task first";
                cout << "\n\tOr Terminate the program\n";
                cout << "\n\tMAIN MENU\n\tWork have to be done in sequence...\n\n";
                cout << "\tindex\tchoice\n";
                cout << "\t1  \tOpen lid\n";
                cout << "\t2  \tInsert filter\n";
                cout << "\t3  \tInsert Coffee\n";
                cout << "\t4  \tInsert Water\n";
                cout << "\t5  \tClose lid\n";
                cout << "\t6  \tSwitch ON\n";
                cout << "\t7  \tStart Cooking\n";
                cout << "\t8  \tSwitch OFF\n";
                cout << "\t9  \tTake Coffee\n";
                cout << "\t10  \tTake Filter out\n";
                cout << "\t11  \tTerminate the program\n";

                enum Coffee_Machine { Open_lid = 1 , Insert_filter , Insert_Coffee , Insert_Water , Close_lid , Switch_On , Start_Cooking , Switch_Off , Take_Coffee , Take_Filter_out };

                cin.clear();
                cout << "\n\tmake a choice by giving index number: ";
                iSelect1=iInput();
                switch (iSelect1)
                    {
                        case Open_lid :
                            {
                                cout << "\n\tyou wanted to open the lid.\n";
                                test.Open_lid();
                            }
                                break;

                        case Insert_filter :
                            {
                                cout << "\n\tyou wanted to Insert the filter.\n";
                                test.Insert_filter();
                            }
                                 break;

                        case Insert_Coffee :
                            {
                                cout << "\n\tyou wanted to Insert Coffee.\n";
                                cout << "\n\tInsert coffee.Maximum limit 100 gram.\n";
                                cout << "\n\tGive the coffee to the reservoir: ";
                                float temp_coffee_reservoir = fInput();
                                test.Insert_coffee( temp_coffee_reservoir );
                            }
                                 break;

                        case Insert_Water :
                            {
                                cout << "\n\tyou wanted to Insert Water.\n";
                                cout << "\n\tInsert Water.Maximum limit 5.00 litre.\n";
                                cout << "\n\tGive the coffee to the reservoir: ";
                                float temp_water_reservoir = fInput();
                                test.Insert_water(temp_water_reservoir);

                            }
                                 break;

                        case Close_lid :
                            {
                                cout << "\n\tyou wanted to Close the lid.\n";
                                test.Close_lid();
                            }
                                break;

                        case Switch_On :
                            {
                                cout << "\n\tyou wanted to Switch ON.\n";
                                test.Switch_on();
                            }
                                break;

                        case Start_Cooking :
                            {
                                cout << "\n\tyou wanted to Start Cooking.\n";
                                test.Start_cooking();
                            }
                                break;


                        case Switch_Off :
                            {
                                cout << "\n\tyou wanted to Switch Off.\n";
                                test.Switch_off();
                            }
                                break;

                        case Take_Coffee :
                            {
                                cout << "\n\tyou wanted to Take Coffee.\n";
                                test.Take_coffee();
                            }
                                break;

                        case Take_Filter_out :
                            {
                                cout << "\n\tyou wanted to Take Filter out to make new coffee.\n";
                                test.Take_Filter_out();
                            }
                                break;

                        default:
                            {
                                 if(iSelect1==11);
                                 else
                                 cout<<"\n\tplease give correct number......\n\n";
                            }

                    }

            }
        while(iSelect1!=11);
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


float fInput()
    {
        float fNumber;
        while(!(cin >> fNumber))
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout<<"\n\tplease give correct value: ";
            }
        cout<<"\n\tentered: "<<fNumber<<"\n";
        return (fNumber);
    }














