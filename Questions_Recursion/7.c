#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

struct IntStack
{
    int *values;
    int top;
    int capacity;
};

struct CharStack
{
    char *operators;
    int top;
    int capacity;
};

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int applyOp(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
    return 0; // This should not happen in valid expressions
}

void initIntStack(struct IntStack *stack, int capacity)
{
    stack->values = (int *)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
}

void pushInt(struct IntStack *stack, int value)
{
    stack->values[++stack->top] = value;
}

int popInt(struct IntStack *stack)
{
    return stack->values[stack->top--];
}

void initCharStack(struct CharStack *stack, int capacity)
{
    stack->operators = (char *)malloc(capacity * sizeof(char));
    stack->top = -1;
    stack->capacity = capacity;
}

void pushChar(struct CharStack *stack, char op)
{
    stack->operators[++stack->top] = op;
}

char popChar(struct CharStack *stack)
{
    return stack->operators[stack->top--];
}

int evaluateExpression(char *tokens)
{
    int i;
    int length = strlen(tokens);
    struct IntStack values;
    struct CharStack ops;

    initIntStack(&values, length);
    initCharStack(&ops, length);

    for (i = 0; i < length; i++)
    {
        if (tokens[i] == ' ')
            continue;
        else if (tokens[i] == '(')
        {
            pushChar(&ops, tokens[i]);
        }
        else if (isdigit(tokens[i]))
        {
            int val = 0;
            while (i < length && isdigit(tokens[i]))
            {
                val = val * 10 + (tokens[i] - '0');
                i++;
            }
            pushInt(&values, val);
            i--;
        }
        else if (tokens[i] == ')')
        {
            while (ops.top != -1 && ops.operators[ops.top] != '(')
            {
                int val2 = popInt(&values);
                int val1 = popInt(&values);
                char op = popChar(&ops);
                pushInt(&values, applyOp(val1, val2, op));
            }
            if (ops.top != -1)
                popChar(&ops);
        }
        else
        {
            while (ops.top != -1 && precedence(ops.operators[ops.top]) >= precedence(tokens[i]))
            {
                int val2 = popInt(&values);
                int val1 = popInt(&values);
                char op = popChar(&ops);
                pushInt(&values, applyOp(val1, val2, op));
            }
            pushChar(&ops, tokens[i]);
        }
    }

    while (ops.top != -1)
    {
        int val2 = popInt(&values);
        int val1 = popInt(&values);
        char op = popChar(&ops);
        pushInt(&values, applyOp(val1, val2, op));
    }

    int result = popInt(&values);
    free(values.values);
    free(ops.operators);
    return result;
}

int main()
{
    printf("%d", evaluateExpression("3 + (2 * 5) - 6 / 2"));
    return 0;
}
