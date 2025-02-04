#include <stdio.h>

int main(){
    int n;

    scanf("%d", &n);

    while ( n != 0 ){
        char str1[201];

        gets(str1);

        printf("%s\n", str1);
        n--;
    }

    return 0;
}