#include <stdio.h>

void selectionSort(int arr[], int n)
{
    int i, j, minIndex, temp;
    int swapCount = 0;

    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swapCount++;

            printf("Mang sau khi hoan doi: ");
            for (int k = 0; k < n; k++)
            {
                printf("%d ", arr[k]);
            }
            printf("\n");
        }
    }

    printf("So lan hoan doi: %d\n", swapCount);
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

     for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("Mang ban dau: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    selectionSort(arr, n);

    printf("Mang sau khi sap xep: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
