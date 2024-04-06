#include <iostream>
#include <ncurses.h>
#include <math.h>
#include "window.h"

int main() {
    initscr();
    curs_set(0);
    noecho();
    timeout(40);
    int row, col;
    getmaxyx(stdscr, row, col);
    Window w = Window(row, col);
    

    

    endwin();  // завершение работы с ncurses
    

    return 0;

}