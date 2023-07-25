#include <stdio.h>
#include <stdlib.h>

// Definition of struct Node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* reverseDLL(struct Node* head) {
    struct Node* curr = head;
    // Base case:
    if (curr == NULL || curr->next == NULL) {
        return head;
    }

    // Move curr to the last node
    while (curr->next != NULL) {
        curr = curr->next;
    }

    head = curr;

    while (curr != NULL) {
        struct Node* temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        curr = curr->next;
    }

    return head;
}

// Utility function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Utility function to insert a node at the end of the list
void insertEnd(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    struct Node* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

// Utility function to print the doubly linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    // Insert nodes at the end of the doubly linked list
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertEnd(&head, 5);

    printf("Original list: ");
    printList(head);

    head = reverseDLL(head);

    printf("Reversed list: ");
    printList(head);

    return 0;
}
