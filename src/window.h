#ifndef WINDOW_H
#define WINDOW_H
#include <vector>
#include <iostream>
#include <ncurses.h>
#include <math.h>
#define PIXEL_ASPECT 0.5
#define GRADIENT " .:!/r(l1Z4H9W8$@";





class Window {
    private:

        int col = 0;
        int row = 0;
        int** matrix;
        int** create_matrix(int row, int col);

    public:
        Window(int row, int col);
        const int get_size_x();
        const int get_size_y();
        void draw();
        ~Window();


};


#endif