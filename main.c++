#include <iostream>
using namespace std;
void insetionSort(int a[], int size);

int main()
{
    int a[] = {
        12,
        23,
        34,
        4565,
        6,
        87,
        98,

    };
    int size = sizeof(a) / sizeof(int);
    insetionSort(a, size);
    for (size_t i = 0; i < size; i++)

    {
        cout << a[i] << ", ";
    }
}
void swap(int a[], int start, int end)
{
    int temp = a[start];
    a[start] = a[end];
    a[end] = temp;
}
void insetionSort(int a[], int size)
{
    int temp, i;
    for (i = 1; i < size; i++)
    {
        temp = a[i];
        for (size_t j = i - 1; j < size; j--)
        {
            if (temp < a[j])
            {
                swap(a, j, j + 1);
            }
        }
    }
}
int FindElementIn2DArray(int *nums[], int r, int c, int value)
{

    int row{0};
    int col = c - 1;
    while (row < r && col >= 0)
    {
        if (nums[row][col] == value)
        {
            return 1;
        }
        else if (value > nums[row][col])
        {
            col--;
        }
        else
        {
            row++;
        }
    }
    return 1;
}
