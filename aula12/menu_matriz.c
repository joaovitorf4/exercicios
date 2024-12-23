#include <stdio.h>

#define MAX 100

void leMatriz(double mat[][MAX], int n);
void imprimeMatriz(double mat[][MAX], int n);
void soma(double mat1[][MAX], double mat2[][MAX], double resp[][MAX], int n);
void subtrai(double mat1[][MAX], double mat2[][MAX], double resp[][MAX], int n);
void multiplica(double mat1[][MAX], double mat2[][MAX], double resp[][MAX], int n);
void transpor(double mat[][MAX], double resp[][MAX], int n);

int main() {
    double mat1[MAX][MAX], mat2[MAX][MAX], mat3[MAX][MAX];
    int n, opcao = 0;

    printf("Qual a dimensao das matrizes: ");
    scanf("%d", &n);

    leMatriz(mat1, n);
    leMatriz(mat2, n);

    while(opcao != 5) {
        printf("\nEscolha a operacao:\n");
        printf("1 - Somar Matrizes\n");
        printf("2 - Subtrair Matrizes\n");
        printf("3 - Multiplicar Matrizes\n");
        printf("4 - Transpor Matriz 1\n");
        printf("5 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                soma(mat1, mat2, mat3, n);
                printf("\nResultado da Soma:\n");
                imprimeMatriz(mat3, n);
                break;
            case 2:
                subtrai(mat1, mat2, mat3, n);
                printf("\nResultado da Subtracao:\n");
                imprimeMatriz(mat3, n);
                break;
            case 3:
                multiplica(mat1, mat2, mat3, n);
                printf("\nResultado da Multiplicacao:\n");
                imprimeMatriz(mat3, n);
                break;
            case 4:
                transpor(mat1, mat3, n);
                printf("\nMatriz Transposta de mat1:\n");
                imprimeMatriz(mat3, n);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }

    return 0;
}

void leMatriz(double mat[][MAX], int n) {
    printf("Digite os valores da matriz: ");
    printf("\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%lf", &mat[i][j]);
}

void imprimeMatriz(double mat[][MAX], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            printf("%.2lf ", mat[i][j]);
        printf("\n");
    }
}

void soma(double mat1[][MAX], double mat2[][MAX], double resp[][MAX], int n) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            resp[i][j] = mat1[i][j] + mat2[i][j];
}

void subtrai(double mat1[][MAX], double mat2[][MAX], double resp[][MAX], int n) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            resp[i][j] = mat1[i][j] - mat2[i][j];
}

void multiplica(double mat1[][MAX], double mat2[][MAX], double resp[][MAX], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            resp[i][j] = 0;
            for(int k = 0; k < n; k++)
                resp[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
}

void transpor(double mat[][MAX], double resp[][MAX], int n) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            resp[j][i] = mat[i][j];
}
