#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head){
    struct Node *ptr = head;

    do
    {
        printf("element : %d\n", ptr -> data);
        ptr = ptr -> next;
    } while (ptr != head);
    
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr -> data = data;

    struct Node *p = head -> next;
    while (p -> next != head)
    {
        p = p -> next; // now p points to the last node of the circular linked list
    }

    p -> next = ptr;
    ptr -> next = head;
    head = ptr; // updating head
    return head;    
}


int main(){
    struct Node *head;
    struct Node *sec;
    struct Node *third;
    struct Node *fourth;

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

    fourth -> data = 10;
    fourth -> next = head;

    head = insertAtFirst(head, 77);
    printf("After inserting a element at first of circular linked list:\n");
    linkedListTraversal(head);


    return 0;
}