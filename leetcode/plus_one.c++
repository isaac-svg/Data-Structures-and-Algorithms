// 66. Plus one

/**
 * @brief your are given a a large
 *
 */

#include <iostream>
#include <vector>
using namespace std;
#include <math.h>
vector<int> plusOne(vector<int> digits)
{
    for (int i = digits.size() - 1; i >= 0; i--)
    {
        if (digits[i] != 9)
        {
            digits[i] = digits[i] + 1;
            break;
        }
        else
        {
            digits[i] = 0;
        }
    }
    if (digits[0] == 0)
    {
        digits.insert(digits.begin(), 1);
    }
    return digits;
}

int main()
{
    vector<int> data = {6, 1, 4, 5, 3, 9, 0, 1, 9, 5, 1, 8, 6, 7, 0, 5, 5, 4, 3};

    vector<int> result = plusOne(data);

    for (size_t i = 0; i < data.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}