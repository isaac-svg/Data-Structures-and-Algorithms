#include <iostream>


void insertion_sort(int *arr, int  size){

    for (size_t i = 2; i < size; i++)
    {
        int keyEl = arr[i];
        int j = i - 1;

        while (j >= 0 && keyEl <  arr[j])
        {
            arr[j + 1] = std::move(arr[j]);
            j = j - 1;
        }

        arr[j + 1] = keyEl;
    }
    
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}


int main(){

    int arr[] = {12, 24, 11, 13, 5, 6, -1,0};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    printArray(arr, n);

    insertion_sort(arr, n);

    std::cout << "Sorted array: ";
    printArray(arr, n);
    return (0);
}