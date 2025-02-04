#include <stdio.h>
#include <stdlib.h>

struct Aluno {
    int matricula;
    float frequencia;
    float nota;
};

int main() {
    FILE *arquivo = fopen("arq6.bin", "rb");
    if ( arquivo == NULL ) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    fseek(arquivo, 0, SEEK_END);
    int tamanho = ftell(arquivo);
    int n = tamanho / sizeof(struct Aluno);
    rewind(arquivo);

    struct Aluno *alunos = malloc(n * sizeof(struct Aluno));
    
    if ( alunos == NULL ) {
        printf("Erro na alocação de memória!\n");
        fclose(arquivo);
        return 1;
    }

    fread(alunos, sizeof(struct Aluno), n, arquivo);
    fclose(arquivo);

    printf("\nLista de Alunos:\n");
    for (int i = 0; i < n; i++) {
        printf("Matricula: %d\n", alunos[i].matricula);
        printf("Frequencia: %.2f%%\n", alunos[i].frequencia);
        printf("Nota final: %.2f\n", alunos[i].nota);
        printf("----------------------\n");
    }

    free(alunos);

    return 0;
}
