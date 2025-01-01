#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} ArrayQueue;

void initArrayQueue(ArrayQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

bool isArrayQueueEmpty(ArrayQueue *queue) {
    return queue->front == -1;
}

bool isArrayQueueFull(ArrayQueue *queue) {
    return queue->rear == MAX_SIZE - 1;
}

void enqueueArray(ArrayQueue *queue, int value) {
    if (isArrayQueueFull(queue)) {
        printf("Hang doi day.\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->data[++queue->rear] = value;
    printf("Them %d vao hang doi.\n", value);
}

int dequeueArray(ArrayQueue *queue) {
    if (isArrayQueueEmpty(queue)) {
        printf("Hang doi trong.\n");
        return -1;
    }
    int value = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    printf("Lay %d ra khoi hang doi.\n", value);
    return value;
}

int peekArrayQueue(ArrayQueue *queue) {
    if (isArrayQueueEmpty(queue)) {
        printf("Hang doi trong\n");
        return -1;
    }
    return queue->data[queue->front];
}

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} LinkedListQueue;

void initLinkedListQueue(LinkedListQueue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

bool isLinkedListQueueEmpty(LinkedListQueue *queue) {
    return queue->front == NULL;
}

void enqueueLinkedList(LinkedListQueue *queue, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Them %d vao hang doi.\n", value);
}

int dequeueLinkedList(LinkedListQueue *queue) {
    if (isLinkedListQueueEmpty(queue)) {
        printf("Hang doi trong.\n");
        return -1;
    }
    Node *temp = queue->front;
    int value = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    printf("Lay %d ra khoi hang doi.\n", value);
    return value;
}

int peekLinkedListQueue(LinkedListQueue *queue) {
    if (isLinkedListQueueEmpty(queue)) {
        printf("Hang doi trong.\n");
        return -1;
    }
    return queue->front->data;
}

int main() {
    printf("\n--- Hang doi mang ---\n");
    ArrayQueue arrayQueue;
    initArrayQueue(&arrayQueue);

    enqueueArray(&arrayQueue, 10);
    enqueueArray(&arrayQueue, 20);
    enqueueArray(&arrayQueue, 30);
    printf("Phan tu dau tien: %d\n", peekArrayQueue(&arrayQueue));
    dequeueArray(&arrayQueue);
    dequeueArray(&arrayQueue);
    dequeueArray(&arrayQueue);
    printf("\n--- Hang doi danh sach lien ket ---\n");
    LinkedListQueue linkedListQueue;
    initLinkedListQueue(&linkedListQueue);

    enqueueLinkedList(&linkedListQueue, 100);
    enqueueLinkedList(&linkedListQueue, 200);
    enqueueLinkedList(&linkedListQueue, 300);
    printf("Phan tu dau tien: %d\n", peekLinkedListQueue(&linkedListQueue));
    dequeueLinkedList(&linkedListQueue);
    dequeueLinkedList(&linkedListQueue);
    dequeueLinkedList(&linkedListQueue);

    return 0;
}
