/* hanoi.cc - implementation of solution to Hanoi Tower Problem */
#include <iostream>

static int count{};

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        std::cout << "Move a disk from rod " << from_rod << " to rod " << to_rod << std::endl;
        count++;
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    std::cout << "Move a disk from rod " << from_rod << " to rod " << to_rod << std::endl;
    count++;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

// Driver code
int main()
{
    int n{5};                      // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods return 0;
    std::cout << "\nTotal number of moves for " << n << " disks is : " << count << '\n';
    return 0;
}