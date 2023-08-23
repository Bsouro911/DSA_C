#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *middle(struct ListNode *head)
{
    struct ListNode *fast = head;
    struct ListNode *slow = head;

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
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

    struct ListNode *middleNode = middle(head);

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
