// Console_Star.h
//

#pragma once

#include <windows.h>

#include <cstdio>
#include <iostream>

#include "star.h"

void gotoxy(int x, int y) {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),
                             COORD{static_cast<short>(x), static_cast<short>(y)});
}