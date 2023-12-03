#include <vector>
#include <iostream>

template<typename T>
class BinaryHeap
{
    public:
        explicit BinaryHeap(int capacity = 100)
        {
            array.resize(capacity);
            currentSize = 0;
        };  

        void insert(const T& x)
        {
            // double allocation as needed
            if (currentSize == array.size() - 1)
                array.resize(array.size() * 2);

            int hole = ++currentSize;
            T copy = x;
            
            array[0] = std::move(copy);

            for(; x < array[hole/2]; hole /= 2)
                array[hole] = std::move(array[hole/2]);
            array[hole] = std::move(array[0]);
        }

        int get_size()
        {
            return currentSize;
        }

        void print_heap()
        {
            for (int i{}; i < currentSize; i++)
                std::cout << array[i] << " ";
            std::cout << '\n';
        }

    private:
        int currentSize;
        std::vector<T> array{};
};