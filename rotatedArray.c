// find the target element index from a rotated sorted array.
#include <stdio.h>

int binarySearch(int *arr, int start, int end, int target)
{

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (target == arr[mid])
        {
            return mid;
        }
        else if (target > arr[mid])
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

// for without duplicates
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
    }
    return -1;
}
// for with duplicates
int findPivotWithDuplicates(int *arr, int length)
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

        if(arr[mid]==arr[start] && arr[mid]==arr[end])
        {
            if(start <end && arr[start] >arr[start+1]){
                return start;
            }
            start++;
            if(end >start && arr[end] < arr[end-1]){
                return end -1;
                
            }
            end --;
        }
        else if(arr[start] <arr [mid] || (arr[start]==arr[mid] && arr[mid] >arr[end])){
            start = mid +1;
            
        }
        else{
        end = mid -1;
        }
    }
    return -1;
}
int search(int *arr, int length, int target)
{

    int pivot = findPivot(arr, length);

    // no pivot found that means it is a normal sorted array
    if (pivot == -1)
    {
        return binarySearch(arr, 0, length - 1, target);
    }

    // pivot is the required answer
    if (arr[pivot] == target)
    {
        return pivot;
    }

    if (arr[0] <= target)
    {
        return binarySearch(arr, 0, pivot - 1, target); // search in left subarray
    }
    else
    {
        return binarySearch(arr, pivot + 1, length - 1, target); // search in right subarray
    }

    return -1;
}
int main()
{
    int arr[] = {4, 5, 6, 7, 0, 1, 2, 3};
    int length = sizeof(arr) / sizeof(arr[0]);
    int ans = search(arr, length, 0); // should return 4
    printf("%d ", ans);

    return 0;
}
