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

//color info for fonts and backgrounds
//choice 1: FOREGROUND_ or BACKGROUND_ (or a number)
//choice 2: RED or GREEN or BLUE or INTENSITY (or a number)

namespace simpcon
{
          
void Program(char *String, ...);
void Delay (clock_t MiliSeconds);
BOOL ShowCursor(char *Show);
void Output(int x, int y, WORD Color, char *String, ...);
BOOL SetColor (WORD Color);

void Program(char *String, ...)
{
	va_list List;
	char FormattedString[80] = {0};
    va_start (List, String);
		vsprintf (FormattedString, String, List);
	va_end (List);
	SetConsoleTitle (FormattedString);
}

void Delay (clock_t MiliSeconds)
{
	clock_t EndTime = 0;
	if (MiliSeconds > 0)
	{
		EndTime = clock () + MiliSeconds;
		while (clock () < EndTime);
	}
	else
	{
		if ( !(MiliSeconds > 0) )
		{printf ("Error", MiliSeconds);}
	}
}

BOOL ShowCursor(char *Show)
{
	CONSOLE_CURSOR_INFO cci = {0};
	BOOL StatusCCI = 0;
	if (Show="YES")
	{
		cci.dwSize   = 30;
		cci.bVisible = TRUE;
		StatusCCI    = SetConsoleCursorInfo (GetStdHandle (STD_OUTPUT_HANDLE), &cci);		
	}
	else
	{
		cci.dwSize   = 100;
		cci.bVisible = FALSE;
		StatusCCI    = SetConsoleCursorInfo (GetStdHandle (STD_OUTPUT_HANDLE), &cci);
	}
	if (!StatusCCI)
	{printf ("Error", GetLastError ());}
	return StatusCCI;
}

void Output(int x, int y, WORD Color, char *String, ...)
{
	COORD   screenPosition = {0};
    int   i = 0, FormattedStringLength = 0;
    va_list List;
	char    FormattedString[100] = {0};
	HANDLE hOutput;
	DWORD  NoOfCharsWritten = 0, NoOfAttrsWritten = 0;
    va_start (List, String);
		vsprintf (FormattedString, String, List);
		FormattedStringLength = (int) strlen (FormattedString);
	va_end (List);
	if ( (x >= 0) && (x <= 79) && (y >= 0) && (x+FormattedStringLength <= 80) && (y <= 25) )
	{
		hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		for (i = 0; i < FormattedStringLength; i++)
		{
			screenPosition.X = (short) (x + i);
			screenPosition.Y = (short) y;
			WriteConsoleOutputCharacter (hOutput, &FormattedString[i], 1, screenPosition, &NoOfCharsWritten);
			WriteConsoleOutputAttribute (hOutput, &Color, 1, screenPosition, &NoOfAttrsWritten);
		}
		if (NoOfAttrsWritten != NoOfCharsWritten)
		{printf ("Error", NoOfCharsWritten, NoOfAttrsWritten);}
	}
	else
	{
		if ( !(x >= 0 && x <= 79) )
		{printf ("Error", x);}
		if ( !(y >= 0 && y <= 24)  )
		{printf ("Error", y);}
		if ( !(x+FormattedStringLength <= 80) )
		{printf ("Error", x+FormattedStringLength);}
	}
}

BOOL SetColor (WORD Color)
{return SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), Color);}

}
