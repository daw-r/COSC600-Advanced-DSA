/*
Filename: problem2.cc

Author: Devere Anthony Weaver 

Assignment: Programming Assignment 3
Problem: Problem 2

Description: This program implements insertion sort, selection sort, bubble 
sort, and merge sort algorithms on a list of 5,000 randomly generated elements.
*/

#include <iostream> 
#include <vector>
#include <random>
#include <chrono>
#include <string>

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

template<typename T>
void insertion_sort(std::vector<T> vec)
{
    /* Simple insertion sort implementation without any explicit swapping */
    int j{};

    auto start = std::chrono::high_resolution_clock::now();
    for (int p = 1; p < vec.size(); p++)
    {
        auto temp = vec[p];

        for(j = p; (j > 0) && temp < vec[j - 1]; j--)
            vec[j] = vec[j-1];
        vec[j] = temp;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
    print_vector(vec, 100); std::cout << '\n';
    std::cout << "Insertion sort execution time: " << duration.count() 
              << " miliseconds(s).\n";
}

template<typename T>
void selection_sort(std::vector<T> vec)
{
    int smallest_index{};
    T temp{};

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < vec.size(); i++)
    {
        smallest_index = i;

        // search for smallest element index in unsorted portion
        for (int j = i + 1; j < vec.size(); j++)
        {
            if (vec[j] < vec[smallest_index])
                smallest_index = j;
        }

        // put smallest in proper sequence order 
        temp = vec[i];
        vec[i] = vec[smallest_index];
        vec[smallest_index] = temp;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
    print_vector(vec, 100); std::cout << '\n';
    std::cout << "Selection sort execution time: " << duration.count() 
              << " miliseconds(s).\n";
}

template<typename T>
void merge(std::vector<T>& vec, std::vector<T>& temp, int left, int right, 
          int right_end)
{
    int left_end = right - 1;
    int temp_position = left;
    int n = right_end - left + 1;

    while (left <= left_end && right <= right_end)
    {
        if (vec[left] <= vec[right])
            temp[temp_position++] = vec[left++];
        else 
            temp[temp_position++] = vec[right++];
    }

    while (left <= left_end) 
        temp[temp_position++] = vec[left++];

    while(right <= right_end)
        temp[temp_position++] = vec[right++];

    for (int i = 0; i < n; i++, right_end--)
        vec[right_end] = temp[right_end];
}

template<typename T>
void merge_sort(std::vector<T>& vec, std::vector<T>& temp, int left, int right)
{
    if (left < right)
    {
        int center = (left + right) / 2;
        merge_sort(vec, temp, left, center);
        merge_sort(vec, temp, center + 1, right);
        merge(vec, temp, left, center + 1, right);
    }
}

template<typename T>
void merge_sort(std::vector<T> vec)
{
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<T> temp(vec.size());
    merge_sort(vec, temp, 0, vec.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
    print_vector(vec, 100); std::cout << '\n';
    std::cout << "Merge sort execution time: " << duration.count() 
              << " miliseconds(s).\n";
}

template<typename T>
void bubble_sort(std::vector<T> vec)
{
    auto start = std::chrono::high_resolution_clock::now();
    for (int i{}; i < vec.size() - 1; i++)
    {
        for (int j{}; j < vec.size() - i - 1; j++) 
        {
            if (vec[j] > vec[j+1])
            {
                T temp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = temp;
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
    print_vector(vec, 100); std::cout << '\n';
    std::cout << "Bubble sort execution time: " << duration.count() 
              << " miliseconds(s).\n";
}

int main()
{
    std::vector<int>v = generate_random(0, 50000, 5000);
    std::cout << "Unsorted (first 100):\n"; print_vector(v, 100); std::cout << '\n';
    std::cout << std::string(100, '-') << '\n';
    std::cout << "Insertion sort (first 100):\n"; insertion_sort(v); std::cout << '\n';
    std::cout << std::string(100, '-') << '\n';
    std::cout << "Selection sort (first 100):\n"; selection_sort(v); std::cout << '\n';
    std::cout << std::string(100, '-') << '\n';
    std::cout << "Merge sort (first 100):\n"; merge_sort(v); std::cout << '\n';
    std::cout << std::string(100, '-') << '\n';
    std::cout << "Bubble sort (first 100):\n"; bubble_sort(v); std::cout << '\n';
}