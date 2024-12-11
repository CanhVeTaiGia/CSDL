#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 10

typedef struct {
    int priority;
    int data;
} Element;

typedef struct {
    Element elements[MAX_SIZE];
    int size;
} PriorityQueue;

void initQueue(PriorityQueue *pq) {
    pq->size = 0;
}

bool isEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}

void printQueue(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Hang doi rong\n");
        return;
    }
    printf("Hang doi hien tai: \n");
    for (int i = 0; i < pq->size; i++) {
        printf("[Priority: %d, Data: %d] ", pq->elements[i].priority, pq->elements[i].data);
    }
    printf("\n");
}

void enqueue(PriorityQueue *pq, int priority, int data) {
    if (pq->size == MAX_SIZE) {
        printf("Hang doi day, khong the them phan tu moi.\n");
        return;
    }
    Element newElement;
    newElement.priority = priority;
    newElement.data = data;
    int i;
    for (i = pq->size - 1; i >= 0 && pq->elements[i].priority < priority; i--) {
        pq->elements[i + 1] = pq->elements[i];
    }
    pq->elements[i + 1] = newElement;
    pq->size++;
    printf("Them phan tu [Priority: %d, Data: %d] vao hang doi.\n", priority, data);
    printQueue(pq);
}

void dequeue(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Hang doi rong, khong the lay phan tu ra.\n");
        return;
    }
    Element removedElement = pq->elements[0];
    for (int i = 1; i < pq->size; i++) {
        pq->elements[i - 1] = pq->elements[i];
    }
    pq->size--;
    printf("Lay phan tu [Priority: %d, Data: %d] ra khoi hang doi.\n", removedElement.priority, removedElement.data);
    printQueue(pq);
}

int main() {
    PriorityQueue pq;
    initQueue(&pq);
    enqueue(&pq, 2, 100);
    enqueue(&pq, 1, 200);
    enqueue(&pq, 3, 300);
    dequeue(&pq);
    enqueue(&pq, 4, 400);
    dequeue(&pq);
    dequeue(&pq);
    dequeue(&pq);
    dequeue(&pq);
    return 0;
}
