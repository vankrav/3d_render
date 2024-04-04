#ifndef DRAW_H
#define DRAW_H

#define SIZE_X 80
#define SIZE_Y 40
#define ASPECT (double)SIZE_X / (double)SIZE_Y
#define PIXEL_ASPECT 1. / 2.

#define Y_STEP 2 / SIZE_Y
#define X_STEP 2 / SIZE_X
#define GRADIENT " .:!/r(l1Z4H9W8$@";

void draw(int matrix[SIZE_Y][SIZE_X]);

#endif