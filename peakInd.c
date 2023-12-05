// given a bitonic array (ex.1 , 2 , 5 , 4 , 2) find the peak index of the mountain here index = 2
#include <stdio.h>

// linear search approach takes O(n)
int findPeakIndLinear(int *arr, int size)
{
    int i = 0;
    while (arr[i] < arr[i + 1] && i != size)
    {
        i++;
        if (arr[i] > arr[i + 1])
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1, 2, 5, 4, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("%d ", findPeakIndLinear(arr, size));
    return 0;
}