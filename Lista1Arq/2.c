#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *file;

    char filename[20], aux;
    int cont = 0;

    printf("Digite o nome do arquivo de texto que voce deseja ler (coloque o .txt no final): ");

    scanf("%s", filename);

    file = fopen(filename, "r");

    while ( fscanf(file, "%c", &aux) != EOF ){
        if ( aux == '\n' )
            cont++;
    }

    if ( aux != '\n' && cont > 0 ) {
        cont++;
    }

    printf("O arquivo tem %d linha(s).", cont);
    
    return 0;
}