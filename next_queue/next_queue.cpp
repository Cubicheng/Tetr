#include "next_queue.h"

namespace nq {
    std::vector<int> next_queue;
    int pack[7];

    void init() {
        for (int i = 0; i < 7; i++)
            pack[i] = i;
        while (next_queue.size())
            next_queue.erase(next_queue.begin());
        add_new_pack();
    }

    void add_new_pack() {
        std::random_shuffle(pack, pack + 7);
        for (int i = 0; i < 7; i++) {
            next_queue.push_back(pack[i]);
        }
    }

    int get() {
        int tmp = *(next_queue.begin());
        next_queue.erase(next_queue.begin());
        if (next_queue.size() < 5) {
            add_new_pack();
        }
        return tmp;
    }

}  // namespace nq