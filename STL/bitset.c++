using namespace std;
#include <iostream>
#include <bitset>
int main()
{

    bitset<5> bt;

    bt.set();
    cout << bt.any();
    return 0;
}