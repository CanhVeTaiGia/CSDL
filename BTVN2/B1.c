#include <stdio.h>

int main()
{
    int n;
    int max;
    do
    {
        printf("Nhap do dai mang: ");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    printf("Phan tu co gia tri lon nhat: %d\n", max);
    return 0;
}