/**
 * @file index_of_the_first_occurence_of_a_string.c++
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-04
 *
 * @copyright Copyright (c) 2023
 *
 */

// Find the first index of the First Occurence in a String

/*
Given two strings needle and haystack , return the first occurence of
needle in haystack , or -1 if needle is not found in haystack.
*/
#include <iostream>
#include <string>
using namespace std;
int strStr(string haystack, string needle)
{
    int count = 0;
    for (int i = 0; i < haystack.size(); i++)
    {
        if (haystack[i] == needle[0])
        {
            count = 1;
            while (count < needle.size())
            {
                if (haystack[i + count] != needle[count])
                {
                    count = 0;
                    break;
                }
                ++count;
            }
            if (count == needle.size())
            {
                return i;
            }
        }
    }
    return -1;
}
int main()
{
    string haystack = "commander";
    string needle = "man";

    cout << strStr(haystack, needle) << '\n';

    return 0;
}