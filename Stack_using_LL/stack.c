// head is now top here
// push and pop operation would be from head side
// stack empty condition (top == NULL)
// stack full condition (when heap memory is exhausted)
// you can always set a custom size here

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr){
    while (ptr != NULL){
        printf("element : %d\n", ptr -> data);
        ptr = ptr -> next;
    }
}

int isEmpty(struct Node *top){
    if(top == NULL){
        return 1;
    }
    return 0;
}

int isFull(struct Node *top){
    struct Node *p = (struct Node *) malloc(sizeof(struct Node));
    if( p == NULL){
        return 1;
    }
    return 0;
}

struct Node *push(struct Node *top, int x){
    if(!isFull(top)){
        struct Node *p = (struct Node *) malloc(sizeof(struct Node));
        p -> data = x;
        p -> next = top;
        top = p;
        return top;
    }
    else{
        printf("Stack Overflow!\n");
    }
}

int pop(struct Node **tp){ 
    if(!isEmpty(*tp)){
        struct Node *p = *tp;
        *tp = (*tp) -> next;
        int x = p -> data;
        free(p);
        return x;
    }
    else{
        printf("Stack Underflow!\n");
    }
}


int main()

{
    struct Node *top = NULL; // you can avoid this ** in pop function by making this *top as global pointer variable in your program
    top = push(top, 77);
    top = push(top, 78);
    top = push(top, 79);
    top = push(top, 80);
    linkedListTraversal(top);
    pop(&top);
    printf("\n");
    linkedListTraversal(top);
    return 0;
}