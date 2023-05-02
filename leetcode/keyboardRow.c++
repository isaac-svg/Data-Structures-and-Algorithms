/**
 * @file keyboardRow.c++
 * @author Isaac Sakyi (isaacsakyi009@gmail.com)
 * @brief 500 Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard .

 * @version 0.1
 * @date 2023-05-01
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
/**
 @brief run time O(n^2)
 * @param words vector of strings
 * @return vector<string>
 */
vector<string> indWord1(vector<string> &words)
{

    vector<string> ans;
    unordered_map<char, int> m;

    string r1 = "qwertyuiop";
    string r2 = "asdfghjkl";
    string r3 = "zxcvbnm";
    // Fill in the map with values characters of each row
    for (const auto &c : r1)
        m[c] = 1;
    for (const auto &c : r2)
        m[c] = 2;
    for (const auto &c : r3)
        m[c] = 3;
    // pick each word and loop through each letter checking if each character is found in a specific row
    for (const auto &word : words)
    {
        // check the row the word belongs to using the first index
        int r = m[tolower(word[0])];
        // boundary Checker
        bool skip = false;
        // loop throgh each character
        for (const auto &c : word)
        {
            // check if there exists a character which has not the value of r

            if (m[tolower(c)] != r)
            {
                // we want to skip this word and break from further looping
                skip = true;
                break; // no need to continue since the word is not a single row
            }
            if (skip)
                continue; // if skip is true we don't have to keep int the ans vector
            ans.push_back(word);
        }
    }
    return ans;
}
vector<string> indWord(vector<string> &words)
{
    // create three sets to contain each character in a row
    unordered_set<char> r1 = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
    unordered_set<char> r2 = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
    unordered_set<char> r3 = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};

    vector<string> ans;
    // pick each word
    for (const auto &word : words)
    {
        unordered_set<char> row;
        // use the first character of the word to find the row it belongs to

        if (r1.find(tolower(word[0])) != r1.end())
        {
            row = r1;
        }
        if (r2.find(tolower(word[0])) != r2.end())
        {
            row = r2;
        }
        if (r3.find(tolower(word[0])) != r3.end())
        {
            row = r3;
        }
        // loop through the remaining of the  word
        bool skip = false;
        for (const auto &c : word)
        {
            if (row.find(tolower(c)) == row.end())
            {
                skip = true;
                break;
            }
        }
        if (skip)
            continue;
        ans.push_back(word);
    }
    return ans;
}

int main()
{
}