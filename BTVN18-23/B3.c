#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

int isEmpty()
{
    return top == -1;
}

int isFull()
{
    return top == MAX - 1;
}

int pop()
{
    if (isEmpty())
    {
        printf("Ngan xep rong, khong the lay phan tu.\n");
        return -1;
    }
    else
    {
        int value = stack[top--];
        printf("Da lay %d ra khoi ngan xep.\n", value);
        return value;
    }
}

void push(int value)
{
    if (isFull())
    {
        printf("Ngan xep day, khong the them phan tu.\n");
        return;
    }
    stack[++top] = value;
    printf("Da them %d vao ngan xep.\n", value);
}

int peek()
{
    if (isEmpty())
    {
        printf("Ngan xep rong.\n");
        return -1;
    }
    return stack[top];
}

void checkStatus()
{
    if (isEmpty())
    {
        printf("Ngan xep trong.\n");
    }
    else if (isFull())
    {
        printf("Ngan xep day.\n");
    }
    else
    {
        printf("Ngan xep khong trong va khong day.\n");
    }
}

int main()
{
    int choice, value;
    do
    {
        printf("\n----- Menu -----\n");
        printf("0. Thoat.\n");
        printf("1. Them phan tu vao ngan xep.\n");
        printf("2. Lay va xoa phan tu ra khoi ngan xep.\n");
        printf("3. Kiem tra phan tu tren dinh ngan xep.\n");
        printf("4. Kiem tra trang thai ngan xep nhu trong hoac day.\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Moi nhap gia tri: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            value = peek();
            if (value != -1)
            {
                printf("Phan tu tren dinh ngan xep la: %d\n", value);
            }
            break;
        case 4:
            checkStatus();
            break;
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Moi nhap lai.\n");
        }
    } while (choice != 0);

    return 0;
}
