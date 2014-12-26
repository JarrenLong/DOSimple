#include "DOSimple.h"

bool DOSimple::Program(char *String, ...)
{
	va_list List;
	char FormattedString[80] = {0};
    va_start (List, String);
		vsprintf (FormattedString, String, List);
	va_end (List);
	SetConsoleTitle(FormattedString);
}
bool DOSimple::Delay (clock_t MiliSeconds)
{
	clock_t EndTime = 0;
	if (MiliSeconds > 0)
	{
		EndTime = clock () + MiliSeconds;
		while (clock () < EndTime);
	}
	else
	{
		if (!(MiliSeconds > 0) )
		{printf("Error", MiliSeconds);}
	}
}
BOOL DOSimple::ShowCursor(char *Show)
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
bool DOSimple::Output(int x, int y, WORD Color, char *String, ...)
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
BOOL DOSimple::SetColor (WORD Color)
{return SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), Color);}
bool DOSimple::Pause(char *prompt)
{
    cout<<prompt<<endl;
    getch();
}
bool DOSimple::GotoXY (int x, int y)
{
	COORD coord = {0};
	if ( (x >= 0) && (x <= 78) && (y >= 0) && (y <= 24) )
	{
		coord.X = (short) x;
		coord.Y = (short) y;
		SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), coord);
	}
	else
	{
		if ( !((x >= 0) && (x <= 78)) )
		{printf ("Error! Value x is not between 0 and 78 (x = %02d).", x);}
		if ( !((y >= 0) && (y <= 24)) )
		{printf ("Error! Value y is not between 0 and 24 (y = %02d).", y);}
	}
}
int DOSimple::DOSProgress(int x, int y, WORD color, int speed, char *doneMessage, bool beep)
{
    int a=x;
    Output(x-1,y,color,"|====================|");
    for(a;a<x+20;a++)
    {
    Delay(speed);
    Output(a,y,color,"[]");
    a++;
    }
    Output(a+2,y,color,doneMessage);
    if(beep==TRUE){Beep(440,100);}
    else{beep==FALSE;}
}

bool DOSimple::type(char *text, int wait)
{
    int len=strlen(text);
    int z=0;
    while(z<len)
    {
        cout<<text[z];
        Sleep(wait);
        z=z+1;
    }
    cout<<endl;
}

bool DOSimple::fullscreen() 
{ 
keybd_event(VK_MENU,0x38,0,0); 
keybd_event(VK_RETURN,0x1c,0,0); 
keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0); 
keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0); 
}
