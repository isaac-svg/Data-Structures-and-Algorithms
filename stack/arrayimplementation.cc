

#include <memory>
#include <iostream>


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
     * @brief The dynamic array used to store the stack elements.
     */
    int *data;
    /**
     * @brief The index of the top element in the stack (-1 if empty).
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
     * @brief Helper function to write stack elements to an array.
     *
     * @param array The array to write the elements to.
     * @param size The number of elements to write.
     */
    void write_to_array(int array[], int size);
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
    Stack(int array[], int size, int maxCapacity);
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
    data = new int[maxCapacity];
    this->capacity = maxCapacity;
}

Stack::Stack(int array[], int size, int maxCapacity){
    write_to_array(array, size);
    this->capacity = maxCapacity;
    stack_top = size - 1;
}
Stack::~Stack(){
    delete[] data;
}

bool Stack::is_empty(){
    return (stack_top == -1);
}

int Stack::top(){
    return (data[stack_top]);
}

int Stack::push(int val){
    if (size() == capacity)
    {
        int *del =  data;
        
        capacity = 2 *capacity;
        data = new int[capacity];

        for (int i = stack_top; i >= 0; i--)
        {
            data[i] = del[i];
        }
        
    }

    stack_top++;
    data[stack_top] = val;
    
}

int Stack::pop(){
   try
   {
     if (stack_top == -1){
        std::__throw_out_of_range("Can't pop from an empty stack");
     }
     int topVal = data[stack_top];
     stack_top--;
     if (stack_top < capacity / 2 && stack_top > MIN_CAPACITY)
    {
            capacity = capacity / 2;
            int *delMe = data;
            data = new int[capacity];
            for (int i = stack_top; i > -1; i--)
            {
                data[i] = delMe[i];
            }
            std::cout << "stack size reduced" << std::endl;
    }
    return topVal;
   }
   catch(const std::exception& e)
   {
    std::cerr << e.what() << '\n';
   }
   
}

int Stack::size(){
    return this->stack_top;
}
void Stack::write_to_array(int array[], int size){

    data = new int[size - 1];

    for (int i = 0; i < size; i++)
    {
        data[i] = array[i];
    }
    
}

void Stack::print()
{
    for (int i = stack_top; i > -1; i--)
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