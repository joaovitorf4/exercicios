#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *file1;
    FILE *file2;

    char filename[20], aux;
    char vogais[11] = "aeiouAEIOU";

    printf("Digite o nome do arquivo de texto que voce deseja ler (coloque o .txt no final): ");

    scanf("%s", filename);

    file1 = fopen(filename, "r");

    file2 = fopen("output3.txt", "w");

    if ( file1 == NULL ) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    if ( file2 == NULL ) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    while ( fscanf(file1, "%c", &aux) != EOF ){
        for ( int i = 0; i < strlen(vogais); i++ ){
            if ( vogais[i] == aux ){
                aux = '*';
                break;
            }
        }
        fprintf(file2, "%c", aux);
    }

    return 0;
}