#include <stdio.h>
#define MAX 10

// struct Queue
// {
//     int arr[MAX];
//     int front, rare;
// };

// void initQ(struct Queue *q)
// {
//     q->front = q->rare = -1;
// }

void addQ(struct Queue *q, int val)
{
    if (!(q->rare == MAX - 1))
    {
        q->rare++;
        q->arr[q->rare] = val;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
}

void delQ(struct Queue *q)
{
    if (!(q->front == -1 || q->front > q->rare))
    {
        q->arr[q->front] = 0;
    }
    if (q->front == q->rare)
    {
        q->front = q->rare = -1;
    }
    else
    {
        q->front++;
    }
}

void traverseQ(struct Queue *q)
{
    if (!(q->front == -1))
    {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rare; i++)
        {
            printf("%d ", q->arr[i]);
        }
    }
}

int main()
{
    struct Queue Q;
    int data;

    initQ(&Q); // initialise the Queue
    addQ(&Q, 11);
    addQ(&Q, 12);
    addQ(&Q, 13);
    addQ(&Q, 14);

    delQ(&Q);
    delQ(&Q);
    traverseQ(&Q);

    return 0;
}
