#ifndef DOSIMPLE_H
#define DOSIMPLE_H

#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <math.h>
#define SCREEN_X             80
#define SCREEN_Y             25
#define ERASE_PATTERN        32
#define NOPROMPT ""
#define DEFAULT "Press any key to continue . . ."

class DOSimple
{
    public:
        bool Program(char *String, ...);
        bool Delay (clock_t MiliSeconds);
        bool ShowCursor(char *Show);
        bool Output(int x, int y, WORD Color, char *String, ...);
        bool SetColor (WORD Color);
        bool Pause(char *prompt);
        bool GotoXY (int x, int y);
        bool DOSProgress(int x, int y, WORD color, int speed, char *doneMessage, bool beep);
        bool type(char *text, int wait);
};

#endif //DOSIMPLE_H
