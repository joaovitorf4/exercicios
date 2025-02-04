#include <stdio.h>

int main(){

    char c, d;
    int cont = 0;

    printf("Digite o caracter que deseja contar no arquivo: ");
    scanf("%c", &c);

    FILE *arquivo = fopen("arq1lab.txt", "r");


    if ( arquivo == NULL ) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    while ( fscanf(arquivo, "%c", &d) != EOF ){ {
        if ( d == c ){
            cont++;
        }
    }

    printf("O caracter %c aparece %d vezes no arquivo.\n", c, cont);

    fclose(arquivo);

    return 0;
}