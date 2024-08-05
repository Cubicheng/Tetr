# pragma once
# include "define.h"

//show information about the game running
namespace ut{

    int fps();

    inline int b2c(int b) {
        return 2*b - 1;
    }

    bool timer(std::chrono::microseconds sec);

    int my_rand(int i);

    extern DWORD frame_start_time;
    extern DWORD frame_end_time;
    extern DWORD frame_time;

    void frame_sleep();
}