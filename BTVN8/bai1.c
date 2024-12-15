#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct Queue{
	int array[MAX];
	int front;
	int rear;
}Queue;

void initalQueue(Queue* queue){
	queue->front = -1;
	queue->rear = -1;
}

int isEmpty(Queue* queue){
	if(queue->front == -1){
		return 1;
	}
	return 0;
}
int isFull(Queue* queue){
	if(queue->rear >= MAX - 1){
		return 1;
	}
	return 0;
}
void enqueue(Queue* queue,int value){
	if(isFull(queue) == 1){
		printf("Hang doi da day");
		return;
	}
	if(isEmpty(queue) == 1){
		queue->front = 0;
	}
	queue->rear++;
	queue->array[queue->rear] = value;
}

void displayQueue(Queue* queue){
	for(int i = queue->front; i <= queue->rear;i++){
		printf("%d \t",queue->array[i]);
	}
}
int main(){
	Queue queue;
	initalQueue(&queue);
	int value;
	do{
		printf("\n==================MENU================\n");
		printf("0. Thoat\n");
		printf("1. Them phan tu vao cuoi\n");
		printf("2. Hien thi hang doi\n");
		printf("Vui long chon: ");
		int choice;
		scanf("%d",&choice);
		switch(choice){
			case 0: 
				exit(0);
			case 1:
				printf("Nhap gia tri them: ");
				scanf("%d",&value);
				enqueue(&queue,value);
				break;
			case 2:
				displayQueue(&queue);
				break;
			default:
				printf("Vui long chon lai");
		}	
	}while(1 == 1);
	return 0;
}

