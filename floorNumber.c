// Q.From a given sorted array find the floor number
// floor number  is a greatest number which is less than or equal to target number

#include <stdio.h>
int floorOfANum(int arr[], int left, int right, int target)
{
    if (target == 0)
    {
        return -1;
    }

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return right;
}
int main()
{
    int arr[] = {2, 3, 5, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 6;
    int floorN = arr[floorOfANum(arr, 0, size - 1, target)];
    printf("Ceiling of %d from given array is: %d.\n", target, floorN);

    return 0;
}
