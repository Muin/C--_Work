#ifndef CUBOID_H
#define CUBOID_H


class Cuboid
    {

        int iLength,iWidth,iHeight;
        int iVolume,iSurface;

        public:
            Cuboid();
            void SetDimensions(int a, int b, int c);
            void GetDimensions();
            void CalculateVolume();
            void CalculateSurface();
            int GetVolume();
            int GetSurface();
            ~Cuboid();
    };


#endif // CUBOID_H
