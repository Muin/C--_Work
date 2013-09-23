/*      Lecture -07, Number-01
             NAMESPACE
        ISLAM,MOHAMMAD MUINUL
      MATRICULATION NO:-2581908
INFORMATION AND AUTOMATION ENGINEERING
        UNIVERSITY OF BREMEN
        CREATED: 07.12.2012

            PROPOSED TASK
Create the namespaces Numbers and Letters.
Implement in both namespaces the function Display():
    Numbers::Display()
    Letters::Display()
should display „Number was called“
should display „Letter was called“

In the main function call both of the Display() functions.
Try the three usage versions for the two namespaces!

*/

#include <iostream>

using namespace std;

namespace Numbers
    {
        void Display()
            {
                cout<<"\n\n\tNumber was called";
            }
    }

namespace Letters
    {
        void Display()
            {
                cout<<"\n\n\tLetter was called";
            }
    }

int main()
    {
            //1st Method:
        using namespace Numbers;
        Display();
        //using namespace Letters;
        Letters::Display();

            //2nd Method:
        using Numbers::Display;
        Display();
        //using Letters::Display;
        Letters::Display();

            //3rd Method:
        Numbers::Display();
        Letters::Display();

        cout<<"\n\n";
        return 0;
    }
