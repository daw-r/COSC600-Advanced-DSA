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

template<typename T>
int Max_Sub_Sum_Quadratic(const std::vector<T>& vec) 
{
    int maximum_sum{};

    for (size_t i{}; i < vec.size(); i++)
    {
        int this_sum{};
        for (size_t j{i}; j < vec.size(); j++)
        {
            this_sum += vec[j];

            if (this_sum > maximum_sum)
            maximum_sum = this_sum;
        }
    }
    return maximum_sum;
}

template<typename T> 
int max3( T a, T b, T c )
{
    /* Return the maximum of three object */
    return a > b ? a > c ? a : c : b > c ? b : c;
}

template<typename T>
int Max_Sub_Sum_Recursive(const std::vector<T>& vec, int left, int right)
{
    /* Recursive implementation of maximum subsequence sum problem */
    // base case
    if (left == right)    
    {
        if (vec[left] > 0)
            return  vec[left];
        else 
            return 0;
    }
    
    int center = (left + right) / 2;
    int max_left_sum = Max_Sub_Sum_Recursive(vec, left, center);
    int max_right_sum = Max_Sub_Sum_Recursive(vec, center + 1, right);

    int max_left_border_sum{}, left_border_sum{};
    for (int i = center; i >= left; --i)
    {
        left_border_sum += vec[i];
        if(left_border_sum > max_left_border_sum)
            max_left_border_sum = left_border_sum;
    }

    int max_right_border_sum{}, right_border_sum{};
    for (int j = center + 1; j <= right; ++j)
    {
        right_border_sum += vec[j];
        if (right_border_sum > max_right_border_sum)
            max_right_border_sum = right_border_sum;
    }

    return max3(max_left_sum, max_right_sum, max_left_border_sum + max_right_border_sum);
}

template<typename T>
int Max_Sub_Sum_Recursive_Driver(const std::vector<T>& vec)
{
    return Max_Sub_Sum_Recursive(vec, 0, vec.size() - 1);
}

template<typename T>
int Max_Sub_Sum_Linear(const std::vector<T>& vec) 
{
    int maximum_sum{}, this_sum{};

    for (size_t i{}; i < vec.size(); i++)
    {
        this_sum += vec[i];

        if (this_sum > maximum_sum)
            maximum_sum = this_sum;
        else if (this_sum < 0)
            this_sum = 0;
    }
    return maximum_sum;
}

template<typename T>
void Max_Sub_Sum_Solutions(const std::vector<T>& vec, int n) 
{
    std::cout << "\nANALYSIS FOR N = " << n << "\n\n";
    std::cout << "CUBIC RUNTIME\n";
    auto start = std::chrono::high_resolution_clock::now();
    int max = Max_Sub_Sum_Cubic(vec);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Output: " << max << '\n';
    if (duration.count() < 0)
        std::cout << "Execution time: <" << duration.count() << " millisecond(s).\n";
    else   
        std::cout << "Execution time: < " << duration.count() << " millisecond(s).\n";


    std::cout << "\n\nQUADRATIC RUNTIME\n";
    start = std::chrono::high_resolution_clock::now();
    max = Max_Sub_Sum_Quadratic(vec);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Output: " << max << '\n';
    if (duration.count() < 0)
        std::cout << "Execution time: <" << duration.count() << " millisecond(s).\n";
    else   
        std::cout << "Execution time: < " << duration.count() << " millisecond(s).\n";


    std::cout << "\n\n(N LOG N) RUNTIME\n";
    start = std::chrono::high_resolution_clock::now();
    max = Max_Sub_Sum_Recursive_Driver(vec);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Output: " << max << '\n';
    if (duration.count() < 0)
        std::cout << "Execution time: <" << duration.count() << " millisecond(s).\n";
    else   
        std::cout << "Execution time: < " << duration.count() << " millisecond(s).\n";

    std::cout << "\n\nLINEAR RUNTIME\n";
    start = std::chrono::high_resolution_clock::now();
    max = Max_Sub_Sum_Linear(vec);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Output: " << max << '\n';
    if (duration.count() < 0)
        std::cout << "Execution time: <" << duration.count() << " millisecond(s).\n";
    else   
        std::cout << "Execution time: < " << duration.count() << " millisecond(s).\n";
}

int main() 
{
    std::vector<int> input_vec{};
    int n{};

    while (true)
    {
        std::cout << "Enter size of input vector: N = ";
        std::cin >> n;

        /* Generate random integers in [-5000, 5000] */
        std::random_device rd; // obtain a random number from hardware
        std::mt19937 gen(rd()); // seed the generator
        std::uniform_int_distribution<> distr(-5000, 5000); // define the range

        for(int i = 0; i < n; ++i)
            input_vec.push_back(distr(gen));

        Max_Sub_Sum_Solutions(input_vec, input_vec.size());

        std::string c{};
        std::cout << "\nRun again? [y/N] > ";
        std::cin >> c;
        if (c == "y" || c == "Y")
        {
            std::cout << '\n';
            continue;
        }
        else
            break;
    }
}