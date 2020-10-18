// Console_Star.cpp

#include "Console_Star.h"

int main() {
    system("clear");

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    Rect area = {5, 5, w.ws_col / 2 - 5, w.ws_row - 5};

    Star center_star(20, 20, 0, 0, -90, 60, 20);

    draw_border(area);

    while (true) {
        center_star.update_polygon();

        for (int y = 0; y < area.bottom - area.top; ++y) {
            gotoxy(area.left * 2, y + area.top);
            for (int x = 0; x < area.right - area.left; ++x) {
                if (center_star.check_inside(
                        Star::dPoint2D{static_cast<double>(x), static_cast<double>(y)})) {
                    printf("%s", "* ");
                } else {
                    printf("%s", "  ");
                }
            }
        }
        printf("\n");

        sleep(1);
        center_star.move_for_time(1);
    }

    return 0;
}
