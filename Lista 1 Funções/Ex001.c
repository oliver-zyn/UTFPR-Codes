#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "primos.h"

int main(void) {
    
    int num, boolar;
    char continuar[] = "";

    do {
        
        char C = '\0';
        int num, i, count;
        float soma, media;
        
        printf("Informe a opcao: (A, B ou C): \nA-Eh primo?\nB-Primos entre 1 e 100\nC-Media dos primos de 100 a 200\n");
        scanf(" %c", &C);
        
        
        switch(C) {
            case ('A'):
                printf("Informe um numero: ");
                scanf("%i", &num);
                if (primo(num) == 0) {
                    printf("%i eh primo", num);
                } else {
                    printf("%i nao eh primo", num);
                }
                break;
            case ('B'):
                for (i = 2; i<=100; i++) {
                    if (primo(i) == 0) {
                        printf("%i\t", i);
                    }
                }
                break;
            case ('C'):
                for (i = 100; i<=200; i++) {
                    if (primo(i) == 0) {
                        count += 1;
                        soma += i;
                    }
                }
                media = soma/count;
                printf("Media entre os primos entre 100 e 200: %.2f", media);
                break;
            default:
                printf("Nao eh uma opcao valida!");
                break;
        }
        
        printf("\n Deseja repetir o programa (S ou N)? ");
        scanf(" %c", continuar);

    } while (strcmp("S", continuar) == 0);
    
    return 0;
}

