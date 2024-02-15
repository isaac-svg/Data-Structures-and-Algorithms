#include <vector>
#include <iostream>


/**
 * @brief Performs a binary search for a given key in a sorted vector of integers.
 *
 * This function implements the binary search algorithm to efficiently find the
 * index of the `key` element within the sorted `arr` vector. If the key is
 * not found, the function returns -1.
 *
 * @param arr The sorted vector of integers to search within.
 * @param key The integer value to search for.
 * @return The index of the `key` element in `arr`, or -1 if not found.
 *
 * @complexity Time: O(log n), Space: O(1)
 *
 * @precondition The `arr` vector must be sorted in ascending order.
 */
int binarysearch(std::vector<int> arr, int key){

    int size = arr.size();
    int lowerbound = 0;
    int upperbound = size -1;

    while (lowerbound <= upperbound)
    {

    int midpoint = (upperbound + lowerbound)/2;
        if (arr[midpoint] > key)
        {
            upperbound = midpoint - 1;
        }
        else  if (arr[midpoint] < key)
        {
            lowerbound = midpoint + 1;
        }
        if (arr[midpoint] == key)
        {
            return midpoint;
        }
    }

    return -1;
    

}

int main(void)
{

    std::vector<int> data =  {1,2,3,4,5,6,7,8,9,10};

    std::cout << binarysearch(data, 0)<< std::endl;

    return 0;
}