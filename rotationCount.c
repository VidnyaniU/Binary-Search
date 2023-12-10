// find the how many times the sorted array has been rotated . ans= pivot+1
#include <stdio.h>

// works with duplicates as well
int findPivot(int *arr, int length)
{
    int start = 0;
    int end = length - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (mid < end && arr[mid] > arr[mid + 1])
        {
            return mid;
        }

        if (mid > start && arr[mid] < arr[mid - 1])
        {
            return mid - 1;
        }

        if (arr[mid] <= arr[0])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }

        if (arr[mid] == arr[start] && arr[mid] == arr[end])
        {
            if (start < end && arr[start] > arr[start + 1])
            {
                return start;
            }
            start++;
            if (end > start && arr[end] < arr[end - 1])
            {
                return end - 1;
            }
            end--;
        }
        else if (arr[start] < arr[mid] || (arr[start] == arr[mid] && arr[mid] > arr[end]))
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {4, 5, 6, 6, 7, 7, 0, 1, 2, 3};
    int length = sizeof(arr) / sizeof(arr[0]);
    int pivot = findPivot(arr, length);
    printf("%d ", pivot + 1);

    return 0;
}