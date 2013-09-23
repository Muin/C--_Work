#ifndef GUI_H
#define GUI_H

#include <QFrame>
#include <QWidget>

QT_BEGIN_NAMESPACE
class QLCDNumber;
class QLabel;
class QPushButton;
QT_END_NAMESPACE
class User_Interface;


class GUI : public QWidget
    {
            Q_OBJECT

        public:
            GUI();

        private:
            QLabel *createLabel(const QString &text);

            User_Interface *board;
            QLabel *nextPieceLabel;
            QLCDNumber *scoreLcd;
            QLCDNumber *linesLcd;
            QPushButton *startButton;
            QPushButton *quitButton;
            QPushButton *pauseButton;
            QPushButton *autoplayButton;
    };

#endif // GUI_H
