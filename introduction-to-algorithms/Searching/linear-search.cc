/* linear-search.cc - illustration of the linear search algorithm */

#include <iostream>

template<typename T, typename X>
int LinearSearch(T list, int listSize, X key)
{
    /* LinearSearch() - search for key in list, return the index of key if it
    is found in the list, if not then return -1 */
    for(int i{0}; i < listSize; ++i) {
        if (list[i] == key) {
            return i;    // key found, return index
        }
    }
    return -1;
}

template<typename T>
void printvec(T v) 
{
    std::cout << "Input: { ";
    for(int i{}; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << "}\n";    
}

int main() 
{
    std::vector<int> numbers{2,4,7,10,11,32,45,87};
    int key{}, keyIndex{}, size = numbers.size();
    // std::cout << "Input: { ";
    // for(int i{}; i < numbers.size(); i++)
    //     std::cout << numbers[i] << " ";
    // std::cout << "}\n";
    printvec(numbers);
    std::cout << "Enter integer key: ";
    std::cin >> key;
    keyIndex = LinearSearch(numbers, size, key);
    if(keyIndex == -1)
        std::cout << key << " not found.\n";
    else
        std::cout << key << " found at index " << keyIndex << "\n";

    std::vector<char> chars{'d', 'e', 'v', 'r', 'w', 'a'};
    char ckey{};
    size = chars.size();
    std::cout << '\n';printvec(chars);
    std::cout << "Enter character key: ";
    std::cin >> ckey;
    keyIndex = LinearSearch(chars, size, ckey);
    if(keyIndex == -1)
        std::cout << ckey << " not found.\n";
    else
        std::cout << ckey << " found at index " << keyIndex << "\n"; 
}