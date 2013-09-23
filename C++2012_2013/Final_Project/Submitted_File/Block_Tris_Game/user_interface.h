#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include <QBasicTimer>
#include <QFrame>
#include <QPointer>
#include <qrect.h>

#include <board.h>
#include <Interfaces.h>


QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE


class User_Interface : public QFrame , public Board , public IPlayer
    {
            Q_OBJECT

        public:
            User_Interface(QWidget *parent = 0);
            virtual ~User_Interface(){}

            virtual void Play ( IBoard * pBoard );

            void NextBlockLabel(QLabel *label);
            QSize WindowSize() const;
            QSize MinimumWindowSize() const;

        public slots:
            void start();
            void pause();
            void autoplay();

        signals:
            void PointsChange(int Points);
            void RowsRemoveChange(int numLines);

        protected:
            void paintEvent(QPaintEvent *event);
            void keyPressEvent(QKeyEvent *event);
            void timerEvent(QTimerEvent *event);

        private:
            bool GameStarted;
            bool GamePaused;
            bool WaitingAfterLine;
            bool AutoPlayMode;
            bool MoveTo(const Pieces &newPiece, int newX, int newY);

            void VerticalMovement();
            void BlockDropped();
            void RemoveRow();
            void NewBlock();
            void ShowNextBlock();
            void drawSquare(QPainter &painter, int x, int y, BlockType_E shape);

            int PixelWidth() { return contentsRect().width() / BoardWidth; }
            int PixelHeight() { return contentsRect().height() / BoardHeight; }          

            QBasicTimer timer;
            QPointer<QLabel> Next_Block_Label;
    };

#endif // USER_INTERFACE_H
