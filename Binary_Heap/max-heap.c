#include <stdio.h>

void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void heapify(int arr[], int size, int i)
{
    int left_child, right_child, largest;

    left_child = 2 * i + 1;
    right_child = 2 * i + 2;

    if (left_child >= size)
        return;

    largest = i;

    if (left_child < size && arr[left_child] > arr[largest])
        largest = left_child;
    if (right_child < size && arr[right_child] > arr[largest])
        largest = right_child;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, size, largest);
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
