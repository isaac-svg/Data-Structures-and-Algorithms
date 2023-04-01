#include <iostream>
using namespace std;

int main()
{
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
}
