#include "control.h"
#include "define.h"
#include "draw.h"
#include "game.h"
#include "terminal_control.h"
#include "tetromino.h"
#include "utils.h"

void init() {
    #ifdef _WIN32
        system("chcp 65001");
    #endif

    tc::hide_cursor();
    gm::start_listner();
    gm::init();
    srand(time(0));
}

void loop() {

    while (gm::running) {
        tc::clean_screen();

        gm::process();
        dw::create_block(1, 1, 9, 6, "HOLD");
        dw::create_block(1, 10, 12, 22, "TETR");
        dw::create_block(7, 1, 9, 16, "STATUS");
        dw::create_block(19, 22, 8, 4, "INFO");
        dw::create_block(1, 22, 8, 18, "NEXT");
        dw::print_next();
        dw::print_hold();


        tc::reset_color();
        tc::move_cursor_to(10, 7);
        std::cout << "FPS: " << ut::fps();

        tc::move_cursor_to(12, 5);
        std::cout << "POINTS: " << gm::points;

        dw::print_frame(gm::frame,1,11);

        std::cout << std::flush;
        tc::reset_color();
        std::this_thread::sleep_for(50ms);
    }
}

void exit() {
    tc::show_cursor();
    tc::reset_color();
    tc::clean_screen();
    tc::move_cursor_to(0, 0);
    tc::set_fore_color(9);
    std::cout << "Bye!\n";
}

int main() {
    init();
    loop();
    exit();
    return 0;
}