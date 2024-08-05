#include "draw.h"
#include <iostream>
#include "next_queue.h"
#include "terminal_control.h"
#include "tetromino.h"
#include "utils.h"
#include "game.h"
#include <string>

#pragma comment(lib,"MSIMG32.LIB")

namespace dw {

    IMAGE block[9];
    IMAGE background;
    IMAGE next_title;
    IMAGE hold_title;

    void init() {
        for (int i = 0; i < 9; i++) {
            std::wstring path = L"resource/block_" + std::to_wstring(i) + L".png";
            loadimage(&block[i], path.c_str(), 30, 30);
        }
        initgraph(1260, 720);

        loadimage(&background, _T("resource/background_picture.png"), 1260, 720);
        loadimage(&next_title, _T("resource/next_title.png"));
        loadimage(&hold_title, _T("resource/hold_title.png"));
    }

    void print_ui() {

        putimage(0, 0, &background);

        setlinestyle(PS_SOLID, 5);

        line(477, 60, 477, 662);
        line(477, 662, 783, 662);
        line(783, 662, 783, 60);

        line(477, 60, 300, 60);
        line(477, 210, 320, 210);
        line(300, 60, 300, 190);
        line(300, 190, 320, 210);

        line(783, 60, 960, 60);
        line(960, 550, 960, 60);
        line(783, 570, 940, 570);
        line(940, 570, 960, 550);


        setlinestyle(PS_DOT, 1);

        for (int x = 480; x <= 750; x += 30) {
            line(x, 60, x, 660);
        }

        for (int y = 60; y <= 630; y += 30) {
            line(480, y, 780, y);
        }
        
        putimage(783, 60, &next_title);
        putimage(300, 60, &hold_title);
    }

    void put_img(int x, int y, IMAGE* img) {
        int w = img->getwidth();
        int h = img->getheight();
        AlphaBlend(GetImageHDC(NULL), x, y, w, h, GetImageHDC(img), 0, 0, w, h,
            { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
    }

    void print_frame(Matrix& frame, int top, int left) {
        // frame x y --> row col
        int row, col;
        for (int x = 0; x < 10; x++) {
            for (int y = 0; y < 22; y++) {
                row = top + (20 - y - 1) * 30;
                col = left + x * 30;    
                if (frame[y][x] > 0)   // colorful block
                    put_img(col, row, &block[frame[y][x]]);
                
                else if (frame[y][x] < 0) {  // shade block
                    put_img(col, row, &block[0]);
                }
            }
        }
    }

    void print_tetromino(Tetromino& t, int top, int left, int index) {
        int delta_x, delta_y;
        if (t[0][0].first != 'I' && t[0][0].first != 'O') delta_x = 15;
        else delta_x = 0;
        if (t[0][0].first == 'I') delta_y = -15;
        else delta_y = 0;
        putimage(left * 30 + delta_x, top * 30 + delta_y, &block[t[0][0].second]);
        for (auto p : t[index]) {
            if (p.first > 'A')
                continue;
            putimage((left + p.first) * 30 + delta_x, (top - p.second) * 30 + delta_y, &block[t[0][0].second]);
        }
    }

    void print_next() {
        for (int i = 0; i < 5; i++) {
            print_tetromino(gm::id[nq::next_queue[i]], 5 + 3 * i, 28, 0);
        }
    }

    void print_hold() {
        if (gm::hold_id == -1) return;
        Tetromino tmp = gm::id[gm::hold_id];
        if (gm::holded) tmp[0][0].second = 8;
        print_tetromino(tmp, 5, 12, 0);
    }
}
