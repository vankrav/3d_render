#include "draw.h"

#include <stdio.h>

void draw(int matrix[SIZE_Y][SIZE_X]) {
    printf(" ");
    for (int i = 0; i < SIZE_X; i++) printf("_");
    printf(" \n");

    for (int y = 0; y < SIZE_Y; y++) {
        printf("|");
        for (int x = 0; x < SIZE_X; x++) {
            if (matrix[y][x]) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("|\n");
    }

    printf(" ");
    for (int i = 0; i < SIZE_X; i++) printf("-");
    printf(" \n");
}