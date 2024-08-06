#include "utils.h"
#include "define.h"

namespace ut {
    DWORD frame_start_time;
    DWORD frame_end_time;
    DWORD frame_time;
    

    int fps() {
        static auto start_time = std::chrono::steady_clock::now();
        static int frame_count = 0;
        static int fps;
        frame_count++;
        auto end_time = std::chrono::steady_clock::now();
        if (end_time - start_time > 1s) {
            fps = frame_count;
            frame_count = 0;
            start_time = end_time;
        }
        return fps;
    }

    bool timer(DWORD sec) {
        static DWORD start_time = GetTickCount();
        DWORD end_time = GetTickCount();
        if (end_time - start_time > sec) {
            start_time = end_time;
            return true;
        }
        return false;
    }

    int my_rand(int i) {
        return std::rand() % i;
    }

    void frame_sleep(){
        frame_end_time = GetTickCount();
        frame_time = frame_end_time - frame_start_time;
        if (frame_time < 1000 / 120) {
            Sleep(1000 / 120 - frame_time);
        }
    }
}
