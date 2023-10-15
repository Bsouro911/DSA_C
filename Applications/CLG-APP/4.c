#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the QueueNode Structure
typedef struct QueueNode
{
    char name[50];
    struct QueueNode *next;
} QueueNode;

// Function to create an empty queue
QueueNode *createQueue()
{
    return NULL;
}

// Function to check if the queue is empty
int isEmpty(QueueNode *front)
{
    return (front == NULL);
}

// Function to enqueue a player (name) into the queue
void enqueuePlayer(QueueNode **front, QueueNode **rear, const char *name)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (newNode == NULL)
    {
        perror("Memory allocation for QueueNode failed");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (isEmpty(*front))
    {
        *front = newNode;
        *rear = newNode;
    }
    else
    {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

// Function to dequeue and return the front player from the queue
char *dequeuePlayer(QueueNode **front, QueueNode **rear)
{
    if (isEmpty(*front))
    {
        fprintf(stderr, "Error: Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    QueueNode *temp = *front;
    char *name = temp->name;

    if (*front == *rear)
    {
        *front = NULL;
        *rear = NULL;
    }
    else
    {
        *front = (*front)->next;
    }

    free(temp);
    return name;
}

// Function to simulate the Hot Potato game
char *playHotPotato(const char *playerNames[], int numPlayers, int passCount)
{
    QueueNode *front = NULL;
    QueueNode *rear = NULL;

    // Enqueue players into the queue
    for (int i = 0; i < numPlayers; i++)
    {
        enqueuePlayer(&front, &rear, playerNames[i]);
    }

    // Simulate passing the potato
    while (!isEmpty(front))
    {
        for (int i = 0; i < passCount - 1; i++)
        {
            // Move the front player to the rear of the queue
            char *player = dequeuePlayer(&front, &rear);
            enqueuePlayer(&front, &rear, player);
        }

        // Remove the front player from the queue (eliminate)
        char *eliminatedPlayer = dequeuePlayer(&front, &rear);
        if (isEmpty(front))
        {
            return eliminatedPlayer;
        }
    }

    // This should never be reached
    return NULL;
}

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    const char *playerNames[] = {"Alice", "Bob", "Charlie", "David", "Eve"};
    int numPlayers = sizeof(playerNames) / sizeof(playerNames[0]);
    int passCount;

    printf("Enter the pass count for the Hot Potato game: ");
    scanf("%d", &passCount);

    char *eliminatedPlayer = playHotPotato(playerNames, numPlayers, passCount);
    printf("The player eliminated from the game: %s\n", eliminatedPlayer);

    return 0;
}
