/**
 * @file 3Sum.c++
 * @author isaac sakyi (isaacsakyi@gmail.com)
 * @brief  Given an integer array nums of Length n and an integer, find three integers in nums such that their sum is closest to target. Return the sum of the three integers
 * @version 0.1
 * @date 2023-05-04
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <vector>
using namespace std;
#include <algorithm>
#include <iostream>
#include <climits>
int threeSumClosest(vector<int> nums, int target)
{

    // sort the vector in ascending order;
    sort(nums.begin(), nums.end());
    int diff = INT_MAX;
    int ans;
    // use a outer loop to pick a number starting from the smallest .
    // use an  inner loop to to pick two pointers one at the end and fro from the begining and ahead of the main value by one;

    // starting and ending pointers

    for (int i = 0; i < nums.size(); i++)
    {
        int first = nums[i];
        int end = nums.size() - 1;
        int start = i + 1;
        while (start < end)
        {

            // find the difference the current sum (currSum) and the target
            // int diff = abs(currSum - target);
            // cout << diff << '\n';

            // if the difference is 0 then it means the sum is same is the target so we don't have to go further we have found the best closest sum
            if (first + nums[start] + nums[end] == target)
            {
                return target;
            }
            // if the difference is less than the current closest then the current closest is set to the current Sum and we move our pointer forward;
            else if (abs(first + nums[start] + nums[end] - target) < diff)
            {
                diff = abs(first + nums[start] + nums[end] - target);
                ans = first + nums[start] + nums[end];
            }
            // if the difference is greater than the current closest then the we move the end pointer backward

            if (abs(first + nums[start] + nums[end] - target) > target)
            {
                end--;
            }
            else
            {
                start++;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    cout << threeSumClosest(nums, target) << "\n";

    return 0;
}