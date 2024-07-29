cmake_minimum_required(VERSION 3.22.1)

project(tetris)

set(CXX_STANDARD 20)

add_executable(main main.cpp terminal_control/terminal_control.cpp utils/utils.cpp draw/draw.cpp control/control.cpp game/game.cpp tetromino/tetromino.cpp piece/piece.cpp)

target_include_directories(main PUBLIC terminal_control)
target_include_directories(main PUBLIC utils)
target_include_directories(main PUBLIC draw)
target_include_directories(main PUBLIC control)
target_include_directories(main PUBLIC game)
target_include_directories(main PUBLIC tetromino)
target_include_directories(main PUBLIC piece)