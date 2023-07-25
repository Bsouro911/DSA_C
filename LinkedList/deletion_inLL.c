#include<stdio.h>
#include<stdlib.h>

// cases:
// 1. deleting the first Node
// 2. deleting a node in-b/w
// 3. deleting the last Node
// 4. delete a node with a given value


// defining a linked list
struct Node
{
    int data;
    struct Node *next; //self referencing structure
};

// printing the linked list
void linked_list_traversal(struct Node *ptr){
   while (ptr != NULL)
   {
        printf("Element : %d\n", ptr -> data);
        ptr = ptr -> next;
   }
   
}

// case 1:
struct Node *deleteFirst(struct Node *head){
    struct Node *ptr = head;
    head = head -> next;
    free(ptr);
    return head;
}

// case 2:
struct Node *deleteAtIndex(struct Node *head, int index){
    struct Node *p = head;
    struct Node *q = head -> next;

    for(int i =0; i < index - 1; i++){
        p = p -> next;
        q = q -> next;
    }

    p -> next = q -> next;
    free(q);
    
    return head;
}

// case 3:
struct Node *deleteLast(struct Node *head){
    struct Node *p = head;
    struct Node *q = head -> next;

    while( q -> next != NULL){
        p = p -> next;
        q = q -> next;
    }

    p -> next = NULL;
    free(q);
    
    return head;
}

// case 4:
struct Node *delNodeWithVal(struct Node *head, int val){
    struct Node *p = head;
    struct Node *q = head -> next;

    while( q -> next != NULL && q -> data != val){
        p = p -> next;
        q = q -> next;
    }

    if( q -> data == val){
        p -> next = q -> next;
        free(q);
    }
    
    return head;
}

int main(){

    struct Node *head;
    struct Node *sec;
    struct Node *third;
    
    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *) malloc(sizeof(struct Node));
    sec = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));

    // link first and sec nodes
    head -> data = 7;
    head -> next = sec;

    // link sec and third nodes
    sec -> data = 8;
    sec -> next = third;

    // terminate the list at third node
    third -> data = 9;
    third -> next = NULL;

    printf("Linked list before deletion!\n");
    linked_list_traversal(head);

    // printf("Linked list after deletion!\n");
    // head = deleteFirst(head); //
    // head = deleteFirst(head); // deleting two times means 2 elements from the first will get deleted
    // linked_list_traversal(head);

    // printf("Linked list after deletion of element at an index!\n");
    // head = deleteAtIndex(head, 1); 
    // linked_list_traversal(head);

    // printf("Linked list after deletion of last element!\n");
    // head = deleteLast(head); 
    // linked_list_traversal(head);

    printf("Linked list after deletion of node with given value!\n");
    head = delNodeWithVal(head, 8); 
    linked_list_traversal(head);

    return 0;
}


