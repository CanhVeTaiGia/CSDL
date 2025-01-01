#include <stdio.h>

#define MAX 10

void add(int arr[], int *n, int data, int pos)
{
    if (pos > *n || pos < 0)
    {
        printf("Vi tri khong kha dung.\n");
        return;
    }

    if (*n >= MAX)
    {
        printf("Mang da day, khong the them phan tu moi.\n");
        return;
    }

    for (int i = *n; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos] = data;
    (*n)++;
}

void edit(int arr[], int data, int n, int pos)
{
    if (pos > n - 1 || pos < 0)
    {
        printf("Vi tri khong kha dung.\n");
        return;
    }
    arr[pos] = data;
}

void search(int arr[], int val, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == val)
        {
            printf("Tim thay %d tai vi tri %d\n", val, i);
            return;
        }
    }
    printf("Khong tim thay gia tri %d\n", val);
}

void delete(int arr[], int *n, int pos)
{
    if (*n <= 0)
    {
        printf("Khong the xoa phan tu.\n");
        return;
    }
    if (pos >= *n || pos < 0)
    {
        printf("Vi tri khong kha dung.\n");
        return;
    }
    for (int i = pos; i < *n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void display(int arr[], int n)
{
    printf("arr = [");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i < n - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}

int main()
{
    int n, value, pos;
    do
    {
        printf("Nhap n (0 < n <= MAX): ");
        scanf("%d", &n);
    } while (n <= 0 || n > MAX);
    int arr[MAX];

    do
    {
        printf("-----Menu----\n");
        printf("0.Thoat.\n");
        printf("1. Them 1 phan tu.\n");
        printf("2. In ra mang.\n");
        printf("3. Sua 1 phan tu.\n");
        printf("4. Xoa 1 phan tu.\n");
        printf("5. Tim kiem gia tri.\n");
        int choice;
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            printf("Tam biet.\n");
            return 0;
            break;
        case 1:
            printf("Gia tri can them vao: ");
            scanf("%d", &value);
            printf("Vi tri them vao: ");
            scanf("%d", &pos);
            add(arr, &n, value, pos);
            break;
        case 2:
            display(arr, n);
            break;
        case 3:
            printf("Gia tri: ");
            scanf("%d", &value);
            printf("Vi tri can sua: ");
            scanf("%d", &pos);
            edit(arr, value, n, pos);
            break;
        case 4:
            printf("Vi tri can xoa: ");
            scanf("%d", &pos);
            delete(arr, &n, pos);
            break;
        default:
            printf("Chon lai.\n");
            break;
        }
    } while (1);
    return 0;
}
