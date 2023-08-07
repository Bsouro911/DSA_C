#include <stdio.h>
#include <stdlib.h>

// Define the structure for a single node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node with the given data
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

// Function to insert a new node at a specific position in the linked list
void insertAtPosition(struct Node **head, int data, int position)
{
    if (position <= 0)
    {
        insertAtBeginning(head, data);
        return;
    }

    struct Node *newNode = createNode(data);
    struct Node *current = *head;

    for (int i = 1; i < position && current != NULL; i++)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        // Position is beyond the end of the list
        insertAtEnd(head, data);
    }
    else
    {
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to print the linked list
void printList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free the memory occupied by the linked list
void freeList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    struct Node *head = NULL;

    // Insert nodes at the beginning
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    // Insert nodes at the end
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    // Insert node at a specific position
    insertAtPosition(&head, 6, 2);

    // Print the linked list
    printf("Linked List: ");
    printList(head);

    // Free the memory
    freeList(head);

    return 0;
}
