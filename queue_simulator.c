#include <stdio.h>
#include <string.h>

#define MAX 5

char queue[MAX][50];
int front = 0, rear = -1;

void enqueue()
{
    char name[50];

    if (rear == MAX - 1)
    {
        printf("Queue is Full!\n");
    }
    else
    {
        printf("Enter person's name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        rear++;
        strcpy(queue[rear], name);

        printf("%s added to the queue successfully!\n", name);
    }
}

void dequeue()
{
    if (front > rear)
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        printf("%s has been served.\n", queue[front]);
        front++;

        if (front > rear)
        {
            front = 0;
            rear = -1;
        }
    }
}

void display()
{
    int i;

    if (front > rear)
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        printf("\nPeople waiting in the queue:\n");

        for (i = front; i <= rear; i++)
        {
            printf("%d. %s\n", i - front + 1, queue[i]);
        }
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n===== TICKET COUNTER QUEUE SIMULATOR =====\n");
        printf("1. Add Person to Queue\n");
        printf("2. Serve Person\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting Queue Simulator...\n");
                return 0;

            default:
                printf("Invalid Choice! Try Again.\n");
        }
    }

    return 0;
}
