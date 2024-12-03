#include <stdio.h>

int main(){
    int n;
    do{
        printf("Moi nhap n: ");
        scanf("%d", &n);
    }while(n <= 0 || n > 100);
    int arr[n];
    for(int i = 0; i < n; i++){
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("Mang sau khi dao nguoc\n");
    for(int i = n - 1; i >= 0; i-- ){
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    return 0;
}