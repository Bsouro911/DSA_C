// Student Grade Sorting: Write a program that sorts a list of student records based on their grades. Allow users to choose whether to sort by ascending or descending grades.

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[50];
    int grade;
} Student;

// Function to compare two student records based on grades
int compareGrades(const void *a, const void *b)
{
    return ((Student *)a)->grade - ((Student *)b)->grade;
}

int main()
{
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Allocate memory for an array of students
    Student *students = (Student *)malloc(numStudents * sizeof(Student));

    // Input student records
    for (int i = 0; i < numStudents; ++i)
    {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter the grade of student %d: ", i + 1);
        scanf("%d", &students[i].grade);
    }

    int choice;
    printf("Enter 1 to sort in ascending order or 2 to sort in descending order: ");
    scanf("%d", &choice);

    // Use qsort to sort the array based on grades
    if (choice == 1)
    {
        qsort(students, numStudents, sizeof(Student), compareGrades);
    }
    else if (choice == 2)
    {
        qsort(students, numStudents, sizeof(Student), compareGrades);
        // Reverse the array to get descending order
        for (int i = 0; i < numStudents / 2; ++i)
        {
            Student temp = students[i];
            students[i] = students[numStudents - i - 1];
            students[numStudents - i - 1] = temp;
        }
    }
    else
    {
        printf("Invalid choice. Exiting...\n");
        return 1;
    }

    // Display sorted student records
    printf("\nSorted Student Records:\n");
    for (int i = 0; i < numStudents; ++i)
    {
        printf("Name: %s, Grade: %d\n", students[i].name, students[i].grade);
    }

    // Free allocated memory
    free(students);

    return 0;
}
