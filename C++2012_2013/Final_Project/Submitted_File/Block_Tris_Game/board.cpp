#include "board.h"

Board::Board(){}

void Board::clearBoard()
    {
        NoShape = (BlockType_E)(7);
        for (int i = 0; i < BoardHeight * BoardWidth; ++i)
            board[i] = NoShape;
    }



void Board::InitBoard()
    {
        CurrentBlock = NextBlock;
        NextBlock.RandomPieceShape();
    }



unsigned int Board::GetField( unsigned int PosX , unsigned int PosY ) const
    {
        BlockType_E A = PixelLocation(PosX , PosY);
        if (A == NoShape)
            {
                return 0;
            }
        else return 1;
    }



bool Board::try_Move ( const Pieces &newPiece, int newX, int newY )
    {
        for (int i = 0; i < 4; ++i)
            {
                int x = newX + newPiece.x(i);
                int y = newY - newPiece.y(i);
                if (x < 0 || x >= BoardWidth || y < 0 || y >= BoardHeight)
                    return false;
                if (PixelLocation(x, y) != NoShape)
                    return false;
            }
        CurrentBlock = newPiece;
        Current_X_cordinate = newX;
        Currenty_Y_cordinate = newY;
        return true;
    }



void Board::Move(Movement_E Movement)
    {
        switch (Movement)
            {
                case MoveLeft_e:
                    try_Move(CurrentBlock, Current_X_cordinate - 1, Currenty_Y_cordinate);
                    break;

                case MoveRight_e:
                    try_Move(CurrentBlock, Current_X_cordinate + 1, Currenty_Y_cordinate);
                    break;

                case RotateCounterClockwise_e:
                    try_Move(CurrentBlock.RightRotation(), Current_X_cordinate, Currenty_Y_cordinate);
                    break;

                case RotateClockwise_e:
                    try_Move(CurrentBlock.LeftRotation(), Current_X_cordinate, Currenty_Y_cordinate);
                    break;

                case Release_e:
                    {
                        int newY = Currenty_Y_cordinate;
                        while ( newY < BoardHeight )
                            {
                                if (!try_Move(CurrentBlock, Current_X_cordinate, newY + 1))
                                    break;
                                ++newY;
                            }
                    }
                    break;

                default:
                    {}
            }
    }



bool Board::IsFinished() const
    {
        if(Currenty_Y_cordinate<4)
            {
                return true;
            }
        return false;
    }



BlockType_E Board::GetNextBlockType() const
    {
        return NextBlock.shape();
    }



unsigned int Board::GetPoints() const
    {
        return Points;
    }


unsigned int Board::GetRemovedRows() const
    {
        return RemovedRows;
    }



void Board::Random_Next_Piece()
    {
        NextBlock.RandomPieceShape();
    }



int Board::Board_Height() const
    {
        return BoardHeight;
    }



int Board::Board_Width() const
    {
        return BoardWidth;
    }



BlockType_E Board::No_Shape()
    {
        NoShape = (BlockType_E)(7);
        return NoShape;
    }



BlockType_E Board::Current_Shape()
    {
        return CurrentBlock.shape();
    }



void Board::Current_NoShape()
    {
        CurrentBlock.ChooseShape(NoShape);
    }



int Board::Current_Shape_Position_X ( int x )
    {
        return Current_X_cordinate + CurrentBlock.x( x );
    }



int Board::Current_Shape_Position_Y(int y)
    {
        return Currenty_Y_cordinate - CurrentBlock.y( y );
    }



int Board::Next_Shape_Position_X ( int x )
    {
        return NextBlock.x( x ) - NextBlock.minX();
    }



int Board::Next_Shape_Position_Y( int y )
    {
        return NextBlock.y(y) - NextBlock.minY();
    }



int Board::Pixel_Length_X()
    {
        return NextBlock.maxX() - NextBlock.minX();
    }



int Board::Pixel_Length_Y()
    {
        return NextBlock.maxY() - NextBlock.minY();
    }



int Board::Initial_Piece_position_X()
    {
        return Board_Width() / 2 ;
    }



int Board::Initial_Piece_position_Y()
    {
        return 3 + CurrentBlock.minY();
    }



int Board::Num_Full_Lines()
    {
        int numFullLines = 0;
        for (int i = 0; i < Board_Height() ; ++i)
            {
                bool lineIsFull = true;
                for (int j = 0; j < Board_Width(); ++j)
                    {
                        if (PixelLocation(j, i) == No_Shape())
                            {
                                lineIsFull = false;
                                break;
                            }
                    }
                if (lineIsFull)
                {
                    ++numFullLines;
                    for (int k = i; k > 0 ; --k)
                        {
                            for (int j = 0; j < Board_Width(); ++j)
                            PixelLocation(j, k) = PixelLocation(j, k - 1 );
                        }

                    for (int j = 0; j < Board_Width(); ++j)
                    PixelLocation(j, 0 ) = No_Shape();
                }
            }
        return numFullLines;
    }


