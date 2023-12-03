// Find the first and last position of the target in a sorted array
#include <stdio.h>
#include <stdbool.h>

int search(int nums[], int numsSize, int target, bool findStartIndex)
{

    int start = 0;
    int end = numsSize - 1;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (target > nums[mid])
        {
            start = mid + 1;
        }
        else if (target < nums[mid])
        {
            end = mid - 1;
        }
        else
        {
            ans = mid; // potential answer found
            if (findStartIndex == true)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
    }
    return ans;
}

int main()
{
    int nums[] = {2, 4, 5, 6, 6, 6, 6, 7, 9};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int ans[] = {-1, -1};
    int target = 6;
    ans[0] = search(nums, numsSize, target, true);
    if (ans[0] != -1)
    {
        ans[1] = search(nums, numsSize, target, false);
    }

    for (int i = 0; i < 2; i++)
    {
        printf("%d ", ans[i]);
    }

    return 0;
}