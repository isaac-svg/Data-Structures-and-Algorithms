#include <algorithm>
#include <vector>
#include <iostream>
#include <climits>
#include <string>
/**
 * 2605
 * @brief Form smallest number form two digit array
 *
 * GIven two arrays of unique numbers nums1 and nums2 return the smallest number that contains at least one digit from each array
 */
// approach 1 Time Complexity nlogn +mlogm
int smallestNumber1(std::vector<int> nums1, std::vector<int> nums2)
{

    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());
    int digit1 = nums1[0];
    int digit2 = nums2[0];
    if (digit1 == digit2)
        return digit1;
    else if (digit1 < digit2)
    {
        return (digit1 * 10 + digit2);
    }
    else
    {
        return (digit2 * 10 + digit1);
    }
}

// approach 2 time time complexity nlogn +m

int smallestNumber2(std::vector<int> nums1, std::vector<int> nums2)
{
    int size2 = nums2.size();
    sort(nums1.begin(), nums1.end());
    int sortedSmallest = nums1[0];
    int smNumIdx;
    int smNum = INT_MAX;
    for (int i = 0; i < size2; i++)
    {
        smNum = std::min(nums2[i], smNum);
    }
    if (sortedSmallest == smNum)
        return sortedSmallest;

    return (10 * std::min(smNum, sortedSmallest) + std::max(smNum, sortedSmallest));
}

void divisibilityArray(std::string s1, int num)
{
    int previous = 0;

    int length = s1.size();
    std::vector<int> divs(length);

    for (int i = 0; i < length; i++)
    {
        char currInt = s1[i];
        previous = 10 * previous + static_cast<int>(s1[i]);
        int divisibility = previous % num;
        if (divisibility == 0)
        {
            divs[i] = 1;
        }
        else
        {
            divs[i] = 0;
        }
    }
    for (int j = 0; j < divs.size(); j++)
    {
        std::cout << divs[j] << " ";
    }
    std::cout << std::endl;
}

int removeDuplicates(std::vector<int> nums)
{
    int i = 0;

    for (size_t j = 1; j < nums.size(); j++)
    {
        if (nums[i] != nums[j])
        {
            i++;
            nums[i] = nums[j];
        }
        /* code */
    }
    return (i + 1);
}

/**
 * @brief 179.Largest Number
 * Given a list of of non-negative integers arrange the so that they form the largest and retrn it (as a string)
 *
 *
 * @return string
 */
bool comp(int el1, int el2)
{
    if (el1 > el2)
        return true;
    return false;
}

int main(void)
{

    std::vector<int> nums1 = {4, 1, 3};
    std::vector<int> nums2 = {5, 7};
    // std::cout << smallestNumber1(nums1, nums2) << std::endl;
    // std::cout << smallestNumber2(nums1, nums2) << std::endl;
    std::string s1 = "998244353";
    int nums = 3;

    divisibilityArray(s1, nums);
}
