#include <stdio.h>

int main() {
    int n;
    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d", &n);
    int arr[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int foundDuplicate = 0;
    for (int i = 0; i < n; i++) {
        int count = 0;
        int isDuplicateChecked = 0;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDuplicateChecked = 1;
                break;
            }
        }
        if (!isDuplicateChecked) {
            for (int j = 0; j < n; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                }
            }
            if (count > 1) {
                printf("Phan tu %d xuat hien %d lan.\n", arr[i], count);
                foundDuplicate = 1;
            }
        }
    }
    if (!foundDuplicate) {
        printf("Khong co phan tu lap lai.\n");
    }
    return 0;
}
