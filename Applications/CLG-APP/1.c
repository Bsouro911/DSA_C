#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Book Structure
typedef struct Book
{
    char title[100];
    char author[50];
    int publicationYear;
    struct Book *next;
} Book;

// Define the Genre Structure
typedef struct Genre
{
    char genreName[50];
    Book *books;
    struct Genre *next;
} Genre;

Genre *genreList = NULL;

// Function to create a new Book node
Book *createBookNode(char title[], char author[], int publicationYear)
{
    Book *newBook = (Book *)malloc(sizeof(Book));
    if (newBook == NULL)
    {
        perror("Memory allocation for Book failed");
        exit(EXIT_FAILURE);
    }
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->publicationYear = publicationYear;
    newBook->next = NULL;
    return newBook;
}

// Function to insert a book at the front of a genre's book list
void insertBookAtFront(Genre *genre, Book *newBook)
{
    newBook->next = genre->books;
    genre->books = newBook;
}

// Function to delete the first book from a genre's book list
void deleteBookFromFront(Genre *genre)
{
    if (genre->books == NULL)
    {
        printf("No books in this genre.\n");
        return;
    }

    Book *temp = genre->books;
    genre->books = temp->next;
    free(temp);
}

// Function to display all books under a specific genre
void displayBooks(Genre *genre)
{
    printf("Books in the genre '%s':\n", genre->genreName);
    Book *currentBook = genre->books;
    while (currentBook != NULL)
    {
        printf("Title: %s\n", currentBook->title);
        printf("Author: %s\n", currentBook->author);
        printf("Publication Year: %d\n\n", currentBook->publicationYear);
        currentBook = currentBook->next;
    }
}

// Function to create a new Genre node
Genre *createGenreNode(char genreName[])
{
    Genre *newGenre = (Genre *)malloc(sizeof(Genre));
    if (newGenre == NULL)
    {
        perror("Memory allocation for Genre failed");
        exit(EXIT_FAILURE);
    }
    strcpy(newGenre->genreName, genreName);
    newGenre->books = NULL;
    newGenre->next = NULL;
    return newGenre;
}

// Function to insert a genre at the front of the genre list
void insertGenreAtFront(char genreName[])
{
    Genre *newGenre = createGenreNode(genreName);
    newGenre->next = genreList;
    genreList = newGenre;
}

// Function to delete the first genre from the genre list and its books
void deleteGenreFromFront()
{
    if (genreList == NULL)
    {
        printf("No genres in the catalog.\n");
        return;
    }

    Genre *temp = genreList;
    genreList = temp->next;
    free(temp);

    printf("Genre deleted from the catalog.\n");
}

// Function to display all genres in the library catalog
void displayGenres()
{
    Genre *currentGenre = genreList;
    printf("Library Catalog Genres:\n");
    while (currentGenre != NULL)
    {
        printf("%s\n", currentGenre->genreName);
        currentGenre = currentGenre->next;
    }
}

int main()
{
    char genreName[50];
    char title[100];
    char author[50];
    int publicationYear;

    while (1)
    {
        printf("\nLibrary Catalog Management System Menu:\n");
        printf("1. Add a Genre\n");
        printf("2. Add a Book\n");
        printf("3. Delete a Genre and its Books\n");
        printf("4. Display All Genres and Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the name of the genre: ");
            scanf("%s", genreName);
            insertGenreAtFront(genreName);
            break;
        case 2:
            printf("Enter the genre name for the book: ");
            scanf("%s", genreName);
            Genre *selectedGenre = genreList;
            while (selectedGenre != NULL && strcmp(selectedGenre->genreName, genreName) != 0)
            {
                selectedGenre = selectedGenre->next;
            }
            if (selectedGenre == NULL)
            {
                printf("Genre not found.\n");
                break;
            }
            printf("Enter the title of the book: ");
            scanf("%s", title);
            printf("Enter the author of the book: ");
            scanf("%s", author);
            printf("Enter the publication year of the book: ");
            scanf("%d", &publicationYear);
            Book *newBook = createBookNode(title, author, publicationYear);
            insertBookAtFront(selectedGenre, newBook);
            break;
        case 3:
            printf("Enter the name of the genre to delete: ");
            scanf("%s", genreName);
            Genre *prevGenre = NULL;
            Genre *currentGenre = genreList;
            while (currentGenre != NULL && strcmp(currentGenre->genreName, genreName) != 0)
            {
                prevGenre = currentGenre;
                currentGenre = currentGenre->next;
            }
            if (currentGenre == NULL)
            {
                printf("Genre not found.\n");
                break;
            }
            if (prevGenre == NULL)
            {
                genreList = currentGenre->next;
            }
            else
            {
                prevGenre->next = currentGenre->next;
            }
            free(currentGenre);
            printf("Genre and its books deleted from the catalog.\n");
            break;
        case 4:
            displayGenres();
            printf("Enter the name of the genre to display its books: ");
            scanf("%s", genreName);
            selectedGenre = genreList;
            while (selectedGenre != NULL && strcmp(selectedGenre->genreName, genreName) != 0)
            {
                selectedGenre = selectedGenre->next;
            }
            if (selectedGenre == NULL)
            {
                printf("Genre not found.\n");
                break;
            }
            displayBooks(selectedGenre);
            break;
        case 5:
            // Clean up memory and exit
            while (genreList != NULL)
            {
                Genre *tempGenre = genreList;
                genreList = genreList->next;
                while (tempGenre->books != NULL)
                {
                    Book *tempBook = tempGenre->books;
                    tempGenre->books = tempGenre->books->next;
                    free(tempBook);
                }
                free(tempGenre);
            }
            exit(EXIT_SUCCESS);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }

    return 0;
}
