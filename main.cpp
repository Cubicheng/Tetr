#include "control.h"
#include "define.h"
#include "draw.h"
#include "game.h"
#include "tetromino.h"
#include "utils.h"
#include "graphics.h"
#include "music.h"
#include <string>

void init() {
    dw::init();
    gm::init();
    mus::init();
    srand(time(0));
    BeginBatchDraw();
}

void loop() {

    mus::bgm();

    while (gm::running) {

        ut::frame_start_time = GetTickCount();

        cleardevice();

        dw::print_ui();

        gm::keyboard_event();
        gm::process();
        dw::print_next();
        dw::print_hold();
        dw::print_fps();
        dw::print_pps();
        dw::print_points();
        dw::print_time();

        dw::print_frame(gm::frame,60,480);

        FlushBatchDraw();

        ut::frame_sleep();
    }
}

void exit() {
    mus::warning_end();
    MessageBox(GetHWnd(), _T("Å¶°¡°¡ÚÀÚÀ°¡"), _T("ÓÎÏ·½áÊø"), MB_OK);
    EndBatchDraw();
}

int main() {
    init();
    loop();
    exit();
    return 0;
}