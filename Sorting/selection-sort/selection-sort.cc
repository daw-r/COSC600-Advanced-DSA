#include <iostream>

void selection_sort(int arr[], int n)
{
    int smallest = arr[0];

    for (size_t i{}; i < n; ++i) {
        for (size_t j{}; j < n; ++j) {
            if (arr[j] > arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                smallest = arr[i];
            }
        }
    }
}

void print_arr(int arr[], int n) 
{
    std::cout << "[ ";
    for (size_t i{}; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << "]";
}

int main() 
{
    int arr[] = {2, 1, 4, 3};
    std::cout << "Input: "; print_arr(arr, 4); std::cout << '\n';
    selection_sort(arr, 4);
    std::cout << "Output: "; print_arr(arr, 4); std::cout << '\n';
}
