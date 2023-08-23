#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a stack
struct Stack
{
    int top;
    unsigned capacity;
    char *array;
};

// Function to create a stack
struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char *)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, char item)
{
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
char pop(struct Stack *stack)
{
    if (!isEmpty(stack))
    {
        return stack->array[stack->top--];
    }
    return '\0'; // Empty stack marker
}

// Function to reverse a string using a stack
void reverseString(char *s, int sSize)
{
    struct Stack *stack = createStack(sSize);

    // Push each character onto the stack
    for (int i = 0; i < sSize; i++)
    {
        push(stack, s[i]);
    }

    // Pop characters from the stack and place them back in the string
    for (int i = 0; i < sSize; i++)
    {
        s[i] = pop(stack);
    }

    // Free the memory used by the stack
    free(stack->array);
    free(stack);
}

int main()
{
    char str[] = "Hello, World!";
    int size = strlen(str);

    printf("Original string: %s\n", str);
    reverseString(str, size);
    printf("Reversed string: %s\n", str);

    return 0;
}
