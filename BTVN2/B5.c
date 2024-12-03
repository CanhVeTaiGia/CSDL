#include <stdio.h>
#include <stdlib.h>

void deleteAt(int arr[], int *n, int k);

int main()
{
    int n, k;
    do
    {
        printf("Moi nhap n: ");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("Nhap vi tri can xoa: ");
    scanf("%d", &k);
    deleteAt(arr, &n, k);
    for (int i = 0; i < n; i++)
        printf("arr[%d] = %d\n", i, arr[i]);
    return 0;
}

void deleteAt(int arr[], int *n, int k)
{
    if (k < 0 || k > *n)
    {
        printf("Vi tri khong hop le\n");
        return;
    }
    for (int i = k; i < *n; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}
