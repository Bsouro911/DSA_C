#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for the linked list
struct Node
{
    char data;
    struct Node *next;
};

// Function to create a new Node
struct Node *newNode(char data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to reverse the linked list
struct Node *reverseLinkedList(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Simple implementation to check if the linked list is a palindrome
bool isPalindromeSimple(struct Node *head)
{
    struct Node *reversedHead = reverseLinkedList(head);
    while (head != NULL)
    {
        if (head->data != reversedHead->data)
            return false;
        head = head->next;
        reversedHead = reversedHead->next;
    }
    return true;
}

// Function to check if the linked list is a palindrome using a stack
bool isPalindromeStack(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head;
    struct Node *stack = NULL;

    // Traverse the linked list to find the middle node
    while (fast != NULL && fast->next != NULL)
    {
        struct Node *newStackNode = newNode(slow->data); // Rename the variable here
        newStackNode->next = stack;
        stack = newStackNode;
        slow = slow->next;
        fast = fast->next->next;
    }

    // If the linked list has odd number of nodes, skip the middle node
    if (fast != NULL)
        slow = slow->next;

    // Compare the second half of the linked list with the elements in the stack
    while (slow != NULL)
    {
        if (slow->data != stack->data)
            return false;
        struct Node *temp = stack;
        stack = stack->next;
        free(temp);
        slow = slow->next;
    }

    return true;
}

// Function to print the linked list
void printLinkedList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%c -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the linked list
void freeLinkedList(struct Node *head)
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
    // Create a sample linked list for testing
    struct Node *head = newNode('r');
    head->next = newNode('a');
    head->next->next = newNode('d');
    head->next->next->next = newNode('a');
    head->next->next->next->next = newNode('r');

    // Simple implementation
    printf("Linked list: ");
    printLinkedList(head);
    if (isPalindromeSimple(head))
        printf("Simple Implementation: The linked list is a palindrome.\n");
    else
        printf("Simple Implementation: The linked list is not a palindrome.\n");

    // Free the memory allocated for the linked list
    freeLinkedList(head);

    // Create the same sample linked list for testing the stack implementation
    head = newNode('t');
    head->next = newNode('a');
    head->next->next = newNode('b');
    head->next->next->next = newNode('c');
    head->next->next->next->next = newNode('a');

    // Stack implementation
    printf("\nLinked list: ");
    printLinkedList(head);
    if (isPalindromeStack(head))
        printf("Stack Implementation: The linked list is a palindrome.\n");
    else
        printf("Stack Implementation: The linked list is not a palindrome.\n");

    // Free the memory allocated for the linked list
    freeLinkedList(head);

    return 0;
}
