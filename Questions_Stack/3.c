#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

struct Stack
{
    int top;
    char items[MAX_STACK_SIZE];
};

void initialize(struct Stack *s)
{
    s->top = -1;
}

int isEmpty(struct Stack *s)
{
    return s->top == -1;
}

void push(struct Stack *s, char item)
{
    if (s->top == MAX_STACK_SIZE - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        s->top++;
        s->items[s->top] = item;
    }
}

char pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow\n");
        return '\0';
    }
    else
    {
        char item = s->items[s->top];
        s->top--;
        return item;
    }
}

int getPrecedence(char operator)
{
    if (operator== '+' || operator== '-')
        return 1;
    else if (operator== '*' || operator== '/')
        return 2;
    else
        return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    struct Stack stack;
    initialize(&stack);

    int infixLength = strlen(infix);
    int postfixIndex = 0;

    for (int i = 0; i < infixLength; i++)
    {
        char ch = infix[i];

        if (isalnum(ch))
        {
            postfix[postfixIndex++] = ch;
        }
        else if (ch == '(')
        {
            push(&stack, ch);
        }
        else if (ch == ')')
        {
            while (!isEmpty(&stack) && stack.items[stack.top] != '(')
            {
                postfix[postfixIndex++] = pop(&stack);
            }
            pop(&stack); // Pop '('
        }
        else
        { // Operator
            while (!isEmpty(&stack) && getPrecedence(ch) <= getPrecedence(stack.items[stack.top]))
            {
                postfix[postfixIndex++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    while (!isEmpty(&stack))
    {
        postfix[postfixIndex++] = pop(&stack);
    }

    postfix[postfixIndex] = '\0';
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

void infixToPrefix(char infix[], char prefix[])
{
    struct Stack stack;
    initialize(&stack);

    int infixLength = strlen(infix);
    int prefixIndex = 0;

    for (int i = infixLength - 1; i >= 0; i--)
    {
        char ch = infix[i];

        if (isalnum(ch))
        {
            prefix[prefixIndex++] = ch;
        }
        else if (ch == ')')
        {
            push(&stack, ch);
        }
        else if (ch == '(')
        {
            while (!isEmpty(&stack) && stack.items[stack.top] != ')')
            {
                prefix[prefixIndex++] = pop(&stack);
            }
            pop(&stack); // Pop ')'
        }
        else if (isOperator(ch))
        {
            while (!isEmpty(&stack) && getPrecedence(ch) < getPrecedence(stack.items[stack.top]))
            {
                prefix[prefixIndex++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    while (!isEmpty(&stack))
    {
        prefix[prefixIndex++] = pop(&stack);
    }

    prefix[prefixIndex] = '\0';

    // Reverse the prefix string to get the correct order
    int len = strlen(prefix);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = prefix[i];
        prefix[i] = prefix[len - i - 1];
        prefix[len - i - 1] = temp;
    }
}

int evaluatePostfix(char postfix[])
{
    struct Stack stack;
    initialize(&stack);

    int postfixLength = strlen(postfix);

    for (int i = 0; i < postfixLength; i++)
    {
        char ch = postfix[i];

        if (isdigit(ch))
        {
            push(&stack, ch - '0'); // Convert char to int
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (ch)
            {
            case '+':
                push(&stack, operand1 + operand2);
                break;
            case '-':
                push(&stack, operand1 - operand2);
                break;
            case '*':
                push(&stack, operand1 * operand2);
                break;
            case '/':
                push(&stack, operand1 / operand2);
                break;
            }
        }
    }

    return pop(&stack);
}

int main()
{
    char infix[100];
    char postfix[100];
    char prefix[100];
    char postfixEval[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    printf("Enter postfix expression for Evaluation: ");
    scanf("%s", postfixEval);

    int result = evaluatePostfix(postfixEval);
    printf("Result of postfix expression: %d\n", result);

    return 0;
}
