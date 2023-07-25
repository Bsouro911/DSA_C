// Application of stack:

// 1. Function Calls and Recursion
// 2. Infix to Postfix conversion
// 3. Parenthesis matching 
// 4. Backtracking Algorithms
// 5. Parsing
// 6. Browser History
// 7. Memory Management
// 8. Compiler and Interpreter Design
// 9. Buffer Management
// 10. Scheduling Algorithms

// Stack ADT(abstract data type):

// 1. Push: Adds an element to the top of the stack.
// 2. Pop: Removes and returns the top element from the stack.
// 3. Peek (or Top): Returns the top element of the stack without removing it.
// 4. IsEmpty: Checks if the stack is empty.
// 5. Size: Returns the number of elements currently in the stack.

// Implementing stack using Arrays
// 1. fixed size array creation
// 2. top element

#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size; // size of array
    int top; // top most element
    int *arr; // array in heap
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

int main(){
    struct stack *s;
    s->size = 80;
    s->top = -1;
    s->arr = (int *) malloc(s -> size*sizeof(int));

    if(isEmpty(s)){
        printf("the stack is empty!");
    }
    else{
        printf("the stack is not empty!");
    }

    return 0;
}
