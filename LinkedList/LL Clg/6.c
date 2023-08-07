#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *createNode(int value)
{
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

void deleteList(struct ListNode *head)
{
    struct ListNode *current = head;
    struct ListNode *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

struct ListNode *removeDuplicates(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    struct ListNode *current = head;

    while (current->next != NULL)
    {
        if (current->val == current->next->val)
        {
            struct ListNode *duplicate = current->next;
            current->next = current->next->next;
            free(duplicate);
        }
        else
        {
            current = current->next;
        }
    }

    return head;
}

void printList(struct ListNode *head)
{
    struct ListNode *current = head;

    while (current != NULL)
    {
        printf("%d -> ", current->val);
        current = current->next;
    }

    printf("NULL\n");
}

// Efficient implementation to remove duplicates in sorted linked list
struct ListNode *removeDuplicatesEfficient(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    struct ListNode *current = head;

    while (current != NULL && current->next != NULL)
    {
        if (current->val == current->next->val)
        {
            struct ListNode *duplicate = current->next;
            current->next = duplicate->next;
            free(duplicate);
        }
        else
        {
            current = current->next;
        }
    }

    return head;
}

int main()
{
    // Create a sorted linked list with duplicates
    struct ListNode *head = createNode(1);
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(3);
    head->next->next->next->next->next = createNode(4);

    printf("Original Linked List: ");
    printList(head);

    // Remove duplicates from the list using the efficient version
    head = removeDuplicatesEfficient(head);

    printf("Linked List after removing duplicates: ");
    printList(head);

    // Free memory for the list
    deleteList(head);

    return 0;
}
