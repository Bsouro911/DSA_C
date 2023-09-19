#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Function to insert a node into the binary tree
struct TreeNode *insertNode(struct TreeNode *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function for pre-order traversal
void preorderTraversal(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Function for in-order traversal
void inorderTraversal(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Function for post-order traversal
void postorderTraversal(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

// Function to find the height of the binary tree
int height(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}

// Function to count the number of leaf nodes
int countLeafNodes(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Helper function to check if a binary tree is a valid BST
bool isBSTUtil(struct TreeNode *root, struct TreeNode **prev)
{
    if (root == NULL)
    {
        return true;
    }

    // Recursively check the left subtree
    if (!isBSTUtil(root->left, prev))
    {
        return false;
    }

    // Check if the current node's data is greater than the previous node's data
    if (*prev != NULL && root->data <= (*prev)->data)
    {
        return false;
    }

    // Update the previous node
    *prev = root;

    // Recursively check the right subtree
    return isBSTUtil(root->right, prev);
}

// Function to check if a binary tree is a valid BST
bool isBST(struct TreeNode *root)
{
    struct TreeNode *prev = NULL;
    return isBSTUtil(root, &prev);
}

// Helper function to find the diameter of a binary tree
int diameterUtil(struct TreeNode *root, int *diameter)
{
    if (root == NULL)
    {
        return 0;
    }

    // Recursively calculate the height of the left and right subtrees
    int leftHeight = diameterUtil(root->left, diameter);
    int rightHeight = diameterUtil(root->right, diameter);

    // Update the diameter if the current path is longer
    if (leftHeight + rightHeight > *diameter)
    {
        *diameter = leftHeight + rightHeight;
    }

    // Return the height of the current subtree
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Function to find the diameter of a binary tree
int findDiameter(struct TreeNode *root)
{
    int diameter = 0;
    diameterUtil(root, &diameter);
    return diameter;
}

int main()
{
    struct TreeNode *root = NULL;
    int data;

    // Create the binary tree
    int elements[] = {5, 3, 7, 2, 4, 6, 8};
    int numElements = sizeof(elements) / sizeof(elements[0]);
    for (int i = 0; i < numElements; i++)
    {
        root = insertNode(root, elements[i]);
    }

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    printf("Height of Binary Tree: %d\n", height(root));

    printf("Number of Leaf Nodes: %d\n", countLeafNodes(root));

    // Check if the binary tree is a valid BST
    bool isBSTResult = isBST(root);
    if (isBSTResult)
    {
        printf("The binary tree is a valid Binary Search Tree (BST).\n");
    }
    else
    {
        printf("The binary tree is not a valid Binary Search Tree (BST).\n");
    }

    // Find the diameter of the binary tree
    int diameter = findDiameter(root);
    printf("The diameter of the binary tree is: %d\n", diameter);

    return 0;
}
