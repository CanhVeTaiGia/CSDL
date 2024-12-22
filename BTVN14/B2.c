#include <stdio.h>

void selectionSort(int arr[], int n, int ascending) {
    int i, j, minMaxIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minMaxIndex = i; 

        for (j = i + 1; j < n; j++) {
            if ((ascending && arr[j] < arr[minMaxIndex]) || (!ascending && arr[j] > arr[minMaxIndex])) {
                minMaxIndex = j;
            }
        }
        if (minMaxIndex != i) {
            temp = arr[i];
            arr[i] = arr[minMaxIndex];
            arr[minMaxIndex] = temp;
            printf("Hoan doi %d va %d:\n", arr[minMaxIndex], arr[i]);
            for (int k = 0; k < n; k++) {
                printf("%d ", arr[k]);
            }
            printf("\n");
        }
    }
}

int main() {
    int n, i, choice;

    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Chon cach sap xep:\n");
    printf("1. Tang dan\n");
    printf("2. Giam dan\n");
    printf("Nhap lua chon cua ban (1 hoac 2): ");
    scanf("%d", &choice);

    int ascending = (choice == 1) ? 1 : 0;

    printf("Mang ban dau:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    selectionSort(arr, n, ascending);

    printf("Mang sau khi sap xep:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
