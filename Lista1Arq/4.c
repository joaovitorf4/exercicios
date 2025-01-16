#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno{
        float nota;
        char nome[15];
};

int main(){

    FILE *file;

    char filename[20], aux;

    //printf("Digite o nome do arquivo de texto que voce deseja ler (coloque o .txt no final): ");

    //scanf("%s", filename);

    file = fopen("arq4.txt", "r");

    if ( file == NULL ) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    
    char auxStr[20];
    int i = 0;

    struct Aluno aluno1;

    float maiorNota = -1.0;
    char maiorNome[15] = "";

    while ( fscanf(file, " NOME: %s NOTA: %f", aluno1.nome, &aluno1.nota) == 2 ){
           if ( aluno1.nota > maiorNota ){
                strcpy(maiorNome, aluno1.nome);
                maiorNota = aluno1.nota;
           }
    }

    fclose(file);

    printf("Nome do Aluno com a maior nota: %s\n", maiorNome);
    printf("Maior nota: %.2f\n", maiorNota);

    return 0;
}