#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack *stack) {
    stack->top = -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Ngan xep day\n");
        return;
    }
    stack->data[++stack->top] = value;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong\n");
        return -1;
    }
    return stack->data[stack->top--];
}

void displayStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong\n");
        return;
    }
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    initializeStack(&stack);

    int n, value;

    printf("Nhap so luong phan tu can them (khong qua %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("Vuot qua kich thuoc toi da\n");
        return 1;
    }

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(&stack, value);
    }

    printf("Ngan xep sau khi them: ");
    displayStack(&stack);

    printf("Thuc hien pop\n");
    int poppedValue = pop(&stack);

    if (poppedValue != -1) {
        printf("Phan tu bi xoa: %d\n", poppedValue);
    }

    printf("Ngan xep sau khi pop: ");
    displayStack(&stack);

    return 0;
}
