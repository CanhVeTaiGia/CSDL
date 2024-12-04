#include <stdio.h>
#include <string.h>

int symmetrical(char str[], int s, int e){
    if(s != e){
        return 1;
    }
    if(s >= e){
        return 0;
    }
    symmetrical(str, s + 1, e - 1);
}

int main(){
    char str[100];
    int length = strlen(str);
    printf("Moi nhap chuoi: ");
    fgets(str, sizeof(str), stdin);
    int s, e;
    if(symmetrical(str, 0, length - 1) == 0){
        printf("Mang doi xung");
    }else{
        printf("Mang khong doi xung");
    }
}