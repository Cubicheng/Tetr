#include "control.h"
#include "define.h"
#include "draw.h"
#include "game.h"
#include "terminal_control.h"
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

    while (gm::running) {

        ut::frame_start_time = GetTickCount();

        cleardevice();

        dw::print_ui();

        gm::keyboard_event();
        gm::process();
        dw::print_next();
        dw::print_hold();

        dw::print_frame(gm::frame,60,480);

        FlushBatchDraw();

        ut::frame_sleep();
    }
}

void exit() {
    tc::show_cursor();
    tc::reset_color();
    tc::clean_screen();
    tc::move_cursor_to(0, 0);
    tc::set_fore_color(9);
    std::cout << "Bye!\n";
    EndBatchDraw();
}

int main() {
    init();
    loop();
    exit();
    return 0;
}