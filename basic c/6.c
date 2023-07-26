#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[100];
    char author[100];
};

int main() {
    int numBooks;
    printf("Enter the number of books: ");
    scanf("%d", &numBooks);

    // Dynamically allocate memory for the array of Book structures
    struct Book* books = (struct Book*)malloc(numBooks * sizeof(struct Book));

    // Check if memory allocation was successful
    if (books == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    // Input book details using pointer arithmetic
    struct Book* ptr = books;
    for (int i = 0; i < numBooks; i++) {
        printf("Enter title for book %d: ", i + 1);
        scanf(" %[^\n]", ptr->title);

        printf("Enter author for book %d: ", i + 1);
        scanf(" %[^\n]", ptr->author);

        ptr++; // Move the pointer to the next Book structure in the array
    }

    // Output book details using pointer arithmetic
    ptr = books;
    printf("\nBook Details:\n");
    for (int i = 0; i < numBooks; i++) {
        printf("Book %d:\n", i + 1);
        printf("Title: %s\n", ptr->title);
        printf("Author: %s\n\n", ptr->author);

        ptr++; // Move the pointer to the next Book structure in the array
    }

    // Don't forget to free the dynamically allocated memory
    free(books);

    return 0;
}
