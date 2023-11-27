/* shell_sort.cc - simple implementation of the Shell sort algorithm
 * that utitlizes a variation of the insertion sort algorithm
 */

#include <iostream>
#include <vector>

template <typename T>
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

template <typename T>
void insertion_sort_interleaved(std::vector<T>& vec, int start, int gap)
{
    /* Sort the interleaved lists that are created via Shell sort
     *
     * Args:
     *  1. vec - templated vector
     *  2. start - starting index of the interleaved list
     *  3. gap - the step size of the interleaved lists
     *
     * Return: void (modifies in place)
     */
    T i{}, j{}, temp{};

    // Sort the interleaved lists
    for (int i = start + gap; i < vec.size(); i = i + gap)
    {
        j = i;

        // iterate over interleaved list
        while (j - gap >= start && vec[j] < vec[j - gap])
        {
            // swap as needed
            temp = vec[j];
            vec[j] = vec[j - gap];
            j = j - gap;
            vec[j]  = temp;
        }
    }
}

template<typename T>
void shell_sort(std::vector<T>& vec, std::vector<int> gaps)
{
    /* Implementation of shell sort algorithm that calls a modified 
     * insertion sort algorithm
     * 
     * Args:
     *  1. vec - templated vector to be sorted
     *  2. gaps - vector of gap values to create interleaved lists 
     * 
     * Return: void (modifies in place)
     */
    for (auto gap : gaps) 
    {
        for (int i{}; i < gap; i++)
            insertion_sort_interleaved(vec, i, gap);
    }
}

int main()
{
  //  std::vector<int> vec{88, 67, 91, 45, 14, 68, 71, 26, 64};
    std::vector<int> vec{23,65,35,89,98,84,94,68,54,67,83,46,91,72,39};
    std::vector<int> gaps{5,3,1};
    std::cout << "Input: "; print_vector(vec);
    shell_sort(vec, gaps);
    std::cout << "Output: ", print_vector(vec);
}
