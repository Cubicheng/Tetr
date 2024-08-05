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
#include <algorithm>
#include <conio.h>
#include <graphics.h>

using namespace std::chrono_literals;
using Matrix = std::vector<std::vector<int>>;
using Tetromino = std::array<std::array<std::pair<int, int>, 4>, 4>;
using Offset = std::array<std::vector<std::pair<int, int>>, 4>;
