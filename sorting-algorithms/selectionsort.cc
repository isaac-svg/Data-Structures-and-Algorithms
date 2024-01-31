#include <iostream>


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}


void selection_sort(int arr[], int size){

    for (size_t i = 0; i < size; i++)
    {
        int maxElePos = 0;
        for (size_t j = 1; j < size - i; j++)
        {
            if (arr[j] > arr[maxElePos]){
                maxElePos = j;
            }
        }
        
        int temp = arr[maxElePos];
        arr[maxElePos] = arr[size -i -1];
        arr[size - i - 1] = temp;
    }
    
}


int main(){

    int arr[] = {12, 24, 11, 13, 5, 6, -1,0};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    printArray(arr, n);

    selection_sort(arr, n);

    std::cout << "Sorted array: ";
    printArray(arr, n);
    return (0);
}