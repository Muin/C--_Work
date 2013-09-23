/*      Lecture-05 , Exercise-01
           CLASS EXERCISE
            (1st method)
        ISLAM,MOHAMMAD MUINUL
      MATRICULATION NO:-2581908
INFORMATION AND AUTOMATION ENGINEERING
        UNIVERSITY OF BREMEN
        CREATED: 22.11.2012

            PROPOSED TASK
Create a class Cuboid that offers the following functionalities
(ﬁrst implement empty methods):
    Set and get the required parameters height, width and
    depth, e.g. SetDimensions(), GetDimensions(), ...
    Calculation of surface area and volume, e.g.
    CalculateVolume(), ...
    Returning of the calculated values, e.g. GetVolume(), ...
    Implement all these methods.
    Add a standard constructor and a destructor.
    Verify the class with the help of a test program.
*/

#include <iostream>
#include <limits>
#include <cuboid.h>

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
        Cuboid my_cuboid;
        my_cuboid.SetDimensions(x , y , z);
        my_cuboid.GetDimensions();
        my_cuboid.CalculateSurface();
        my_cuboid.CalculateVolume();
        cout<<"\nThe Surface of the Cuboid is: "<<my_cuboid.GetSurface();
        cout<<"\nThe Volume of the Cuboid is: "<<my_cuboid.GetVolume()<<"\n";
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
