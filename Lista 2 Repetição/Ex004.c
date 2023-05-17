#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    char c;
    int maiusculo = 0, minusculo = 0, naoletra = 0;

    printf("Digite uma sequencia de caracteres: ");

    do {
        scanf(" %c", &c);
        if (c == '0') {
            break;
        } else {
            if (c >= 65 && c <= 90) {
                maiusculo++;
            } else if (c >= 97 && c <= 122) {
                minusculo++;
            } else {
                naoletra++;
            }
        }
        
    } while (c != '0');

    printf("Quantidade de letras maiusculas: %d\n", maiusculo);
    printf("Quantidade de letras minusculas: %d\n", minusculo);
    printf("Quantidade de caracteres nao letras: %d\n", naoletra);

    return 0;
}

