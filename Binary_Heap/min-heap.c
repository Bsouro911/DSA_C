#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// 0 - based indexing
// Max Heap
void heapify(int arr[], int size, int i)
{
    int smallest, left_child, right_child;
    left_child = 2 * i + 1;
    right_child = 2 * i + 2;

    if (left_child >= size)
        return;

    smallest = i;

    // if left child or right child is larger than the root
    if (left_child < size && arr[left_child] < arr[smallest])
        smallest = left_child;
    if (right_child < size && arr[right_child] < arr[smallest])
        smallest = right_child;

    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, size, smallest);
    }
}

int main()
{
    int arr[] = {11, 2, 9, 13, 3, 25, 17, 1, 90, 57};
    int i, size;

    size = 10;
    for (i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }

    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}