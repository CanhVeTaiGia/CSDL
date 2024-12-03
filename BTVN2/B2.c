#include <stdio.h>

int main(){
    int n;
    int found = 0;
    int x;
    do{
        printf("Moi nhap n: ");
        scanf("%d", &n);
    }while(n <= 0 || n > 100);
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);
    int arr[n];
    for(int i = 0; i < n; i++){
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n; i++){
        if(x == arr[i]){
            found++;
        }
    }
    printf("So lan xuat hien %d trong mang la: %d", x, found);
    return 0;
}