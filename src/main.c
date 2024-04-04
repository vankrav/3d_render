
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "draw.h"

int lightness(double x) { return (int)((x * 16) > 16 ? 16 : ((x * 16) < 0 ? 0 : (x * 16))); }

int main() {
    int matrix[SIZE_Y][SIZE_X] = {0};
    double x = 0;
    double y = 0;
    for (int j = 0; j < SIZE_Y; j++)
        for (int i = 0; i < SIZE_X; i++) {
            x = (double)i / SIZE_X * 2.0 - 1.0;
            y = (double)j / SIZE_Y * 2.0 - 1.0;
            x *= ASPECT * PIXEL_ASPECT;
            matrix[j][i] = lightness(0.04 / sqrt(pow(x, 2) + pow(y, 2)));
        }

    draw(matrix);

    return 0;
}