#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct
{
    int arr[MAX];
    int top;
} Stack;

void init(Stack *stack)
{
    stack->top = -1;
}

bool isFull(Stack *stack)
{
    return stack->top == MAX - 1;
}

bool isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Day, khong the them\n");
        return;
    }
    stack->arr[++(stack->top)] = value;
}

void print(Stack *stack)
{
    printf("Stack: [");
    for (int i = (stack->top) ; i >= 0; i--)
    {
        printf("%d", stack->arr[i]);
        if (i > 0)
        {
            printf(", ");
        }
    }
    printf("]\n");
}

int main()
{
    Stack stack;
    init(&stack);
    int n;
    do
    {
        printf("Nhap n (0 < n <= 100): ");
        scanf("%d", &n);
    } while (n <= 0 || n > MAX);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        push(&stack, arr[i]);
    }
    print(&stack);
    return 0;
}