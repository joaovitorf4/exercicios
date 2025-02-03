#include <stdio.h>
#include <stdlib.h>

struct Aluno {
    int matricula;
    float frequencia;
    float nota;
};

int main() {
    int n;

    printf("Digite o numero de alunos: ");
    scanf("%d", &n);

    struct Aluno *alunos = malloc(n * sizeof(struct Aluno));
    if ( alunos == NULL ) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    for ( int i = 0; i < n; i++ ) {
        printf("\nAluno %d:\n", i + 1);
        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Frequência (0-100%%): ");
        scanf("%f", &alunos[i].frequencia);
        printf("Nota final: ");
        scanf("%f", &alunos[i].nota);
    }

    FILE *arquivo = fopen("arq6.bin", "wb");

    if ( arquivo == NULL ) {
        printf("Erro ao abrir o arquivo!\n");
        free(alunos);
        return 1;
    }

    fwrite(alunos, sizeof(struct Aluno), n, arquivo);
    printf("\nDados dos alunos foram salvos em 'alunos.bin'.\n");

    fclose(arquivo);
    free(alunos);

    return 0;
}
