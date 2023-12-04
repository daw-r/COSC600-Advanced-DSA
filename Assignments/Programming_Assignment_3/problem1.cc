/* Filename: problem1.cc
 *
 * Author: Devere Anthony Weaver 
 * 
 * Assignment: Programming Assignment 3
 * Problem: Problem 1
 * 
 * Description: This program implements min-heap building algorithms for both 
 * O(log N) and O(N) time. 
*/

#include "MinHeap.hpp"
#include <vector>
#include <iostream>
#include <random>

template<typename T>
void print_vector(std::vector<T>& vec, int n)
{
    std::cout << "(";
    for (int i{}; i < n; i++)
    {
        if (i == n - 1)
            std::cout << vec[i] << ")\n";
        else
            std::cout << vec[i] << ", ";
    }
}

std::vector<int> generate_random(int low, int high, int n)
{
    // generate 5,000 random numbers 
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(low,high);
    std::vector<int> v{};
    for (int i = 0; i < n; i++)
        v.push_back(distr(gen));
    return v;
}

int main()
{
    std::vector<int> input = generate_random(0, 50000, 5000);
    MinHeap<int> log_heap;

    /* Build a binary heap in O(log N) time */
    std::cout << "Building heap in O(log N): \n";
    auto start = std::chrono::high_resolution_clock::now();
    for (int i{}; i < input.size(); i++)
        log_heap.insert(input[i]);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start);
    std::cout << "\nFirst 50 elements: \n";
    std::cout << log_heap.get_heap_array_string(50) << '\n';
    int log_swaps = log_heap.get_build_swaps();
    std::cout << "\nThe total number of swaps: " << log_swaps << '\n';
    std::cout << "\nExecution time: " << duration.count() << " nanoseconds.\n";

    /* Build binary heap in O(N) time */
    std::cout << "\n\n\nBuilding heap in O(N): \n";
    start = std::chrono::high_resolution_clock::now();
    MinHeap<int> linear_heap(input);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start);
    std::cout << "\nFirst 50 elements: \n";
    std::cout << linear_heap.get_heap_array_string(50) << '\n';
    int linear_swaps = linear_heap.get_build_swaps();
    std::cout << "\nThe total number of swaps: " << linear_swaps << '\n';
    std::cout << "\nExecution time: " << duration.count() << " nanoseconds.\n";

}
