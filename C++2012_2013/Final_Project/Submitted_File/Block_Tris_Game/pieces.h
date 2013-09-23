#ifndef PIECES_H
#define PIECES_H

#include <Interfaces.h>


class Pieces
    {
        public:
            Pieces();

            void RandomPieceShape();
            void ChooseShape(BlockType_E shape);

            int minX() const;
            int maxX() const;
            int minY() const;
            int maxY() const;
            int x(int index) const;
            int y(int index) const;

            BlockType_E shape() const { return pieceShape; }            
            Pieces LeftRotation() const;
            Pieces RightRotation() const;

        protected:
            void setX(int index, int x);
            void setY(int index, int y);
            int coords[4][2];

            BlockType_E NoShape;            
            BlockType_E pieceShape;
    };

#endif // PIECES_H
