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

void peek(Queue* queue){
    if(isEmpty(queue)){
        printf("Hang doi trong, khong the lay phan tu dau\n");
        return;
    }
    printf("Phan tu dau tien la: %d\n", queue->arr[queue->front]);
}


int main()
{
    Queue queue;
    init(&queue);
    int n;
    printf("Phan tu duoc them vao: ");
    scanf("%d", &n);
    enqueue(&queue, n);
    peek(&queue);
    return 0;
}