#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct PrintJob
{
    int jobID;
    char jobName[50];
    int numPages;
    struct PrintJob *next;
};

struct PrinterQueue
{
    struct PrintJob *front;
    struct PrintJob *rear;
};

struct PrintJob *createPrintJob(int id, char *name, int pages)
{
    struct PrintJob *newJob = (struct PrintJob *)malloc(sizeof(struct PrintJob));
    newJob->jobID = id;
    strcpy(newJob->jobName, name);
    newJob->numPages = pages;
    newJob->next = NULL;
    return newJob;
}

void initQueue(struct PrinterQueue *queue)
{
    queue->front = queue->rear = NULL;
}

int isEmpty(struct PrinterQueue *queue)
{
    return (queue->front == NULL);
}

void enqueue(struct PrinterQueue *queue, struct PrintJob *job)
{
    if (isEmpty(queue))
    {
        queue->front = queue->rear = job;
    }
    else
    {
        queue->rear->next = job;
        queue->rear = job;
    }
}

struct PrintJob *dequeue(struct PrinterQueue *queue)
{
    if (isEmpty(queue))
    {
        return NULL;
    }
    else
    {
        struct PrintJob *job = queue->front;
        queue->front = job->next;
        if (queue->front == NULL)
        {
            queue->rear = NULL;
        }
        return job;
    }
}

void printJob(struct PrintJob *job)
{
    printf("Printing Job ID: %d, Name: %s, Pages: %d\n", job->jobID, job->jobName, job->numPages);
    sleep(2);
    free(job);
}

int main()
{
    struct PrinterQueue queue;
    initQueue(&queue);

    int jobIdCounter = 1;
    int choice;
    char jobName[50];
    int numPages;

    printf("Printer Queue Management\n");

    while (1)
    {
        printf("\n1. Add Print Job\n2. Process Print Jobs\n3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character left in the input buffer

        switch (choice)
        {
        case 1:
            printf("Enter Print Job Name: ");
            fgets(jobName, sizeof(jobName), stdin);
            jobName[strcspn(jobName, "\n")] = '\0';
            printf("Enter Number of Pages: ");
            scanf("%d", &numPages);
            getchar();

            struct PrintJob *newJob = createPrintJob(jobIdCounter++, jobName, numPages);
            enqueue(&queue, newJob);
            break;

        case 2:
            while (!isEmpty(&queue))
            {
                struct PrintJob *job = dequeue(&queue);
                printJob(job);
            }
            printf("All print jobs processed.\n");
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
