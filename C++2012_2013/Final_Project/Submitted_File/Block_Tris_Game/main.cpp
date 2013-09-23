/*         FINAL PROJECT
           BLOCKTRIS GAME
        ISLAM,MOHAMMAD MUINUL
      MATRICULATION NO:-2581908
INFORMATION AND AUTOMATION ENGINEERING
         UNIVERSITY OF BREMEN
         CREATED: 14.02.2013
*/


#include <QtGui>

#include <stdlib.h>

#include "gui.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    GUI window;
    window.show();
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    return app.exec();
}


/*
comment: Playing Instruction:

         Use Left-ArrowKey to move left
         Use Right-ArrowKey to move right
         Use Up-ArrowKey to rotate Clockwise
         Use Down-ArrowKey to rotate AntiClockwise
         Use Key 'd' to move one line down
         Use spaceKey to release

         Steady Game:

         If you do not want to play the game in motion, just make 329 No. Line
         of user_interface.cpp as comment(i.e. make VerticalMovement(); function as comment)
         you can enjoy the game without motion of the falling blocks.

         Regarding My code:

         In My Game Design I couldn't be able to separate my AutoPlayer Algorithm
         from the User_Interface Class because I have to use the main Thread of
         the QFrame which I have defined in the User_Interface cLass.

         And also my User_Interface class where I have defined user input is also inherited
         from Class Board. I have to do that because of using the main Thread.
*/

