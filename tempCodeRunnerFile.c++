using namespace std;
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

// Three Sum leetCode
// header file for sort ?
int threeSum(vector<int> nums, int target)
{
    // sort the array
    sort(nums.begin(), nums.end());
    // set three pointers
    int start = 0;
    int end = nums.size() - 1;
    int step = 1;

    int currMin = 0;
    int sum;
    while (start < end)
    {
        sum = abs(nums[start] + nums[end] + nums[step]);
        if (sum < currMin)
        {
            currMin = sum;
        }
        else if (sum > currMin)
        {
        }
    }

    return 0;
}
int main()
{
    return 1;
}