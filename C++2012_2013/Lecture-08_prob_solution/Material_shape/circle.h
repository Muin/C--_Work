#ifndef CIRCLE_H
#define CIRCLE_H

#include <shape.h>
#include <iostream>

class circle : public shape
{
public:
    circle();
    ~circle();
    virtual void Draw();
};

#endif // CIRCLE_H
