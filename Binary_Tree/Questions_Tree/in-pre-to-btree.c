#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;

    return node;
}

void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

struct Node *construct(int inorder[], int start, int end, int preorder[], int *pIndex)
{
    if (start > end)
    {
        return NULL;
    }

    struct Node *node = newNode(preorder[(*pIndex)++]);

    int i;
    for (i = start; i <= end; i++)
    {
        if (inorder[i] == node->data)
        {
            break;
        }
    }

    node->left = construct(inorder, start, i - 1, preorder, pIndex);

    node->right = construct(inorder, i + 1, end, preorder, pIndex);

    return node;
}

struct Node *constructTree(int inorder[], int preorder[], int n)
{
    int pIndex = 0;
    return construct(inorder, 0, n - 1, preorder, &pIndex);
}

int main()
{

    int inorder[] = {4, 2, 1, 7, 5, 8, 3, 6};
    int preorder[] = {1, 2, 4, 3, 5, 7, 8, 6};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    struct Node *root = constructTree(inorder, preorder, n);

    printf("The inorder traversal is ");
    inorderTraversal(root);

    return 0;
}
