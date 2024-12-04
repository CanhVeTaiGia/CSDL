#include <stdio.h>
#include <string.h>

void reverseStr(char str[], int start, int end)
{
    if (start >= end){
        return;
    }
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverseStr(str, start + 1, end - 1);
}

int main()
{
    char str[100];
    printf("Vui long nhap chuoi: ");
    fgets(str, sizeof(str), stdin);
    int length = strlen(str);
    reverseStr(str, 0, length - 1);
    printf("Ham dao nguoc la: %s", str);
    return 0;
}