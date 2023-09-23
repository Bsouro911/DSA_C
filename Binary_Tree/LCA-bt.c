#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *tree = NULL;

struct node *create_node(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_element(struct node **tree, int data)
{
    if (*tree == NULL)
    {
        *tree = create_node(data);
    }
    else if (data <= (*tree)->data)
    {
        insert_element(&((*tree)->left), data);
    }
    else
    {
        insert_element(&((*tree)->right), data);
    }
}

struct node *lowestCommonAncestor(struct node *tree, struct node *p, struct node *q)
{
    if (tree == NULL)
        return NULL;
    int curr = tree->data;
    if (curr < p->data && curr < q->data)
        return lowestCommonAncestor(tree->right, p, q);
    if (curr > p->data && curr > q->data)
        return lowestCommonAncestor(tree->left, p, q);

    return tree;
}

int main()
{
    int val;

    insert_element(&tree, 5);
    insert_element(&tree, 6);
    insert_element(&tree, 8);
    insert_element(&tree, 4);
    insert_element(&tree, 9);
    insert_element(&tree, 7);
    insert_element(&tree, 2);

    struct node *node7 = tree->right->right->right;
    struct node *node9 = tree->right->right->left;

    struct node *lca = lowestCommonAncestor(tree, node7, node9);

    printf("Lowest Common Ancestor: %d\n", lca->data);

    return 0;
}
