#include <stdio.h>
#define MAX 10

struct Queue {
    int arr[MAX];
    int front, rear;
};

void initq(struct Queue *);
void addq(struct Queue *, int);
int delq(struct Queue *);

int main() {
    struct Queue Q;
    int data;

    initq(&Q); // initialise the Queue
    addq(&Q, 11);
    addq(&Q, 12);
    addq(&Q, 13);
    addq(&Q, 14);

    data = delq(&Q);
    if (data != -1)
        printf("deleted element: %d\n", data);

    data = delq(&Q);
    if (data != -1)
        printf("deleted element: %d\n", data);

    data = delq(&Q);
    if (data != -1)
        printf("deleted element: %d\n", data);

    data = delq(&Q);
    if (data != -1)
        printf("deleted element: %d\n", data);

    data = delq(&Q);
    if (data != -1)
        printf("deleted element: %d\n", data);

    return 0;
}

void initq(struct Queue *Q) {
    Q->front = -1;
    Q->rear = -1;
}

void addq(struct Queue *Q, int data) {
    if (Q->rear == MAX - 1) {
        printf("the queue is full!\n");
        return;
    }

    Q->rear++;
    Q->arr[Q->rear] = data;

    if (Q->front == -1) {
        Q->front = 0;
    }
}

int delq(struct Queue *Q) {
    int data;

    if (Q->front == -1 || Q->front > Q->rear) {
        printf("the queue is empty!\n");
        return -1;
    }

    data = Q->arr[Q->front];
    Q->arr[Q->front] = 0;

    if (Q->front == Q->rear) {
        Q->front = Q->rear = -1;
    } else {
        Q->front++;
    }

    return data;
}
