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

// to remove all the duplicte nodes in a linked list
struct ListNode *rvDuplicates(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    struct ListNode *curr = head;

    while (curr != NULL)
    {
        while (curr->next && curr->next->val == curr->val)
        {
            struct ListNode *duplicate = curr->next;
            curr->next = duplicate->next;
            free(duplicate);
        }
        curr = curr->next;
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
    head = rvDuplicates(head);

    printf("Linked List after removing duplicates: ");
    printList(head);

    // Free memory for the list
    deleteList(head);

    return 0;
}
