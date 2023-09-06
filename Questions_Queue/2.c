#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // for sleep function (POSIX)

// Structure to represent a process
struct Process
{
    int processID;
    char processName[50];
    int priority;
    int burstTime;
    struct Process *next;
};

// Structure to represent the task scheduler queue
struct TaskScheduler
{
    struct Process *front;
    struct Process *rear;
};

// Function to create a new process
struct Process *createProcess(int id, char *name, int priority, int burst)
{
    struct Process *newProcess = (struct Process *)malloc(sizeof(struct Process));
    newProcess->processID = id;
    strcpy(newProcess->processName, name);
    newProcess->priority = priority;
    newProcess->burstTime = burst;
    newProcess->next = NULL;
    return newProcess;
}

// Function to initialize the task scheduler queue
void initTaskScheduler(struct TaskScheduler *scheduler)
{
    scheduler->front = scheduler->rear = NULL;
}

// Function to check if the task scheduler queue is empty
int isEmpty(struct TaskScheduler *scheduler)
{
    return (scheduler->front == NULL);
}

// Function to enqueue a process
void enqueue(struct TaskScheduler *scheduler, struct Process *process)
{
    if (isEmpty(scheduler))
    {
        scheduler->front = scheduler->rear = process;
    }
    else
    {
        scheduler->rear->next = process;
        scheduler->rear = process;
    }
}

// Function to dequeue a process
struct Process *dequeue(struct TaskScheduler *scheduler)
{
    if (isEmpty(scheduler))
    {
        return NULL;
    }
    else
    {
        struct Process *process = scheduler->front;
        scheduler->front = process->next;
        if (scheduler->front == NULL)
        {
            scheduler->rear = NULL;
        }
        return process;
    }
}

// Function to simulate task execution with a delay
void executeTask(struct Process *process)
{
    printf("Executing Process ID: %d, Name: %s, Priority: %d, Burst Time: %d\n",
           process->processID, process->processName, process->priority, process->burstTime);
    // Simulate execution by introducing a delay (e.g., 2 seconds)
    sleep(2);
    free(process); // Free memory after execution
}

int main()
{
    struct TaskScheduler scheduler;
    initTaskScheduler(&scheduler);

    int processIdCounter = 1;
    int choice;
    char processName[50];    // Moved variable declaration here
    int priority, burstTime; // Moved variable declaration here

    printf("Task Scheduler Simulation\n");

    while (1)
    {
        printf("\n1. Add Process\n2. Execute Processes\n3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Simulate process arrival
            printf("Enter Process Name: ");
            scanf("%s", processName);
            printf("Enter Priority: ");
            scanf("%d", &priority);
            printf("Enter Burst Time: ");
            scanf("%d", &burstTime);

            struct Process *newProcess = createProcess(processIdCounter++, processName, priority, burstTime);
            enqueue(&scheduler, newProcess);
            break;

        case 2:
            // Execute processes based on priority
            while (!isEmpty(&scheduler))
            {
                struct Process *process = dequeue(&scheduler);
                executeTask(process);
            }
            printf("All processes executed.\n");
            break;

        case 3:
            // Quit the program
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
