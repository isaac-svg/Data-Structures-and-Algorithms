using namespace std;
#include <iostream>
#include <bitset>
int main()
{

    bitset<5> bt;
    // set()  sets all bits to 1 or an index you provide for the second arg
    // reset() resets all bits to 0 all or an index you provide for the second arg
    // any() return bool checks if any of the bit is set to 1
    // all() bool checks if all of the bit is set to 1
    // flip() flips 0 to 1 and vice versa
    // size() returns the size of the bitset;
    // count( ) counts the numbers of 1s
    // test()

    bt.set();
    cout << bt.any();
    return 0;
}