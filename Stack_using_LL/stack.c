// head is now top here
// push and pop operation would be from head side
// stack empty condition (top == NULL)
// stack full condition (when heap memory is exhausted)
// you can always set a custom size here

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node **top, int val)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        printf("Stack Overflow!\n");
        return;
    }
    temp->data = val;
    temp->next = *top;
    *top = temp;
}

bool pop(struct Node **top)
{
    if (*top == NULL)
    {
        printf("Stack is Empty!\n");
        return false;
    }
    struct Node *ptr = *top;
    *top = (*top)->next;

    free(ptr);
    return true;
}

void delStack(struct Node **top)
{
    while (*top != NULL)
    {
        struct Node *ptr = *top;
        *top = (*top)->next;
        free(ptr);
    }
}

void printStack(struct Node *top)
{
    struct Node *ptr = top;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct Node *stack = NULL;

    push(&stack, 5);
    push(&stack, 4);
    push(&stack, 3);
    push(&stack, 2);
    push(&stack, 1);

    printStack(stack);
    // delStack(&stack);
    pop(&stack);
    pop(&stack);
    printf("\n");
    printStack(stack);

    return 0;
}
