#include "DOSimple.h"

DSAPI bool APIENTRY DS_Init(DS &dataStruct)
{
    dataStruct.console = GetStdHandle(STD_OUTPUT_HANDLE);
    return true;
}

DSAPI bool APIENTRY DS_Destroy(DS &dataStruct)
{
    dataStruct.console = NULL;
    return true;
}

DSAPI bool APIENTRY DS_Title(LPCWSTR title)
{
    SetConsoleTitle(title);
    return true;
}

DSAPI bool APIENTRY DS_Delay(clock_t MiliSeconds)
{
    clock_t EndTime=0;
    if(MiliSeconds>0)
    {
        EndTime=clock()+MiliSeconds;
        while(clock()<EndTime);
    }
    else{return false;}
    return true;
}

DSAPI bool APIENTRY DS_ShowCursor(DS dataStruct, bool Show)
{
    CONSOLE_CURSOR_INFO cci;
    if(Show=TRUE&&dataStruct.console!=NULL)
    {
        cci.dwSize   = 30;
        cci.bVisible = TRUE;
        SetConsoleCursorInfo(dataStruct.console,&cci);		
    }
    else
    {
        cci.dwSize   = 100;
        cci.bVisible = FALSE;
        SetConsoleCursorInfo(dataStruct.console,&cci);
    }
    return Show;
}

DSAPI bool APIENTRY DS_Output(DS dataStruct, int x, int y, WORD Color, LPCWSTR text)
{
    COORD screenPosition = {0};
    unsigned int i=0;
    DWORD NoOfCharsWritten = 0, NoOfAttrsWritten = 0;
    if(x>=0&&x<=79&&y>=0&&(x+wcslen(text)<=80)&&y<=25&&dataStruct.console!=NULL)
    {
        for(i=0;i<wcslen(text);i++)
        {
            screenPosition.X = (short)(x + i);
            screenPosition.Y = (short)y;
            WriteConsoleOutputCharacter(dataStruct.console,&text[i],1,screenPosition,&NoOfCharsWritten);
            WriteConsoleOutputAttribute(dataStruct.console,&Color,1,screenPosition,&NoOfAttrsWritten);
        }
        if(NoOfAttrsWritten!=NoOfCharsWritten){return false;}
    }
    else{return false;}
    return true;
}

DSAPI bool APIENTRY DS_SetColor(DS dataStruct, WORD Color)
{
    if(dataStruct.console!=NULL){SetConsoleTextAttribute(dataStruct.console,Color);}
    return TRUE;
}

DSAPI bool APIENTRY DS_Pause(char *prompt)
{
    printf(prompt);
    _getch();
    return true;
}

DSAPI bool APIENTRY DS_GotoXY(DS dataStruct, int x, int y)
{
    COORD coord = {0};
    if(x>=0&&x<=78&&y>=0&&y<=24&&dataStruct.console!=NULL)
    {
        coord.X = (short)x;
        coord.Y = (short)y;
        SetConsoleCursorPosition(dataStruct.console,coord);
    }
    else{return false;}
    return true;
}

DSAPI bool APIENTRY DS_DOSProgress(DS dataStruct, int x, int y, WORD color, int speed, LPCWSTR doneMessage, bool beep)
{
    int a=x;
    DS_Output(dataStruct,x-1,y,color,L"|                    |");
    for(a;a<x+20;a++)
    {
        DS_Delay(speed);
        DS_Output(dataStruct,a,y,color,L"==");
        a++;
    }
    DS_Output(dataStruct,a+2,y,color,doneMessage);
    if(beep){Beep(440,100);}
    return true;
}

DSAPI bool APIENTRY DS_Type(char *text, int wait)
{
    int len=strlen(text);
    int z=0;
    while(z<len)
    {
        printf("%c",text[z]);
        Sleep(wait);
        z=z+1;
    }
    return true;
}

DSAPI bool APIENTRY DS_Fullscreen()
{ 
	/*
    keybd_event(VK_MENU,0x38,0,0);
    keybd_event(VK_RETURN,0x1c,0,0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
	*/
    return true;
}
