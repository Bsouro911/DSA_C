#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *left, *right;
};

int max(int a, int b) { return (a > b) ? a : b; }

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

int height(struct node *node)
{
    if (node == NULL)
        return 0;

    return 1 + max(height(node->left), height(node->right));
}

int diameter(struct node *tree)
{
    if (tree == NULL)
        return 0;

    int lheight = height(tree->left);
    int rheight = height(tree->right);

    int ldiameter = diameter(tree->left);
    int rdiameter = diameter(tree->right);

    return max(lheight + rheight + 1,
               max(ldiameter, rdiameter));
}

int isBalanced(struct node *root)
{
    if (root == NULL)
        return 0;
    int lh = isBalanced(root->left);
    if (lh == -1)
        return -1;
    int rh = isBalanced(root->right);
    if (rh == -1)
        return -1;

    if (abs(lh - rh) > 1)
        return -1;
    else
        return lh > rh ? lh + 1 : rh + 1;
}

bool isBST(struct node *root, struct node **prev)
{
    if (root == NULL)
    {
        return true;
    }

    if (!isBST(root->left, prev))
    {
        return false;
    }

    if (*prev != NULL && root->data <= (*prev)->data)
    {
        return false;
    }

    *prev = root;

    return isBST(root->right, prev);
}

bool checkBst(struct node *root)
{
    struct node *prev = NULL;
    return isBST(root, &prev);
}

int countLeafNodes(struct node *root)
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

int main()
{

    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Diameter of the given binary tree is %d\n", diameter(root));

    if (isBalanced(root) > 0)
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    bool isBSTResult = checkBst(root);
    if (isBSTResult)
    {
        printf("The binary tree is a valid Binary Search Tree (BST).\n");
    }
    else
    {
        printf("The binary tree is not a valid Binary Search Tree (BST).\n");
    }

    printf("Number of Leaf Nodes: %d\n", countLeafNodes(root));

    return 0;
}
