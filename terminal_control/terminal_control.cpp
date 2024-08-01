#include "terminal_control.h"
#include <iostream>
#include <windows.h>

#define CSI "\033["

void tc::move_cursor_to(int row, int col) {
    std::cout << CSI << row << ';' << col << 'H';
}

void tc::hide_cursor() {
    std::cout << CSI << "?25l";
}

void tc::show_cursor() {
    std::cout<< CSI << "?25h";
}

void tc::set_fore_color(int id) {
    std::cout << CSI << "38;5;" << id << 'm';
}

void tc::set_back_color(int id) {
    std::cout << CSI << "48;5;" << id << 'm';
}

void tc::clean_screen() {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//在C语言中表示：从bai一个du特定的标
    COORD pos;                                      //  准zhi设备dao（标准输出）中取得一个句柄（用来标识不同设备的数值）。 
    pos.X = 0;
    pos.Y = 0;//COORD pos = {x,y}; //定义COORD结构的实bai例pos，初始化参数用x和y，即dupos.x=x; pos.y=y;
    SetConsoleCursorPosition(handle,pos);
}

void tc::reset_color() {
    std::cout << CSI << "0m";
}
