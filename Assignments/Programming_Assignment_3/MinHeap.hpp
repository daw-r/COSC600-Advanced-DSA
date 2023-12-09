/* Filename: MinHeap.hpp    
 *
 * Author: Devere Anthony Weaver 
 * 
 * Assignment: Programming Assignment 3
 * 
 * Description: header-only implementation of a min-heap to be used across all 
 * source code files for programming assignment 3
 */
 
#include <vector>
#include <iostream>

template <typename T>
class MinHeap
{
public:
    explicit MinHeap(int capacity = 100)   // constructor for O(log N) time
        : heap_array(1), current_size{0} {};

    explicit MinHeap(const std::vector<T> &items)   // constructor for O(N) time
        : heap_array(items.size() + 10), current_size{int(items.size())}
    {
        // load into internal array and offset by 1
        for (int i{}; i < items.size(); ++i)
            heap_array[i+1] = items[i];
        
        build_swaps = build_heap();
    }

    void insert(const T& x)
    {
        /* O(log N) time binary heap building algo */

        // double allocation size as needed
        if(current_size == heap_array.size() - 1)
            heap_array.resize(heap_array.size() * 2);

        // percolate up
        int hole = ++current_size;
        T copy = x;

        heap_array[0] = std::move(copy);
        for(; x < heap_array[hole / 2]; hole /= 2)
        {
            heap_array[hole] = std::move(heap_array[hole/2]);
            build_swaps++;
        }
        heap_array[hole] = std::move(heap_array[0]);
    }

    std::string get_heap_array_string(int n) 
    {
        /* return formatted string version of the binary heap array */
      if (current_size == 0) {
         return std::string("[]");
      }
      
      std::string array_string("[");
      array_string += std::to_string(heap_array[1]);
      for (int i = 2; i < n+1; i++) {
         array_string += ", ";
         array_string += std::to_string(heap_array[i]);
      }
      array_string += "]";
      return array_string;
   }


   int get_current_size() {return current_size;}
   int get_build_swaps() {return build_swaps;}

private:
    int current_size;   // number of elements in heap
    std::vector<T> heap_array;   // internal heap array
    int build_swaps{};    // keep track of number of swaps during heap building

    int build_heap()
    {
        /* build heap in linear time */
        int total_swaps{};
        for (int i = current_size / 2; i > 0; --i)
        {
            int swaps = percolate_down(i);
            total_swaps += swaps;
        }
        return total_swaps;
    }

    int percolate_down(int hole)
    {
        /* percolate down algorithm when building binary heap */
        int child;
        int swaps{};
        T temp = std::move(heap_array[hole]);

        for (; hole * 2 <= current_size; hole = child)
        {
            child = hole * 2;
            if (child != current_size && heap_array[child + 1] < heap_array[child])
                ++child;
            if (heap_array[child] < temp)
            {
                heap_array[hole] = std::move(heap_array[child]);
                swaps++;
            }
            else   
                break;
        }
        heap_array[hole] = std::move(temp);
        return swaps;
    }
};