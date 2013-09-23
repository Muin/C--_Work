#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <shape.h>
#include <iostream>

class rectangle : public shape
{
public:
    rectangle();
    ~rectangle();
    virtual void Draw();

};

#endif // RECTANGLE_H
