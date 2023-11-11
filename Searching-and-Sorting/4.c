//  Phonebook Application: Create a phonebook application that allows users to add, delete, and search for contacts. Use an appropriate data structure (e.g., hash table or balanced search tree) for efficient operations.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

// Structure to represent a contact
struct Contact
{
    char name[50];
    char phoneNumber[15];
};

// Structure to represent a node in the hash table
struct Node
{
    struct Contact contact;
    struct Node *next;
};

// Hash table
struct Node *hashTable[TABLE_SIZE];

// Hash function
unsigned int hash(char *key)
{
    unsigned int hashValue = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        hashValue = key[i] + (hashValue << 5) - hashValue;
    }
    return hashValue % TABLE_SIZE;
}

// Function to add a contact to the phonebook
void addContact(char name[], char phoneNumber[])
{
    struct Contact newContact;
    strcpy(newContact.name, name);
    strcpy(newContact.phoneNumber, phoneNumber);

    unsigned int index = hash(name);

    // Create a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->contact = newContact;
    newNode->next = NULL;

    // Insert the node into the hash table
    if (hashTable[index] == NULL)
    {
        hashTable[index] = newNode;
    }
    else
    {
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }

    printf("Contact added successfully.\n");
}

// Function to search for a contact in the phonebook
void searchContact(char name[])
{
    unsigned int index = hash(name);

    struct Node *currentNode = hashTable[index];

    while (currentNode != NULL)
    {
        if (strcmp(currentNode->contact.name, name) == 0)
        {
            printf("Contact found: %s - %s\n", currentNode->contact.name, currentNode->contact.phoneNumber);
            return;
        }
        currentNode = currentNode->next;
    }

    printf("Contact not found.\n");
}

// Function to delete a contact from the phonebook
void deleteContact(char name[])
{
    unsigned int index = hash(name);

    struct Node *currentNode = hashTable[index];
    struct Node *prevNode = NULL;

    while (currentNode != NULL)
    {
        if (strcmp(currentNode->contact.name, name) == 0)
        {
            if (prevNode == NULL)
            {
                // If the node to be deleted is the first node in the list
                hashTable[index] = currentNode->next;
            }
            else
            {
                prevNode->next = currentNode->next;
            }

            free(currentNode);
            printf("Contact deleted successfully.\n");
            return;
        }

        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    printf("Contact not found.\n");
}

int main()
{
    // Initialize the hash table
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i] = NULL;
    }

    // Example usage
    addContact("John Doe", "123-456-7890");
    addContact("Jane Doe", "987-654-3210");
    searchContact("John Doe");

    // Delete a contact
    deleteContact("Jane Doe");

    // Search again after deletion
    searchContact("Jane Doe");

    return 0;
}
