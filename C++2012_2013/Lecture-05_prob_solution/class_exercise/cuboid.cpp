#include "cuboid.h"
#include <iostream>


using namespace std;


Cuboid::Cuboid(){}


void Cuboid::SetDimensions(int a, int b, int c)
    {
        iLength=a;
        iWidth =b;
        iHeight=c;
    }


void Cuboid::GetDimensions()
    {
        cout<<"\nLength of the Cuboid is: "<<iLength;
        cout<<"\nWidth  of the Cuboid is: "<<iWidth;
        cout<<"\nHeight of the Cuboid is: "<<iHeight;
    }


void Cuboid::CalculateVolume()
    {
        iVolume = (iLength * iWidth * iHeight);
    }


void Cuboid::CalculateSurface()
    {
        iSurface = (2 *((iLength * iWidth) + (iWidth * iHeight) + (iHeight * iLength)));
    }


int Cuboid::GetVolume()
    {
        return (iVolume);
    }


int Cuboid::GetSurface()
    {
        return (iSurface);
    }


Cuboid::~Cuboid(){}
