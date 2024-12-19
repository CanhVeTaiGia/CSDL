#include <stdio.h>  

int main() {  
    int n;  
    scanf("%d", &n);  
    int arr[n];  
    for(int i = 0; i < n; i++) {  
        scanf("%d", &arr[i]);  
    }  
    int flag = 1;  
    for(int i = 0; i < n / 2; i++) {  
        if(arr[i] != arr[n - i - 1]) {  
            flag = 0;  
            break;     
        }  
    }  
    if(flag == 1) {  
        printf("mang doi xung\n");  
    } else {  
        printf("mang khong doi xung\n");  
    }  
    return 0;  
}
