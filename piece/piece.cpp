#include "piece.h"
#include "next_queue.h"

namespace gm {

    Piece::Piece(Tetromino& t,
                int x0,
                int y0,
                int i,
                bool bt,
                std::shared_ptr<Matrix> p_pf)
        : tetr_set(t), x(x0), y(y0), index(i), bottom(bt), p_playfiled(p_pf) {}

    void Piece::down() {
        if (test(x, y - 1))
            y--;
    }

    void Piece::left() {
        if (test(x - 1, y))
            x--;
    }

    void Piece::right() {
        if (test(x + 1, y))
            x++;
    }

    void Piece::left_rotate() {
        index = (index + 1) % 4;
    }

    void Piece::right_rotate() {
        index = (index + 3) % 4;
    }

    void Piece::drop() {
        bottom = true;
    }

    bool Piece::test(int ox, int oy) {
        for (int i = 0; i < 4; i++) {
            auto [dx, dy] = get_mino(i);
            int xx = ox + dx;
            int yy = oy + dy;
            // boundary
            if (xx < 0 || xx > (*p_playfiled)[0].size() - 1 || yy < 0 ||
                yy > (*p_playfiled).size() - 1)
                return false;
            if ((*p_playfiled)[yy][xx] > 0)
                return false;
        }
        return true;
    }

    std::pair<int, int> Piece::get_mino(int i) {
        assert(0 <= i && i < 4);
        if (i == 0)
            return std::make_pair(0, 0);

        return tetr_set[index][i];
    }

    std::pair<int, int> Piece::get_xy() {
        return std::pair<int, int>(x, y);
    }

    int Piece::get_color() {
        return tetr_set[index][0].second;
    }

}  // namespace gm