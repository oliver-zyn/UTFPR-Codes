#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    
    int ascii, resultado, i, j, lengthNum = 0, resto, divi, dig, somatotal, num, soma;
    char c, numero;
    char continuar[] = "";

    do {
    
        do {
            printf("Informe um caractere: ");
            scanf(" %c", &c);
            if (c == '0') break;
            if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {
                for (j = 2; j <= c / 2; j++) {
                    if (c % j == 0) {
                        resultado++;
                        break;
                    }
                }
                if (resultado == 0) {
                    printf("%i eh primo\n", c);
                    numero = (int)c;
                    soma = soma + numero;
                } else {
                    printf("%i nao eh primo\n", c);
                }
            }
            
        } while (c != 0);
        num = (int)soma;
        while(num != 0) {
            lengthNum++;
            num /= 10;
        }
        somatotal = 0;
        for (resto = 10, divi = 1, i = 0; i < lengthNum; i++) {
            dig = soma % resto / divi;
            somatotal += dig;
            resto = resto * 10;
            divi = divi * 10;
        }
        printf("Soma dos primos: %i\n", soma);
        printf("Soma dos digitos de %i: %i", soma, somatotal);
        
        printf("\n Deseja repetir o programa (S ou N)? ");
        scanf(" %c", continuar);
    
    } while (strcmp("S", continuar) == 0);
    
    return 0;  
}

