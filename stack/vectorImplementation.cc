#include <iostream>
#include <vector>


/**
 * @brief Represents a stack data structure with LIFO (Last-In-First-Out) behavior.
 *
 * This class implements a stack using a dynamic array to store elements. It
 * provides methods for pushing, popping, checking emptiness, retrieving the top
 * element, and printing the stack contents.
 *
 * @invariant The stack_top variable always points to the index of the top element.
 * @invariant The capacity variable indicates the maximum number of elements the stack can hold.
 */
class Stack
{
private:
    /**
     * @brief The current value held by the stack.
     */
    int value;
    /**
     * @brief The vector used to store the stack elements
    */
    std::vector<int> data;
    /**
     * @brief The index of the top element in the stack
    */
    int stack_top = -1;

    /**
     * @brief The minimum capacity of the stack.
     */
    static const int MIN_CAPACITY = 10;
     /**
     * @brief The current capacity of the stack.
     */
    int capacity;
    /**
     * @brief Helper function to write stack elements to a vector.
     *
     * @param array The array to write the elements to.
     * @param size The number of elements to write.
     */
    void write_to_vector(int array[], int size);
     /**
     * @brief Helper function to write stack elements to a vector.
     *
     * @param data The vector to write the elements to.
     * @param size The number of elements to write.
     */
    void write_to_vector(std::vector<int>data, int size);
public:
 /**
     * @brief Constructs a stack with the specified capacity.
     *
     * @param capacity The initial capacity of the stack.
     * @precondition capacity >= MIN_CAPACITY
     */
    Stack(int capacity);
    /**
     * @brief Constructs a stack from an existing array.
     *
     * @param array The array to initialize the stack with.
     * @param size The number of elements in the array.
     * @param maxCapacity The maximum capacity of the stack.
     * @precondition maxCapacity >= size
     */
    Stack(int array[], int size);
    /**
     * @brief Constructs a stack from an existing vector.
     *
     * @param newVals The vector to initialize the stack with.
     * @param size The number of elements in the vector.
     * 
     */
    Stack(std::vector<int> newVals, int size);
    /**
     * @brief Destroys the stack and deallocates memory.
     */
    ~Stack();
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


Stack::Stack(int maxCapacity){
    data.reserve(maxCapacity);
    this->capacity = maxCapacity;
}

Stack::Stack(int array[], int size){
    write_to_vector(array, size);
}
Stack::Stack(std::vector<int> newVals, int size){
        write_to_vector(newVals, size);

}

Stack::~Stack(){
     data.resize(0);
}

bool Stack::is_empty(){
    return (data.size() == 0);
}

int Stack::top(){
    return (data[data.size() - 1 ]);
}

int Stack::push(int val){
    
    
    data.push_back(val);
    return val;
}

int Stack::pop(){
 
     if (is_empty()){
        std::__throw_out_of_range("Can't pop from an empty stack");
     }
     int topVal = top();
    
     data.pop_back(); 

     return topVal;
    
   
 
   
}

int Stack::size(){
    return this->data.size();
}
void Stack::write_to_vector(int array[], int size){


    for (int i = 0; i < size; i++)
    {
        data[i] = array[i];
    }
    
}

void Stack::write_to_vector(std::vector<int> vectData, int size){


    for (int i = 0; i < size; i++)
    {
        data[i] = vectData[i];
    }
    
}
void Stack::print()
{
    for (int i = data.size() -1; i > -1; i--)
    {
        std::cout << " " << data[i];
    }
}

int main()
{
    Stack s(1000);
    for (int i = 1; i <= 100; i++)
            s.push(i);
    for (int i = 1; i <= 50; i++)
            s.pop();
    s.print();
    return 0;
}