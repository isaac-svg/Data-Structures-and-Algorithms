//

/**
 * @brief 35. Search insert position
 *
 */

#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

int searchInsert(vector<int> nums, int target)
{

    int start = 0;
    int end = nums.size();
    int mid;
    while (start < end)
    {
        mid = start + (end - start) / 2;
        if (nums[mid] == target)
            return mid;

        else if (target > nums[mid])
        {
            start = mid + 1;
        }
        else if (target < nums[mid])
        {
            end = mid;
        }
        else
        {
            break;
        }
    }
    return mid + 1;
}

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 2;
    cout << searchInsert(nums, target) << "\n";
}