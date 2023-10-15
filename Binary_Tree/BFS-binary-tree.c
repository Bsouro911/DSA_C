#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node *create_node(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void printLevel(struct node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
    {
        printf("%d ", root->data);
    }
    else if (level > 1)
    {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

int height_tree(struct node *root)
{
    if (root == NULL)
        return 0;
    int left_height = height_tree(root->left);
    int right_height = height_tree(root->right);

    if (left_height > right_height)
        return left_height + 1;
    else
        return right_height + 1;
}

void levelOrderTraversal(struct node *root)
{
    int h = height_tree(root);
    for (int i = 1; i <= h; i++)
    {
        // print all elements in each level
        printLevel(root, i);
        printf("\n");
    }
}

int main()
{
    root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);

    printf("Level Order traversal of binary tree is \n");
    levelOrderTraversal(root);

    return 0;
}
