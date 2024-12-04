#include <stdio.h>

int fibo(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibo(n - 2) + fibo(n - 1);
}

int main() {
    int n;
    do {
        printf("Nhap n (n >= 2): ");
        scanf("%d", &n);
    } while (n < 2);
    printf("Chuoi fibo cua %d la:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Lan %d: %d\n", i + 1, fibo(i));
    }
    return 0;
}
