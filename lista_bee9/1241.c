#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n = 0;
    scanf("%d", &n);

    while (n != 0) {
        char A[1001];
        char B[1001];

        scanf("%1000s %1000s", A, B);

        char *ptrA = A;
        char *ptrB = B;

        while ( *ptrA != '\0' ) {
            ptrA++;
        }

        while ( *ptrB != '\0' ) {
            ptrB++;
        }

        ptrA--;
        ptrB--;

        int tamB = strlen(B);
        int tamA = strlen(A);

        if ( tamB > tamA ) {
            printf("nao encaixa\n");
            n--;
            continue;
        }

        int encaixa = 1;
        while ( tamB != 0 ) {
            if ( *ptrA == *ptrB ) {
                ptrA--;
                ptrB--;
            } else {
                encaixa = 0;
                break;
            }
            tamB--;
        }

        if ( encaixa ) {
            printf("encaixa\n");
        } else {
            printf("nao encaixa\n");
        }

        n--;
    }

    return 0;
}
