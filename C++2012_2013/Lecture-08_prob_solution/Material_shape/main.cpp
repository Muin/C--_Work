/*      Lecture -08, Number-01
            POLYMORPHISM
        ISLAM,MOHAMMAD MUINUL
      MATRICULATION NO:-2581908
INFORMATION AND AUTOMATION ENGINEERING
        UNIVERSITY OF BREMEN
        CREATED: 14.12.2012

            PROPOSED TASK
Create a class hierarchy with a base class for 2-dimensional
shapes: rectangle, triangle and circle:
    The base class should be an interface (abstract class).
    Create a class for each shape.
    Each class for a shape should have a Draw() method, which outputs „Drawing <shape type>“.
    Store different objects of shapes in one std::vector and
    test the Draw() method within a main() function.

*/

#include <iostream>
#include <shape.h>
#include <rectangle.h>
#include <triangle.h>
#include <circle.h>
#include <vector>

using namespace std;

int main()
    {
        std::vector<shape*> shape_2_D;

        shape_2_D.push_back(new rectangle);
        shape_2_D.push_back(new triangle);
        shape_2_D.push_back(new circle);

        shape_2_D[0]->Draw();
        shape_2_D[1]->Draw();
        shape_2_D[2]->Draw();

        std::cout<<"\n\n";
        return 0;
    }
