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
        return '\0';
    }
    return stack->data[stack->top--];
}

char peek(Stack *stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->data[stack->top];
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isValidExpression(const char *expression) {
    Stack stack;
    initializeStack(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        char current = expression[i];

        if (current == '(' || current == '{' || current == '[') {
            push(&stack, current);
        } else if (current == ')' || current == '}' || current == ']') {
            if (isEmpty(&stack)) {
                return 0;
            }
            char top = pop(&stack);
            if (!isMatchingPair(top, current)) {
                return 0;
            }
        }
    }

    return isEmpty(&stack);
}

int main() {
    char expression[MAX_SIZE];
    printf("Nhap bieu thuc: ");
    fgets(expression, MAX_SIZE, stdin);

    if (expression[strlen(expression) - 1] == '\n') {
        expression[strlen(expression) - 1] = '\0';
    }

    if (isValidExpression(expression)) {
        printf("Hop le\n");
    } else {
        printf("Khong hop le\n");
    }

    return 0;
}
