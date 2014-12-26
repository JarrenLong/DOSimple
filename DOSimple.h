#ifndef _DOSIMPLE_H_
#define _DOSIMPLE_H_

#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <math.h>

#if !defined(__WIN32__)&&(defined(_WIN32)||defined(WIN32)||defined(__CYGWIN__))
# define __WIN32__
#endif

#if !defined(DSAPI)
# if defined(__LCC__)&&defined(__WIN32__)
#  define DSAPI __stdcall
# elif (defined(_MSC_VER)||defined(__WIN32__))
#  define DSAPI __declspec(dllexport)
# else
#  define DSAPI extern
# endif
#endif

#if !defined(APIENTRY)
# if defined(__WIN32__)
#  define APIENTRY __stdcall
# else
#  define APIENTRY
# endif
#endif


#define SCREEN_X             80
#define SCREEN_Y             25
#define ERASE_PATTERN        32
#define NOPROMPT ""
#define DEFAULT "Press any key to continue . . ."
//Pre-defined Colors
// *text or back*_*the color*(*optional*: _B for bright color(s))
#define TEXT_RED FOREGROUND_RED
#define TEXT_RED_B FOREGROUND_RED|FOREGROUND_INTENSITY
#define TEXT_GREEN FOREGROUND_GREEN
#define TEXT_GREEN_B FOREGROUND_GREEN|FOREGROUND_INTENSITY
#define TEXT_BLUE FOREGROUND_BLUE
#define TEXT_BLUE_B FOREGROUND_BLUE|FOREGROUND_INTENSITY
#define TEXT_YELLOW FOREGROUND_RED|FOREGROUND_GREEN
#define TEXT_YELLOW_B FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY
#define TEXT_AQUA FOREGROUND_GREEN|FOREGROUND_BLUE
#define TEXT_AQUA_B FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY
#define TEXT_MAGENTA FOREGROUND_RED|FOREGROUND_BLUE
#define TEXT_MAGENTA_B FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY
#define TEXT_WHITE FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE
#define TEXT_WHITE_B FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY
#define TEXT_BLACK 0
#define TEXT_BLACK_B 0|FOREGROUND_INTENSITY

#define BACK_RED BACKGROUND_RED
#define BACK_RED_B BACKGROUND_RED|BACKGROUND_INTENSITY
#define BACK_GREEN BACKGROUND_GREEN
#define BACK_GREEN_B BACKGROUND_GREEN|BACKGROUND_INTENSITY
#define BACK_BLUE BACKGROUND_BLUE
#define BACK_BLUE_B BACKGROUND_BLUE|BACKGROUND_INTENSITY
#define BACK_YELLOW BACKGROUND_RED|BACKGROUND_GREEN
#define BACK_YELLOW_B BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_INTENSITY
#define BACK_AQUA BACKGROUND_GREEN|BACKGROUND_BLUE
#define BACK_AQUA_B BACKGROUND_GREEN|BACKGROUND_BLUE|BACKGROUND_INTENSITY
#define BACK_MAGENTA BACKGROUND_RED|BACKGROUND_BLUE
#define BACK_MAGENTA_B BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_INTENSITY
#define BACK_WHITE BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE
#define BACK_WHITE_B BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE|BACKGROUND_INTENSITY
#define BACK_BLACK 0
#define BACK_BLACK_B 0|BACKGROUND_INTENSITY


#ifdef __cplusplus
extern "C" {
#endif

#if TARGET_OS_MAC
 #pragma export on
#endif

typedef struct tagDS {
    HANDLE console;
    int currentX;
    int currentY;
} DS;

DSAPI bool APIENTRY DS_Init(DS &dataStruct);
DSAPI bool APIENTRY DS_Destroy(DS &dataStruct);
DSAPI bool APIENTRY DS_Title(LPCWSTR title);
DSAPI bool APIENTRY DS_Delay(clock_t MiliSeconds);
DSAPI bool APIENTRY DS_ShowCursor(DS dataStruct, bool Show);
DSAPI bool APIENTRY DS_Output(DS dataStruct, int x, int y, WORD Color, LPCWSTR text);
DSAPI bool APIENTRY DS_SetColor(DS dataStruct, WORD Color);
DSAPI bool APIENTRY DS_Pause(LPCWSTR prompt);
DSAPI bool APIENTRY DS_GotoXY(DS dataStruct, int x, int y);
DSAPI bool APIENTRY DS_DOSProgress(DS dataStruct, int x, int y, WORD color, int speed, LPCWSTR doneMessage, bool beep);
DSAPI bool APIENTRY DS_Type(LPCWSTR text, int wait);
DSAPI bool APIENTRY DS_Fullscreen();

#if TARGET_OS_MAC
 #pragma export off
#endif

#ifdef __cplusplus
}
#endif

#endif //_DOSIMPLE_H_
