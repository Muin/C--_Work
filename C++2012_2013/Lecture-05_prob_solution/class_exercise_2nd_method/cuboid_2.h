#ifndef CUBOID_2_H
#define CUBOID_2_H


class cuboid_2
    {

        int iLength,iWidth,iHeight;
        int iVolume,iSurface;

        public:
            cuboid_2 (int a, int b, int c);
            cuboid_2 (const cuboid_2& cuboid_2_obj);
            void GetDimensions();
            void CalculateVolume();
            void CalculateSurface();
            int GetVolume();
            int GetSurface();
            ~cuboid_2();
    };


#endif // CUBOID_2_H
