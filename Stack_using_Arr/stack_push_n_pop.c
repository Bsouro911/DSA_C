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

bool pop(struct stack *ptr){
     if(isEmpty(ptr)){
        printf("Stack Underflow!\n");
        return false;
    }
    else{
        int val = ptr -> arr[ptr -> top];
        ptr -> top--;
        return true;
    }
}

void display(struct stack *ptr){
    if (isEmpty(ptr)) {
        printf("Stack is empty!\n");
    }
    else {
        printf("Stack elements: ");
        for (int i = ptr->top; i >= 0; i--) {
            printf("%d ", ptr->arr[i]);
        }
        printf("\n");
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

    display(s);

    pop(s);
    printf("Popped! from the stack"); // last in forst out

    free(s->arr);
    free(s);

    return 0;
}