#include <iostream>
// insertion sort

/**
 * @size: number of elements in the array
*/

void insertionSort(int arr[], int size){

    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j = j -1;
        }
        
        arr[j + 1] = key;
    }
    
}

void displayArray(int a[], int size)
{
    int i = 0;
    while (i < size)
    {

        std::cout << a[i] << ", ";
        i++;
    }
    std::cout << std::endl;
}

void selectionSort(int arr[], int size){

    int i, j, min, temp;
    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}


void selectionSort2(int arr[], int size){

    for (int i = 0; i < size - 1; i++)
    {
        int maxindex = 0;
        for (int j = 1; j < size - i; j++)
        {
            if (arr[j] > arr[maxindex]){
                maxindex = j;
            }
        }
        int temp = arr[size - i -1];
        arr[size - i -1] = arr[maxindex];
        arr[maxindex] = temp;

    }
    
}
int main(){



    int arr[] = {1,3,4,23,1,21,4,3,4,5,5,0,-1,2, 1000};
    selectionSort2(arr,15);
    displayArray(arr, 15);
    return (0);
}