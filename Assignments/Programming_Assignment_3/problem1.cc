#include "BinaryHeap.hpp"
#include <vector>
#include <iostream>

int main()
{
    MaxHeap mx;
    std::vector<int>v{1,2,3,4,5};
    for (int i{}; i < v.size(); i++)
        mx.Insert(v[i]);
    std::cout << mx.GetHeapArrayString() << '\n';

}