#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct
{
    int arr[MAX];
    int front;
    int rear;
} Queue;

Queue *init(Queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

bool isEmpty(Queue *queue)
{
    return queue->front == -1;
}

bool isFull(Queue *queue)
{
    return queue->rear >= MAX - 1;
}

void enqueue(Queue *queue, int value)
{
    if (isFull(queue))
    {
        printf("Hang doi da day, khong the them.\n");
        return;
    }
    if (isEmpty(queue))
    {
        queue->front = 0;
    }
    queue->rear++;
    queue->arr[queue->rear] = value;
}

void dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Hang doi trong, khong the xoa");
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++)
    {
        queue->arr[i] = queue->arr[i + 1];
    }
    queue->rear--;
}

void displayQueue(Queue *queue)
{
    printf("Queue: [");
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d", queue->arr[i]);
        if (i < queue->rear)
        {
            printf("][");
        }
    }
    printf("]\n");
}

int main()
{
    Queue queue;
    init(&queue);
    int n;
    do
    {
        printf("Nhap n (0 < n <= 100): ");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
        enqueue(&queue, arr[i]);
    }
    printf("Hang doi truoc khi xoa phan tu: \n");
    displayQueue(&queue);
    dequeue(&queue);
    printf("Hang doi sau khi xoa phan tu: \n");
    displayQueue(&queue);
    return 0;
}