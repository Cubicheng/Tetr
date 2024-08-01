#pragma once
#include "..//define.h"
#include "..//tetromino//tetromino.h"

// draw something

namespace dw {
    void create_block(int top, int left, int width, int height, const std::string &title);
    void print_tetromino(Tetromino& t, int top, int left, int index);
    void print_frame(Matrix& frame, int top, int left);
    void print_next();
    void print_hold();
}  // namespace dw