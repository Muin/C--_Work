/*      Exercise-02, Number-03
           BUISENESS FIRM
        ISLAM,MOHAMMAD MUINUL
      MATRICULATION NO:-2581908
INFORMATION AND AUTOMATION ENGINEERING
        UNIVERSITY OF BREMEN
        CREATED: 03.12.2012

            PROPOSED TASK
Define a class employee with the features name and salary which could not be accessed from outside
the class. Create a constructor, by which those features can be initialized during the object definition.
The class should have two methods: works which has no return value, no arguments to be passed and
prints name and salary on the screen. The second method is reports and does not have a return value
and arguments to be passed, too. The second method is empty.

Define a class manager and derive it from the class employee. Define a constructor by which a name
can be assigned during the object definition. The salary for every manger is 10.000 EUR per month.
This should also be set during initialization. The manager class should also have a reports method which
prints a message on the screen that the manager reports to the CEO.

Define a class department which has the features department name and meeting and a reports method
without parameters to be passed or returned. In the feature meeting a weekday should be stored later.

Define a class marketing and derive it from the class department. Marketing departments always meet
on Tuesdays and reports to the executive department.

Define a class chief of marketing which is derived from the classes manager and marketing. Create also
a special constructor to give a name during object definition. Create an object of type chief of marketing
and call for it in the main function the reports method to print on the screen to whom the marketing
department reports.

*/


#include <iostream>
#include <chief_of_marketing.h>


using namespace std;


int main()
    {

        chief_of_marketing C_O_M ("Chief");
        C_O_M.employee::works();
        C_O_M.manager::reports();
        C_O_M.department::reports();
        C_O_M.marketing::reports();
        cout<<"\n\n";
        return 0;

    }
