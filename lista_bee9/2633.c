#include <stdio.h>

struct Carne {
    char nome[21];
    int validade;
};

void ordena(struct Carne *carne, int tam) {
    short i = 1, j;
    struct Carne pivo;

    while ( i < tam ) {
        j = i - 1;
        pivo = carne[i];

        while ( j >= 0 && carne[j].validade > pivo.validade ) {
            carne[j + 1] = carne[j];
            j--;
        }
        carne[j + 1] = pivo;
        i++;
    }
}

int main() {
    int n;

    while ( scanf("%d", &n) != EOF ) {
        if ( n == 0 ) {
            printf("\n");
            continue;
        }

        struct Carne carne[n];

        for ( int i = 0; i < n; i++ ) {
            scanf("%s %d", carne[i].nome, &carne[i].validade);
        }

        ordena(carne, n);

        for ( int i = 0; i < n; i++ ) {
            if ( i > 0 ) {
                printf(" ");
            }
            printf("%s", carne[i].nome);
        }
        printf("\n");
    }

    return 0;
}
