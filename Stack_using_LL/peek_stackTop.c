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

int peek(struct Node *top, int pos){ // peek can be used for traversing all the element in stack also
    struct Node *ptr = top;
    for(int i = 0; ( i< pos-1 && ptr != NULL); i++){
        ptr = ptr -> next;
    }
    if(ptr != NULL){
        return ptr -> data;
    }
    else{
        return -1; // assuming all the elements are positive in the stack
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
    printf("%d", peek(top, 3));
    return 0;
}