#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int val;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rare;
};

void initQ(struct Queue *q)
{
    q->front = q->rare = NULL;
}

void enqueue(struct Queue *q, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (!(ptr == NULL))
    {
        ptr->val = data;
        ptr->next = NULL;
        if (q->front == NULL)
        {
            q->front = q->rare = ptr;
        }
        q->rare->next = ptr;
        q->rare = ptr;
    }
}

bool dequeue(struct Queue *q)
{
    struct Node *temp = q->front;
    if (!(q->front == NULL))
    {
        q->front = q->front->next;
        free(temp);
        return true;
    }
}

void traverse(struct Queue *q)
{
    struct Node *current = q->front;

    printf("Queue Elements: ");
    while (current != NULL)
    {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    struct Queue Q;
    struct Node *node;

    initQ(&Q);
    enqueue(&Q, 14);
    enqueue(&Q, 15);
    enqueue(&Q, 16);
    enqueue(&Q, 17);

    dequeue(&Q);
    dequeue(&Q);
    traverse(&Q);

    // deA_queue(&Q);
    return 0;
}
