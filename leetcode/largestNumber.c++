/**
 * @file largestNumber.c++
 * @author isaac sakyi (isaacsakyi009@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-05-02
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool custome_comparator(string s1, string s2)
{
    return (s1 + s2) > (s2 + s1);
}

string largestNumber1(vector<int> &nums)
{

    // create a string vector
    vector<string> nums_String;
    string ans;
    // convert nums to string and keep in the nums_String vector
    for (int num : nums)
    {
        nums_String.push_back(to_string(num));
    }
    // we sort basesd on the sum of two strings
    sort(nums_String.begin(), nums_String.end(), [](string s1, string s2)
         { return (s1 + s2) > (s2 + s1); });

    // append the strings t ans variable
    for (string s : nums_String)
    {
        ans.append(s);
    }
    // chack if the nums contained only 0s

    int start = 0;
    while (nums_String[0] == "0" && start < nums_String.size() - 1)
        start++;
    return ans.substr(start);
}
