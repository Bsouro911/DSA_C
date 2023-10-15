#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to find the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to create a new binary tree node
struct TreeNode *create_node(int val)
{
    struct TreeNode *new_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Helper function to find the maximum path sum starting at a node
int maxPathSumHelper(struct TreeNode *root, int *maxSum)
{
    if (root == NULL)
        return 0;

    // Recursively calculate the maximum path sums for the left and right subtrees
    int leftMax = maxPathSumHelper(root->left, maxSum);
    int rightMax = maxPathSumHelper(root->right, maxSum);

    // Calculate the maximum path sum that includes the current node
    int currentMax = max(max(leftMax + root->val, rightMax + root->val), root->val);

    // Update the global maxSum with the maximum path sum found so far
    *maxSum = max(*maxSum, max(currentMax, leftMax + rightMax + root->val));

    return currentMax;
}

int maxPathSum(struct TreeNode *root)
{
    int maxSum = root->val; // Initialize maxSum with the root's value
    maxPathSumHelper(root, &maxSum);
    return maxSum;
}

int main()
{
    // Example usage:
    struct TreeNode *root = create_node(10);
    root->left = create_node(2);
    root->right = create_node(10);
    root->left->left = create_node(20);
    root->left->right = create_node(1);
    root->right->right = create_node(-25);
    root->right->right->left = create_node(3);
    root->right->right->right = create_node(4);

    int result = maxPathSum(root);
    printf("Maximum path sum: %d\n", result); // Output: 42
    free(root->right->right->right);
    free(root->right->right->left);
    free(root->right->right);
    free(root->right);
    free(root->left->right);
    free(root->left->left);
    free(root->left);
    free(root);

    return 0;
}
