#include <iostream>

#if defined(_WIN32) || defined(_WIN64)
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>

// Function to disable buffered input
void disableBufferedInput() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ICANON;
    t.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

// Function to enable buffered input
void enableBufferedInput() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= ICANON;
    t.c_lflag |= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}
#endif

// Function to get a single character input
char _turboggetch() {

    #if defined(_WIN32) || defined(_WIN64)
        return _getch();
    #else
        disableBufferedInput();
        char ch = getchar();
        enableBufferedInput();
        return ch;
    #endif
    
}
