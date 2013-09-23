#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <shape.h>
#include <iostream>

class triangle : public shape
{
public:
    triangle();
    ~triangle();
    virtual void Draw();
};

#endif // TRIANGLE_H
