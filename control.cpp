#include "control.h"
#include "define.h"
#include "game.h"

namespace gm {

    char command;

    ExMessage msg;

    int opt = -1;
    DWORD start_time = GetTickCount(), end_time;


    std::map<int,std::function<void()>> comm_func{
        {0x51,command_quit},
        {0x5A,command_left_rotate},
        {0x58,command_right_rotate},
        {VK_UP,command_right_rotate},
        {VK_LEFT,command_left},
        {VK_DOWN,command_down},
        {VK_RIGHT,command_right},
        {VK_SPACE,command_drop},
        {VK_SHIFT,command_hold}
    };

    void keyboard_event() {
        while (peekmessage(&msg)) {
            if (msg.message == WM_KEYDOWN) {
                if (msg.vkcode == VK_LEFT || msg.vkcode == VK_RIGHT || msg.vkcode == VK_DOWN) {
                    
                    if (opt == -1) start_time = GetTickCount();
                    else {
                        end_time = GetTickCount();
                        if (end_time - start_time > 10) comm_func[opt]();
                    }

                    opt = msg.vkcode;
                }
            }
            else if (msg.message == WM_KEYUP) {
                opt = -1;
                if (comm_func.find(msg.vkcode) != comm_func.end())
                    comm_func[msg.vkcode]();
            }
        }
        
    }

    void start_listner() {
        std::thread t(gm::keyboard_event);
        t.detach();
    }

    void command_quit() {
        quit();
    }

    void command_left() {
        left();
    }

    void command_right() {
        right();
    }

    void command_down() {
        down();
    }

    void command_left_rotate() {
        left_rotate();
    }

    void command_right_rotate() {
        right_rotate();
    }

    void command_drop(){
        drop();
    }

    void command_hold(){
        hold();
    }

}  // namespace gm
