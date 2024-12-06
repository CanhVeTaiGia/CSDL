#include <stdio.h>

int tinhBuocDi(int m, int n)
{
    if (m == 1 || n == 1)
    {
        return 1;
    }
    return tinhBuocDi(m, n - 1) + tinhBuocDi(m - 1, n);
}

int main()
{
    int n, m;
    printf("Nhap m va n: ");
    scanf("%d %d", &m, &n);
    int result = tinhBuocDi(m, n);
    printf("%d", result);
    return 0;
}