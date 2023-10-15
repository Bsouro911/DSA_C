// 1. File System Implementation: Create a simplified file system using a tree structure. Nodes represent directories and files. Implement operations like creating files, deleting files, navigating directories, and listing contents.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for representing files and directories
typedef struct Node
{
    char name[50];
    int isFile; // 1 for file, 0 for directory
    struct Node *parent;
    struct Node *children;
    struct Node *next;
} Node;

// Create a new node (file or directory)
Node *createNode(const char *name, int isFile, Node *parent)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        perror("Memory allocation for Node failed");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->name, name);
    newNode->isFile = isFile;
    newNode->parent = parent;
    newNode->children = NULL;
    newNode->next = NULL;
    return newNode;
}

// Create a directory
void createDirectory(Node **currentDir, const char *name)
{
    Node *newNode = createNode(name, 0, *currentDir);
    if ((*currentDir)->children == NULL)
    {
        (*currentDir)->children = newNode;
    }
    else
    {
        Node *currentChild = (*currentDir)->children;
        while (currentChild->next != NULL)
        {
            currentChild = currentChild->next;
        }
        currentChild->next = newNode;
    }
}

// Create a file
void createFile(Node **currentDir, const char *name)
{
    Node *newNode = createNode(name, 1, *currentDir);
    if ((*currentDir)->children == NULL)
    {
        (*currentDir)->children = newNode;
    }
    else
    {
        Node *currentChild = (*currentDir)->children;
        while (currentChild->next != NULL)
        {
            currentChild = currentChild->next;
        }
        currentChild->next = newNode;
    }
}

// List contents of the current directory
void listContents(Node *currentDir)
{
    printf("Contents of directory '%s':\n", currentDir->name);
    Node *currentChild = currentDir->children;
    while (currentChild != NULL)
    {
        if (currentChild->isFile)
        {
            printf("File: %s\n", currentChild->name);
        }
        else
        {
            printf("Directory: %s\n", currentChild->name);
        }
        currentChild = currentChild->next;
    }
}

// Change the current directory
void changeDirectory(Node **currentDir, const char *name)
{
    if (strcmp(name, "..") == 0)
    {
        // Move up one level
        if ((*currentDir)->parent != NULL)
        {
            *currentDir = (*currentDir)->parent;
        }
    }
    else
    {
        // Move to a subdirectory
        Node *currentChild = (*currentDir)->children;
        while (currentChild != NULL)
        {
            if (!currentChild->isFile && strcmp(currentChild->name, name) == 0)
            {
                *currentDir = currentChild;
                return;
            }
            currentChild = currentChild->next;
        }
        printf("Directory '%s' not found.\n", name);
    }
}

int main()
{
    Node *root = createNode("/", 0, NULL);
    Node *currentDir = root;

    while (1)
    {
        char command[50];
        printf("\nEnter a command (createDir, createFile, list, cd, exit): ");
        scanf("%s", command);

        if (strcmp(command, "createDir") == 0)
        {
            char name[50];
            printf("Enter directory name: ");
            scanf("%s", name);
            createDirectory(&currentDir, name);
        }
        else if (strcmp(command, "createFile") == 0)
        {
            char name[50];
            printf("Enter file name: ");
            scanf("%s", name);
            createFile(&currentDir, name);
        }
        else if (strcmp(command, "list") == 0)
        {
            listContents(currentDir);
        }
        else if (strcmp(command, "cd") == 0)
        {
            char name[50];
            printf("Enter directory name or '..' to go up: ");
            scanf("%s", name);
            changeDirectory(&currentDir, name);
        }
        else if (strcmp(command, "exit") == 0)
        {
            break;
        }
        else
        {
            printf("Invalid command. Try again.\n");
        }
    }

    return 0;
}
