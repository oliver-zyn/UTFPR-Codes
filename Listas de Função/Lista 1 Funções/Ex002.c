#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "fatoriais.h"

int main(void) {
    
    int i, num, fat;
    char C = '\0';
    char continuar[] = "";

    do {
        
        printf("Informe a opcao desejada: \nA-Fatoriais de 1 a 8\nB-Fatorial de um numero positivo.\n");
        scanf(" %c", &C);
        
        switch (C) {
            case 'A':
                for (i = 1; i <= 8; i++) {
                    fat = calculaFat(i);
                    mostraFat(i,fat);
                }
                break;
            case 'B':
                printf("Informe um numero positivo: ");
                scanf("%i", &num);
                if (num <= 0) break;
                fat = calculaFat(num);
                mostraFat(num, fat);
                break;
            default:
                printf("Opcao invalida!");
        }
    
        printf("\n Deseja repetir o programa (S ou N)? ");
        scanf(" %c", continuar);

    } while (strcmp("S", continuar) == 0);
    
    return 0;
}

