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

#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

void push(struct Stack *stack, int item)
{
    if (isFull(stack))
    {
        printf("Stack is full. Cannot push %d\n", item);
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    return stack->array[stack->top--];
}

int peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty. Cannot peek.\n");
        return -1;
    }
    return stack->array[stack->top];
}

void delStack(struct Stack *stack)
{
    free(stack->array);
    free(stack);
}

int main()
{
    struct Stack *stack = createStack(5);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Top element: %d\n", peek(stack));

    printf("Popped: %d\n", pop(stack));
    printf("Popped: %d\n", pop(stack));

    printf("Top element: %d\n", peek(stack));

    push(stack, 40);
    push(stack, 50);

    printf("Top element: %d\n", peek(stack));

    printf("Popped: %d\n", pop(stack));

    delStack(stack);

    return 0;
}
