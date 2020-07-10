// Console_Star.cpp
//

#include "Console_Star.h"

int main() {
    system("mode con cols=90 lines=46");

    Rect area    = {5, 5, 40, 40};
    char str[14] = "*Stars!      ";

    for (int i = 0; i < 500; ++i) {
        for (char c : str) putchar(c);
    }

    Star center_star(20, 20, 0, 0, -90, 90, 20);

    gotoxy(0, 0);

    draw_border(area);

    while (true) {
        gotoxy(area.left * 2, area.top);
        for (int y = 0; y < 36; ++y) {
            for (int x = 0; x < 35; ++x) {
                if (center_star.check_inside(
                        Star::dPoint{static_cast<double>(x), static_cast<double>(y)})) {
                    putchar('*');
                } else {
                    putchar(' ');
                }
                putchar(' ');
            }
            gotoxy(area.left * 2, y + area.top);
        }
        Sleep(50);
        center_star.move_for_time(0.05);
    }

    return 0;
}
