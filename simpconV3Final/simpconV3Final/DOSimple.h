#ifndef DOSIMPLE_H
#define DOSIMPLE_H

#include <windows.h>
#include <iostream>
#include <conio.h>
#include <time.h>
#include <math.h>
#define SCREEN_X             80
#define SCREEN_Y             25
#define ERASE_PATTERN        32
#define NOPROMPT ""
#define DEFAULT "Press any key to continue . . ."

class DOSimple
{
    public:
        DOSimple();
        ~DOSimple();
        bool Title(char *title);
        bool Delay(clock_t MiliSeconds);
        bool ShowCursor(bool Show);
        bool Output(int x, int y, WORD Color, char *text);
        bool SetColor(WORD Color);
        bool Pause(char *prompt);
        bool GotoXY(int x, int y);
        bool DOSProgress(int x, int y, WORD color, int speed, char *doneMessage, bool beep);
        bool type(char *text, int wait);
        bool fullscreen();
    private:
        HANDLE console;
};

#endif //DOSIMPLE_H
