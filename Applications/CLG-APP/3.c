#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// Define the StackNode Structure
typedef struct StackNode
{
    int data;
    struct StackNode *next;
} StackNode;

// Function to create a new StackNode
StackNode *createStackNode(int data)
{
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (newNode == NULL)
    {
        perror("Memory allocation for StackNode failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the stack is empty
bool isEmpty(StackNode *stack)
{
    return (stack == NULL);
}

// Function to push a value onto the stack
void push(StackNode **stack, int data)
{
    StackNode *newNode = createStackNode(data);
    newNode->next = *stack;
    *stack = newNode;
}

// Function to pop a value from the stack
int pop(StackNode **stack)
{
    if (isEmpty(*stack))
    {
        fprintf(stderr, "Error: Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    int data = (*stack)->data;
    StackNode *temp = *stack;
    *stack = (*stack)->next;
    free(temp);
    return data;
}

// Function to peek at the top value of the stack without popping it
int peek(StackNode *stack)
{
    if (isEmpty(stack))
    {
        fprintf(stderr, "Error: Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->data;
}

// Function to evaluate a given postfix expression
int evaluatePostfixExpression(const char *postfix)
{
    StackNode *stack = NULL;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (isdigit(postfix[i]))
        {
            // Operand: Push onto the stack
            push(&stack, postfix[i] - '0');
        }
        else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
        {
            // Operator: Pop operands, perform operation, and push result back onto the stack
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            int result;

            switch (postfix[i])
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
                if (operand2 == 0)
                {
                    fprintf(stderr, "Error: Division by zero\n");
                    exit(EXIT_FAILURE);
                }
                result = operand1 / operand2;
                break;
            default:
                fprintf(stderr, "Error: Invalid operator\n");
                exit(EXIT_FAILURE);
            }
            push(&stack, result);
        }
    }

    if (!isEmpty(stack))
    {
        int result = pop(&stack);
        if (isEmpty(stack))
        {
            return result;
        }
        else
        {
            fprintf(stderr, "Error: Invalid postfix expression\n");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "Error: Invalid postfix expression\n");
        exit(EXIT_FAILURE);
    }
}

int main()
{
    char postfixExpression[100];

    printf("Enter a postfix expression: ");
    scanf("%s", postfixExpression);

    int result = evaluatePostfixExpression(postfixExpression);
    printf("Result of the postfix expression: %d\n", result);

    return 0;
}
