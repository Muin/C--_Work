#ifndef BOARD_H
#define BOARD_H



#include <Interfaces.h>
#include <pieces.h>



class Board : public IBoard
    {
        public:
            Board();
            virtual ~Board(){}

            virtual void InitBoard();
            virtual unsigned int GetField( unsigned int PosX , unsigned int PosY ) const;
            virtual void Move ( Movement_E Movement );
            virtual bool IsFinished() const;
            virtual BlockType_E GetNextBlockType() const;
            virtual unsigned int GetPoints() const;
            virtual unsigned int GetRemovedRows() const;

            //Set the Movement
            bool try_Move(const Pieces &newPiece, int newX, int newY);

            //Set Random Next Shape
            void Random_Next_Piece();

            //Clear the Board
            void clearBoard();

            //Set No Shape as a Current Shape
            void Current_NoShape();

            int Board_Height() const;
            int Board_Width() const;
            int Current_Shape_Position_X ( int x );
            int Current_Shape_Position_Y ( int y );
            int Next_Shape_Position_X ( int x );
            int Next_Shape_Position_Y ( int y );
            int Pixel_Length_X ();
            int Pixel_Length_Y ();
            int Initial_Piece_position_X();
            int Initial_Piece_position_Y();
            int Num_Full_Lines();

            BlockType_E No_Shape();
            BlockType_E Current_Shape();

        protected:
            enum { BoardWidth = 10, BoardHeight = 16 };

            BlockType_E &PixelLocation (int x, int y) { return board [(y * BoardWidth) + x]; }
            const BlockType_E &PixelLocation (int x, int y) const { return board [(y * BoardWidth) + x]; }
            BlockType_E board [BoardWidth * BoardHeight];
            BlockType_E NoShape;

            Pieces CurrentBlock;
            Pieces NextBlock;

            int Current_X_cordinate;
            int Currenty_Y_cordinate;
            int RemovedRows;
            int Points;
    };

#endif // BOARD_H
