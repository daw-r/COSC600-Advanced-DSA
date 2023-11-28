/* selection_sort.cc - simple implementation of the selection sort algorithm */

#include <iostream>

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
void selection_sort(std::vector<T>& list)
{
    int smallest_index{};
    T temp{};

    // iterate over list and sort
    for (int i = 0; i < list.size(); i++)
    {
        smallest_index = i;

        // search for smallest element index in unsorted portion
        for (int j = i + 1; j < list.size(); j++)
        {
            if (list[j] < list[smallest_index])
                smallest_index = j;
        }

        // put smallest in proper sequence order 
        temp = list[i];
        list[i] = list[smallest_index];
        list[smallest_index] = temp;
    }

    print_vector(list);
}

int main()
{
    std::vector<int> vec{10, 2, 78, 4, 45, 32, 7, 11};
    selection_sort(vec);
}