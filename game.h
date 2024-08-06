# pragma once

#include "tetromino.h"
#include "piece.h"
# include "define.h"

namespace gm{

    //game var
    extern bool running;
    extern bool bottom;
    extern int hold_id;
    extern bool holded;
    extern Piece one_piece;

    extern int points;

    
    extern Matrix playfield;
    extern Matrix frame;
    extern std::map<int,Tetromino> id;
    extern bool warning;

    extern int cnt_blocks;


    extern DWORD duration;
    extern DWORD begin_time;
    extern DWORD now_time;
    
    void render();

    // game method
    void pick();
    void quit();
    void init();
    void process();
    void left();
    void right();
    void down();
    void left_rotate();
    void right_rotate();
    void drop();
    void hold();
    void add_piece_to_playfield();
    void clear_row();
    void check_warning();

    // extern int row, col;
    // extern Tetromino cur_set;
    // extern int cur_index;
}