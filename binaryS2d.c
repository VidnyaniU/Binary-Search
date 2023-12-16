#include <stdio.h>

struct rowCol
{
    int row, col;
};

typedef struct rowCol Struct;

Struct binaryS2D(int arr[4][4], int target)
{
    int row = 0;
    int col = 3;

    Struct s;

    while (row < sizeof(arr[0]) && col >= 0)
    {
        s.row = row;
        s.col = col;

        if (arr[row][col] == target)
            return s;
        // {
        //     printf("Element found at %d %d.\n", row, col);
        //     break;
        // }

        else if (arr[row][col] > target)
            col--;

        else
            row++;
    }
    return s;
}
int main()
{
    int arr[4][4] = {{10, 20, 30, 40}, {15, 25, 35, 45}, {28, 29, 37, 49}, {33, 34, 38, 50}};

    Struct res = binaryS2D(arr, 37);

    printf("%d %d", res.row, res.col);

    return 0;
}
