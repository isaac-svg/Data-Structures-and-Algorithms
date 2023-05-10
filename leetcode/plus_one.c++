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
    int length = digits.size();
    // cout << length;
    // ans vector
    vector<int> ans;
    int num = 0;
    for (int i = 0; i < length; i++)
    {
        // cout << (digits[i] * pow(10, (length - 1 - i))) << " ,";
        num += (digits[i] * pow(10, (length - 1 - i)));
    }
    //  add one to num
    num += 1;

    int singledigit = 0;
    length = digits.size();
    int test = num;
    for (int i = 0; i < length; i++)
    {
        singledigit = num / pow(10, (length - 1 - i));
        num = num % static_cast<int>(pow(10, (length - 1 - i)));

        ans.push_back(singledigit);
    }
    return ans;
}

int main()
{
    vector<int> data = {1, 2, 3};

    vector<int> result = plusOne(data);

    for (size_t i = 0; i < data.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}