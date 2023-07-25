#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node *next;
};

void linked_list_traversal(struct Node *ptr){
   while (ptr != NULL)
   {
        printf("Element : %d\n", ptr -> data);
        ptr = ptr -> next;
   }
   
}

// iterative solution:
struct Node *reverse(struct Node **head){
    // first check is the list is empty or have 1 element
    if(*head == NULL || head -> next == NULL){
        return *head;
    }

    struct Node *previous = NULL;
    struct Node *current = *head;
    struct Node *forward = NULL;

    while(current != NULL){
        forward = current -> next;
        current -> next = previous;
        previous = current;
        current = forward;
    }

    return previous;
}

// recursive approach:
void rec_rev(struct Node **head, struct Node *curr, struct Node *prev) {
    // base case:
    if (curr == NULL) {
        *head = prev; // Update the head pointer through the double pointer
        return;
    }

    struct Node *forwd = curr->next;
    rec_rev(head, forwd, curr);
    curr->next = prev;
}

struct Node *rec_reverse(struct Node *head) {
    struct Node *curr = head;
    struct Node *prev = NULL;
    rec_rev(&head, curr, prev); // Pass the address of the head pointer
    return head; // Return the new head after reversal
}

// recursive approach 2:
struct Node *reverse2(struct Node *head){
    // base case:
    if(head == NULL || head -> next == NULL){
        return head;
    }

    struct Node *secHead = reverse2(head -> next);

    head -> next -> next = head;
    head -> next = NULL;

    return secHead;
}


int main()

{   
    struct Node* head = NULL;

    // Append elements to the linked list
    for (int i = 1; i <= 5; ++i) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = i;
        newNode->next = head;
        head = newNode;
    }

    linked_list_traversal(head);
    head = reverse2(head);
    printf("after reversal\n");
    linked_list_traversal(head);
    
    return 0;
}