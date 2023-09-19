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

struct node *create_node(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node *insert(struct node **root, int data)
{
    if (*root == NULL)
    {
        *root = create_node(data);
    }
    else if (data <= (*root)->data)
    {
        insert(&((*root)->left), data);
    }
    else
    {
        insert(&((*root)->right), data);
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

struct node *deleteNode(struct node **root, int k)
{
    if ((*root) == NULL)
    {
        return (*root);
    }

    if (k < (*root)->data)
    {
        (*root)->left = deleteNode(&((*root)->left), k);
    }
    else if (k > (*root)->data)
    {
        (*root)->right = deleteNode(&((*root)->right), k);
    }
    else
    {
        // Node with only one child or no child
        if ((*root)->left == NULL)
        {
            struct node *temp = (*root)->right;
            free((*root));
            return temp;
        }
        else if ((*root)->right == NULL)
        {
            struct node *temp = (*root)->left;
            free((*root));
            return temp;
        }

        // Node with two children, get the inorder successor
        struct node *temp = findMin((*root)->right);

        // Copy the inorder successor's content to this node
        (*root)->data = temp->data;

        // Delete the inorder successor and update the right subtree
        (*root)->right = deleteNode(&((*root)->right), temp->data);
    }
    return *root; // Updated the pointer to the root of the subtree
}

void inorder_traversal(struct node *tree)
{
    if (tree != NULL)
    {
        inorder_traversal(tree->left);
        printf("%d\t", tree->data);
        inorder_traversal(tree->right);
    }
}

struct node *leastCa(struct node *root, int p, int q)
{
    if (root == NULL)
        return NULL;
    int curr = root->data;
    if (curr < p && curr < q)
    {
        return leastCa(root->right, p, q);
    }
    if (curr > p && curr > q)
    {
        return leastCa(root->left, p, q);
    }
    return root;
}

int main()
{
    insert(&root, 20);
    insert(&root, 17);
    insert(&root, 6);
    insert(&root, 18);
    insert(&root, 8);
    insert(&root, 5);
    insert(&root, 7);
    insert(&root, 10);
    insert(&root, 13);

    // struct node *temp = findMin(root);
    // printf("%d", temp->data);
    // inorder_traversal(root);
    // deleteNode(&root, 8);
    // deleteNode(&root, 18);
    // deleteNode(&root, 10);
    // printf("\n");
    // inorder_traversal(root);

    // struct node *temp = leastCa(root, 7, 18);
    // printf("%d", temp->data);

    return 0;
}

// bool search(struct node *root, int data)
// {
//     while (root != NULL)
//     {
//         if (data == root->data)
//         {
//             return true;
//         }
//         else if (data < root->data)
//         {
//             root = root->left;
//         }
//         else
//         {
//             root = root->right;
//         }
//     }
//     return false;
// }