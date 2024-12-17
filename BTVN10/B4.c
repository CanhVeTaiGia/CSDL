#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

void enqueue(Queue* queue, int value) {
    Node* newNode = createNode(value);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

void dequeue(Queue* queue) {
    if (isEmpty(queue)) return;
    Node* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
}

int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong\n");
        exit(1);
    }
    return queue->front->data;
}

void freeQueue(Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

int main() {
    Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("Phan tu dau hang doi: %d\n", peek(queue));

    dequeue(queue);
    printf("Phan tu dau sau khi dequeue: %d\n", peek(queue));

    printf("Kiem tra hang doi rong: %s\n", isEmpty(queue) ? "Co" : "Khong");

    dequeue(queue);
    dequeue(queue);

    printf("Kiem tra hang doi rong sau khi xoa het: %s\n", isEmpty(queue) ? "Co" : "Khong");

    freeQueue(queue);
    return 0;
}
