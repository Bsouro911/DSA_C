#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SIZE 100

// Stack structure
typedef struct
{
    int top;
    char items[MAX_SIZE];
} Stack;

// Initialize an empty stack
void initialize(Stack *stack)
{
    stack->top = -1;
}

// Check if the stack is empty
bool isEmpty(Stack *stack)
{
    return stack->top == -1;
}

// Push an item onto the stack
void push(Stack *stack, char item)
{
    if (stack->top == MAX_SIZE - 1)
    {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = item;
}

// Pop an item from the stack
char pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

// Get the top item of the stack without popping
char peek(Stack *stack)
{
    return stack->items[stack->top];
}

// Check if a character is an operator (+, -, *, /, etc.)
bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Get the precedence of an operator
int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

// Convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[])
{
    Stack stack;
    initialize(&stack);
    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        char ch = infix[i];

        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(&stack, ch);
        }
        else if (ch == ')')
        {
            while (!isEmpty(&stack) && peek(&stack) != '(')
            {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Pop the '(' from the stack
        }
        else if (isOperator(ch))
        {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(ch))
            {
                postfix[j++] = pop(&stack);
            }
            push(&stack, ch);
        }

        i++;
    }

    while (!isEmpty(&stack))
    {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

// Evaluate postfix expression
int evaluatePostfix(char postfix[])
{
    Stack stack;
    initialize(&stack);
    int i = 0;

    while (postfix[i] != '\0')
    {
        char ch = postfix[i];

        if (isdigit(ch))
        {
            push(&stack, ch - '0');
        }
        else if (isOperator(ch))
        {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            int result;

            switch (ch)
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            }

            push(&stack, result);
        }

        i++;
    }

    return pop(&stack);
}

int main()
{
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
