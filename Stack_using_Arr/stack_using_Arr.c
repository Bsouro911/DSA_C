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
#include <stdbool.h>

struct Stack
{
    int top;
    unsigned cap;
    int *arr;
};

struct Stack *create_stack(unsigned cap)
{
    struct Stack *newStack = (struct Stack *)malloc(sizeof(struct Stack));
    newStack->top = -1;
    newStack->cap = cap;
    newStack->arr = (int *)malloc(sizeof(int) * newStack->cap);

    return newStack;
}

bool isEmpty(struct Stack *s)
{
    return s->top == -1;
}

bool isFull(struct Stack *s)
{
    return s->top == s->cap - 1;
}

void push(struct Stack *s, int val)
{
    if (!(isFull(s)))
    {
        s->arr[++s->top] = val;
    }
}

void pop(struct Stack *s)
{
    if (!(isEmpty(s)))
    {
        s->arr[s->top--];
    }
}

int peek(struct Stack *s)
{
    if (!(isEmpty(s)))
    {
        return s->arr[s->top];
    }
}

void del_stack(struct Stack *s)
{
    free(s->arr);
    free(s);
}

void traverseStack(struct Stack *s)
{
    if (!(isEmpty(s)))
    {
        printf("Stack elements: ");
        for (int i = 0; i <= s->top; i++)
        {
            printf("%d ", s->arr[i]);
        }
    }
}

int main()
{
    struct Stack *stack = create_stack(5);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Top element: %d\n", peek(stack));

    pop(stack);
    pop(stack);

    printf("Top element: %d\n", peek(stack));

    push(stack, 40);
    push(stack, 50);

    printf("Top element: %d\n", peek(stack));

    traverseStack(stack);

    del_stack(stack);

    return 0;
}
