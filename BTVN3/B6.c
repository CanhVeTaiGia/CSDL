#include <stdio.h>

int sumArr(int arr[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    return arr[n - 1] + sumArr(arr, n - 1);
}

int main()
{
    int n;
    do
    {
        printf("Nhap n (0 < n <= 100) la: ");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    int result = sumArr(arr, n);

    printf("Tong cac phan tu cua mang: %d\n", result);
    return 0;
}