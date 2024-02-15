#include "sort.h"


void bubble_sort(int *arr, int size){

    bool swapped =  true;
    for (size_t i = 0; ((i < size)&& swapped); i++)
    {
         swapped = false;
        for (size_t j = 0; j < size -1 -i; j++)
        {
            if (arr[j] > arr[j + 1]){
               int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        
    }
    
}


int main()
{
    int data[] = { 9, 1, 8, 2, 7, 3, 6, 4, 5, -1,19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    bubble_sort(data, 20);

    print_array(data, 20);
    return 0;
}