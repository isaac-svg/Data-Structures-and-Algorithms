/**
 * @file lengthOfLongestSubstring.c++
 * @author  isaac sakyi (isaacsakyi009@gmail.com)
 * @brief Solution to leetcode question -> Longest substring without repesting characters
 * @version 0.1
 * @date 2023-05-04
 *
 * @copyright Copyright (c) 2023
 *
 */
// Given a string find the longest substring without repeating characters
#include <string>
#include <unordered_set>
#include <iostream>
#include <climits>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_set<char> container;
    int count = 0;
    int max = INT_MIN;
    for (int i = 0; i < s.size(); i++)
    {
        if (container.find(s[i]) != container.end())
        {
            container.clear();
            container.insert(s[i]);
            if (count > max)
            {
                max = count;
            }
            count = 1;
        }
        else
        {
            container.insert(s[i]);
            ++count;
        }
    }
    return max;
}

int main()
{

    string s = "pwwkew";

    cout << lengthOfLongestSubstring(s) << '\n';

    return 0;
}