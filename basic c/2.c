#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure named "Student"
struct Student {
    char name[50];
    int age;
};

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Dynamically allocate memory for the array of structures
    struct Student* students = (struct Student*)malloc(numStudents * sizeof(struct Student));

    // Check if memory allocation was successful
    if (students == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    // Input student data using pointer arithmetic
    struct Student* ptr = students;
    for (int i = 0; i < numStudents; i++) {
        printf("Enter name for student %d: ", i + 1);
        scanf("%s", ptr->name);

        printf("Enter age for student %d: ", i + 1);
        scanf("%d", &(ptr->age));

        ptr++; // Move the pointer to the next structure in the array
    }

    // Output student data using pointer arithmetic
    ptr = students;
    printf("\nStudent Data:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", ptr->name);
        printf("Age: %d\n\n", ptr->age);

        ptr++; // Move the pointer to the next structure in the array
    }

    // Don't forget to free the dynamically allocated memory
    free(students);

    return 0;
}
