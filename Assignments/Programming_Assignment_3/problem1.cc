#include "BinaryHeap.hpp"
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v{5, 4, 3, 2, 1};

    BinaryHeap<int> bh(v);
    std::cout << bh.GetCurrentSize() << '\n';
    std::cout << bh.GetHeapArrayString() << '\n';
}