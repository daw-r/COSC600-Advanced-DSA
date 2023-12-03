#include <catch2/catch_test_macros.hpp>
#include "BinaryHeap.hpp"

TEST_CASE("Build heap in linear time")
{
    std::vector<int> v{5, 4, 3, 2, 1};
    BinaryHeap<int> linear_heap(v);
    
    SECTION("correct heap array size")
    {
        REQUIRE(linear_heap.GetCurrentSize() == 5);
        REQUIRE(linear_heap.GetBuildSwaps() == 3);
    }

    SECTION("correct min heap order")
    {
        REQUIRE(linear_heap.GetHeapArrayString() == "[1, 2, 3, 5, 4]");
    }
}

TEST_CASE("Build heap in O(log N) time")
{
    BinaryHeap<int> log_heap;
    std::vector<int> v{5, 4, 3, 2, 1};
    for (int i{}; i < v.size(); i++)
        log_heap.insert(v[i]);
    
    SECTION("correct heap array size")
    {
        REQUIRE(log_heap.GetCurrentSize() == 5);
        REQUIRE(log_heap.GetBuildSwaps() == 6);
    }

    SECTION("correct min heap order")
    {
        REQUIRE(log_heap.GetHeapArrayString() == "[1, 2, 4, 5, 3]");
    }
}