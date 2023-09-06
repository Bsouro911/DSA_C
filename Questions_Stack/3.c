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

char peek(struct Stack *stack)
{
    return stack->items[stack->top];
}

int precedence(char operator)
{
    if (operator== '+' || operator== '-')
        return 1;
    else if (operator== '*' || operator== '/')
        return 2;
    else
        return 0;
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

void reverseString(char str[])
{
    int length = strlen(str);
    int left = 0;
    int right = length - 1;

    while (left < right)
    {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

void infixToPrefix(char infix[], char prefix[])
{
    reverseString(infix);
    struct Stack stack;
    initialize(&stack);
    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        char ch = infix[i];

        if (isalnum(ch))
        {
            prefix[j++] = ch;
        }
        else if (ch == ')')
        {
            push(&stack, ch);
        }
        else if (ch == '(')
        {
            while (!isEmpty(&stack) && peek(&stack) != ')')
            {
                prefix[j++] = pop(&stack);
            }
            pop(&stack);
        }
        else if (isOperator(ch))
        {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(ch))
            {
                prefix[j++] = pop(&stack);
            }
            push(&stack, ch);
        }

        i++;
    }

    while (!isEmpty(&stack))
    {
        prefix[j++] = pop(&stack);
    }

    prefix[j] = '\0';
    reverseString(prefix);
}

int main()
{
    char infix[100];
    char prefix[100];
    // char postfixEval[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    // printf("Enter postfix expression for Evaluation: ");
    // scanf("%s", postfixEval);

    // int result = evaluatePostfix(postfixEval);
    // printf("Result of postfix expression: %d\n", result);

    return 0;
}
