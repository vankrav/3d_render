#include "ndraw.h"

#include <stdio.h>

void draw(int** matrix, int row, int col) {
    char gradient[18] = GRADIENT;
    for (int j = row - 1; j >= 0; j--)
        for (int i = 0; i < col; i++) printw("%c", gradient[matrix[j][i]]);
}