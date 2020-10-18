// Console_Star.h

#pragma once

#include <sys/ioctl.h>
#include <unistd.h>

#include <cstdio>
#include <iostream>

#include "lib/star.h"

void gotoxy(int x, int y) {
    printf("\033[%d;%df", y + 1, x + 1);
    fflush(stdout);
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

inline void draw_border(Rect area) {
    draw_border(area.left, area.top, area.right, area.bottom);
}
