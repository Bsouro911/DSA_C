#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *left;
    struct node *right;
};

struct node *create_node(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->val = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

bool areIdentical(struct node *t1, struct node *t2)
{
    if (t1 == NULL && t2 == NULL)
    {
        return true;
    }
    if (t1 == NULL || t2 == NULL)
    {
        return false;
    }
    return (t1->val == t2->val) &&
           areIdentical(t1->left, t2->left) &&
           areIdentical(t1->right, t2->right);
}

bool isSubtree(struct node *tlarge, struct node *tsmall)
{
    if (tlarge == NULL || tsmall == NULL)
    {
        return false;
    }
    if (areIdentical(tlarge, tsmall))
    {
        return true;
    }
    return isSubtree(tlarge->left, tsmall) || isSubtree(tlarge->right, tsmall);
}

int main()
{

    // TREE 1
    struct node *Tlarge = create_node(26);
    Tlarge->right = create_node(3);
    Tlarge->right->right = create_node(3);
    Tlarge->left = create_node(10);
    Tlarge->left->left = create_node(4);
    Tlarge->left->left->right = create_node(30);
    Tlarge->left->right = create_node(6);

    // TREE 2
    struct node *Tsmall = create_node(10);
    Tsmall->right = create_node(6);
    Tsmall->left = create_node(4);
    Tsmall->left->right = create_node(30);

    if (isSubtree(Tlarge, Tsmall))
        printf("Tree 2 is subtree of Tree 1");
    else
        printf("Tree 2 is not a subtree of Tree 1");

    return 0;
}
