#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main() {
    int n, target;

    printf("Nhap so phan tu: ");
    scanf("%d", &n);

    int arr[n];
    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Nhap so can tim: ");
    scanf("%d", &target);
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            printf("%d tim thay tai vi tri %d\n", target, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("%d khong tim thay trong mang.\n", target);
    }
    return 0;
}
