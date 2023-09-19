#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

// Function to remove the nth node from the end of the linked list.
struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *first = dummy;
    struct ListNode *second = dummy;

    // Advance the first pointer to the (n+1)th node from the beginning.
    for (int i = 0; i <= n; i++)
    {
        first = first->next;
    }

    // Move both pointers simultaneously until the first pointer reaches the end.
    while (first != NULL)
    {
        first = first->next;
        second = second->next;
    }

    // Remove the nth node from the end.
    struct ListNode *temp = second->next;
    second->next = second->next->next;
    free(temp);

    return dummy->next;
}

// Function to create a new node with the given value.
struct ListNode *createNode(int val)
{
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to create a linked list from an array of integers.
struct ListNode *createLinkedList(int *arr, int size)
{
    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;

    for (int i = 0; i < size; i++)
    {
        struct ListNode *newNode = createNode(arr[i]);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

// Function to print the linked list.
void printLinkedList(struct ListNode *head)
{
    struct ListNode *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the linked list.
void freeLinkedList(struct ListNode *head)
{
    struct ListNode *current = head;
    while (current != NULL)
    {
        struct ListNode *temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    struct ListNode *head = createLinkedList(arr, size);
    int n = 2;

    printf("Original linked list: ");
    printLinkedList(head);

    head = removeNthFromEnd(head, n);

    printf("Modified linked list: ");
    printLinkedList(head);

    freeLinkedList(head);
    return 0;
}
