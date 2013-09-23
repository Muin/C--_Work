/*      Lecture-05 , Exercise-01
           CLASS EXERCISE
            (2nd method)
        ISLAM,MOHAMMAD MUINUL
      MATRICULATION NO:-2581908
INFORMATION AND AUTOMATION ENGINEERING
         UNIVERSITY OF BREMEN
         CREATED: 23.11.2012

            PROPOSED TASK
Create a class Cuboid that offers the following functionalities
    A general constructor to set these height, width and depth
    with the creation of an object.
    A copy constructor to initialize an object with another
    object of the same class.
    Instantiate an object of that class with the help of a test
    program. Use the general constructor.
    Instantiate another object of that class by using the copy
    constructor.
    Get the parameters of the second object and print them on
    the screen.

*/

#include <iostream>
#include <limits>
#include <cuboid_2.h>


using namespace std;


int iInput();




int main()
    {
        int x, y, z;
        cout<<"\nEnter the value Length, Width and Height.\nLength: ";
        x=iInput();
        cout<<"\nWidth: ";
        y=iInput();
        cout<<"\nHeight: ";
        z=iInput();
        cuboid_2 my_cuboid(x , y , z);
        cuboid_2 my_cuboid1 = my_cuboid;
        my_cuboid1.GetDimensions();
        my_cuboid1.CalculateSurface();
        my_cuboid1.CalculateVolume();
        cout<<"\nThe Surface of the Cuboid is: "<<my_cuboid1.GetSurface();
        cout<<"\nThe Volume of the Cuboid is: "<<my_cuboid1.GetVolume()<<"\n";
        return 0;
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
