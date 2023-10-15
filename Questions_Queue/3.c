#include <stdio.h>
#include <stdlib.h>

// Define the structure for a customer
typedef struct Customer
{
    int customerNumber;
    char name[50];
} Customer;

// Define the structure for a queue node
typedef struct QueueNode
{
    Customer customer;
    struct QueueNode *next;
} QueueNode;

// Define the structure for a queue
typedef struct Queue
{
    QueueNode *front;
    QueueNode *rear;
} Queue;

// Function to initialize an empty queue
void initializeQueue(Queue *queue)
{
    queue->front = queue->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(Queue *queue)
{
    return (queue->front == NULL);
}

// Function to enqueue (add) a customer to the queue
void enqueue(Queue *queue, Customer customer)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->customer = customer;
    newNode->next = NULL;

    if (isEmpty(queue))
    {
        queue->front = queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Customer %d added to the queue.\n", customer.customerNumber);
}

// Function to dequeue (remove) a customer from the queue
Customer dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty. No customers to dequeue.\n");
        Customer emptyCustomer = {-1, ""};
        return emptyCustomer;
    }

    QueueNode *temp = queue->front;
    Customer customer = temp->customer;
    queue->front = temp->next;

    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    free(temp);
    printf("Customer %d removed from the queue.\n", customer.customerNumber);
    return customer;
}

int main()
{
    Queue customerQueue;
    initializeQueue(&customerQueue);

    int customerNumber = 1;
    char customerName[50];
    char choice;

    do
    {
        Customer newCustomer;
        newCustomer.customerNumber = customerNumber;
        printf("Enter the name of Customer %d: ", customerNumber);
        scanf("%s", newCustomer.name);

        enqueue(&customerQueue, newCustomer);

        printf("Do you want to add another customer? (y/n): ");
        scanf(" %c", &choice);

        customerNumber++;
    } while (choice == 'y' || choice == 'Y');

    printf("\nCustomers in the queue:\n");
    while (!isEmpty(&customerQueue))
    {
        Customer servingCustomer = dequeue(&customerQueue);
        printf("Serving Customer %d: %s\n", servingCustomer.customerNumber, servingCustomer.name);
    }

    return 0;
}
