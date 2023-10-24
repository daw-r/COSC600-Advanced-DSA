/* illustration of implementing an elementary array-based stack */
#include <iostream>

template<typename T>
class Stack 
{
public:
    /* naive implementation of an array-based stack, observe from algorihm analysis topics last
    week, all the operations defined for this are O(1), i.e. constant-time operations */
    Stack(int size) : size{size}, top{-1}, arr{new T[size]} {}
    bool StackEmpty() {
        /* check if the stack is empty */
        if (top == -1) 
            return true;
        else 
            return false;
    }
    ~Stack() {
        delete[] arr;
    }
    void Push(T x) {
        /* push an element of type T onto the top of the stack */
        if (top == size)
            throw std::runtime_error{"Error: Stack overflow"};
        else {
            top++;   // increment stack pointer
            arr[top] = x;    // assign new top index to value x
        }
    }
    T Pop() {
        /* remove top element from array */
        if (StackEmpty())
            //throw std::runtime_error{"Error: Underflow"};
            std::cout << "Stack is empty, nothing to remove\n";
        top--;
        return arr[top+1];
    }
    void PrintStack() {
        if (StackEmpty())
            std::cout << "Stack currently empty\n";
        else {
            std::cout << "< ";
            for (size_t i{}; i <= top; i++)
                std::cout << arr[i] << " ";
            std::cout << ">\n";
        }
    }
    int GetStackSize() {
        return size;
    }
    int GetTopIndex() {
        return top;
    }
    T GetTopElement() {
        return arr[top];
    }
private:
    int size;       // maximum size of the current stack
    T* arr;    // array of type T elements of size size
    int top;          // index of top of the stack
};

int main()
{
    // create a stack that stores only integers
    Stack<int> mystack(10);
    mystack.PrintStack();
    std::cout << "Current top: " << mystack.GetTopIndex() << '\n';

    // push 10 elements onto the stack
    std::cout << "\nAdd 5 elements to the stack:\n";
    for (size_t i{1}; i <= 5; ++i)
        mystack.Push(i);
    mystack.PrintStack();

    // which element is at the top of the stack?
    std::cout << "Top of stack: " << mystack.GetTopElement() << '\n';

    // remove the top element 
    std::cout << "Element removed: " << mystack.Pop() << '\n';
    mystack.PrintStack();

    // overflow the stack now 
    for (size_t i{}; i < 10; ++i)
        mystack.Push(i);
}