#include "utils.h"
#include "..//define.h"

int ut::fps() {
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

std::string ut::utf32_to_utf8(std::u32string str) {
    static std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> convert;
    return convert.to_bytes(str);
}

bool ut::timer(std::chrono::microseconds sec) {
    static auto start_time = std::chrono::steady_clock::now();
    auto end_time = std::chrono::steady_clock::now();
    if (end_time - start_time > sec) {
        start_time = end_time;
        return true;
    }
    return false;
}

int ut::my_rand(int i) {
    return std::rand()%i;
}
