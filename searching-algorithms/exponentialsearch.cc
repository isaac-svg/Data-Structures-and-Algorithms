#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;  // Target not found
}

int exponentialSearch(const std::vector<int>& arr, int target) {
    int size = arr.size();

    // Find the range for binary search
    int i = 1;
    while (i < size && arr[i] < target)
        i *= 2;

    // Perform binary search within the identified range
    return binarySearch(arr, i / 2, std::min(i, size - 1), target);
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 6;

    int result = exponentialSearch(arr, target);

    if (result != -1)
        std::cout << "Element " << target << " found at index " << result << std::endl;
    else
        std::cout << "Element " << target << " not found in the array." << std::endl;

    return 0;
}
