#include <stdio.h>
#include <stdlib.h>

void resizeArray(int **arr, int *size) {
    int new_size = *size * 2;

    // Reallocate memory for the resized array
    int *temp = (int *)realloc(*arr, new_size * sizeof(int));

    if (temp != NULL) {
        *arr = temp; // Update the original array pointer to the resized array
        *size = new_size; // Update the size to the new size
    } else {
        printf("Memory reallocation failed. Array remains unchanged.\n");
    }
}

int main() {
    int size = 5;
    int *arr = (int *)malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    printf("Original array (size %d):\n", size);
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
        printf("%d ", arr[i]);
    }
    printf("\n");

    resizeArray(&arr, &size);

    printf("Resized array (size %d):\n", size);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}
