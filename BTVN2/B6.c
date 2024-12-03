#include <stdio.h>

int main()
{
    int m, n;
    do
    {
        printf("Moi nhap n va m: ");
        scanf("%d %d", &n, &m);
    } while (n <= 0 || n > 100 || m <= 0 || m > 100);
    int arr1[m], arr2[n], result[m + n];
    for (int i = 0; i < m; i++)
    {
        printf("arr1[%d] = ", i);
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("arr2[%d] = ", i);
        scanf("%d", &arr2[i]);
    }
    printf("Hai mang la:\n arr1[");
    for(int i = 0; i < m - 1; i++){
        printf("%d,", arr1[i]);
    }
    printf("%d]\n", arr1[m - 1]);
    
    printf("arr2[");
    for(int i = 0; i < n - 1; i++){
        printf("%d,", arr2[i]);
    }
    printf("%d]\n", arr2[n - 1]);
    printf("Mang sau khi gop la: \n");
    for(int i = 0; i < m; i++){
        result[i] = arr1[i];
    }
    for(int i = 0; i < n; i++){
        result[i + m] = arr2[i];
    }
    printf("result = [");
    for (int i = 0; i < m + n - 1; i++)
    {
        printf("%d,",result[i]);
    }
    printf("%d]\n", result[m + n - 1]);
    
    return 0;
}