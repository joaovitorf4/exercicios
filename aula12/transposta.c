#include <stdio.h>

int main(){
    int n, m;
    
    printf("Digite a os tamanhos n x m da sua matriz: ");
    scanf("%d %d", &n, &m);
    
    int mat[n][m], mat_t[m][n];
    
    for ( int i = 0; i < n; i++ ){
        for ( int j = 0; j < m; j++ ){
            scanf("%d", &mat[i][j]);
        }
    }
    
    for ( int i = 0; i < n; i++ ){
        for ( int j = 0; j < m; j++ ){
            mat_t[j][i] = mat[i][j];
        }
    }
    
    printf("A sua transposta eh: ");
    
    for ( int i = 0; i < m; i++ ){
        printf("\n");
        for ( int j = 0; j < n; j++ ){
            printf("%d ", mat_t[i][j]);
        }
    }

    return 0;
}