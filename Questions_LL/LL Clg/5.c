#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Definition for a linked list node
struct ListNode
{
    int val;
    struct ListNode *next;
};

// check if a linked list contains a cuycle or not
bool isCyclic(struct ListNode *head)
{
    // base case
    if (head == NULL || head->next == NULL)
    {
        return false;
    }

    struct ListNode *fast = head;
    struct ListNode *slow = head;

    while (fast && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}

// Function to find the node at which the cycle starts
struct ListNode *detectCycle(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;
    bool hasCycle = false;

    // Find the meeting point of slow and fast pointers
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            hasCycle = true;
            break;
        }
    }

    // If there is no cycle, return NULL
    if (!hasCycle)
    {
        return NULL;
    }

    // Move slow pointer back to the head and advance both pointers at the same pace
    // The point where they meet again is the node at which the cycle starts
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
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

// Example usage
int main()
{
    // Create a linked list with a cycle (for demonstration purposes)
    struct ListNode *head = createNode(1);
    struct ListNode *node1 = createNode(2);
    struct ListNode *node2 = createNode(3);
    struct ListNode *node3 = createNode(4);
    struct ListNode *node4 = createNode(5);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // Creating a cycle, node4 points back to node2

    // Detect if the linked list contains a cycle
    bool has_cycle = isCyclic(head);
    if (has_cycle)
    {
        printf("The linked list contains a cycle.\n");
        struct ListNode *cycle_start = detectCycle(head);
        printf("The cycle starts at node with value: %d\n", cycle_start->val);
    }
    else
    {
        printf("The linked list does not contain a cycle.\n");
    }

    // Free the allocated memory before exiting the program
    free(head);
    free(node1);
    free(node2);
    free(node3);
    free(node4);

    return 0;
}
