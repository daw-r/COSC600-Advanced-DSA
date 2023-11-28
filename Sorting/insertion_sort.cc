#include <iostream>
#include <vector>

template<typename T>
void print_vector(std::vector<T>& vec)
{
    std::cout << "(";
    for (int i{}; i < vec.size(); i++)
    {
        if (i == vec.size() - 1)
            std::cout << vec[i] << ")\n";
        else
            std::cout << vec[i] << ", ";
    }
}

template<typename T>
void insertion_sort(std::vector<T>& vec)
{
    /* Simple insertion sort implementation without any explicit swapping */
    int j{};

    // iterate over the vector
    for (int p = 1; p < vec.size(); p++)
    {
        // store value at pth element corresponding to pth pass
        auto temp = vec[p];

        // move the current pth value to the left if it is less 
        // than the values to the left of it
        for(j = p; (j > 0) && temp < vec[j - 1]; j--)
            vec[j] = vec[j-1];
        vec[j] = temp;
    }
    print_vector(vec);
}

int main()
{
    std::vector<int>vec{34,8,64,51,32,21};
    std::cout << "Input: "; print_vector(vec);
    std::cout << "Sorted output: "; insertion_sort(vec);
}