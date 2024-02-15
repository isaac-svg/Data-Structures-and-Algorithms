#include <iostream>
#include <vector>
#include <list>


/**
 * @brief Represents a stack data structure with LIFO (Last-In-First-Out) behavior.
 *
 * This class implements a stack using a doubly linkedlist to store elements. It
 * provides methods for pushing, popping, checking emptiness, retrieving the top
 * element, and printing the stack contents.
 *
 * @invariant The stack_top variable always points to the index of the top element.
 * @invariant The capacity variable indicates the maximum number of elements the stack can hold.
 */
class Queue
{
private:

    /**
     * @brief The vector used to store the stack elements
    */
    std::list<int> _data;

     
public:

    
     /**
     * @brief Pushes a value onto the top of the stack.
     *
     * @param val The value to push.
     * @return 0 if successful, -1 if the stack is full.
     */
   virtual int push(int val);
    /**
     * @brief Checks if the stack is empty.
     *
     * @return true if the stack is empty, false otherwise.
     */
   virtual bool is_empty();
   /**
     * @brief Retrieves the value at the top of the stack without removing it.
     *
     * @return The value at the top of the stack.
     * @precondition !is_empty()
     */
   virtual int top();
   /**
     * @brief Removes and returns the value at the top of the stack.
     *
     * @return The value at the top of the stack.
     * @precondition !is_empty()
     */
   virtual int pop();
   /**
     * @brief Returns the number of elements in the stack.
     *
     * @return The size of the stack.
     */
   virtual int size();
   /**
     * @brief Prints the contents of the stack to the console.
     */
   virtual void print(); 
};



bool Queue::is_empty(){
    
   
    return (_data.size() == 0);
}

int Queue::top(){
    return (_data.front());
}

int Queue::push(int val){
    
    
    _data.push_back(val);
    return val;
}

int Queue::pop(){
 
     if (is_empty()){
        std::__throw_out_of_range("Can't pop from an empty stack");
     }
     int topVal = top();
    
     _data.pop_front(); 

     return topVal;

}

int Queue::size(){
    return _data.size();
}



void Queue::print()
{
    for (auto i = _data.begin(); i != _data.end(); i++)
    {
        std::cout << " " << *i;
    }
}

int main()
{
    Queue s;
    for (int i = 1; i <= 100; i++)
            s.push(i);
    for (int i = 1; i <= 50; i++)
            s.pop();
    s.print();
    return 0;
}