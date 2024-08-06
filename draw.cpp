#include "draw.h"
#include <iostream>
#include "next_queue.h"
#include "tetromino.h"
#include "utils.h"
#include "game.h"
#include <string>

#pragma comment(lib,"MSIMG32.LIB")

namespace dw {

    IMAGE block[10];
    IMAGE background;
    IMAGE next_title;
    IMAGE hold_title;
    IMAGE next_title_warning;
    IMAGE hold_title_warning;


    void init() {
        for (int i = 0; i < 10; i++) {
            std::wstring path = L"resource/block_" + std::to_wstring(i) + L".png";
            loadimage(&block[i], path.c_str(), 30, 30);
        }
        initgraph(1260, 720);

        loadimage(&background, _T("resource/background_picture.png"), 1260, 720);
        loadimage(&next_title, _T("resource/next_title.png"));
        loadimage(&hold_title, _T("resource/hold_title.png"));
        loadimage(&next_title_warning, _T("resource/next_title_warning.png"));
        loadimage(&hold_title_warning, _T("resource/hold_title_warning.png"));
    }

    void print_ui() {

        putimage(0, 0, &background);

        if (gm::warning) setcolor(RGB(255, 0, 0));
        else setcolor(RGB(255, 255, 255));

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
        setcolor(RGB(255, 255, 255));

        for (int x = 480; x <= 750; x += 30) {
            line(x, 60, x, 660);
        }

        for (int y = 60; y <= 630; y += 30) {
            line(480, y, 780, y);
        }
        if (gm::warning) {
            putimage(783, 60, &next_title_warning);
            putimage(300, 60, &hold_title_warning);
        }
        else {
            putimage(783, 60, &next_title);
            putimage(300, 60, &hold_title);
        }
    }

    void put_img(int x, int y, IMAGE* img) {
        int w = img->getwidth();
        int h = img->getheight();
        AlphaBlend(GetImageHDC(NULL), x, y, w, h, GetImageHDC(img), 0, 0, w, h,
            { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
    }

    void print_warning_next_block() {
        Tetromino next_tr = gm::id[nq::next_queue.front()];
        next_tr[0][0].second = 9;
        print_tetromino(next_tr, 1, 20, 0, 0);
    }

    void print_frame(Matrix& frame, int top, int left) {
        if (gm::warning) {
            print_warning_next_block();
        }
        // frame x y --> row col
        int row, col;
        for (int x = 0; x < 10; x++) {
            for (int y = 0; y < 22; y++) {
                row = top + (20 - y - 1) * 30;
                col = left + x * 30;    
                if (frame[y][x] > 0) {   // colorful block
                    put_img(col, row, &block[frame[y][x]]);
                }
                
                else if (frame[y][x] < 0) {  // shade block
                    put_img(col, row, &block[0]);
                }
            }
        }
    }

    void print_tetromino(Tetromino& t, int top, int left, int index, int op) {
        int delta_x = 0, delta_y = 0;
        if (op) {
            if (t[0][0].first != 'I' && t[0][0].first != 'O') delta_x = 15;
            else delta_x = 0;
            if (t[0][0].first == 'I') delta_y = -15;
            else delta_y = 0;
        }
        putimage(left * 30 + delta_x, top * 30 + delta_y, &block[t[0][0].second]);
        for (auto p : t[index]) {
            if (p.first > 'A')
                continue;
            putimage((left + p.first) * 30 + delta_x, (top - p.second) * 30 + delta_y, &block[t[0][0].second]);
        }
    }

    void print_next() {
        for (int i = 0; i < 5; i++) {
            print_tetromino(gm::id[nq::next_queue[i]], 5 + 3 * i, 28, 0, 1);
        }
    }

    void print_hold() {
        if (gm::hold_id == -1) return;
        Tetromino tmp = gm::id[gm::hold_id];
        if (gm::holded) tmp[0][0].second = 8;
        print_tetromino(tmp, 5, 12, 0 ,1);
    }
    void print_fps(){
        static TCHAR text[64];
        _stprintf_s(text, _T("FPS: %d"), ut::fps());
        settextstyle(15, 0, _T("Consolas"));
        setbkmode(TRANSPARENT);
        settextcolor(RGB(255, 255, 255));
        outtextxy(10, 10, text);
    }

    void print_pps() {
        if (gm::warning) settextcolor(RGB(255, 0, 0));
        else settextcolor(RGB(255, 255, 255));

        static TCHAR text[64];

        settextstyle(25, 0, _T("Consolas"));
        _stprintf_s(text, _T("PIECES"));
        setbkmode(TRANSPARENT);
        outtextxy(370, 380, text);

        gm::now_time = GetTickCount();
        DWORD delta = gm::now_time - gm::begin_time;

        settextstyle(40, 0, _T("Consolas"));
        _stprintf_s(text, _T("%d,%.2lf"), gm::cnt_blocks, 1000.0*gm::cnt_blocks/delta);
        setbkmode(TRANSPARENT);
        outtextxy(330, 415, text);
        
    }

    void print_points(){
        if (gm::warning) settextcolor(RGB(255, 0, 0));
        else settextcolor(RGB(255, 255, 255));

        static TCHAR text[64];
        settextstyle(25, 0, _T("Consolas"));

        _stprintf_s(text, _T("LINES"));
        setbkmode(TRANSPARENT);
        outtextxy(380, 480, text);

        _stprintf_s(text, _T("%d"), gm::points);
        settextstyle(40, 0, _T("Consolas"));
        setbkmode(TRANSPARENT);
        if(gm::points<10)
            outtextxy(410, 515, text);
        else 
            outtextxy(400, 515, text);
    }

    void print_time(){
        if (gm::warning) settextcolor(RGB(255, 0, 0));
        else settextcolor(RGB(255, 255, 255));
        gm::now_time = GetTickCount();
        DWORD delta = gm::now_time - gm::begin_time;

        static TCHAR text[64];

        settextstyle(25, 0, _T("Consolas"));
        _stprintf_s(text, _T("TIME"));
        outtextxy(390, 580, text);

        if (delta < 1000)
            _stprintf_s(text, _T("00:00.%d"), delta);
        else if (1000 <= delta && delta < 60000)
            _stprintf_s(text, _T("00:%d.%d"), delta / 1000, delta % 1000);
        else
            _stprintf_s(text, _T("%d:%d.%d"), delta / 60000, (delta % 60000) / 1000, (delta % 60000) % 1000);

        settextstyle(40, 0, _T("Consolas"));
        setbkmode(TRANSPARENT);
        outtextxy(285, 615, text);
    }
}
