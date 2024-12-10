#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
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

void push(Stack *stack, char value) {
    if (isFull(stack)) {
        printf("Ngan xep day\n");
        return;
    }
    stack->data[++stack->top] = value;
}

char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong\n");
        return '\0';
    }
    return stack->data[stack->top--];
}

int main() {
    Stack stack;
    initializeStack(&stack);

    char str[MAX_SIZE];
    printf("Nhap chuoi (khong qua %d ky tu): ", MAX_SIZE);
    fgets(str, MAX_SIZE, stdin);

    int length = strlen(str);
    if (str[length - 1] == '\n') {
        str[length - 1] = '\0';
        length--;
    }

    for (int i = 0; i < length; i++) {
        push(&stack, str[i]);
    }

    printf("Chuoi dao nguoc: ");
    while (!isEmpty(&stack)) {
        printf("%c", pop(&stack));
    }
    printf("\n");

    return 0;
}
