#include <stdio.h>
#include <string.h>
#include <ctype.h>

int calcularDigito(int cpf[], int tamanho, int pesoInicial) {
    int acumulador = 0;
    int j = pesoInicial;
    
    for (int i = 0; i < tamanho; i++) {
        acumulador += cpf[i] * j;
        j--;
    }

    int digito = 11 - (acumulador % 11);
    if (digito > 9) {
        digito = 0;
    }

    return digito;
}

int main() {
    char cpf[15] = "000.000.000-00";
    int cpfArray[9];
    
    gets(cpf);
    
    int j = 0;
    for (int i = 0; i < strlen(cpf); i++) {
        if (isdigit(cpf[i])) {
            cpfArray[j] = cpf[i] - '0';
            j++;
        }
    }
    
    int digito1 = calcularDigito(cpfArray, 9, 10);
    cpfArray[9] = digito1;
    
    int digito2 = calcularDigito(cpfArray, 10, 11);
    cpfArray[10] = digito2;

    char cpfNovo[15];
    snprintf(cpfNovo, sizeof(cpfNovo), "%03d.%03d.%03d-%02d", 
             cpfArray[0] * 100 + cpfArray[1] * 10 + cpfArray[2],
             cpfArray[3] * 100 + cpfArray[4] * 10 + cpfArray[5],
             cpfArray[6] * 100 + cpfArray[7] * 10 + cpfArray[8],
             cpfArray[9] * 10 + cpfArray[10]);
    
    if (strcmp(cpfNovo, cpf) == 0) {
        printf("CPF valido\n");
    } else {
        printf("CPF invalido\n");
    }

    return 0;
}