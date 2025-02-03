#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 40

int main() {
    int n;

    printf("Digite o numero de alunos: ");
    scanf("%d", &n);
    getchar();

    char (*nomes)[MAX_NOME + 1] = malloc(n * (MAX_NOME + 1) * sizeof(char));
    float *notas = malloc(n * sizeof(float));

    if ( nomes == NULL || notas == NULL ) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    for ( int i = 0; i < n; i++ ) {
        printf("Nome do aluno %d: ", i + 1);
        fgets(nomes[i], MAX_NOME + 1, stdin);
        nomes[i][strcspn(nomes[i], "\n")] = '\0';

        printf("Nota do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
        getchar();
    }

    FILE *arquivo = fopen("arq5.txt", "w");
    if ( arquivo == NULL ) {
        printf("Erro ao abrir o arquivo!\n");
        free(nomes);
        free(notas);
        return 1;
    }

    for ( int i = 0; i < n; i++ ) {
        char nome_formatado[MAX_NOME + 1];
        snprintf(nome_formatado, MAX_NOME + 1, "%-40s", nomes[i]);
        fprintf(arquivo, "%s %.2f\n", nome_formatado, notas[i]);
    }

    printf("Dados salvos em 'arq5.txt'.\n");

    free(nomes);
    free(notas);
    fclose(arquivo);

    return 0;
}
