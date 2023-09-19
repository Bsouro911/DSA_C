#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to insert a node at the end of the linked list
void append(struct Node **head_ref, int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    struct Node *last = *head_ref;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
}

// Function to split the linked list into two lists (even and odd indexed elements)
void splitEvenOdd(struct Node *head, struct Node **even_head, struct Node **odd_head)
{
    struct Node *even_tail = NULL;
    struct Node *odd_tail = NULL;
    int index = 0;

    while (head != NULL)
    {
        if (index % 2 == 0)
        {
            if (*even_head == NULL)
            {
                *even_head = head;
                even_tail = head;
            }
            else
            {
                even_tail->next = head;
                even_tail = even_tail->next;
            }
        }
        else
        {
            if (*odd_head == NULL)
            {
                *odd_head = head;
                odd_tail = head;
            }
            else
            {
                odd_tail->next = head;
                odd_tail = odd_tail->next;
            }
        }

        index++;
        head = head->next;
    }

    if (even_tail != NULL)
    {
        even_tail->next = NULL;
    }
    if (odd_tail != NULL)
    {
        odd_tail->next = NULL;
    }
}

// Function to print the linked list
void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to free the memory used by the linked list
void freeList(struct Node *head)
{
    struct Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    struct Node *head = NULL;
    struct Node *even_head = NULL;
    struct Node *odd_head = NULL;

    // Test data: 1->2->3->4->5
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    printf("Original Linked List: ");
    printList(head);

    splitEvenOdd(head, &even_head, &odd_head);

    printf("Even-indexed Linked List: ");
    printList(even_head);

    printf("Odd-indexed Linked List: ");
    printList(odd_head);

    // Free the memory used by the linked lists
    freeList(even_head);
    freeList(odd_head);

    return 0;
}
