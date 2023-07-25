#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* findMiddle(struct ListNode* head) {
    struct ListNode* p1 = head;
    struct ListNode* p2 = head;

    // Base case: If the list is empty, return NULL
    if (head == NULL) {
        return NULL;
    } else {
        while (p2 != NULL && p2->next != NULL) {
            p2 = p2->next->next;
            p1 = p1->next;
        }
        return p1;
    }
}

struct ListNode* getElementsAfterMiddle(struct ListNode* head) {
    struct ListNode* middle = findMiddle(head);
    if (middle == NULL || middle->next == NULL) {
        return NULL; // There are no elements after the middle
    }
    return middle->next;
}

// Utility function to create a new node
struct ListNode* createNode(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = data;
    newNode->next = NULL;
    return newNode;
}

// Utility function to insert a node at the end of the list
void insertEnd(struct ListNode** head_ref, int data) {
    struct ListNode* newNode = createNode(data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    struct ListNode* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

int main() {
    struct ListNode* head = NULL;
    // Insert nodes at the end of the singly linked list
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertEnd(&head, 5);

    printf("Original list: ");
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");

    struct ListNode* elementsAfterMiddle = getElementsAfterMiddle(head);
    printf("Elements after the middle: ");
    while (elementsAfterMiddle != NULL) {
        printf("%d ", elementsAfterMiddle->val);
        elementsAfterMiddle = elementsAfterMiddle->next;
    }
    printf("\n");

    return 0;
}
