#include <stdio.h>
#include <stdlib.h>

void findPair(int arr[], int n, int k);

int main()
{
    int n, k;
    int *pArr = NULL;
    pArr = (int *)malloc(n * sizeof(int));
    do
    {
        printf("Nhap do dai cua mang: ");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);
    printf("Nhap tong de so sanh");
    scanf("%d", &k);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    return 0;
}

void findPair(int arr[], int n, int k)
{
    int found = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (arr[i] + arr[j] == k)
            {
                found += 1;
            }
        }
    }
    if(found < 1){
        return;
    }else{
        
    }
}