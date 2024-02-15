#include <iostream>



/**
 * Best Case O(n)
 * Worst Case O(n^2)
*/
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void insertionSort(int arr[], int size){

    for (size_t i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            
        }

        arr[j + 1] = key; 
    }
    
}

void insertionSort2(int arr[], int size){

    for (size_t i = 1; i < size; i++)
    {
        int current = std::move(arr[i]);
        int j = i - 1;

        while (j >= 0 && current < arr[j])
        {
            arr[j + 1] = std::move(arr[j]);
            --j;
        }
        arr[j+1] = current;
    }
    
}


int main(){

    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    printArray(arr, n);

    insertionSort(arr, n);

    std::cout << "Sorted array: ";
    printArray(arr, n);
    return (0);
}