#pragma once
#include "..//define.h"
#include "..//color.h"

namespace gm {

    
    extern Tetromino I,L,J,T,O,S,Z;

    Tetromino rotate(Tetromino &t);

    extern std::map<int,Color> tetro_color;

}  // namespace gm