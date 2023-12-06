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

// Binary search approach takes O(log n)

int findPeakIndBinary(int *arr, int size)
{
    int start = 0;
    int end = size - 1;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] > arr[mid + 1])
        {
            // this means that we are in decreasing part of the array and the peak element lies in the left part
            // it can be mid as well thatswhy no mid -1
            end = mid;
        }
        else
        {
            // this means that we are in increasing part of the array and the peak element lies in the right part

            start = mid + 1;
        }
    }

    // when start == end we will get our peak index
    return start; // or return end
}

int main()
{
    int arr[] = {1, 2, 5, 4, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    // printf("%d ", findPeakIndLinear(arr, size));
    printf("%d ", findPeakIndBinary(arr, size));

    return 0;
}