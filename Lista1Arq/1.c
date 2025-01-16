#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char ch;

    file = fopen("arq.txt", "w");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    printf("Digite caracteres para gravar no arquivo (digite '0' para encerrar):\n");

    while (1) {
        scanf(" %c", &ch);
        if (ch == '0') {
            break;
        }
        fprintf(file, "%c", ch);
    }

    fclose(file);

    file = fopen("arq.txt", "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        return 1;
    }

    printf("\nConteúdo do arquivo:\n");

    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);

    return 0;
}
