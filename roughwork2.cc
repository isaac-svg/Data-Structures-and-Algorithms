#include <iostream>

int main() {
    int num = 5;
    int result;

    // Inline assembly to square a number
    asm("movl %[input], %%eax;"      // Move the input number to the eax register
        "imull %[input], %%eax;"     // Multiply eax by the input number
        "movl %%eax, %[output];"     // Move the result from eax to the 'result' variable
        : [output] "=r" (result)      // Output operand (result)
        : [input] "r" (num)           // Input operand (num)
        : "eax"                       // List of clobbered registers (eax is clobbered)
    );

    

    std::cout << "Square of " << num << " is: " << result << std::endl;

    return 0;
}
