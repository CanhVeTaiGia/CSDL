#include <stdio.h>

void bubbleSort(int arr[], int n, int ascending) {
    int i, j, temp;
    int swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1])) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; 
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}

int main() {
    int n, i, choice;

    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    int arr[n];
    printf("arr[%d]= ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Chon cach sap xep:\n");
    printf("1. Tang dan\n");
    printf("2. Giam dan\n");
    printf("Chon: ");
    scanf("%d", &choice);

    int ascending = (choice == 1) ? 1 : 0;
    bubbleSort(arr, n, ascending);
    printf("Mang sau khi sap xep:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
