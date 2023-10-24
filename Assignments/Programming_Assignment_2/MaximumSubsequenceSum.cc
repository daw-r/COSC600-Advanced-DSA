/* MaximumSubsequenceSum.cc - four different solutions to the maximum 
subsequence sum problem */
#include <iostream>
#include <vector>
#include <random>
#include <chrono>

template<typename T>
void print_vector(const std::vector<T>& vec) 
{
    for (size_t i{}; i < vec.size(); i++)
        std::cout << vec[i] << ' ';
    std::cout << '\n';
}

template<typename T>
int Max_Sub_Sum_Cubic(const std::vector<T>& vec)
{
    /* Cubic runtime implementation of maximum subsequence sum problem */
    int maximum_sum{};
    for (size_t i{}; i < vec.size(); i++)    // n
    {
        for (size_t j{i}; j < vec.size(); j++)    // n
        {
            int this_sum{}; 

            for (size_t k{i}; k <= j; k++)    // n
                this_sum += vec[k];

            if (this_sum > maximum_sum)
                maximum_sum = this_sum;
        }
    }
    return maximum_sum;
}


int main() 
{
    std::vector<int> input_vec{};
    std::vector<int> test_vec{-2, 11, -4, 13, -5, -2};

    /* Generate random integers in [-5000, 5000] */
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(-5000, 5000); // define the range
    for(int n=0; n<5000; ++n)
        input_vec.push_back(distr(gen));
    
    /* WORK WITH TEST_VEC FOR NOW UNTIL CORRECT */
    std::cout << "CUBIC RUNTIME\n";
    //std::cout << "Input: "; print_vector(input_vec);
    auto start = std::chrono::high_resolution_clock::now();
    int max = Max_Sub_Sum_Cubic(input_vec);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Output: " << max << '\n';
    std::cout << "Execution time: " << duration.count() << " milisecond(s).\n";

}

