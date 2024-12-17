#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, int value) {
    Node* newNode = createNode(value);
    newNode->next = stack->top;
    stack->top = newNode;
}

void pop(Stack* stack) {
    if (isEmpty(stack)) return;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong\n");
        exit(1);
    }
    return stack->top->data;
}

void freeStack(Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}

int main() {
    Stack* stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Phan tu tren cung: %d\n", peek(stack));

    pop(stack);
    printf("Phan tu tren cung sau khi pop: %d\n", peek(stack));

    printf("Kiem tra ngan xep rong: %s\n", isEmpty(stack) ? "Co" : "Khong");

    pop(stack);
    pop(stack);

    printf("Kiem tra ngan xep rong sau khi xoa het: %s\n", isEmpty(stack) ? "Co" : "Khong");

    freeStack(stack);
    return 0;
}
