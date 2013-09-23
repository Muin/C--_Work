/*      Lecture -08, Number-02
           TEMPLATE CLASS
        ISLAM,MOHAMMAD MUINUL
      MATRICULATION NO:-2581908
INFORMATION AND AUTOMATION ENGINEERING
        UNIVERSITY OF BREMEN
        CREATED: 15.12.2012

            PROPOSED TASK
Create a simple stack template class with methods to add,
remove and get elements from the top of the stack.

Create a test application to test your stack template class.

template <class T>
class SimpleStack
    {
        public:
        const T& Top(void) const;   // Method to get top element
        void Pop(void);             // Method to remove top element
        void Push(const T & x);     // Method to add element
        private:
        std::vector<T> m_Array;     // std::vector for stack
    };

*/


#include <iostream>
#include <SimpleStack.h>

using namespace std;

int main()
{
    SimpleStack< unsigned int > SSTack;

    SSTack.Push(1);
    SSTack.Push(2);
    SSTack.Push(3);

    std::cout<<"\n\tThe Top Element of the Stack is: "<<SSTack.Top()<<"\n";

    SSTack.Pop();
    std::cout<<"\n\tThe Top Element of the Stack after removing the top element is: "<<SSTack.Top();

    cout<<"\n\n";
    return 0;
}
