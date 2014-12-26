#include "DOSimple.h"

using namespace std;

int main()
{
    DOSimple simple;
    simple.Title("Program Title");
    simple.fullscreen();
    simple.ShowCursor(FALSE);
    simple.Output(10,10,FOREGROUND_RED,"Red Test Text @ (10,10)");
    simple.SetColor(BACKGROUND_GREEN|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    simple.GotoXY(20,20);
    simple.SetColor(FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    simple.Delay(3000);
    simple.type("This is the type command",100);
    simple.Delay(1000);
    simple.Pause("Pause -- Press any key to exit . . .");
    return 0;
}
