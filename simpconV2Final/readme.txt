===========================|
Simple Console C++ Library |
Version 2.0 Final Release  |
                           |
Copyright(c)2005 JincS.    |
Created by Jarren Long.    |
===========================|

This is a free function library, but
please distribute this readme file with
the SimpCon.h header file. Please contact
me at vbslong@gmail.com if you plan to use
this library in any commercial application.
Other than that, have fun!

===========================|
Uses:                      |
===========================|
For less complex C++ console programming.
Eight simple functions to make your life easier!

===========================|
How to Use:                |
===========================|
Include SimpCon.h in your project. That's it!

===========================|
Functions:                 |
===========================|
void Program(char *String, ...)--To fill the titlebar of you app with
the inputted string.

void Delay (clock_t MiliSeconds)--Tells you app to wait for x milli-
seconds until continuing with the rest of the code.

BOOL ShowCursor(char *Show)--Tells you app whether or not to display
the flashing caret (cursor).

void Output(int x, int y, WORD Color, char *String, ...)--Output a
string at (x,y) with a specific color.

BOOL SetColor (WORD Color)--Change the color of all of the text in
your app until you specify differently.

void Pause(char *prompt)--Pause the console (while displaying the
specified text) until a key is pushed.

void Erase(int x, int y, int EraseLength, int NoOfLines,
 WORD EraseColor, char ErasePattern)--Same as Output, but erases text,
rather than writing it.

void GotoXY (int x, int y)--Move the text caret to (x,y) in the console.

int DOSProgress(int x, int y, WORD color,
int speed, char *doneMessage, bool beep)--A DOS-Style progress
bar (kinda). Set the progress speed and color, and then the
message you want displayed when the bar finishes, as well as
if you want a beep to sound when it's done.

===========================|
Simple Console C++ Library |
Version 2.0 Final Release  |
                           |
Copyright(c)2005 JincS.    |
Created by Jarren Long.    |
===========================|
