// 2. Binary Expression Tree Evaluation: Implement a program that builds a binary expression tree from an infix expression and then evaluates it. The nodes of the tree represent operators and operands.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define a structure for representing nodes in the expression tree
typedef struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
} Node;

// Create a new node with the given data
Node *createNode(char data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        perror("Memory allocation for Node failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Check if a character is an operator (+, -, *, /)
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Get operator precedence (higher number means higher precedence)
int getPrecedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

// Build a binary expression tree from an infix expression
Node *buildExpressionTree(char *infix)
{
    Node *stack[100];  // Stack to hold operators
    Node *output[100]; // Stack to hold output nodes (operators and operands)
    int stackTop = -1;
    int outputTop = -1;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == ' ')
        {
            continue; // Skip spaces
        }
        else if (isdigit(infix[i]))
        {
            // Operand: Create a node and push it to the output stack
            int j = i;
            while (isdigit(infix[j]) || infix[j] == '.')
            {
                j++;
            }
            char operand[j - i + 1];
            strncpy(operand, &infix[i], j - i);
            operand[j - i] = '\0';
            i = j - 1;                           // Update the index
            Node *operandNode = createNode('0'); // Placeholder for an operand
            operandNode->data = atof(operand);   // Convert the string to a floating-point number
            output[++outputTop] = operandNode;
        }
        else if (isOperator(infix[i]))
        {
            // Operator: Pop operators from the stack and push to output stack
            while (stackTop >= 0 && getPrecedence(stack[stackTop]->data) >= getPrecedence(infix[i]))
            {
                output[++outputTop] = stack[stackTop--];
            }
            // Push the current operator to the stack
            stack[++stackTop] = createNode(infix[i]);
        }
        else if (infix[i] == '(')
        {
            // Left parenthesis: Push to the stack
            stack[++stackTop] = createNode(infix[i]);
        }
        else if (infix[i] == ')')
        {
            // Right parenthesis: Pop operators and push to output until a left parenthesis is encountered
            while (stackTop >= 0 && stack[stackTop]->data != '(')
            {
                output[++outputTop] = stack[stackTop--];
            }
            // Pop and discard the left parenthesis
            if (stackTop >= 0 && stack[stackTop]->data == '(')
            {
                free(stack[stackTop--]);
            }
        }
    }

    // Pop any remaining operators from the stack to the output
    while (stackTop >= 0)
    {
        output[++outputTop] = stack[stackTop--];
    }

    // Build the expression tree using the output stack
    Node *treeStack[100];
    int treeTop = -1;

    for (int i = 0; i <= outputTop; i++)
    {
        if (!isOperator(output[i]->data))
        {
            // Operand: Push to the tree stack
            treeStack[++treeTop] = output[i];
        }
        else
        {
            // Operator: Create a new operator node and assign left and right children
            Node *operatorNode = output[i];
            operatorNode->right = treeStack[treeTop--];
            operatorNode->left = treeStack[treeTop--];
            // Push the operator node back to the tree stack
            treeStack[++treeTop] = operatorNode;
        }
    }

    // The root of the expression tree will be the top of the tree stack
    return treeStack[treeTop];
}

// Evaluate the expression tree recursively
double evaluateExpressionTree(Node *root)
{
    if (root == NULL)
    {
        return 0.0;
    }
    if (!isOperator(root->data))
    {
        // Operand node
        return root->data;
    }
    else
    {
        // Operator node: Recursively evaluate left and right subtrees
        double leftValue = evaluateExpressionTree(root->left);
        double rightValue = evaluateExpressionTree(root->right);
        switch (root->data)
        {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            if (rightValue == 0.0)
            {
                fprintf(stderr, "Error: Division by zero\n");
                exit(EXIT_FAILURE);
            }
            return leftValue / rightValue;
        default:
            fprintf(stderr, "Error: Invalid operator\n");
            exit(EXIT_FAILURE);
        }
    }
}

// Free memory recursively by post-order traversal
void freeExpressionTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    freeExpressionTree(root->left);
    freeExpressionTree(root->right);
    free(root);
}

int main()
{
    char infixExpression[100];
    printf("Enter an infix expression (without spaces): ");
    scanf("%s", infixExpression);

    Node *root = buildExpressionTree(infixExpression);
    double result = evaluateExpressionTree(root);

    printf("Infix Expression: %s\n", infixExpression);
    printf("Result: %.2f\n", result);

    // Free memory used by the expression tree
    freeExpressionTree(root);

    return 0;
}
