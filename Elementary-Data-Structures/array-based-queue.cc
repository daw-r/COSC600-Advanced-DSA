/* illustration on implementing an array-based queue, this queue implementation
   is for demonstration purposes only and as such will only use basic int types
   for the head and tail attributes, in practice it would likely be better to 
   implement these using pointers 
*/
#include <iostream>

template<typename T>
class Queue
{
public:
    Queue(int size) : size{size}, head{0}, tail{0}, arr{new T[size]} {}
    void Enqueue(T x) {
        /* adds an element to the end of the queue */
        if (head == (tail + 1))
            throw std::runtime_error{"Queue overflow: queue is already full"};
        arr[tail] = x;

        // check and account for the wrap-around
        if (tail == size)    
            tail = 0;    
        else
            tail++;
    }
    T Dequeue() {
        int x = head;

        // check and move head as needed
        if (head == size)
            head = 0;
        else
            head++;
        return x;
    }
    void Print() {
        if (head == tail)
            std::cout << "Queue currently empty";
        else {
            std::cout << "< ";
            for (size_t i = head; i < tail; i++)
                std::cout << arr[i] << " ";
            std::cout << ">\n";
        }
    }
    void PrintAll() {
        std::cout << "< ";
        for (size_t i{}; i < size; i++)
            std::cout << arr[i] << " ";
        std::cout << ">\n";
    }
    int GetHead() {
        return head;
    }
    int GetTail() {
        return tail;
    }
private:
    int size;    // size of the array
    T* arr;    // pointer to dynamically allocated elements
    int head;    // index of the start of queue (implement with pointer later)
    int tail;    // index of end of queue (again, can be implemented with a pointer)
};

int main()
{
    // implement queue example illustrated in text
    std::vector<int> elements{15,6,9,8,4};
    Queue<int> myq(12);
    myq.Print();
//    std::cout << ": "; myq.Pri();
    
    // add element from elements vector to myq
    for (auto e : elements)
        myq.Enqueue(e);
    std::cout <<  "\nAfter the initial Enqueue: "; myq.Print();
    std::cout << "The current head location is : " << myq.GetHead() << '\n';
    std::cout << "The current tail location is: " << myq.GetTail() << '\n';
    
    // enqueue two more elements
    myq.Enqueue(3);
    myq.Enqueue(5);
    std::cout << "\nAfter the second enqueue calls: "; myq.Print();
    std::cout << "The current head location is : " << myq.GetHead() << '\n';
    std::cout << "The current tail location is: " << myq.GetTail() << '\n';

    // dequeue 
    myq.Dequeue();
    std::cout << "\nAfter the first dequeue call: "; myq.Print();
    std::cout << "The current head location is : " << myq.GetHead() << '\n';
    std::cout << "The current tail location is: " << myq.GetTail() << '\n';

    // attempt to overflow the deque
    std::cout << "\nAttempting to cause an overflow...\n";
    try {
        for (size_t i{1}; i < 20; i++)
            myq.Enqueue(i);
    } catch(std::runtime_error& err) {
        std::cout << err.what() << ". Operation aborted\n";
    }
}