#include <stdio.h>

int sumNumberFromNtoM(int n, int m);

int main(){
    int m, n;
    int sum = 0;
    do{
        printf("Moi nhap n va m (n phai nho hon m): ");
        scanf("%d %d", &n, &m);
    } while(m <= n);
    printf("Tong cac so tu %d den %d la: %d\n", n, m, sumNumberFromNtoM(n, m));

    return 0;
}

int sumNumberFromNtoM(int n, int m){
    if(n > m){
        return 0;
    }
    return n + sumNumberFromNtoM(n + 1, m);
}
