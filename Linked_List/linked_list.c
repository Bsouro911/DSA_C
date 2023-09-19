#include<stdio.h>
#include<stdlib.h>

// defining a linked list
struct Node
{
    int data;
    struct Node *next; //self referencing structure
};

void linked_list_traversal(struct Node *ptr){
   while (ptr != NULL)
   {
        printf("Element : %d\n", ptr -> data);
        ptr = ptr -> next;
   }
   
}

int main(){

    struct Node *head;
    struct Node *sec;
    struct Node *third;
    
    // Dynamically allocate memory for nodes in the linked list in Heap
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

    linked_list_traversal(head);
    return 0;
}

