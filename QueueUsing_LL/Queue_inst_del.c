#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Queue{
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

    deA_queue(&Q);
    return 0;
}

void initQ(struct Queue *){

}
void enqueue(struct Queue *, int){

}
int dequeue(struct Queue *){

}
void deA_queue(struct Queue *){

}