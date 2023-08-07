#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *findMiddleNode(struct ListNode *head)
{
    if (head == NULL)
        return NULL;

    struct ListNode *slow_ptr = head;
    struct ListNode *fast_ptr = head;

    // Move slow_ptr by one node and fast_ptr by two nodes
    // When fast_ptr reaches the end, slow_ptr will be at the middle
    while (fast_ptr != NULL && fast_ptr->next != NULL)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }

    return slow_ptr;
}

// Helper function to create a new node
struct ListNode *createNode(int val)
{
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Helper function to append a new node at the end of the list
void appendNode(struct ListNode **head, int val)
{
    struct ListNode *newNode = createNode(val);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct ListNode *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Helper function to print the linked list
void printList(struct ListNode *head)
{
    struct ListNode *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct ListNode *head = NULL;

    // Example: create a linked list 1 -> 2 -> 3 -> 4 -> 5
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);
    // appendNode(&head, 6);

    printf("Original Linked List: ");
    printList(head);

    struct ListNode *middleNode = findMiddleNode(head);

    if (middleNode != NULL)
    {
        printf("Middle Node: %d\n", middleNode->val);
    }
    else
    {
        printf("The list is empty.\n");
    }

    return 0;
}
