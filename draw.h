#pragma once
#include "define.h"
#include "tetromino.h"
#include "graphics.h"

// draw something

namespace dw {
    extern IMAGE block[10];
    extern IMAGE background;
    extern IMAGE next_title;
    extern IMAGE hold_title;
    extern IMAGE next_title_warning;
    extern IMAGE hold_title_warning;
    void init();
    void print_ui();
    void print_tetromino(Tetromino& t, int top, int left, int index,int op);
    void print_frame(Matrix& frame, int top, int left);
    void print_warning_next_block();
    void put_img(int x, int y, IMAGE* img);
    void print_next();
    void print_hold();
    void print_fps();
    void print_points();
    void print_time();
    void print_pps();
}  // namespace dw