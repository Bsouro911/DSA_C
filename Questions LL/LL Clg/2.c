#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Reverse a linked list using iterative approach
struct Node *reverse(struct Node *head)
{
    struct Node *curr = head;
    struct Node *prev = NULL;
    struct Node *next = NULL;

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

// Function to reverse a linked list recursively
struct Node *reverseRecursive(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head; // Base case: empty list or last node
    }

    struct Node *rest = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest; // New head of the reversed list
}

// Function to print the linked list
void printLinkedList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the linked list
void freeLinkedList(struct Node *head)
{
    while (head != NULL)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function to test the reverse functions
int main()
{
    struct Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    printf("Original linked list: ");
    printLinkedList(head);

    struct Node *reversedIterative = reverse(head);
    printf("Reversed iterative: ");
    printLinkedList(reversedIterative);

    struct Node *head2 = createNode(5);
    head2->next = createNode(6);
    head2->next->next = createNode(7);
    head2->next->next->next = createNode(8);

    printf("Original linked list: ");
    printLinkedList(head2);

    struct Node *reversedRecursive = reverseRecursive(head2);
    printf("Reversed recursive: ");
    printLinkedList(reversedRecursive);

    freeLinkedList(reversedIterative);
    freeLinkedList(reversedRecursive);

    return 0;
}
