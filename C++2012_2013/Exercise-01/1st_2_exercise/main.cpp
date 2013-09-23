/*      Exercise-1, Number-02
      QUADRATIC EQUATION SOLVER
        ISLAM,MOHAMMAD MUINUL
      MATRICULATION NO:-2581908
INFORMATION AND AUTOMATION ENGINEERING
         UNIVERSITY OF BREMEN
         CREATED: 10.11.2012

            PROPOSED TASK
Create a program for the calculation of a quadratic equation (e.g. using the quadratic formula).
The  program has the following functionalities:
    (a) When a user presses the key <r> or <R>, the program will print out
        "Please input the coefficients".
    The coefficients of the quadratic polynomial should be read.

    (b) When a user presses the key <c> or <C>, the program will print out
        "Quadratic equation will be calculated, the results are: "
    and the results will be given. The real as well as the complex solution should be offered (see Note).

    (c) When a user push the button <w> or <W>, the program will print out
        "The program is waiting".
    Within the wait state the program has to execute a loop that terminates after a counter reaches a
    predetermined limit. This limit has to be set by the user. Please check the plausibility of the input
    (only non-negative limit is allowed) and print an error message if necessary.

    (d) When a user push the button <t> or <T>, the program will print out
        "The program will be terminated".
    Then the program terminates.

Notes:
     Note: Use the data-type complex
*/

#include <iostream>
#include <complex>
#include <cmath>
#include <limits>
#include <sstream>
#include <stdlib.h>

using namespace std;

complex<long double> fX1,fX2,lDisc1,lDisc2;
float fX3_1,fX4_1,fX3_2,fX4_2;
long double lDisc;

void menu();
void date();
void insert_data();
void show_entry();
void Wait();
int iInput();
char cInput();



void date()
    {
        char buff[100];
        time_t now = time (0);
        strftime (buff, 100, "%Y-%m-%d %H:%M:%S.000", localtime (&now));
        cout<<"  "<<buff<<"\n";
    }




void menu()
    {
        cout<<"\n\t\t*********************************\n";
        cout<<"\n\t\t   QUADRATIC EQUATION SOLVER\n";
        cout<<"\t\t  ";date();
        cout<<"\n\t\t*********************************\n\n";


        char cInput1;
        do
            {

                cout<<"\n\nMAIN MENU:\npress the key <r> or <R> to give the coeficients of the quadratic polynomial.\n";
                cout<<"press the key <c> or <C> to see the result.\n";
                cout<<"press the key <w> or <W> to go to the waiting state.\n";
                cout<<"press the key <t> or <T> to terminate the program.\n";

                cout<<"press the key: ";
                cInput1=cInput();
                if(cInput1 =='r' || cInput1 =='R')
                    {
                        cout<<"\n\nyou wanted to give the input coeficients of the quadratic polynomial.\n";
                        insert_data();

                    }

                else if (cInput1 =='c' || cInput1 =='C')
                    {
                        cout<<"\n\nyou wanted to see the result.\n";
                        show_entry();
                    }
                else if (cInput1 =='w' || cInput1 =='W')
                    {
                        cout<<"\n\nyou wanted to wait for certain period of time.\n";
                        Wait();
                    }
                else
                    {
                        if(cInput1=='t' || cInput1=='T');
                        else
                        cout<<"\nplease give correct character......\n";
                    };

            }
        while(cInput1 !='t' && cInput1 !='T');
        cout<<"\n";
    }




int main()
    {
        menu();
        return 0;
    }



//The coefficients of the quadratic polynomial should be read.

void insert_data()
    {

            int iA,iB,iC;
            cout << "Ideal Polynomial Equation is: ax^2 + bx + c = 0\n";
            cout << "Enter values, a,b and c: \n";
            cout << " \na : ";
            iA=iInput();
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << " \nb : ";
            iB=iInput();
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << " \nc : ";
            iC=iInput();

            lDisc = ((iB*iB) -4*iA*iC);

            if (lDisc > 0)
               {
                   fX3_1 = (-iB +sqrt((iB*iB) -4*iA*iC))/2*iA;
                   fX4_1 = (-iB -sqrt((iB*iB) -4*iA*iC))/2*iA;
               }

            else if (lDisc ==0)
                {
                     fX3_2=fX4_2 =(-iB)/(2*iA);
                }

            else
                {
                    lDisc1=lDisc;
                    lDisc2=sqrt(lDisc1);
                    fX1 = (-static_cast<long double> (iB) + lDisc2)/(2*static_cast<long double> (iA));
                    fX2 = (-static_cast<long double> (iB) - lDisc2)/(2*static_cast<long double> (iA));
                }

    }



//the program will print out and the results will be given. The real as well as the complex solution should be offered

void show_entry()
    {
        if (lDisc > 0)
            {
                cout << "The discriminant is: " << lDisc <<"\n";
                cout<<"1st root is: "<<fX3_1<<"\n2nd root is: "<<fX4_1<<"\n";
            }

        else if(lDisc==0)
            {
                cout << "The discriminant is: " << lDisc << "\n";
                cout<<"1st root is: "<<fX3_2<<"\n2nd root is: "<<fX4_2<<"\n";
            }

        else
            {
                cout << "The discriminant is: " << lDisc <<"\n\n";
                cout << "First root:\nreal part: " << fX1.real() <<"\nimaginary part: "<< fX1.imag()<<" i\n\n";
                cout << "Second root:\nreal part: " << fX2.real() <<"\nimaginary part: "<< fX2.imag()<<" i"<<"\n";
            }
    }



/*Within the wait state the program has to execute a loop that terminates after a counter reaches a
predetermined limit. This limit has to be set by the user.*/

void Wait()
    {
        int iWait,iMax=10000;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout<<"\nGive a value to wait: ";
        iWait=iInput();
        if (iWait<iMax)
            {
                cout<<"\nWaiting..........\n";
                for(int iLoop=0;iLoop<=iWait;iLoop++);
            }
        else cout<<"\n\nyou can not wait that much long time.\n";
    }




int iInput()
    {
        int iNumber;
        while(!(cin >> iNumber))
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout<<"\nplease give correct value: ";
            }
        cout<<"\nentered: "<<iNumber<<"\n";
        return (iNumber);
    }




char cInput()
    {
        char cChar;
        while(!(cin >> cChar))
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            }
        cout<<"\nentered: "<<cChar<<"\n";
        return (cChar);

    }
















