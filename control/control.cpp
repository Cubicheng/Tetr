#include "control.h"
#include "..//define.h"
#include "..//game//game.h"

namespace gm {

    char command;

    std::map<char,std::function<void()>> comm_func{
        {KEY_QUIT,command_quit},
        {KEY_LEFT_ROTATE,command_left_rotate},
        {KEY_RIGHT_ROTATE,command_right_rotate},
        {KEY_UP,command_right_rotate},
        {KEY_LEFT,command_left},
        {KEY_DOWN,command_down},
        {KEY_RIGHT,command_right},
        {KEY_DROP,command_drop},
        {KEY_HOLD,command_hold}
    };

    #ifdef __linux__
    char getch() {
        char c;
        struct termios old, cur;
        tcgetattr(0, &cur);
        old = cur;
        cfmakeraw(&cur);
        tcsetattr(0, 0, &cur);
        c = getchar();
        tcsetattr(0, 0, &old);
        return c;
    }
    #endif

    void keyboard_event() {
        while (running) {
            command = _getch();
            if(comm_func.find(command)!=comm_func.end())
                comm_func[command]();
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
