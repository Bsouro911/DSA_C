#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to insert a new node at the end of the linked list
void insert(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *curr = *head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

// function to merge two sorted linked lists
struct Node *mergeTwoLists(struct Node *l1, struct Node *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    struct Node *mergedList = NULL;

    if (l1->data <= l2->data)
    {
        mergedList = l1;
        mergedList->next = mergeTwoLists(l1->next, l2);
    }

    else
    {
        mergedList = l2;
        mergedList->next = mergeTwoLists(l2->next, l1);
    }

    return mergedList;
}

// Function to print the linked list
void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node *list1 = NULL;
    struct Node *list2 = NULL;

    // Insert elements into the first linked list
    insert(&list1, 1);
    insert(&list1, 3);
    insert(&list1, 5);
    insert(&list1, 5);

    // Insert elements into the second linked list
    insert(&list2, 2);
    insert(&list2, 4);
    insert(&list2, 6);

    printf("First sorted linked list: ");
    printList(list1);

    printf("Second sorted linked list: ");
    printList(list2);

    // Merge the two sorted linked lists
    struct Node *mergedList = mergeTwoLists(list1, list2);

    printf("Merged sorted linked list: ");
    printList(mergedList);

    // Free memory
    while (mergedList != NULL)
    {
        struct Node *temp = mergedList;
        mergedList = mergedList->next;
        free(temp);
    }

    return 0;
}
