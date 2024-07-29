# pragma once

#include <termios.h>
#include <chrono>
#include <iostream>
#include <thread>
#include <map>
#include <functional>
#include <chrono>
#include <codecvt>
#include <locale>
#include <vector>
#include <array>
#include <memory>
#include <assert.h>

using namespace std::chrono_literals;
using Matrix = std::vector<std::vector<int>>;
using Tetromino = std::array<std::array<std::pair<int,int>,4>,4>;

# define KEY_QUIT 'q'
# define KEY_DOWN 'k'
# define KEY_LEFT_ROTATE 'z'
# define KEY_RIGHT_ROTATE 'x'
# define KEY_LEFT 'j'
# define KEY_RIGHT 'l'
# define KEY_UP 'i'
# define KEY_DROP 'm'


