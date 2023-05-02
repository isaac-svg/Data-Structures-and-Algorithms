/**
 * @file sort_the_people.c++
 * @author isaac sakyi (isaacsakyi009@gmail.com)
 * @brief  sort the people 2418
 * @version 0.1
 * @date 2023-05-02
 *
 * @copyright Copyright (c) 2023
 *
 */

/*
You are given an array of strings [names],and an array [heights]
that consists of distinct positive integers. Both arrays are of length n.
For each index i names[i] and height[i] denote the name and height of the ith person
retuen the names of thwe people sorted in descending order by the peoples height
*/
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
vector<string> sortPeople(vector<string> &names, vector<int> &height)
{

    // create the map to keep name:height pairs
    unordered_map<int, string> m;
    for (int i = 0; i < names.size(); i++)
    {
        // fill the map with key value pairs
        m.insert({height[i], names[i]});
    }
    vector<string> ans;
    sort(height.begin(), height.end(), [](int one, int two)
         { return (one + two) > (two + one); });

    for (int h : height)
    {
        string sortedName = m.at(h);
        ans.push_back(sortedName);
    }
    return ans;
}