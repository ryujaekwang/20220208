#include "Util.h"
#include <windows.h>

void Util::GotoXY(int X, int Y)
{
    COORD Cur;
    Cur.X = X;
    Cur.Y = Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
