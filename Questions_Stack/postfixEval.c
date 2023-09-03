#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

char peek(struct Stack *stack)
{
    return stack->array[stack->top];
}

int pop(struct Stack *stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$'; // This is an arbitrary character to indicate an error
}

void push(struct Stack *stack, int item)
{
    stack->array[++stack->top] = item;
}

int evaluatePostfix(char postfix[])
{
    struct Stack *stack = createStack(strlen(postfix));
    int i;

    for (i = 0; postfix[i]; ++i)
    {
        char ch = postfix[i];

        if (isdigit(ch))
        {
            int operand = 0;
            while (isdigit(postfix[i]))
            {
                operand = operand * 10 + (postfix[i] - '0');
                i++;
            }
            i--; // Backtrack one character to account for the loop increment
            push(stack, operand);
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            int operand2 = pop(stack);
            int operand1 = pop(stack);

            switch (ch)
            {
            case '+':
                push(stack, operand1 + operand2);
                break;
            case '-':
                push(stack, operand1 - operand2);
                break;
            case '*':
                push(stack, operand1 * operand2);
                break;
            case '/':
                push(stack, operand1 / operand2);
                break;
            }
        }
    }

    return pop(stack);
}

int main()
{
    char postfix[] = "2 3 +";
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
    return 0;
}
