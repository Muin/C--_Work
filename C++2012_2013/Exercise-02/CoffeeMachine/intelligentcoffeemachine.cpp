#include "intelligentcoffeemachine.h"
#include <iostream>


using namespace std;


IntelligentCoffeeMachine::IntelligentCoffeeMachine()
    {
        water_volume = 0;
        coffee_reservoir = 0;
        lid_opened = false ;
        insert_filter = false ;
        switch_on = false ;
        take_coffee = false ;
        cook = false ;
    }


void IntelligentCoffeeMachine::Open_lid()
    {
    if(!switch_on)
        {
            lid_opened = true ;
            if(lid_opened)
                {
                    cout << "\n\tThe lid is Open Now.\n\n";
                }
            else cout<< "\n\tThe lid is Close Now.\n\n";
        }
    else cout<< "\n\tSwitch the coffee machine Off first.\n\n";
    }


void IntelligentCoffeeMachine::Insert_filter()
    {
        if(!cook)
            {
                if (lid_opened==true)
                    {
                        insert_filter=true;
                        cout << "\n\tThe filter is inserted.\n\n";
                    }
                else cout<<"\n\tCaution! The lid is not opened.\n\tOpen the lid first.\n\n";
            }
        else cout <<"\n\tCaution! Please Take the old filter out first.\n\n";

    }


void IntelligentCoffeeMachine::Insert_coffee( float temp_coffee_reservoir )
    {
        if (lid_opened == true && insert_filter == true)
            {               
                coffee_reservoir = temp_coffee_reservoir ;
                if (coffee_reservoir <= 0 )
                    {
                        cout << "\n\tCaution! Undefined quantity.\n\n ";
                    }
                else if(coffee_reservoir <= 100.00)
                    {
                        cout << "\n\tCoffee Reservoir is loaded.\n\n ";
                    }
                else {cout<<"\n\tCaution! Coffee Reservoir is overloaded.\n\n";}
            }

        else if(lid_opened == true && insert_filter!= true)
            {
                cout<<"\n\tCaution! The filter is not inserted.\n\tinsert the filter first.\n\n";
            }

        else cout<< "\n\tCaution! The lid is not opened.\n\tOpen the lid first.\n\n";
    }


void IntelligentCoffeeMachine::Insert_water( float temp_water_reservoir )
    {
        if (lid_opened == true)
            {
                water_volume = temp_water_reservoir ;

                if (water_volume <= 0 )
                    {
                        cout << "\n\tCaution! Undefined volume.\n\n ";
                    }

                else if(water_volume <= 5.00)
                    {
                        cout << "\n\tWater Reservoir is loaded.\n\n ";
                    }
                else {cout<<"\n\tCaution! Water Reservoir is overloaded.\n\n";}
            }

        else cout<< "\n\tCaution! The lid is not opened.\n\tOpen the lid first.\n\n";
    }


void IntelligentCoffeeMachine::Close_lid()
    {
        lid_opened = false ;
        if(!lid_opened)
            {
                cout << "\n\tThe lid is Close Now.\n\n";
            }
        else cout<< "\n\tThe lid is Open Now.\n\n";

    }


void IntelligentCoffeeMachine::Switch_on()
    {
        if(lid_opened==false)
            {
                switch_on = true ;
                if(switch_on)
                    {
                        cout<<"\n\tCoffee Machine is ON now.\n\n";
                        //lid_opened = true ;
                    }
                else cout<<"\n\tCoffee Machine is OFF now.\n\n";
            }
        else cout<<"\n\tCaution! Please close the lid first.\n\n";

    }


void IntelligentCoffeeMachine::Start_cooking()
    {

        if(switch_on==true)
            {
                if(!cook)
                    {
                        if(water_volume!=0 && coffee_reservoir != 0 )
                            {
                                cout<< "\n\tCooking will start in few minutes.\n\n";
                                for(int a=0; a<1000001; a++)
                                    {
                                        cout<<"\r        Cooking.............."<<a/10000<<"%";
                                    }
                                water_volume = 0;
                                take_coffee = true ;
                                cook = true ;
                                cout<<"\n\n\tCooking finished.\n\n";
                            }
                        else if(water_volume==0)
                            {
                                cout<<"\n\tCaution! No Water in the reservoir.\n\n";
                            }
                        else if (coffee_reservoir==0)
                            {
                                cout<<"\n\tCaution! No coffee in the reservoir.\n\n";
                            }
                    }
            else cout << "\n\tCoffee has been cooked already.\n\n";
            }

        else cout<<"\n\tCaution! Please Switch On the coffee machine first.\n\n";

    }


void IntelligentCoffeeMachine::Switch_off()
    {
        if(!switch_on)
            {
                cout<<"\n\tCoffee Machine is still not ON yet.\n\n";
            }

        else if(switch_on)
            {
                switch_on = false ;
                cout<<"\n\tCoffee Machine is OFF now.\n\n";
            }

    }


void IntelligentCoffeeMachine::Take_coffee()
    {
        if(!switch_on)
            {
                if(take_coffee)
                    {
                        cout<<"\n\tPlease Take the coffee.\n\n";
                        take_coffee = false ;
                    }
                else if(!take_coffee)
                    {
                        cout <<"\n\tCaution! No coffee has been cooked yet\n\n";
                    }
            }
        else if(switch_on)
            {
                cout<<"\n\tCaution! Please Switch Off the Coffee Machine first.\n\n";
            }

    }


void IntelligentCoffeeMachine::Take_Filter_out()
    {
        if (!switch_on)
            {
                if(!take_coffee)
                    {
                        if(lid_opened)
                            {
                                if(cook)
                                    {
                                        cout <<"\n\tThe old filter has been removed.\n\n";
                                        cook = false ;
                                        coffee_reservoir = 0 ;
                                        insert_filter = false;
                                    }
                                else if(!cook)
                                    {
                                        cout <<"\n\tCaution! No Coffee has been cooked yet.\n\n";
                                    }
                            }
                        else cout<<"\n\tCaution! Please open the lid first.\n\n";
                    }
                else cout<<"\n\tPlease Take out the coffee first.\n\n";
            }
        else  cout<<"\n\tCaution! Please Switch Off the Coffee Machine first.\n\n";

    }

IntelligentCoffeeMachine::~IntelligentCoffeeMachine()
{}
















