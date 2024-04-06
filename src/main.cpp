#include <math.h>
#include <ncurses.h>

#include <iostream>

#include "window.h"

int main() {
    initscr();
    curs_set(0);
    noecho();

    int row, col;
    getmaxyx(stdscr, row, col);
    timeout(40);
    Window w = Window(row, col);

    double x = 0;
    double y = 0;
    double aspect = (double)col / row;
    for (int t = 0; t < 10000; t++) {
        w.clear();
        getch();
        for (int j = 0; j < row; j++)
            for (int i = 0; i < col; i++) {
                x = (double)i / col * 2.0 - 1.0;
                y = (double)j / row * 2.0 - 1.0;
                x *= aspect * PIXEL_ASPECT;
                // if (fabs(y - 1) < 0.1) matrix[j][i] = lightness(0.5);
                y += sin(t * 0.1);
                // if (pow(x, 2) + pow(y, 2) < 0.25) matrix[j][i] = lightness(0.5);
                w.matrix[j][i] = lightness(0.04 / sqrt(pow(x, 2) + pow(y, 2)));
            }
        refresh();
        clear();
        w.draw();
    }

    endwin();  // завершение работы с ncurses

    return 0;
}