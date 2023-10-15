#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *left;
    struct node *right;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

struct node *create_node(int val)
{
    struct node *new_node = (struct TreeNode *)malloc(sizeof(struct node));
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

int maxPathSum(struct node *root, int *maxSum)
{
    if (root == NULL)
        return 0;

    int leftMax = maxPathSum(root->left, maxSum);
    int rightMax = maxPathSum(root->right, maxSum);
}
