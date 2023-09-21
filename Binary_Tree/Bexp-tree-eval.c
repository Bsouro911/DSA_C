#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Structure for an expression tree node
struct ExpressionTreeNode
{
    char *value;
    struct ExpressionTreeNode *left;
    struct ExpressionTreeNode *right;
};

// Structure for a stack to help with parsing and tree construction
struct Stack
{
    int top;
    unsigned capacity;
    struct ExpressionTreeNode **array;
};

// Function to create a new expression tree node
struct ExpressionTreeNode *createNode(char *value)
{
    struct ExpressionTreeNode *newNode = (struct ExpressionTreeNode *)malloc(sizeof(struct ExpressionTreeNode));
    newNode->value = strdup(value); // Use strdup to duplicate the string
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a new stack of given capacity
struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (struct ExpressionTreeNode **)malloc(stack->capacity * sizeof(struct ExpressionTreeNode *));
    return stack;
}

// Function to check if a character is an operator (+, -, *, /)
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to get the precedence of an operator
int getPrecedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

// Function to convert infix expression to postfix notation
char *infixToPostfix(char *infix)
{
    int len = strlen(infix);
    char *postfix = (char *)malloc((len + 1) * sizeof(char));
    struct Stack *stack = createStack(len);
    int j = 0;

    for (int i = 0; i < len; i++)
    {
        char c = infix[i];

        if (isalnum(c))
        {
            postfix[j++] = c;
        }
        else if (c == '(')
        {
            struct ExpressionTreeNode *node = createNode("(");
            stack->array[++stack->top] = node;
        }
        else if (c == ')')
        {
            while (stack->top != -1 && strcmp(stack->array[stack->top]->value, "(") != 0)
            {
                postfix[j++] = ' ';
                postfix[j++] = stack->array[stack->top]->value[0];
                stack->top--;
            }
            stack->top--; // Pop the "("
        }
        else
        {
            while (stack->top != -1 && getPrecedence(c) <= getPrecedence(stack->array[stack->top]->value[0]))
            {
                postfix[j++] = ' ';
                postfix[j++] = stack->array[stack->top]->value[0];
                stack->top--;
            }
            postfix[j++] = ' ';
            struct ExpressionTreeNode *node = createNode("");
            node->value[0] = c;
            stack->array[++stack->top] = node;
        }
    }

    while (stack->top != -1)
    {
        postfix[j++] = ' ';
        postfix[j++] = stack->array[stack->top]->value[0];
        stack->top--;
    }

    postfix[j] = '\0';
    free(stack->array);
    free(stack);
    return postfix;
}

// Function to build an expression tree from a postfix expression
struct ExpressionTreeNode *buildExpressionTree(char *postfix)
{
    struct Stack *stack = createStack(strlen(postfix));
    struct ExpressionTreeNode *t, *t1, *t2;
    char *token = strtok(postfix, " ");

    while (token != NULL)
    {
        char c = token[0];

        if (isalnum(c))
        {
            t = createNode(token);
            stack->array[++stack->top] = t;
        }
        else
        {
            t1 = stack->array[stack->top--];
            t2 = stack->array[stack->top--];
            t = createNode(token);
            t->right = t1;
            t->left = t2;
            stack->array[++stack->top] = t;
        }

        token = strtok(NULL, " ");
    }

    return stack->array[stack->top];
}

// Function to evaluate an expression tree
int evaluate(struct ExpressionTreeNode *node)
{
    if (node == NULL)
        return 0;

    if (isOperator(node->value[0]))
    {
        int leftVal = evaluate(node->left);
        int rightVal = evaluate(node->right);
        char op = node->value[0];

        switch (op)
        {
        case '+':
            return leftVal + rightVal;
        case '-':
            return leftVal - rightVal;
        case '*':
            return leftVal * rightVal;
        case '/':
            return leftVal / rightVal;
        default:
            return 0; // Invalid operator
        }
    }
    else
    {
        return atoi(node->value);
    }
}

int main()
{
    char infixExpression[100];
    printf("Enter an infix expression: ");
    scanf("%s", infixExpression);

    // Convert infix to postfix
    char *postfixExpression = infixToPostfix(infixExpression);
    printf("Postfix expression: %s\n", postfixExpression);

    // Build the expression tree from the postfix expression
    struct ExpressionTreeNode *root = buildExpressionTree(postfixExpression);

    // Evaluate and print the result
    int result = evaluate(root);
    printf("Result: %d\n", result);

    // Free dynamically allocated memory
    // (You can create a separate function to handle freeing memory if needed)
    free(postfixExpression);
    free(root);

    return 0;
}
