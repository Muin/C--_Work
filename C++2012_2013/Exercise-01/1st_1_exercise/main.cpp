/*      Exercise-1, Number-01
       MISCELLANEOUS OPERATION
        ISLAM,MOHAMMAD MUINUL
      MATRICULATION NO:-2581908
INFORMATION AND AUTOMATION ENGINEERING
         UNIVERSITY OF BREMEN
         CREATED: 10.11.2012

            PROPOSED TASK
Create a program that reads in two natural numbers and performs the following operations:
    (a) Printing of the corresponding characters from the ASCII-table to the screen (see Note1).
    (b) Multiply the numbers with the fixed number 2 in two different ways (see Note2).
    (c) Perform the following division operations: Division, Modulo-Division and Division with real numbers
    (Typecasting from natural into real number. Don't use C-style typecasting).
Interpret your results and print out all relevant steps.
Notes:
     Note1: Don't forget to check if the user input is in a valid range, for which the characters can be
printed out (e.g. 32...127).
     Note2: Use * and <<!
*/

#include <iostream>
#include <limits>
#include <cmath>
#include <cassert>


using namespace std;

int iInput1,iInput2;

void menu();
void date();
void Ascii_conversion();
void Multiplication_operation();
void Division_operation();
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
        cout<<"\n\t\t*****************************\n";
        cout<<"\n\t\t   MISCELLANEOUS OPERATION\n";
        cout<<"\t\t ";date();
        cout<<"\n\t\t*****************************\n\n";
        cout<<"\nGive two Natural Number.\n\n";
        cout<<"ist number: ";
        iInput1=iInput();
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout<<"\n2nd number: ";
        iInput2=iInput();

        char cInput1;
        do
            {

                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout<<"\n\nMAIN MENU:\npress the key <e> or <E> to go to the ASCII code conversion operation.\n";
                cout<<"press the key <m> or <M> to see two types of multiplication operation where";
                cout<<" numbers multiplied with the fixed number 2.\n";
                cout<<"press the key <d> or <D> to see the division operation.\n";
                cout<<"press the key <t> or <T> to terminate the program.\n";

                cout<<"press the key: ";
                cInput1=cInput();
                if(cInput1 =='e' || cInput1 =='E')
                    {
                        cout<<"\n\nyou wanted to try ASCII code conversion operation.\n";
                        Ascii_conversion();
                    }

                else if (cInput1 =='m' || cInput1 =='M')
                    {
                        cout<<"\n\nyou wanted to see multiplication operation.\n";
                        Multiplication_operation();
                    }
                else if (cInput1 =='d' || cInput1 =='D')
                    {
                        cout<<"\n\nyou wanted to see division operation.\n";
                        Division_operation();
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



//Printing of the corresponding characters from the ASCII-table to the screen
void Ascii_conversion()
    {
        if(31<iInput1 && iInput1<128)
            {
                cout<<"\n\ncorresponding ASCII character is: ";
                cout<<(unsigned char)iInput1;
            }
        else cout<<"\nFor your input1 there are no ASCII character.";


        if(31<iInput2 && iInput2<128)
            {
                cout<<"\n\ncorresponding ASCII character is: ";
                cout<<(unsigned char)iInput2;
            }
        else cout<<"\nFor your input2 there are no ASCII character.";
    }



//Multiply the numbers with the fixed number 2 in two different ways
void Multiplication_operation()
    {
    char cPress;
    do
        {
        cout<<"\npress <A> or <a> to see the multiplication in 1st method.\n";
        cout<<"press <b> or <B> to see the multiplication in second method.";
        cout<<"\npress <c> or <C> to return to the MAIN MENU.";

        cout<<"\npress: ";
        cPress=cInput();
        if(cPress=='a' || cPress=='A')
            {
                cout<<"\nFormula: number*2= output value.\n";
                int iOutput1,iOutput2;
                iOutput1=iInput1*2;
                iOutput2=iInput2*2;
                cout<<"\n1st output is: "<<iOutput1<<"\n";
                cout<<"\n2nd output is: "<<iOutput2<<"\n";
            }
        else if(cPress=='b' || cPress=='B')
            {
                cout<<"\nFormula: number<<1 = number*2 = output value.\n";
                int iOutput1,iOutput2;
                iOutput1=iInput1<<1;
                iOutput2=iInput2<<1;
                cout<<"\n1st output is: "<<iOutput1<<"\n";
                cout<<"\n2nd output is: "<<iOutput2<<"\n";
            }
        else
        {
            if(cPress=='c' || cPress=='C');
            else
            cout<<"\nplease give correct character......\n";
        }

    }
        while(cPress!='c' && cPress!='C');

    }



//Perform the following division operations: Division, Modulo-Division and Division with real numbers
void Division_operation()
    {
        cout<<"\nFormula: output value=1st number/2nd number.";
        int iOutput;
        long double iOutput2;
        assert(iInput2!=0);
        iOutput=iInput1/iInput2;
        cout<<"\n\nQuotient: "<<iOutput;

        iOutput=iInput1%iInput2;
        cout<<"\nRemainder: "<<iOutput;

        cout<<"\n\nDivision with real numbers.\n";
        iOutput2=(static_cast<long double>(iInput1))/(static_cast<long double>(iInput2));
        cout<<"\nQuotient: "<<iOutput2;
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
























