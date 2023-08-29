#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct CircularQueue
{
    struct Node *front;
    struct Node *rear;
};

struct Node *createNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if (node)
    {
        node->data = data;
        node->next = NULL;
    }
    return node;
}

struct CircularQueue *createCircularQueue()
{
    struct CircularQueue *queue = (struct CircularQueue *)malloc(sizeof(struct CircularQueue));
    if (queue)
    {
        queue->front = NULL;
        queue->rear = NULL;
    }
    return queue;
}

int isEmpty(struct CircularQueue *queue)
{
    return (queue->front == NULL);
}

void enqueue(struct CircularQueue *queue, int data)
{
    struct Node *newNode = createNode(data);
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        return;
    }

    if (isEmpty(queue))
    {
        queue->front = newNode;
    }
    else
    {
        queue->rear->next = newNode;
    }

    queue->rear = newNode;
    queue->rear->next = queue->front;
}

void dequeue(struct CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return;
    }

    struct Node *temp = queue->front;
    if (queue->front == queue->rear)
    {
        queue->front = NULL;
        queue->rear = NULL;
    }
    else
    {
        queue->front = queue->front->next;
        queue->rear->next = queue->front;
    }

    free(temp);
}

void display(struct CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return;
    }

    struct Node *current = queue->front;
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != queue->front);
    printf("\n");
}

int main()
{
    struct CircularQueue *queue = createCircularQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printf("Circular Queue: ");
    display(queue);

    dequeue(queue);

    printf("Circular Queue after dequeue: ");
    display(queue);

    return 0;
}
