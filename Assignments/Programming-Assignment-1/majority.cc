#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int CountFrequency(std::vector<int> vec, int left, int right, int key)
{
    int count{};
    for (int i = left; i <= right; i = i + 1)
    {
        if (vec[i] == key)
            count = count + 1;
    }
    return count;
}

int MajorityElement(std::vector<int> vec, int left, int right)
{
    if (left == right)
        return vec[left];

    /* DIVIDE */
    int middle = left + (right - left) / 2;
    int leftMajority = MajorityElement(vec, left, middle);
    int rightMajority = MajorityElement(vec, middle + 1, right);

    /* CONQUER */
    if (leftMajority == rightMajority)
        return leftMajority;

    int leftCount = CountFrequency(vec, left, right, leftMajority);
    int rightCount = CountFrequency(vec, left, right, rightMajority);

    /* COMBINE */
    if (leftCount > (right - left + 1) / 2)
        return leftMajority;
    else if (rightCount > (right - left + 1) / 2)
        return rightMajority;
    else
        return -1; // No majority element in this subarray
}

void PrintVec(std::vector<int>& vec)
{
    for (int i{}; i < vec.size(); i++)
        std::cout << vec[i] << ' ';
    std::cout << '\n';
}

int CountVec(std::vector<int>& vec)
{
    int count{};
    for (int i{}; i < vec.size(); i++)
        count++;
    return count;
}

std::vector<int> ParseFile(std::ifstream& file)
{
    std::vector<int> vec{};
    std::string line{};
    while(file >> line)
        vec.push_back(std::stoi(line));
    return vec;
}

int main()
{
    // files
    std::ifstream file1("Majex1.txt");
    std::ifstream file2("Majex2.txt");
    std::ifstream file3("Majex3.txt");
    std::ifstream file4("Majex4.txt");

    /* Find majority element for Majex1.txt */
    std::cout << "\n=====================================\n";
    std::cout << "File: Majex1.txt\n";
    std::vector<int> vec = ParseFile(file1);
    std::cout << "\nNumber of elements: " << CountVec(vec) << "\n"; 
    int majority = MajorityElement(vec, 0, vec.size());
    if (majority == -1)
        std::cout << "Result: There is no majority element.\n";
    else
        std::cout << "\nResult: Majority element is " << majority << '\n';

    /* Find majority element for Majex2.txt */
    std::cout << "\n=====================================\n";
    std::cout << "File: Majex2.txt\n";
    vec = ParseFile(file2);
    std::cout << "\nNumber of elements: " << CountVec(vec) << "\n"; 
    majority = MajorityElement(vec, 0, vec.size());
    if (majority == -1)
        std::cout << "Result: There is no majority element.\n";
    else
        std::cout << "\nResult: Majority element is " << majority << '\n';

        /* Find majority element for Majex3.txt */
    std::cout << "\n=====================================\n";
    std::cout << "File: Majex3.txt\n";
    vec = ParseFile(file3);
    std::cout << "\nNumber of elements: " << CountVec(vec) << "\n"; 
    majority = MajorityElement(vec, 0, vec.size());
    if (majority == -1)
        std::cout << "Result: There is no majority element.\n";
    else
        std::cout << "\nResult: Majority element is " << majority << '\n';

    
    /* Find majority element for Majex4.txt */
    std::cout << "\n=====================================\n";
    std::cout << "File: Majex3.txt\n";
    vec = ParseFile(file4);
    std::cout << "\nNumber of elements: " << CountVec(vec) << "\n"; 
    majority = MajorityElement(vec, 0, vec.size());
    if (majority == -1)
        std::cout << "Result: There is no majority element.\n";
    else
        std::cout << "\nResult: Majority element is " << majority << '\n';
}