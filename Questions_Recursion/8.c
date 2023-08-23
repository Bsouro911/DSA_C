#include <stdio.h>

int binarySearchRecursive(int arr[], int target, int left, int right)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2; // Calculate middle index to divide the array

        if (arr[mid] == target)
        {
            return mid; // Found the target
        }
        else if (arr[mid] < target)
        {
            return binarySearchRecursive(arr, target, mid + 1, right); // Search in the right half
        }
        else
        {
            return binarySearchRecursive(arr, target, left, mid - 1); // Search in the left half
        }
    }
    return -1; // Target not found
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    int target = 12;

    int index = binarySearchRecursive(arr, target, 0, n - 1);

    if (index != -1)
    {
        printf("Target found at index %d\n", index);
    }
    else
    {
        printf("Target not found in the list\n");
    }

    return 0;
}
