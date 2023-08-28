#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

void initQ(struct Queue *);
void enqueue(struct Queue *, int);
int dequeue(struct Queue *);
void deA_queue(struct Queue *); // deallocates memory

int main()
{
    struct Queue Q;
    int data;

    initQ(&Q);
    enqueue(&Q, 14);
    enqueue(&Q, 15);
    enqueue(&Q, 16);
    enqueue(&Q, 17);

    data = dequeue(&Q);
    if (data != -1)
        printf("deleted element: %d\n", data);

    data = dequeue(&Q);
    if (data != -1)
        printf("deleted element: %d\n", data);

    data = dequeue(&Q);
    if (data != -1)
        printf("deleted element: %d\n", data);

    data = dequeue(&Q);
    if (data != -1)
        printf("deleted element: %d\n", data);

    data = dequeue(&Q);
    if (data != -1)
        printf("deleted element: %d\n", data);

    // deA_queue(&Q);
    return 0;
}

void initQ(struct Queue *q)
{
    q->front = q->rear = NULL;
}

void enqueue(struct Queue *q, int val)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        printf("Queue is Full!");
        return;
    }

    temp->data = val;
    temp->next = NULL;

    if (q->front == NULL)
    {
        q->rear = q->front = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(struct Queue *q)
{
    struct Node *temp;
    int val;

    if (q->front == NULL)
    {
        printf("Queue is Empty!");
        return -1;
    }

    val = q->front->data;
    temp = q->front;
    q->front = q->front->next;
    free(temp);
    return val;
}

void deA_queue(struct Queue *q)
{
    while (q->front != NULL)
    {
        struct Node *temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
}
