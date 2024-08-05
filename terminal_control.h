# pragma once

//terminal control
namespace tc{
    void move_cursor_to(int row,int col);
    void hide_cursor();
    void show_cursor();
    void set_fore_color(int id);
    void set_back_color(int id);
    void clean_screen();
    void reset_color();
}