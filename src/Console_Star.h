// Console_Star.h
//

#pragma once

#include <windows.h>

#include <cstdio>
#include <iostream>

#include "lib/star.h"

void gotoxy(int x, int y) {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),
                             COORD{static_cast<short>(x), static_cast<short>(y)});
}

void draw_border(int left, int top, int right, int bottom) {
    for (int h = left; h < right; ++h) {
        gotoxy(h * 2, top - 1);
        putchar('-');
        putchar('-');
        gotoxy(h * 2, bottom);
        putchar('-');
        putchar('-');
    }

    for (int v = top; v < bottom; ++v) {
        gotoxy(left * 2 - 1, v);
        putchar('|');
        gotoxy(right * 2, v);
        putchar('|');
    }
}

inline void draw_border(Rect area) { draw_border(area.left, area.top, area.right, area.bottom); }