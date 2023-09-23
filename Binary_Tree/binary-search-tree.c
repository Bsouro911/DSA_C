#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node *insert(struct node **root, int data)
{
    if (*root == NULL)
    {
        *root = createNode(data);
    }
    else if (data < (*root)->data)
    {
        insert(&((*root)->left), data);
    }
    else
    {
        insert(&((*root)->right), data);
    }
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d", root->data);
    }
}

struct node *findMin(struct node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

void delete(struct node **root, int data)
{
    if (*root == NULL)
        return;

    if (data < (*root)->data)
    {
        delete (&((*root)->left), data);
    }
    else if (data > (*root)->data)
    {
        delete (&((*root)->right), data);
    }

    else
    {
        if ((*root)->left == NULL)
        {
            struct node *temp = *root;
            *root = (*root)->right;
            free(temp);
        }
        else if ((*root)->right == NULL)
        {
            struct node *temp = *root;
            *root = (*root)->left;
            free(temp);
        }
        else
        {
            struct node *temp = findMin((*root)->right);
            (*root)->data = temp->data;
            delete (&((*root)->right), temp->data);
        }
    }
}

int height(struct node *root)
{
    int left_height, right_height;

    if (!root)
        return 0;
    else
    {
        left_height = height(root->left);
        right_height = height(root->right);

        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}

int totalNodes(struct node *root)
{
    if (root == NULL)
        return 0;
    else
        return totalNodes(root->left) + totalNodes(root->right) + 1;
}

int internalNodes(struct node *root)
{
    if ((root == NULL) || ((root->left == NULL) && (root->right == NULL)))
        return 0;
    else
        return ((internalNodes(root->left) + internalNodes(root->right)) + 1);
}

int externalNodes(struct node *root)
{
    if (root == NULL)
        return 0;
    else if ((root->right == NULL) && (root->left == NULL))
        return 1;
    else
        return (externalNodes(root->left) + externalNodes(root->right));
}

int smallestElement(struct node *root)
{
    if (root == NULL || root->left == NULL)
    {
        if (root != NULL)
            return root->data;
        else
            return -1;
    }
    else
        return smallestElement(root->left);
}

int largestElement(struct node *root)
{
    if (root == NULL || root->right == NULL)
    {
        if (root != NULL)
            return root->data;
        else
            return -1;
    }
    else
        return largestElement(root->right);
}

struct node *lowestCommonAncestor(struct node *root, struct node *p, struct node *q)
{
    if (root == NULL)
        return NULL;
    int curr = root->data;
    if (curr < p->data && curr < q->data)
        return lowestCommonAncestor(root->right, p, q);
    if (curr > p->data && curr > q->data)
        return lowestCommonAncestor(root->left, p, q);

    return root;
}

bool deleteTree(struct node *root)
{
    if (root != NULL)
    {
        deleteTree(root->right);
        deleteTree(root->right);
        free(root);
    }
}

int main()
{
    insert(&root, 5);
    insert(&root, 6);
    insert(&root, 8);
    insert(&root, 4);
    insert(&root, 9);
    insert(&root, 7);
    insert(&root, 2);

    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");

    printf("%d\n", height(root));

    printf("%d\n", totalNodes(root));
    printf("%d\n", internalNodes(root));
    printf("%d\n", externalNodes(root));

    printf("%d\n", largestElement(root));  // 9
    printf("%d\n", smallestElement(root)); // 2

    struct node *node7 = root->right->right->right;
    struct node *node9 = root->right->right->left;

    struct node *lca = lowestCommonAncestor(root, node7, node9);

    printf("Lowest Common Ancestor: %d\n", lca->data);

    delete (&root, 9);
    inorder(root);

    printf("\n");

    if (deleteTree(root))
        printf("done!");

    return 0;
}