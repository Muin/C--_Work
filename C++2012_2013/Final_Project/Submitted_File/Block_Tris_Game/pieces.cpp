#include <QtCore>
#include <stdlib.h>
#include "pieces.h"



Pieces::Pieces()
    {
        NoShape = (BlockType_E)(7);
        ChooseShape(NoShape);
    }



void Pieces::RandomPieceShape()
    {
        ChooseShape(BlockType_E(qrand() % 7 ));
    }



void Pieces::ChooseShape(BlockType_E shape)
    {
        static const int coordsTable[8][4][2] =
            {
                { { 0, -1 },  { 0, 0 },   { 0, 1 },   { 0, 2 } },
                { { -1, -1 }, { 0, -1 },  { 0, 0 },   { 0, 1 } },
                { { -1, 0 },  { 0, 0 },   { 1, 0 },   { 0, 1 } },
                { { 0, -1 },  { -1, -1 },  { -1, 0 },   { -1, 1 } },
                { { -1, -1 },  { 0, 0 },   { 1, 0 },  { 0, -1 } },
                { { -1, 0 },   { 0, 0 },   { -1, 1 },   { 0, 1 } },
                { { 1, 0 },  { -1, 1 },   { 0, 0 },   { 0, 1 } },
                { { 0, 0 },   { 0, 0 },   { 0, 0 },   { 0, 0 } }
            };

        for (int i = 0; i < 4 ; i++)
            {
                for (int j = 0; j < 2; ++j)
                    coords[i][j] = coordsTable[shape][i][j];
            }
        pieceShape = shape;

    }



int Pieces::x(int index) const
    {
        return coords[index][0];
    }



int Pieces::y(int index) const
    {
        return coords[index][1];
    }



void Pieces::setX(int index, int x)
    {
        coords[index][0] = x;
    }



void Pieces::setY(int index, int y)
    {
        coords[index][1] = y;
    }



int Pieces::minX() const
    {
        int min = coords[0][0];
        for (int i = 1; i < 4; ++i)
            min = qMin(min, coords[i][0]);
        return min;
    }



int Pieces::maxX() const
    {
        int max = coords[0][0];
        for (int i = 1; i < 4; ++i)
            max = qMax(max, coords[i][0]);
        return max;
    }



int Pieces::minY() const
    {
        int min = coords[0][1];
        for (int i = 1; i < 4; ++i)
            min = qMin(min, coords[i][1]);
        return min;
    }



int Pieces::maxY() const
    {
        int max = coords[0][1];
        for (int i = 1; i < 4; ++i)
            max = qMax(max, coords[i][1]);
        return max;
    }



Pieces Pieces::LeftRotation() const
    {
        if (pieceShape == O_Block_e)
            return *this;

        Pieces result;
        result.pieceShape = pieceShape;
        for (int i = 0; i < 4; ++i)
            {
                result.setX(i, y(i));
                result.setY(i, -x(i));
            }
        return result;
    }



Pieces Pieces::RightRotation() const
    {
        if (pieceShape == O_Block_e)
            return *this;

        Pieces result;
        result.pieceShape = pieceShape;
        for (int i = 0; i < 4; ++i)
            {
                result.setX(i, -y(i));
                result.setY(i, x(i));
            }
        return result;
    }


