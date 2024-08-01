#include "game.h"
#include "next_queue.h"
#include "utils.h"

namespace gm {

    bool running;
    Piece one_piece;
    Matrix playfield;
    Matrix frame;
    int cur_id;
    int hold_id;
    bool holded;
    int points;
    std::chrono::microseconds duration;
    std::map<int, Tetromino> id{{0, I}, {1, J}, {2, L}, {3, O},
                                {4, S}, {5, T}, {6, Z}};

    static auto bottom_start_time = std::chrono::steady_clock::now();
    auto bottom_end_time = bottom_start_time;

    void init() {
        nq::init();
        running = true;
        // playfield[x][y] x=0~9 y=0~21
        playfield = Matrix(22, std::vector<int>(10, 0));
        duration = 500ms;
        frame = playfield;
        cur_id = nq::get();
        one_piece = Piece(id[cur_id], 4, 20, 0, false, 0,
                        std::make_shared<Matrix>(playfield));
        hold_id = -1;
        holded = false;
        points = 0;
    }

    void add_piece_to_playfield() {
        auto [x, y] = one_piece.get_xy();
        while (one_piece.test(x, --y))
            ;
        y++;
        for (int i = 0; i < 4; i++) {
            auto [dx, dy] = one_piece.get_mino(i);
            playfield[y + dy][x + dx] = one_piece.get_color();
        }
    }

    void clear_row() {
        bool fl;
        for (int i = 0; i < 22; i++) {
            fl = true;
            for (int j = 0; j < 10; j++) {
                if (!playfield[i][j]) {
                    fl = false;
                    break;
                }
            }
            if (fl) {
                points++;
                playfield.erase(playfield.begin() + i);
                playfield.push_back(std::vector<int>(10, 0));
                i--;
            }
        }
    }

    void process() {
        render();
        bottom_end_time = std::chrono::steady_clock::now();
        if ((one_piece.bottom && (one_piece.bottom_cnt >= 15 ||
                                bottom_end_time - bottom_start_time > 2*duration)) ||
            one_piece.bottom_cnt >= 114514) {
            add_piece_to_playfield();
            clear_row();
            pick();
            holded = false;
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
            frame[y1 + dy][x1 + dx] = -one_piece.get_color();
        }

        // colorful blocks
        auto [x2, y2] = one_piece.get_xy();

        for (int i = 0; i < 4; i++) {
            auto [dx, dy] = one_piece.get_mino(i);
            frame[y2 + dy][x2 + dx] = one_piece.get_color();
        }

        if (y1 == y2) {
            if (!one_piece.bottom) {
                one_piece.bottom_cnt++;
                one_piece.bottom = true;
            }
        } else {
            one_piece.bottom = false;
            bottom_start_time = std::chrono::steady_clock::now();
        }
    }

    void pick() {
        // todo: pick the front of the queue
        cur_id = nq::get();
        one_piece = Piece(id[cur_id], 4, 20, 0, false, 0,
                        std::make_shared<Matrix>(playfield));
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

    void drop() {
        one_piece.drop();
    }

    void hold() {
        if (holded)
            return;
        holded = true;
        if (hold_id == -1) {
            hold_id = cur_id;
            pick();
        } else {
            std::swap(hold_id, cur_id);
            one_piece = Piece(id[cur_id], 4, 20, 0, false, 0,
                            std::make_shared<Matrix>(playfield));
        }
    }

}  // namespace gm