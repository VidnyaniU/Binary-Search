// find the smallest letter in the sorted character array which is greater than the target letter

// here we will use binary search as we used for ceil
#include <stdio.h>

char nextGreatestLetter(char *letters, int lettersSize, char target)
{

    int left = 0;
    int right = lettersSize - 1;

    while (left <= right)
    {
        // int mid = (left + right) / 2; // might be possible that (left + right) exceeds the range of int
        int mid = left + (right - left) / 2;

        if (target < letters[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return letters[left % lettersSize]; // % lettersSize is if target character does not exist, return the first character in letters
}
int main()
{
    char arr[] = {'a', 'b', 'e', 'f', 'q'};
    char target = 'f';
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    printf("Next greatest letter is %c .", nextGreatestLetter(arr, arrSize, target));
    return 0;
}