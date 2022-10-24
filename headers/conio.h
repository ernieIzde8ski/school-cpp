// https://stackoverflow.com/questions/3276546/how-to-implement-getch-function-of-c-in-linux
// header filename taken from its Windows counterpart

// prevents the definitions in this file from being read more than once
#pragma once

#include <iostream>
#include <termios.h>
#include <unistd.h>

namespace conio {
    /* reads from keypress, doesn't echo */
    int getch(void) {
        struct termios oldattr, newattr;
        int ch;
        tcgetattr(STDIN_FILENO, &oldattr);
        newattr = oldattr;
        newattr.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
        return ch;
    }

    /* reads from keypress, echoes */
    int getche(void) {
        struct termios oldattr, newattr;
        int ch;
        tcgetattr(STDIN_FILENO, &oldattr);
        newattr = oldattr;
        newattr.c_lflag &= ~(ICANON);
        tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
        return ch;
    }
}
