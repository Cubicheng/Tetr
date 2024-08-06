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


    extern DWORD duration;
    
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

    // extern int row, col;
    // extern Tetromino cur_set;
    // extern int cur_index;
}