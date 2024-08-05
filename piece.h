#pragma once
#include "define.h"
#include "tetromino.h"

namespace gm {

    extern std::vector<std::pair<int,int>> kick_transation;

    class Piece {
    public:
        Piece(Tetromino& t, int x0, int y0, int i, bool bt,int bt_cnt,std::shared_ptr<Matrix> p_pf);
        Piece() = default;
        void down();
        void left();
        void right();
        void left_rotate();
        void right_rotate();
        void rotate(int op);
        void drop();
        std::pair<int, int> get_mino(int i);
        std::pair<int,int> get_xy();
        int get_color();
        bool test(int x, int y);
        int bottom_cnt;
        bool bottom;
    private:
        
        
        Tetromino tetr_set;
        int index;  // 0 L 2 R
        int x, y;
        std::shared_ptr<Matrix> p_playfiled;
};

};  // namespace gm