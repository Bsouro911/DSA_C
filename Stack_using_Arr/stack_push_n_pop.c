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

int main()
{
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s -> size = 2;
    s -> top = -1;
    s -> arr = (int *) malloc(s -> size * sizeof(int));

    printf("Empty: %d\n", isEmpty(s));
    printf("Full: %d\n", isFull(s));
    push(s, 77);
    push(s, 89);
    // printf("Empty: %d\n", isEmpty(s));
    // printf("Full: %d", isFull(s));

    printf("Popped! %d from the stack", pop(s)); // last in forst out

    return 0;
}