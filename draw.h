#pragma once
#include "define.h"
#include "tetromino.h"
#include "graphics.h"

// draw something

namespace dw {
    extern IMAGE block[9];
    extern IMAGE background;
    extern IMAGE next_title;
    extern IMAGE hold_title;
    void init();
    void print_ui();
    void print_tetromino(Tetromino& t, int top, int left, int index);
    void print_frame(Matrix& frame, int top, int left);
    void put_img(int x, int y, IMAGE* img);
    void print_next();
    void print_hold();
    void print_fps();
    void print_points();
}  // namespace dw