#include <iostream>
#include <random>
#include <chrono>

template <typename T>
void print_vector(std::vector<T> &vec)
{
    std::cout << "(";
    for (int i{}; i < vec.size(); i += 100)
    {
        if (i == 4900)
            std::cout << vec[i] << ")\n";
        else 
            std::cout << vec[i] << ", ";
    }
}

template <typename T>
void countSort(std::vector<T> &vec)
{
    std::vector<int> output(vec.size());
    std::vector<int> count(vec.size());
    int max{vec[0]};

    // Find the largest element of the array
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] > max)
            max = vec[i];
    }

    // Store the count of each element
    for (int i = 0; i < vec.size(); i++)
    {
        count[vec[i]]++;
    }

    // Store the cumulative count of each array
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    // Find the index of each element of the original array in count array, and
    // place the elements in output array
    for (int i = vec.size() - 1; i >= 0; i--)
    {
        output[count[vec[i]] - 1] = vec[i];
        count[vec[i]]--;
    }

    // Copy the sorted elements into original array
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i] = output[i];
    }

    print_vector(vec);
}

std::vector<int> generate_random(int low, int high, int n)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(low, high);
    std::vector<int> v{};
    for (int i = 0; i < n; i++)
        v.push_back(distr(gen));
    return v;
}

int main()
{
    std::cout << "Count Sort:\n";
    std::vector<int> vec = generate_random(0, 500, 5000);
    std::cout << "Input (every 100th): ";
    print_vector(vec);
    std::cout << "\nOutput (every 100th): ";
    auto start = std::chrono::high_resolution_clock::now();
    countSort(vec);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "\n\nExecution time: " << duration.count() << " nanoseconds.\n";
}