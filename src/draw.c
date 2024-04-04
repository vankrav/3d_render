#include "draw.h"

#include <stdio.h>

void draw(int matrix[SIZE_Y][SIZE_X]) {
    char gradient[18] = GRADIENT;

    printf(" ");
    for (int i = 0; i < SIZE_X; i++) printf("_");
    printf(" \n");

    for (int j = SIZE_Y - 1; j >= 0; j--) {
        printf("|");
        for (int i = 0; i < SIZE_X; i++) {
            printf("%c", gradient[matrix[j][i]]);
        }
        printf("|\n");
    }

    printf(" ");
    for (int i = 0; i < SIZE_X; i++) printf("-");
    printf(" \n");
}