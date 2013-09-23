#include "cuboid_2.h"
#include <iostream>


using namespace std;



cuboid_2::cuboid_2 (int a, int b, int c)
    {
        iLength=a;
        iWidth =b;
        iHeight=c;
    }


cuboid_2::cuboid_2 (const cuboid_2& cuboid_2_obj)
    {
        iLength=cuboid_2_obj.iLength;
        iWidth =cuboid_2_obj.iWidth;
        iHeight=cuboid_2_obj.iHeight;
    }


void cuboid_2::GetDimensions()
    {
        cout<<"\nLength of the Cuboid is: "<<iLength;
        cout<<"\nWidth  of the Cuboid is: "<<iWidth;
        cout<<"\nHeight of the Cuboid is: "<<iHeight;
    }


void cuboid_2::CalculateVolume()
    {
        iVolume = (iLength * iWidth * iHeight);
    }


void cuboid_2::CalculateSurface()
    {
        iSurface = (2 *((iLength * iWidth) + (iWidth * iHeight) + (iHeight * iLength)));
    }


int cuboid_2::GetVolume()
    {
        return (iVolume);
    }


int cuboid_2::GetSurface()
    {
        return (iSurface);
    }


cuboid_2::~cuboid_2()
{}
