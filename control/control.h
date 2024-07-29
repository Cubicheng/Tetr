#pragma once

namespace gm {
    extern char command;
    char getch();
    void keyboard_event();
    void start_listner();

    // keyborad commmand function
    void command_quit();
    void command_left();
    void command_right();
    void command_down();
    void command_left_rotate();
    void command_right_rotate();
    void command_drop();
    }  // namespace gm