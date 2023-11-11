// Top-N Elements: Implement a program that finds the top N elements from a large dataset. Use a suitable sorting algorithm to efficiently retrieve the highest elements.

#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function used in QuickSort
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] >= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// QuickSort function
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the top N elements
void printTopN(int arr[], int size, int N)
{
    quickSort(arr, 0, size - 1);

    printf("Top %d elements: ", N);
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {10, 7, 8, 3, 1, 15, 6, 12, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int N = 3; // Number of top elements to retrieve

    printTopN(arr, size, N);

    return 0;
}