#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    int swapped;
    int loopCount = 0;

    for (i = 0; i < n - 1; i++)
    {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;

                printf("Mang sau khi hoan doi: ");
                for (int k = 0; k < n; k++)
                {
                    printf("%d ", arr[k]);
                }
                printf("\n");
            }
        }
        loopCount++;
        if (!swapped)
            break;

        printf("Mang sau vong lap thu %d: ", loopCount);
        for (int k = 0; k < n; k++)
        {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }

    printf("So lan lap: %d\n", loopCount);
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

    bubbleSort(arr, n);

    printf("Mang sau khi sap xep: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
