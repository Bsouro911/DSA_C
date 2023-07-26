#include <stdio.h>
#include <stdlib.h>

// Function to dynamically allocate memory for a matrix of size rows x cols
int** allocateMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));

    if (matrix == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        exit(1);
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));

        if (matrix[i] == NULL) {
            printf("Memory allocation failed. Exiting...\n");
            exit(1);
        }
    }

    return matrix;
}

// Function to free the memory allocated for a matrix
void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to input elements of a matrix from the user
void inputMatrix(int **matrix, int rows, int cols) {
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void printMatrix(int **matrix, int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
int** matrixAddition(int **matrix1, int **matrix2, int rows, int cols) {
    int **result = allocateMatrix(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
}

// Function to multiply two matrices
int** matrixMultiplication(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Invalid matrix dimensions for multiplication. Exiting...\n");
        exit(1);
    }

    int **result = allocateMatrix(rows1, cols2);

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

// Function to transpose a matrix
int** matrixTranspose(int **matrix, int rows, int cols) {
    int **result = allocateMatrix(cols, rows);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}

int main() {
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows and columns for matrix 1: ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter the number of rows and columns for matrix 2: ");
    scanf("%d %d", &rows2, &cols2);

    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible with the given dimensions. Exiting...\n");
        return 1;
    }

    int **matrix1 = allocateMatrix(rows1, cols1);
    int **matrix2 = allocateMatrix(rows2, cols2);

    printf("Enter elements of matrix 1:\n");
    inputMatrix(matrix1, rows1, cols1);

    printf("Enter elements of matrix 2:\n");
    inputMatrix(matrix2, rows2, cols2);

    printf("Matrix 1:\n");
    printMatrix(matrix1, rows1, cols1);

    printf("Matrix 2:\n");
    printMatrix(matrix2, rows2, cols2);

    int **sum = matrixAddition(matrix1, matrix2, rows1, cols1);
    printf("Matrix Sum:\n");
    printMatrix(sum, rows1, cols1);
    freeMatrix(sum, rows1);

    int **product = matrixMultiplication(matrix1, matrix2, rows1, cols1, rows2, cols2);
    printf("Matrix Product:\n");
    printMatrix(product, rows1, cols2);
    freeMatrix(product, rows1);

    int **transpose = matrixTranspose(matrix1, rows1, cols1);
    printf("Matrix 1 Transpose:\n");
    printMatrix(transpose, cols1, rows1);
    freeMatrix(transpose, cols1);

    freeMatrix(matrix1, rows1);
    freeMatrix(matrix2, rows2);

    return 0;
}
