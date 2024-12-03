#include <stdio.h>

int main()
{
    int n;
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
    printf("Mang da duoc sap xep\n");
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int key = arr[i];
                arr[i] = arr[j];
                arr[j] = key;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}