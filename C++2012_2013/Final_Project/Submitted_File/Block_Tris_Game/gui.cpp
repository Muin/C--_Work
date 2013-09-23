#include <QtGui>

#include "user_interface.h"
#include "gui.h"


GUI::GUI()
    {
        board = new User_Interface;

        nextPieceLabel = new QLabel;
        nextPieceLabel->setFrameStyle(QFrame::Box | QFrame::Raised);
        nextPieceLabel->setAlignment(Qt::AlignCenter);
        board->NextBlockLabel(nextPieceLabel);

        scoreLcd = new QLCDNumber(5);
        scoreLcd->setSegmentStyle(QLCDNumber::Filled);

        linesLcd = new QLCDNumber(5);
        linesLcd->setSegmentStyle(QLCDNumber::Filled);


        startButton = new QPushButton(tr("&Start"));
        startButton->setFocusPolicy(Qt::NoFocus);
        pauseButton = new QPushButton(tr("&Pause"));
        pauseButton->setFocusPolicy(Qt::NoFocus);
        quitButton = new QPushButton(tr("&Quit"));
        quitButton->setFocusPolicy(Qt::NoFocus);
        autoplayButton = new QPushButton(tr("&AutoPlay"));
        autoplayButton->setFocusPolicy(Qt::NoFocus);

        connect(startButton, SIGNAL(clicked()), board, SLOT(start()));
        connect(pauseButton, SIGNAL(clicked()), board, SLOT(pause()));
        connect(quitButton , SIGNAL(clicked()), qApp, SLOT(quit()));
        connect(autoplayButton, SIGNAL(clicked()), board, SLOT(autoplay()));
        connect(board, SIGNAL(PointsChange(int)), scoreLcd, SLOT(display(int)));
        connect(board, SIGNAL(RowsRemoveChange(int)), linesLcd, SLOT(display(int)));

        QGridLayout *layout = new QGridLayout;
        layout->addWidget(createLabel(tr("Next")), 0, 2);
        layout->addWidget(nextPieceLabel, 1, 2);
        layout->addWidget(createLabel(tr("Points")), 3, 2);
        layout->addWidget(scoreLcd, 4, 2);
        layout->addWidget(createLabel(tr("Removed Rows")), 5, 2);
        layout->addWidget(linesLcd, 6, 2);
        layout->addWidget(startButton, 7, 2);
        layout->addWidget(pauseButton, 8, 2);
        layout->addWidget(quitButton, 9, 2);
        layout->addWidget(autoplayButton, 10, 2);
        layout->addWidget(board, 0, 1, 11, 1);
        setLayout(layout);

        setWindowTitle(tr("BlockTris Game"));
        resize(500, 500);
    }



QLabel *GUI::createLabel(const QString &text)
    {
        QLabel *lbl = new QLabel(text);
        lbl->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
        return lbl;
    }


