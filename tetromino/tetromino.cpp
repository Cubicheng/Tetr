#include "tetromino.h"

namespace gm {

    // Tetromino I{{
    //     {0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0},
    //     {0, 1, 1, 1, 1},
    //     {0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0},
    // }};

    // Tetromino J{{{2, 0, 0}, {2, 2, 2}, {0, 0, 0}}};

    // Tetromino L{{{0, 0, 3}, {3, 3, 3}, {0, 0, 0}}};

    // Tetromino O{{{0, 4, 4}, {0, 4, 4}, {0, 0, 0}}};

    // Tetromino S{{{0, 5, 5}, {5, 5, 0}, {0, 0, 0}}};

    // Tetromino T{{{0, 6, 0}, {6, 6, 6}, {0, 0, 0}}};

    // Tetromino Z{{{7, 7, 0}, {0, 7, 7}, {0, 0, 0}}};

    // std::map<int,Color> tetro_color{
    //     {1,Color::Cyan},
    //     {2,Color::Purple},
    //     {3,Color::Orange},
    //     {4,Color::Yellow},
    //     {5,Color::Green},
    //     {6,Color::Pink},
    //     {7,Color::Red}
    // };

    // Tetromino rotate(Tetromino& t) {
    //     Tetromino result(t.size(), std::vector<int>(t.size(), 0));
    //     for (int i = 0; i < t.size(); i++) {
    //         for (int j = 0; j < t.size(); j++) {
    //             if (t[i][j])
    //                 result[j][t.size() - 1 - i] = t[i][j];
    //         }
    //     }
    //     return std::move(result);
    // }

    Tetromino I{{
        {{{'I', Color::Cyan}, {-1, 0}, {1, 0}, {2, 0}}},   // 0
        {{{'I', Color::Cyan}, {0, 1}, {0, -1}, {0, -2}}},  // R
        {{{'I', Color::Cyan}, {-2, 0}, {-1, 0}, {1, 0}}},  // 2
        {{{'I', Color::Cyan}, {0, 2}, {0, 1}, {0, -1}}}    // L
    }};

    Tetromino J{{
        {{{'J', Color::Purple}, {-1, 1}, {-1, 0}, {1, 0}}},  // 0
        {{{'J', Color::Purple}, {1, 1}, {0, 1}, {0, -1}}},   // R
        {{{'J', Color::Purple}, {-1, 0}, {1, 0}, {1, -1}}},  // 2
        {{{'J', Color::Purple}, {0, 1}, {-1, -1}, {0, -1}}}  // L
    }};

    Tetromino L{{
        {{{'L', Color::Orange}, {-1, 0}, {1, 0}, {1, 1}}},    // 0
        {{{'L', Color::Orange}, {0, 1}, {0, -1}, {1, -1}}},   // R
        {{{'L', Color::Orange}, {-1, -1}, {-1, 0}, {1, 0}}},  // 2
        {{{'L', Color::Orange}, {-1, 1}, {0, 1}, {0, -1}}}    // L
    }};

    Tetromino O{{
        {{{'O', Color::Yellow}, {0, 1}, {1, 1}, {1, 0}}},    // 0
        {{{'O', Color::Yellow}, {0, -1}, {1, 0}, {1, -1}}},   // R
        {{{'O', Color::Yellow}, {-1, -1}, {-1, 0}, {0, -1}}},  // 2
        {{{'O', Color::Yellow}, {-1, 1}, {-1, 0}, {0, 1}}}    // L
    }};

    Tetromino S{{
        {{{'S', Color::Green}, {-1, 0}, {0, 1}, {1, 1}}},    // 0
        {{{'S', Color::Green}, {0, 1}, {1, 0}, {1, -1}}},   // R
        {{{'S', Color::Green}, {-1, -1}, {0, -1}, {1, 0}}},  // 2
        {{{'S', Color::Green}, {-1, 1}, {-1, 0}, {0, -1}}}    // L
    }};

    Tetromino T{{
        {{{'T', Color::Pink}, {-1, 0}, {0, 1}, {1, 0}}},    // 0
        {{{'T', Color::Pink}, {0, 1}, {1, 0}, {0, -1}}},   // R
        {{{'T', Color::Pink}, {-1, 0}, {1, 0}, {0, -1}}},  // 2
        {{{'T', Color::Pink}, {-1, 0}, {0, 1}, {0, -1}}}    // L
    }};

    Tetromino Z{{
        {{{'Z', Color::Red}, {-1, 1}, {0, 1}, {1, 0}}},    // 0
        {{{'Z', Color::Red}, {1, 1}, {1, 0}, {0, -1}}},   // R
        {{{'Z', Color::Red}, {-1, 0}, {0, -1}, {1, -1}}},  // 2
        {{{'Z', Color::Red}, {-1, -1}, {-1, 0}, {0, 1}}}    // L
    }};

}  // namespace gm