#pragma once

#include <assert.h>
#include <algorithm>
#include <array>
#include <chrono>
#include <codecvt>
#include <functional>
#include <iostream>
#include <locale>
#include <map>
#include <memory>
#include <thread>
#include <vector>
#include <windows.h>
#include <conio.h>

# ifdef __linux__
#include <termios.h>
# endif

using namespace std::chrono_literals;
using Matrix = std::vector<std::vector<int>>;
using Tetromino = std::array<std::array<std::pair<int, int>, 4>, 4>;
using Offset = std::array<std::vector<std::pair<int, int>>, 4>;

#define KEY_QUIT 'q'
#define KEY_DOWN 'k'
#define KEY_LEFT_ROTATE 'z'
#define KEY_RIGHT_ROTATE 'x'
#define KEY_LEFT 'j'
#define KEY_RIGHT 'l'
#define KEY_UP 'i'
#define KEY_DROP 'm'
#define KEY_HOLD 'a'
