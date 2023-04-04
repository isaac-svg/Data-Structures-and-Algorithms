#include <iostream>
using namespace std;
#define MAX 100
#include <cstdlib>
void swap(int arr[], int x, int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

// location of smallest function
int locOfSmallest(int a[], int start, int end)
{
    int i = start;
    int j = i;
    while (i < end)
    {
        if (a[i] < a[j])
        {
            j = i;
        }
        i += 1;
    }
    return j;
}
void displayArray(int a[], int size)
{
    int i = 0;
    while (i < size)
    {

        cout << a[i] << ", ";
        i++;
    }
    cout << endl;
}
void selectionSort(int a[], int size)
{
    int i = 0;
    while (i < size - 1)
    {
        int j = locOfSmallest(a, i, size - 1);
        swap(a, i, j);
        i++;
    }
}
int main()
{
    int a[] = {12, 23, 34, 4565, 6, 87, 98, 2, 78, 67, 2, 1, 21, 12, 6768};
    int size = sizeof(a) / sizeof(int);
    displayArray(a, size);
    selectionSort(a, size);
    displayArray(a, size);
    return 0;
}
void BubbleSort(int a[])
{
    int arr[MAX];
    int n;
    cout << "Please enter an integer n" << endl;
    cin >> n;
    // putting in random integers
    for (size_t i = 0; i < n; i++)
    {
        arr[i] = rand();
    }
    // printing random integers
    for (size_t j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl;
    cout << endl;
    cout << endl;

    // sorting in ascending order

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // printing sorted arr

    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}