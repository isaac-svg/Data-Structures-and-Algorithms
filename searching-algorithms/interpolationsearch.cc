#include <iostream>

bool interpolationSearch(int arr[], int n, int target) {
  int low = 0, high = n - 1;

  while (low <= high && arr[low] <= target && arr[high] >= target) {
    // Interpolation formula
    int mid = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

    // Check if target is found at the interpolated position
    if (arr[mid] == target) {
      return true;
    }

    // Adjust search space based on comparison
    if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return false; // Target not found
}

int main() {
  int arr[] = {1, 3, 5, 7, 9, 11, 13};
  int n = sizeof(arr) / sizeof(arr[0]);
  int target = 7;

  if (interpolationSearch(arr, n, target)) {
    std::cout << "Target " << target << " found in the array." << std::endl;
  } else {
    std::cout << "Target " << target << " not found in the array." << std::endl;
  }

  return 0;
}
