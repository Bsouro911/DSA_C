#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new binary tree node
struct TreeNode *createNode(int data)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Pre-order traversal: Root -> Left -> Right
void preOrderTraversal(struct TreeNode *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// In-order traversal: Left -> Root -> Right
void inOrderTraversal(struct TreeNode *root)
{
    if (root == NULL)
        return;

    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

// Post-order traversal: Left -> Right -> Root
void postOrderTraversal(struct TreeNode *root)
{
    if (root == NULL)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}

int main()
{
    // Creating a sample binary tree
    struct TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Pre-order traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}
