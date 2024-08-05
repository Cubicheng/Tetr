#include "piece.h"
#include "next_queue.h"

namespace gm {

    std::vector<std::pair<int, int> > kick_transation(5);

    Piece::Piece(Tetromino& t,
                int x0,
                int y0,
                int i,
                bool bt,
                int bt_cnt,
                std::shared_ptr<Matrix> p_pf)
        : tetr_set(t),
        x(x0),
        y(y0),
        index(i),
        bottom(bt),
        bottom_cnt(bt_cnt),
        p_playfiled(p_pf) {}

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
        rotate(3);
    }

    void Piece::right_rotate() {
        rotate(1);
    }

    void Piece::rotate(int op) {
        int new_index = (index + op) % 4;
        Offset offset;
        if (tetr_set[0][0].first == 'I')
            offset = offset_I;
        else if(tetr_set[0][0].first == 'O')
            offset = offset_O;
        else 
            offset = offset_normal;
        for (int i = 0; i < 5; i++) {
            kick_transation[i].first = offset[index][i].first - offset[new_index][i].first;
            kick_transation[i].second = offset[index][i].second - offset[new_index][i].second;
        }
        std::swap(index, new_index);
        for (int i = 0; i < 5; i++) {
            int xx = x + kick_transation[i].first;
            int yy = y + kick_transation[i].second;
            if (test(xx, yy)) {
                x = xx;
                y = yy;
                return;
            }
        }
        // fail to rotate
        std::swap(index, new_index);
    }

    void Piece::drop() {
        bottom_cnt = 114514;
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