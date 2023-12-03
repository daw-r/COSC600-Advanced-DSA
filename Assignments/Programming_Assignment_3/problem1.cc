#include "BinaryHeap.hpp"
#include <vector>
#include <iostream>

int main()
{
    auto bh = BinaryHeap<int>(100);
    std::vector<int> input{5, 4, 3, 2, 1};
    // for (int i{}; i < input.size(); i++)
    //     bh.insert(input[i]);
    bh.insert(5);
//    bh.insert(4);
    // bh.insert(1);
    // bh.insert(1);
    // bh.insert(1);

    bh.print_heap();
}