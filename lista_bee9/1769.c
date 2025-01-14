#include <stdio.h>
#include <string.h>

int isValidCPF(char cpf[]) {
    int digits[11];

    for (int i = 0, j = 0; i < 14; i++) {
        if (cpf[i] >= '0' && cpf[i] <= '9') {
            digits[j++] = cpf[i] - '0';
        }
    }

    int sum1 = 0;
    for (int i = 0; i < 9; i++) {
        sum1 += digits[i] * (i + 1);
    }
    int b1 = sum1 % 11;
    if (b1 == 10) b1 = 0;

    int sum2 = 0;
    for (int i = 0; i < 9; i++) {
        sum2 += digits[i] * (9 - i);
    }
    int b2 = sum2 % 11;
    if (b2 == 10) b2 = 0;

    if (digits[9] == b1 && digits[10] == b2) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char cpf[15];

    while (scanf("%s", cpf) != EOF) {
        if (isValidCPF(cpf)) {
            printf("CPF valido\n");
        } else {
            printf("CPF invalido\n");
        }
    }

    return 0;
}
