#include <stdio.h>
#define MAX 10

struct queue
{
    int arr[MAX], front, rear;
};

void addq(struct queue *q, int val)
{
    if (q->rear == MAX - 1)
        return;
    q->rear++;
    q->arr[q->rear] = val;
    if (q->front == -1)
        q->front = 0;
}
int delq(struct queue *q)
{
    int data;
    if (q->front == -1)
        return -1;
    data = q->arr[q->front];
    q->arr[q->front] = 0;
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return data;
}
int isEmptyq(struct queue *q)
{
    if (q->front == -1 && q->rear == -1)
        return 1;
    else
        return 0;
}
void bfs(int arr[8][8], int size, int viz[8])
{
    struct queue q;
    int idx, i;
    q.front = q.rear = -1;
    addq(&q, 0);
    while (!isEmptyq(&q)) // Fix the while loop condition
    {
        idx = delq(&q);
        if (viz[idx] == 0)
        {
            viz[idx] = 1;
            printf("%d ", idx + 1);
            for (i = 0; i < size; i++)
            {
                if (viz[i] == 0 && arr[idx][i] == 1)
                {
                    addq(&q, i);
                }
            }
        }
    }
}

int main()
{
    int arr[8][8] = {0};
    int visited[8] = {0};
    arr[0][1] = arr[1][0] = 1;
    arr[0][2] = arr[2][0] = 1;
    arr[1][3] = arr[3][1] = 1;
    arr[1][4] = arr[4][1] = 1;
    arr[2][5] = arr[5][2] = 1;
    arr[2][6] = arr[6][2] = 1;
    arr[3][7] = arr[7][3] = 1;
    arr[4][7] = arr[7][4] = 1;
    arr[5][7] = arr[7][5] = 1;
    arr[6][7] = arr[7][6] = 1;
    printf("BFS Traversal: ");
    for (int i = 0; i < 8; i++)
    {
        if (visited[i] == 0)
        {
            bfs(arr, 8, visited);
        }
    }
    return 0;
}
