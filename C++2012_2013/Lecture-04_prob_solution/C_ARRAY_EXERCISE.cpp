            /*      Lecture-05 Exercise-01
                      C ARRAY EXERCISE
                    ISLAM,MOHAMMAD MUINUL
                  MATRICULATION NO:-2581908
            INFORMATION AND AUTOMATION ENGINEERING
                     UNIVERSITY OF BREMEN
                     CREATED: 15.11.2012

                        PROPOSED TASK
            Create an application that prompts the user to input 5 numbers.
            Store this numbers into a C-Array.
            Use the type double for the numbers.
            Calculate and print the sum and the mean of the numbers.
            */

            #include <iostream>
            #include <limits>
            #include <time.h>

            using namespace std;

            void date();
            void menu();
            long double fInput();


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
                    cout<<"\n\t\t      C ARRAY EXERCISE\n";
                    cout<<"\t\t ";date();
                    cout<<"\n\t\t*****************************\n\n";
                    cout<<"\nGive five Real Numbers.\n\n";
                    long double lArray[5],lSum=0,lMean;
                    int iIn,iIn1;
                    for (iIn1=1; iIn1<6 ;iIn1++)
                        {
                            cout<<"number "<<iIn1<<": ";
                            iIn=iIn1-1;
                            lArray[iIn]=fInput();
                        }
                    cout<<"stored values are= ";
                    for (iIn1=0; iIn1<5; iIn1++)
                    cout<<lArray[iIn1]<<", ";
                    cout<<"\n";
                    for(iIn1=0;iIn1<5;iIn1++)
                    lSum+=lArray[iIn1];
                    cout<<"\nTotal sum of the value stored in the array= "<<lSum;
                    lMean=lSum/5;
                    cout<<"\n\nMean value= "<<lMean<<"\n\n";

                }




            int main()
                {
                    menu();
                    return 0;
                }




            long double fInput()
                {
                    long double fNumber;
                    while(!(cin >> fNumber))
                        {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                            cout<<"\nplease give correct value: ";
                        }
                    cout<<"entered: "<<fNumber<<"\n\n";
                    return (fNumber);
                }
