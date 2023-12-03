#include "BinaryHeap.hpp"
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
    BinaryHeap<int> log_heap;

    /* Build a binary heap in O(log N) time */
    std::cout << "Building heap in O(log N): \n";
    auto start = std::chrono::high_resolution_clock::now();
    for (int i{}; i < input.size(); i++)
        log_heap.insert(input[i]);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start);

    // print first 50
    std::cout << "\nFirst 50 elements: \n";
    std::cout << log_heap.GetHeapArrayString() << '\n';
    
    // number of swaps  
    int log_swaps = log_heap.GetBuildSwaps();
    std::cout << "\nThe total number of swaps: " << log_swaps << '\n';

    // print execution time 
    std::cout << "\nExecution time: " << duration.count() << " nanoseconds.\n";

    /* Build binary heap in O(N) time */
    std::cout << "\n\n\nBuilding heap in O(N): \n";
    start = std::chrono::high_resolution_clock::now();
    BinaryHeap<int> linear_heap(input);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start);

    // print first 50
    std::cout << "\nFirst 50 elements: \n";
    std::cout << linear_heap.GetHeapArrayString() << '\n';
    
    // number of swaps  
    int linear_swaps = linear_heap.GetBuildSwaps();
    std::cout << "\nThe total number of swaps: " << linear_swaps << '\n';

    // print execution time 
    std::cout << "\nExecution time: " << duration.count() << " nanoseconds.\n";

}
