#include <vector>
#include <iostream>

template <typename T>
class BinaryHeap
{
public:
    explicit BinaryHeap(const std::vector<T> &items)
        : heapArray(items.size() + 10), currentSize{int(items.size())}
    {
        // copy all items into internal heap array,
        // notice the offset by 1
        for (int i{}; i < items.size(); ++i)
            heapArray[i+1] = items[i];
        
        buildHeap();
    }

private:
    int currentSize;   // number of elements in heap
    std::vector<T> heapArray;   // internal heap array

    void buildHeap()
    {
        /* build heap in linear time */
        for (int i = currentSize / 2; i > 0; --i)
            percolateDown(i);
    }

    void percolateDown(int hole)
    {
        int child;
        T temp = std::move(heapArray[hole]);

        for (; hole * 2 <= currentSize; hole = child)
        {
            child = hole * 2;
            if (child != currentSize && heapArray[child + 1] < heapArray[child])
                ++child;
            if (heapArray[child] < temp)
                heapArray[hole] = std::move(heapArray[child]);
            else   
                break;
        }
        heapArray[hole] = std::move(temp);
    }
};