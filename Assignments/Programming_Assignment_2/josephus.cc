#include <iostream>
#include <vector>
#include <string>
#include <fstream>

int main()
{
    std::vector<std::string> soldiers{};
    int n{};
    std::ifstream filename{"names.txt"};
    std::cout << "How many soldiers? > ";
    std::cin >> n;
   // std::cout << "Type " << n << " soldier's names: \n";
    for (size_t i{}; i < n; i++)
    {
        std::string name{};
        std::getline(filename, name);
        std::cout << name << '\n';
        soldiers.push_back(name);
    }

    std::cout << soldiers[3%10] << '\n';
    soldiers[3%10] = "";
    std::cout << soldiers[3%10] << '\n';

}