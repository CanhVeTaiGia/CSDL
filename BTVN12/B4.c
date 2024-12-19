#include <stdio.h>
#include <string.h>


struct SinhVien {
    char ten[50];
    int diem;
};

int main() {
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    struct SinhVien sv[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap ten sinh vien thu %d: ", i + 1);
        scanf("%s", sv[i].ten);
        printf("Nhap diem cua %s: ", sv[i].ten);
        scanf("%d", &sv[i].diem);
    }
    char tenCanTim[50];
    printf("Nhap ten sinh vien can tim: ");
    scanf("%s", tenCanTim);
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(sv[i].ten, tenCanTim) == 0) {
            printf("Diem cua %s la: %d\n", sv[i].ten, sv[i].diem);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien.\n");
    }
    return 0;
}
