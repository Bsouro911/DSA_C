#include <stdio.h>

int* findMaxElement(int arr[], int size) {
    if (size == 0) {
        return NULL; // Return NULL for an empty array
    }

    int *maxPtr = &arr[0]; // Pointer to the first element of the array

    for (int i = 1; i < size; i++) {
        if (arr[i] > *maxPtr) {
            maxPtr = &arr[i]; // Update maxPtr to point to the new maximum element
        }
    }

    return maxPtr;
}

int main() {
    int arr[] = {45, 78, 32, 91, 56, 72};
    int size = sizeof(arr) / sizeof(arr[0]);

    int *maxElementPtr = findMaxElement(arr, size);

    if (maxElementPtr != NULL) {
        printf("Maximum element in the array: %d\n", *maxElementPtr);
    } else {
        printf("Array is empty.\n");
    }

    return 0;
}
