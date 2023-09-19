#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr -> top == -1){
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr){
    if(ptr -> top == ptr -> size -1){
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow!\n");
    }
    else{
        ptr -> top++;
        ptr -> arr[ptr -> top] = val;
    }
}

int pop(struct stack *ptr){
     if(isEmpty(ptr)){
        printf("Stack Underflow!\n");
        return -1;
    }
    else{
        int val = ptr -> arr[ptr -> top];
        ptr -> top--;
        return val;
    }
}

int peek(struct stack *ptr, int index){
    int arrIndex= ptr -> top - index + 1;
    if(arrIndex < 0){
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else{
        return ptr -> arr[arrIndex];
    }
}

int main()
{
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s -> size = 10;
    s -> top = -1;
    s -> arr = (int *) malloc(s -> size * sizeof(int));

    // printf("Empty: %d\n", isEmpty(s));
    // printf("Full: %d\n", isFull(s));
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);
    push(s, 60);
    push(s, 70);
    push(s, 80);
    push(s, 90);
    // printf("Empty: %d\n", isEmpty(s));
    // printf("Full: %d", isFull(s));
    printf("the value at position %d : %d", 3, peek(s, 3));
    // printf("Popped! %d from the stack", pop(s)); // last in forst out

    return 0;
}