/* binary-search.cc - illustration of the binary search algorithm */
#include <iostream>

template<typename T, typename X>
int BinarySearch(T list, int listSize, X key)
{
    /* BinarySearch() - implementation of the binary search algorithm for 
    demonstration purposes only; requires list to be sorted */
    int mid{}, low{}, high = listSize - 1;  

    while (high >= low) {
        mid = (high - low) / 2;    // compute new midpoint of subarray
        if (list[mid] < key) {     // if midpoint value is less than key,
            low = mid + 1;         // shift right
        } else if (list[mid] > key) {
            high = mid - 1;    // shift left
        } else {
            return mid;    // key found
        }
    }
    return -1;    // key not found
}

int main()
{
    std::vector<int> numbers = {2,4,7,10,11,32,45,87};
    int key{}, keyIndex{};
    std::cout << "{ ";
    for (size_t i{}; i < numbers.size(); ++i) 
        std::cout << numbers.at(i) << " ";
    std::cout << "}\n";
    std::cout << "Enter key: ";
    std::cin >> key;
    keyIndex = BinarySearch(numbers, numbers.size(), key);
    if (keyIndex == -1)
        std::cout << key << " not found.\n";
    else 
        std::cout << key << " found at index " << keyIndex << '\n';
}