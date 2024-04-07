#include <math.h>
#include <ncurses.h>

#include <iostream>

#include "vector.h"
#include "vector_func.h"
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
        v3 light = norm(v3(sin(t * 0.05), cos(t * 0.05), 1.0));
        w.clear();
        getch();
        for (int j = 0; j < row; j++)
            for (int i = 0; i < col; i++) {
                v2 uw = v2(i, j) / v2(col, row) * 2.0 - 1.0;
                uw.x *= aspect * PIXEL_ASPECT;
                v3 camera = v3(-2, 0, 0);
                v3 ray = norm(v3(1, uw));
                v2 intersection = sphere(camera, ray, 1);

                if (intersection.x > 0) {
                    v3 it_point = camera + ray * intersection.x;
                    v3 n = norm(it_point);
                    double diff = dot(n, light);
                    w.matrix[j][i] = lightness(diff * 1.1);
                }
                // uw.y += sin(t * 0.1);
                // if (pow(x, 2) + pow(y, 2) < 0.25) matrix[j][i] = lightness(0.5);
                // w.matrix[j][i] = lightness(0.04 / sqrt(pow(uw.x, 2) + pow(uw.y, 2)));
            }
        refresh();
        clear();
        w.draw();
    }

    endwin();  // завершение работы с ncurses

    return 0;
}