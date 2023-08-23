#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

typedef struct
{
    int data[STACK_SIZE];
    int top;
} Stack;

void initializeStack(Stack *stack)
{
    stack->top = -1;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

int isFull(Stack *stack)
{
    return stack->top == STACK_SIZE - 1;
}

void push(Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    stack->data[++stack->top] = value;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    return stack->data[stack->top--];
}

int main()
{
    Stack undoStack, redoStack;
    initializeStack(&undoStack);
    initializeStack(&redoStack);

    int currentValue = 0;
    int choice;

    do
    {
        printf("Current Value: %d\n", currentValue);
        printf("1. Perform Action\n");
        printf("2. Undo\n");
        printf("3. Redo\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            // Perform Action
            int newValue;
            printf("Enter new value: ");
            scanf("%d", &newValue);
            push(&undoStack, currentValue);
            currentValue = newValue;
            // Clear redoStack after new action
            while (!isEmpty(&redoStack))
            {
                pop(&redoStack);
            }
            break;
        }
        case 2:
        {
            // Undo
            if (!isEmpty(&undoStack))
            {
                push(&redoStack, currentValue);
                currentValue = pop(&undoStack);
            }
            else
            {
                printf("Nothing to undo.\n");
            }
            break;
        }
        case 3:
        {
            // Redo
            if (!isEmpty(&redoStack))
            {
                push(&undoStack, currentValue);
                currentValue = pop(&redoStack);
            }
            else
            {
                printf("Nothing to redo.\n");
            }
            break;
        }
        case 4:
            // Exit
            printf("Exiting.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }

    } while (choice != 4);

    return 0;
}
