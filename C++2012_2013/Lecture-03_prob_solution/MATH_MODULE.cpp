            /*      Exercise, Lecture-03
                        MATH MODULE
                    ISLAM,MOHAMMAD MUINUL
                  MATRICULATION NO:-2581908
            INFORMATION AND AUTOMATION ENGINEERING
                    UNIVERSITY OF BREMEN
                     CREATED: 9.11.2012

                       PROPOSED TASK
            A simple math-module
            Create a module, which holds a function for dividing two double
            values and giving the result as return-value:
            -> Write a specification for each function
            -> Use assert() to avoid division by 0
            -> Write a main() function to test your function/module, also for divisor = 0
            -> Test the behavior of your application without and with the #define NDEBUG statement
            (hint: insert #define NDEBUG (just) before the #include <cassert>-statement)
            -> overload the function for usage with float and integer values
            */

            #include <iostream>
            #include <limits>
            #include <cmath>
            #include <cassert>
            #include <module1.h>
            #include <time.h>


            using namespace std;

            void menu();
            int iInput();
            float fInput();
            char cInput();



            int main()
                {
                    cout<<"\n\t\t*********************************\n";
                    cout<<"\n\t\t        MATH MODULE\n";
                    cout<<"\n\t\t*********************************\n\n";
                    menu();
                    cout<<"\n\n";
                    return 0;
                }




            void menu()
                {
                    int iDd,iDr;
                    float fDd,fDr;
                    char cKey;
                    do
                        {
                        cout<<"\ngive the value of Dividend and Divisor\n";
                        cout<<"\nif you want to give Natural number press <N> or <n>.";
                        cout<<"\nif you want to give Natural number press <R> or <r>.";
                        cout<<"\npress <t> or <T> to terminate\n";
                        cout<<"\npress: ";
                        cKey=cInput();

                        if(cKey== 'N' || cKey== 'n')
                                {
                                    cout<<"\ngive the value of Dividend: ";
                                    iDd=iInput();
                                    cout<<"\ngive the value of Divisor: ";
                                    iDr=iInput();
                                    cout<<"\nQuotient: "<<division_operation(iDd,iDr);
                                    cout<<"\n";

                               }
                            else if(cKey== 'R' || cKey== 'r')
                                {
                                    cout<<"\ngive the value of Dividend: ";
                                    fDd=fInput();
                                    cout<<"\ngive the value of Divisor: ";
                                    fDr=fInput();
                                    cout<<"\nQuotient: "<<division_operation(fDd,fDr);
                                    cout<<"\n";
                                }
                            else{}
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        }
                    while(cKey!='t' && cKey!='T');
                }




            int iInput()
                {
                    int iNumber;
                    while(!(cin >> iNumber))
                        {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        }
                    cout<<"\nentered: "<<iNumber<<"\n";
                    return (iNumber);
                }




            float fInput()
                {
                    float fNumber;
                    while(!(cin >> fNumber))
                        {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        }
                    cout<<"\nentered: "<<fNumber<<"\n";
                    return (fNumber);

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
