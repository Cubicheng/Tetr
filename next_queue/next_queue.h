# pragma once
# include "..//define.h"

namespace nq{
    extern std::queue<int> next_queue;
    extern int pack[7];
    int get();
    void pop();
    void init();
    void add_new_pack();
    }  // namespace nq