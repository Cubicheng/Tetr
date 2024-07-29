#include "game.h"
#include "utils.h"

namespace gm {

    bool running;
    Piece one_piece;
    Matrix playfield;
    Matrix frame;
    std::chrono::microseconds duration;

    void init() {
        running = true;
        // playfield[x][y] x=0~9 y=0~21
        playfield = Matrix(10, std::vector<int>(22, 0));
        duration = 500ms;
        frame = playfield;
        one_piece = pick();
    }

    void add_piece_to_playfield(){
        auto [x, y] = one_piece.get_xy();
        while (one_piece.test(x, --y));
        y++;
        for (int i = 0; i < 4; i++) {
            auto [dx, dy] = one_piece.get_mino(i);
            playfield[x + dx][y + dy] = one_piece.get_color();
        }
    }

    void clear_row(){
        

    }

    void process() {
        render();
        if(one_piece.bottom){
            add_piece_to_playfield();
            clear_row();
            one_piece = pick();
        }
        if (ut::timer(duration)) {
            one_piece.down();
        }
    }

    void render() {
        frame = playfield;

        
        // shade blocks
        auto [x1, y1] = one_piece.get_xy();
        while (one_piece.test(x1, --y1))
            ;
        y1++;
        for (int i = 0; i < 4; i++) {
            auto [dx, dy] = one_piece.get_mino(i);
            frame[x1 + dx][y1 + dy] = -one_piece.get_color();
        }

        // colorful blocks
        auto [x2, y2] = one_piece.get_xy();
        
        for (int i = 0; i < 4; i++) {
            auto [dx, dy] = one_piece.get_mino(i);
            frame[x2 + dx][y2 + dy] = one_piece.get_color();
        }

        if(y1==y2){
            one_piece.bottom = true;
        }
    }

    Piece pick() {
        // todo: pick the front of the queue
        return Piece(J, 4, 20, 0, false, std::make_shared<Matrix>(playfield));
    }

    void quit() {
        running = false;
    }

    void left() {
        one_piece.left();
    }

    void right() {
        one_piece.right();
    }

    void down() {
        one_piece.down();
    }

    void left_rotate() {
        one_piece.left_rotate();
    }

    void right_rotate() {
        one_piece.right_rotate();
    }

    void drop(){
        one_piece.drop();
    }

}  // namespace gm