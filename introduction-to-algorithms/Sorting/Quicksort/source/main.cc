#include <iostream>
#include "Quicksort.h"
#include <catch2/catch_test_macros.hpp>
#include <vector>

template <typename T>
void print(const T &list)
{
    /* tempalted printing function to print STL containers */
    std::cout << "( ";
    for (auto element : list)
        std::cout << element << " ";
    std::cout << ")\n";
}

TEST_CASE("Partition Test")
{
    /* Test to see if patition is implemented correctly by checking if it
     returns the correct pivot index */

    SECTION("Regular test")
    {
        std::vector<int> vec{2, 8, 7, 1, 3, 5, 6, 4};
        int q = Quicksort::partition(vec, 0, 7);
        REQUIRE(q == 3);
    }
    SECTION("All elements have the same value")
    {
        /* When a list has elements with all the same value, Partition()
        will return the last element in the list as the pivot because there
        are  no changes made to the list */
        std::vector<int> vec{2, 2, 2, 2, 2, 2, 2, 2, 2};
        int q = Quicksort::partition(vec, 0, 8);
        REQUIRE(q == 8);
    }
}

TEST_CASE("Quicksort Test")
{
    /* Test to see if quicksort algorithm properly sorts a given list */
    SECTION("Vector")
    {
        std::vector<int> vec{2, 8, 7, 1, 3, 5, 6, 4};
        std::vector<int> sorted{1, 2, 3, 4, 5, 6, 7, 8};
        std::cout << "Unsorted vector: ";
        print(vec);
        Quicksort::quicksort(vec, 0, 7);
        std::cout << "Sorted vector: ";
        print(vec);
        bool flag = true;
        for (int i{}; i < vec.size(); i++)
        {
            if (vec[i] != sorted[i])
                flag = false;
        }
        REQUIRE(flag == true);
    }
    SECTION("Array")
    {
        int arr[] = {2, 8, 7, 1, 3, 5, 6, 4};
        int arrSize = 8;
        int sorted[] = {1, 2, 3, 4, 5, 6, 7, 8};
        std::cout << "\n\nUnsorted array: ";
        print(arr);
        Quicksort::quicksort(arr, 0, 7);
        std::cout << "Sorted array: ";
        print(arr);
        bool flag = true;
        for (int i{}; i < 8; i++)
        {
            if (arr[i] != sorted[i])
                flag = false;
        }
        REQUIRE(flag == true);
    }
    SECTION("Decreasing order")
    {
        std::vector<int> vec{2, 8, 7, 1, 3, 5, 6, 4};
        std::vector<int> sorted{8, 7, 6, 5, 4, 3, 2, 1};
        std::cout << "\n\nUnsorted vector: ";
        print(vec);
        Quicksort::quicksort(vec, 0, 7, true);
        std::cout << "Sorted vector: ";
        print(vec);
        bool flag = true;
        for (int i{}; i < vec.size(); i++)
        {
            if (vec[i] != sorted[i])
                flag = false;
        }
        REQUIRE(flag == true);
    }
}
