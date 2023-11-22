#include <stdio.h>
int binarySIterative(int arr[], int left, int right, int value)
{
    int mid = left + (right - left) / 2;
    while (left <= right)
    {
        if (value == arr[mid])
            return mid;
        if (value < arr[mid])
            right = mid - 1;
        else
            right = mid + 1;
    }

    return -1;
}

int binarySRecursive(int arr[], int left, int right, int value)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (value == arr[mid])
            return mid;
        if (value < arr[mid])
            binarySRecursive(arr, left, mid - 1, value);
        else
            binarySRecursive(arr, mid + 1, right, value);
    }

    return -1;
}
int main()
{
    int arr[] = {2, 3, 5, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int val = 6;
    printf("Element is available at index %d.\n", binarySRecursive(arr, 0, size - 1, val));

    return 0;
}