#include<stdio.h>
#include<stdlib.h>

// cases: 

// 1. insert at the beginning
// 2. insert in between
// 3. insert at the end
// 4. insert after a node

struct Node
{
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

struct Node *insetAtFirst(struct Node *head, int data){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr -> next = head;
    ptr -> data = data;
    return ptr;
}

struct Node *insertAtIndex(struct Node *head, int data, int index){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr -> data = data;
    int i = 0;

    while (i != index-1)
    {
        p = p -> next;
        i++;
    }

    ptr -> next = p -> next;
    p -> next = ptr;

    return head;
    
}

struct Node *insertAtEnd(struct Node *head, int data){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr -> data = data;

    while (p -> next != NULL)
    {
        p = p -> next;
    }

    p -> next = ptr;
    ptr -> next = NULL;

    return head;
}

struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr -> data = data;

    ptr -> next = prevNode -> next;
    prevNode -> next = ptr;

    return head;
}


int main(){
    
    struct Node *head, *sec, *third, *fourth, *inele;

    head = (struct Node *) malloc(sizeof(struct Node));
    sec = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    fourth = (struct Node *) malloc(sizeof(struct Node));

    head -> data = 7;
    head -> next = sec;

    sec -> data = 8;
    sec -> next = third;

    third -> data = 9;
    third -> next = fourth;

    fourth -> data = 9;
    third -> next = NULL;

    linked_list_traversal(head);
    // head = insetAtFirst(head, 45);
    // printf("\n");
    // linked_list_traversal(head);
    // head = insertAtIndex(head, 51, 2);
    // printf("\n");
    // linked_list_traversal(head);
    // head = insertAtEnd(head, 87);
    // printf("\n");
    // linked_list_traversal(head);
    head = insertAfterNode(head, head, 99);
    printf("\n");
    linked_list_traversal(head);


    return 0;
}
