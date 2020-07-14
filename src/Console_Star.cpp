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

    Star center_star(20, 20, 0, 0, -90, 60, 20);

    gotoxy(0, 0);

    draw_border(area);

    while (true) {
        center_star.update_polygon();

        for (int y = 0; y < 35; ++y) {
            gotoxy(area.left * 2, y + area.top);
            for (int x = 0; x < 35; ++x) {
                if (center_star.check_inside(
                        Star::dPoint2D{static_cast<double>(x), static_cast<double>(y)})) {
                    putchar('*');
                } else {
                    putchar(' ');
                }
                putchar(' ');
            }
        }

        Sleep(200);
        center_star.move_for_time(0.2);
    }

    return 0;
}
