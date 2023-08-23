#include <stdio.h>
#include <stdlib.h>

// Define the structure for a single node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

// create a newNode

struct Node *createNewNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// insert a node at the begining

void insertAt_begin(struct Node **head, int data)
{
    struct Node *insertNew = createNewNode(data);
    insertNew->next = *head;
    *head = insertNew;
}

// insert a node at the end

void insertAt_end(struct Node **head, int data)
{
    struct Node *insertNew = createNewNode(data);
    if (*head == NULL)
    {
        *head = insertNew;
        return;
    }

    struct Node *curr = *head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = insertNew;
}

// insert a node at any given position

void insertAt_pos(struct Node **head, int data, int pos)
{
    if (pos <= 0)
    {
        insertAt_begin(head, data);
        return;
    }

    struct Node *insertNew = createNewNode(data);
    struct Node *curr = *head;

    for (int i = 1; i < pos && curr != NULL; i++)
    {
        curr = curr->next;
    }

    if (curr == NULL)
    {
        insertAt_end(head, data);
    }

    else
    {
        insertNew->next = curr->next;
        curr->next = insertNew;
    }
}

// display the linked list

void dispalyList(struct Node *head)
{
    struct Node *curr = head;
    while (curr != NULL)
    {
        printf("%d ->", curr->data);
        curr = curr->next;
    }
    printf("NULL");
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
    insertAt_begin(&head, 3);
    insertAt_begin(&head, 2);
    // insertAtBeginning(&head, 1);

    // Insert nodes at the end
    // insertAtEnd(&head, 4);
    // insertAtEnd(&head, 5);

    // Insert node at a specific position
    // insertAtPosition(&head, 6, 2);

    // Print the linked list
    printf("Linked List: ");
    dispalyList(head);

    // Free the memory
    freeList(head);

    return 0;
}
