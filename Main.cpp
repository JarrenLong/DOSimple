#include "DOSimple.h"

using namespace std;

int main()
{
    DS TextRPG;
    DS_Init(TextRPG);
    DS_Title(L"Text RPG");
    //DS_Fullscreen();
    DS_ShowCursor(TextRPG, false);
    DS_Output(TextRPG,36,10,TEXT_RED,L"Text RPG");
    DS_GotoXY(TextRPG,0,12);
    DS_SetColor(TextRPG,BACK_RED|TEXT_BLACK);
    DS_DOSProgress(TextRPG,1,0,TEXT_BLUE_B,250,L"Complete!",true);
    DS_Type(L"Welcome to Text RPG, the rip-off of over a million other RPG games in this world",50);
    DS_Type(L" (not to mention others!). The object of this game is "
    L"to learn the basics of programming console applications using the DOSimple"
    L" library. **PLEASE NOTE: The DOSimple library IS NOT compatible with any "
    L"Operating System other than Windows *AS OF NOW*. I plan to expand this "
    L"library to include cross-platform support in the near future.**",50);
    DS_Delay(1000);
    DS_SetColor(TextRPG,TEXT_WHITE_B);
    DS_Pause(L"Push any key . . .");
    DS_Destroy(TextRPG);
    return 0;
}
