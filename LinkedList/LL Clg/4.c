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
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to merge two sorted linked lists
struct Node *mergeSortedLists(struct Node *list1, struct Node *list2)
{
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }

    struct Node *mergedList = NULL;

    if (list1->data <= list2->data)
    {
        mergedList = list1;
        mergedList->next = mergeSortedLists(list1->next, list2);
    }
    else
    {
        mergedList = list2;
        mergedList->next = mergeSortedLists(list1, list2->next);
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

    // Insert elements into the second linked list
    insert(&list2, 2);
    insert(&list2, 4);
    insert(&list2, 6);

    printf("First sorted linked list: ");
    printList(list1);

    printf("Second sorted linked list: ");
    printList(list2);

    // Merge the two sorted linked lists
    struct Node *mergedList = mergeSortedLists(list1, list2);

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
