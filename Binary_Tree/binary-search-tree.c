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

// Function to create a new node
struct node *create_node(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert an element into the BST
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

void preorder_traversal(struct node *tree)
{
    if (tree != NULL)
    {
        printf("%d\t", tree->data);
        preorder_traversal(tree->left);
        preorder_traversal(tree->right);
    }
}

// Function to perform inorder traversal with tree structure
void inorder_traversal(struct node *tree)
{
    if (tree != NULL)
    {
        inorder_traversal(tree->left);
        printf("%d\t", tree->data);
        inorder_traversal(tree->right);
    }
}

// Function to perform postorder traversal with tree structure
void postorder_traversal(struct node *tree)
{
    if (tree != NULL)
    {
        postorder_traversal(tree->left);
        postorder_traversal(tree->right);
        printf("%d\t", tree->data);
    }
}

int tree_height(struct node *root)
{
    if (!root)
        return 0;
    else
    {
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}

void mirror_image(struct node *tree)
{
    struct node *ptr;
    if (tree != NULL)
    {
        mirror_image(tree->left);
        mirror_image(tree->right);

        // swaping
        ptr = tree->left;
        ptr->left = ptr->right;
        tree->right = ptr;
    }
}

int total_nodes(struct node *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        return (total_nodes(tree->left) + total_nodes(tree->right) + 1);
    }
}

// total number of leaf nodes
int total_external_node(struct node *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else if (tree->left == NULL && tree->right == NULL)
    {
        return 1;
    }
    else
    {
        return (total_external_node(tree->left) + total_external_node(tree->right));
    }
}

// total number of nodes - total number of leaf nodes
int total_internal_node(struct node *tree)
{
    if ((tree == NULL) || ((tree->left == NULL) && (tree->right == NULL)))
    {
        return 0;
    }
    else
    {
        return ((total_internal_node(tree->left) + total_internal_node(tree->right)) + 1);
    }
}

bool *delete_tree(struct node *tree)
{
    if (tree != NULL)
    {
        delete_tree(tree->left);
        delete_tree(tree->right);
        free(tree);
    }
}

// Function to find the smallest and largest element in a BST
// Function to find the smallest element in a BST
int find_smallest_element(struct node *tree)
{
    if ((tree == NULL) || (tree->left == NULL))
    {
        if (tree != NULL)
        {
            return tree->data;
        }
        else
        {
            // Handle the case when the tree is empty
            return -1; // Assuming INT_MIN represents an empty tree
        }
    }
    else
    {
        return find_smallest_element(tree->left);
    }
}

// Function to find the largest element in a BST
int find_largest_element(struct node *tree)
{
    if ((tree == NULL) || (tree->right == NULL))
    {
        if (tree != NULL)
        {
            return tree->data;
        }
        else
        {
            // Handle the case when the tree is empty
            return -1; // Assuming INT_MIN represents an empty tree
        }
    }
    else
    {
        return find_largest_element(tree->right);
    }
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

    preorder_traversal(tree);
    printf("\n");
    inorder_traversal(tree);
    printf("\n");
    postorder_traversal(tree);
    printf("\n");

    printf("%d\n", tree_height(tree));

    printf("%d\n", total_nodes(tree));
    printf("%d\n", total_internal_node(tree));
    printf("%d\n", total_external_node(tree));

    printf("%d\n", find_largest_element(tree));  // 9
    printf("%d\n", find_smallest_element(tree)); // 2

    if (delete_tree(tree))
        printf("done!");

    return 0;
}
