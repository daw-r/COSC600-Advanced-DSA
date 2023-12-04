#include <catch2/catch_test_macros.hpp>
#include "MinHeap.hpp"

TEST_CASE("Build heap in linear time")
{
    std::vector<int> v{5, 4, 3, 2, 1};
    MinHeap<int> linear_heap(v);
    
    SECTION("correct heap array size")
    {
        REQUIRE(linear_heap.get_current_size() == 5);
        REQUIRE(linear_heap.get_build_swaps() == 3);
    }

    SECTION("correct min heap order")
    {
        REQUIRE(linear_heap.get_heap_array_string(5) == "[1, 2, 3, 5, 4]");
    }
}

TEST_CASE("Build heap in O(log N) time")
{
    MinHeap<int> log_heap;
    std::vector<int> v{5, 4, 3, 2, 1};
    for (int i{}; i < v.size(); i++)
        log_heap.insert(v[i]);
    
    SECTION("correct heap array size")
    {
        REQUIRE(log_heap.get_current_size() == 5);
        REQUIRE(log_heap.get_build_swaps()== 6);
    }

    SECTION("correct min heap order")
    {
        REQUIRE(log_heap.get_heap_array_string(5) == "[1, 2, 4, 5, 3]");
    }
}