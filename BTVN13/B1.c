#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if(swapped == 0){
            break;
        }
    }
}

void printArr(int arr[], int n)
{
    printf("[");
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
    int n;
    do
    {
        printf("n: ");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);
    int arr[n];
    for(int i = 0; i < n; i++){
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("Mang chua duoc sap xep: ");
    printArr(arr, n);
    bubbleSort(arr, n);
    printf("Mang da sap xep: ");
    printArr(arr, n);
    return 0;
}