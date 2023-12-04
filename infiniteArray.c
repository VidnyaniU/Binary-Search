// Find the target element in an infinite sorted array (the size of the array is not known)
#include <stdio.h>
int binaryS(int *arr, int target, int start, int end)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (target > arr[mid])
        {
            start = mid + 1;
        }
        else if (target < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            return mid;
        }
        return -1;
    }
}

int findRange(int *arr, int target)
{
    // we will move chunk by chunk and double the size of the chunk every time we don't find the range
    // where target element lies
    // starting chunk of size 2
    int start = 0;
    int end = 1;

    while (target > arr[end]) // if target is less than end that means we have found our range where target lies
    {
        int temp = end + 1;                // the new start
        end = end + (end - start + 1) * 2; // end = previous end + sizeofchunk*2 (double the chunk size)
        start = temp;
    }

    return binaryS(arr, target, start, end);
}
int main()
{
    int arr[] = {2, 3, 5, 6, 7, 9, 10, 12, 36, 48}; // assume this is an infinite array where  size is not known
    int target = 6;
    printf("%d ", findRange(arr, target));
    return 0;
}