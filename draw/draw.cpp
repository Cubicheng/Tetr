#include "draw.h"
#include <iostream>
#include "next_queue.h"
#include "terminal_control.h"
#include "tetromino.h"
#include "utils.h"
#include "game.h"

void dw::create_block(int top,
                      int left,
                      int width,
                      int height,
                      const std::string& title) {
#define ch(a, b) ut::utf32_to_utf8({cur_style[a], cur_style[b]})

    //                              0123456
    const std::u32string style1 = U" ┌┐└┘│─";
    const std::u32string style2 = U" ╔╗╚╝║═";
    const std::u32string style3 = U" ┏┓┗┛┃━";
    const std::u32string style4 = U" ╭╮╰╯│─";
    const std::u32string cur_style = style4;

    tc::move_cursor_to(top, ut::b2c(left));

    // first row
    std::cout << ch(0, 1);
    for (int c = 1; c < width - 1; c++)
        std::cout << ch(6, 6);
    std::cout << ch(2, 0) << '\n';

    // normal row
    for (int r = 1; r < height - 1; r++) {
        tc::move_cursor_to(top + r, ut::b2c(left));
        std::cout << ch(0, 5);
        for (int c = 1; c < width - 1; c++) {
            std::cout << ch(0, 0);
        }
        std::cout << ch(5, 0);
    }

    // last row
    tc::move_cursor_to(top + height - 1, ut::b2c(left));
    std::cout << ch(0, 3);
    for (int c = 1; c < width - 1; c++)
        std::cout << ch(6, 6);
    std::cout << ch(4, 0) << '\n';

    // title
    tc::move_cursor_to(top, ut::b2c(left) + (width * 2 - title.length()) / 2);
    std::cout << title;
}

// void dw::print_tetromino(gm::Tetromino& t, int top, int left) {
//     int color=-1;
//     for (int i = 0; i < t.size(); i++) {
//         tc::move_cursor_to(top + i, ut::b2c(left));
//         for (int j = 0; j < t.size(); j++) {
//             if (t[i][j]) {
//                 if(color==-1) color = gm::tetro_color[t[i][j]];
//                 tc::set_back_color(color);
//             } else
//                 tc::reset_color();
//             std::cout<<"  ";
//         }
//     }
// }

void dw::print_frame(Matrix& frame, int top, int left) {
    // frame x y --> row col
    int row, col;
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 20; y++) {
            row = top + 20 - y - 1;
            col = left + x;
            tc::move_cursor_to(top + row, ut::b2c(col));
            if (frame[y][x] > 0) {  // colorful block
                tc::reset_color();
                tc::set_back_color(frame[y][x]);
                std::cout << "  ";
            } else if (frame[y][x] < 0) {  // shade block
                tc::reset_color();
                tc::set_back_color(-frame[y][x]);
                std::cout << "\u25e3\u25e5";
            } else {  // blank
                tc::reset_color();
                std::cout << "\u30FB";
            }
        }
    }
}

void dw::print_tetromino(Tetromino& t, int top, int left, int index) {
    tc::move_cursor_to(top, ut::b2c(left));
    tc::set_back_color(t[index][0].second);
    std::cout << "  ";
    for (auto p : t[index]) {
        if (p.first > 'A')
            continue;
        tc::move_cursor_to(top - p.second, ut::b2c(left + p.first));
        std::cout << "  ";
    }
}

void dw::print_next() {
    for (int i = 0; i < 5; i++) {
        print_tetromino(gm::id[nq::next_queue[i]],4+3*i,25,0);
    }
}

void dw::print_hold() {
    print_tetromino(gm::id[gm::hold_id],4,5,0);

}
