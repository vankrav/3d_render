#include "window.h"

Window::Window(int row, int col) {
    this->row = row;
    this->col = col;
    this->matrix = create_matrix(row, col);
}

int** Window::create_matrix(int row, int col) {
    int** matrix = new int*[row];
    for (int i = 0; i < row; i++) matrix[i] = new int[col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++) matrix[i][j] = 0;

    return matrix;
}

const int Window::get_col() { return (const int)this->col; }
const int Window::get_row() { return (const int)this->row; }

void Window::draw() {
    char gradient[18] = GRADIENT;
    for (int j = row - 1; j >= 0; j--)
        for (int i = 0; i < col; i++) printw("%c", gradient[matrix[j][i]]);
}

void Window::clear() {
    for (int j = row - 1; j >= 0; j--)
        for (int i = 0; i < col; i++) matrix[j][i] = 0;
}

Window::~Window() {
    for (int i = 0; i < this->row; i++) delete[] this->matrix[i];
    delete[] this->matrix;
}

int lightness(double x) { return (int)((x * 16) > 16 ? 16 : ((x * 16) < 0 ? 0 : (x * 16))); }