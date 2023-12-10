#include <stdio.h>

void binaryS2D(int arr[4][4], int target)
{
    int row = 0;
    int col = 3;
    while (row < sizeof(arr[0]) && col >= 0)
    {
        if (arr[row][col] == target)
        // return row, col;
        {
            printf("Element found at %d %d.\n", row, col);
            break;
        }

        else if (arr[row][col] > target)
            col--;

        else
            row++;
    }
    // return {row, col};
}
int main()
{
    int arr[4][4] = {{10, 20, 30, 40}, {15, 25, 35, 45}, {28, 29, 37, 49}, {33, 34, 38, 50}};
    binaryS2D(arr, 37);

    return 0;
}