#ifndef WINDOW_H
#define WINDOW_H
#include <math.h>
#include <ncurses.h>

#include <iostream>
#include <vector>
#define PIXEL_ASPECT 0.5
#define GRADIENT " .:!/r(l1Z4H9W8$@";

int lightness(double x);

class Window {
   private:
    int col;
    int row;

    int** create_matrix(int row, int col);

   public:
    int** matrix;
    Window(int row, int col);
    const int get_col();
    const int get_row();
    void draw();
    void clear();
    ~Window();
};

#endif