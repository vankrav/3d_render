









#include <math.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "ndraw.h"

int **create_matrix(int row, int col);
int lightness(double x);

int main(int argc, char *argv[]) {
    initscr();
    curs_set(0);
    noecho();
    timeout(40);
    int row, col;

    getmaxyx(stdscr, row, col);

    int **matrix = create_matrix(row, col);

    double x = 0;
    double x1 = 0;
    double y = 0;
    double aspect = (double)col / row;
    for (int t = 0; t < 10000; t++) {
        for (int j = 0; j < row; j++)
            for (int i = 0; i < col; i++) matrix[j][i] = 0;
        getch();
        for (int j = 0; j < row; j++)
            for (int i = 0; i < col; i++) {
                x = (double)i / col * 2.0 - 1.0;
                y = (double)j / row * 2.0 - 1.0;
                x *= aspect * PIXEL_ASPECT;
                // if (fabs(y - 1) < 0.1) matrix[j][i] = lightness(0.5);
                y += sin(t * 0.1);
                // if (pow(x, 2) + pow(y, 2) < 0.25) matrix[j][i] = lightness(0.5);
                matrix[j][i] = lightness(0.04 / sqrt(pow(x, 2) + pow(y, 2)));
            }
        refresh();
        clear();
        draw(matrix, row, col);
    }
    // draw(matrix);
    // обновить экран
    // ждём нажатия символа

    endwin();  // завершение работы с ncurses
    free(matrix);

    return 0;
}

int **create_matrix(int row, int col) {
    int **matrix = malloc(row * col * sizeof(int) + row * sizeof(int *));
    int *ptr = (int *)(matrix + row);

    for (int i = 0; i < row; i++) matrix[i] = ptr + col * i;

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++) matrix[i][j] = 0;

    return matrix;
}

int lightness(double x) { return (int)((x * 16) > 16 ? 16 : ((x * 16) < 0 ? 0 : (x * 16))); }