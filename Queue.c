#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int arr[SIZE];
int front = -1, rear = -1, count = 0;

void enqueue();
void dequeue();
void display();
void CopyofQueue();

void enqueue()
{
    int data;
    printf("Enter Value: ");
    scanf("%d", &data);

    if (count == SIZE){
        printf("Queue is full!\n");
        return;
    }

    if (count == 0){
        front = rear = 0;
    }
    else{
        rear = (rear + 1) % SIZE;
    }
    arr[rear] = data;
    count++;
}

void dequeue()
{
    if (count == 0){
        printf("Queue is empty!\n");
        return;
    }

    printf("Dequeued %d\n", arr[front]);

    if (count == 1){
        front = rear = -1;
    }
    else{
        front = (front + 1) % SIZE;
    }
    count--;
}

void display()
{
    if (count == 0){
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    int i = front;

    for (int c = 0; c < count; c++){
        printf("%d ", arr[i]);
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

void CopyofQueue()
{
    if (count == 0){
        printf("Queue is empty!\n");
        return;
    }
    int NewArr[SIZE];
    int i = front;

    for (int j = 0; j < count; j++){
        NewArr[j] = arr[i];
        i = (i + 1) % SIZE;
    }

    printf("Copy Queue: ");
    for (int j = 0; j < count; j++){
        printf("%d ", NewArr[j]);
    }
    printf("\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n**** MENU ****\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Copy Queue\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

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
            CopyofQueue();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
}