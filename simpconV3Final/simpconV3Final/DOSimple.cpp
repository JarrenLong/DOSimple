#include "DOSimple.h"

DOSimple::DOSimple()
{
    console = GetStdHandle(STD_OUTPUT_HANDLE);
}

DOSimple::~DOSimple()
{
    console = NULL;
}

bool DOSimple::Title(char *title)
{
    SetConsoleTitle(title);
}

bool DOSimple::Delay(clock_t MiliSeconds)
{
	 clock_t EndTime=0;
 	 if(MiliSeconds>0)
	 {
        EndTime=clock()+MiliSeconds;
		  while(clock()<EndTime);
    }
    else
    {
        if(!(MiliSeconds>0))
		  {printf("Error", MiliSeconds);}
	 }
}

bool DOSimple::ShowCursor(bool Show)
{
	 CONSOLE_CURSOR_INFO cci;
	 if(Show=TRUE&&console!=NULL)
	 {
		  cci.dwSize   = 30;
		  cci.bVisible = TRUE;
		  SetConsoleCursorInfo(console,&cci);		
    }
    else
    {
        cci.dwSize   = 100;
		  cci.bVisible = FALSE;
		  SetConsoleCursorInfo(console,&cci);
	 }
	 return Show;
}

bool DOSimple::Output(int x, int y, WORD Color, char *text)
{
    COORD screenPosition = {0};
    int i=0;
	 DWORD NoOfCharsWritten = 0, NoOfAttrsWritten = 0;
	 if(x>=0&&x<=79&&y>=0&&(x+strlen(text)<=80)&&y<=25&&console!=NULL)
	 {
		  for(i=0;i<strlen(text);i++)
		  {
			   screenPosition.X = (short)(x + i);
			   screenPosition.Y = (short)y;
			   WriteConsoleOutputCharacter(console,&text[i],1,screenPosition,&NoOfCharsWritten);
			   WriteConsoleOutputAttribute(console,&Color,1,screenPosition,&NoOfAttrsWritten);
        }
		  if(NoOfAttrsWritten!=NoOfCharsWritten)
		  {printf("Error",NoOfCharsWritten,NoOfAttrsWritten);}
    }
	 else{printf("Error",x);}
}

bool DOSimple::SetColor(WORD Color)
{
    if(console!=NULL){SetConsoleTextAttribute(console,Color);}
    return TRUE;
}

bool DOSimple::Pause(char *prompt)
{
    std::cout<<prompt<<std::endl;
    getch();
}

bool DOSimple::GotoXY(int x, int y)
{
	 COORD coord = {0};
	 if(x>=0&&x<=78&&y>=0&&y<=24&&console!=NULL)
	 {
		  coord.X = (short)x;
		  coord.Y = (short)y;
		  SetConsoleCursorPosition(console,coord);
	 }
	 else{printf("Error!",x);}
}

bool DOSimple::DOSProgress(int x, int y, WORD color, int speed, char *doneMessage, bool beep)
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
        std::cout<<text[z];
        Sleep(wait);
        z=z+1;
    }
    std::cout<<std::endl;
}

bool DOSimple::fullscreen() 
{ 
    keybd_event(VK_MENU,0x38,0,0); 
    keybd_event(VK_RETURN,0x1c,0,0); 
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0); 
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0); 
}
