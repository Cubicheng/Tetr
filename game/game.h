# pragma once

#include "tetromino.h"
#include "piece.h"
# include "..//define.h"

namespace gm{

    //game var
    extern bool running;
    extern bool bottom;
    extern Piece one_piece;

    
    extern Matrix playfield;
    extern Matrix frame;
    extern std::map<int,Tetromino> id;


    extern std::chrono::microseconds duration;
    
    void render();

    // game method
    Piece pick();
    void quit();
    void init();
    void process();
    void left();
    void right();
    void down();
    void left_rotate();
    void right_rotate();
    void drop();
    void add_piece_to_playfield();
    void clear_row();

    // extern int row, col;
    // extern Tetromino cur_set;
    // extern int cur_index;
}