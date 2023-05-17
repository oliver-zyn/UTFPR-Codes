#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    
    int opcao, x1, x2, x3, max, meio, min, x1m, x2m, x3m;
    
    printf("Escolha entre as opcoes:\n1 - Mostrar em ordem crescente\n2 - Mostrar em ordem decrescente\n3 - Mostrar os multiplos de 2\n");
    scanf("%i", &opcao);
    printf("Informe os tres valores:\n");
    scanf("%i %i %i", &x1, &x2, &x3);
    
    max = x1;
    if (x2 > max) {
        max = x2;
        if (x3 > max) {
            max = x3;
        }
    }
    min = x1;
    if (x2 < min) {
        min = x2;
        if (x3 < min) {
            min = x3;
        }
    }
    meio = (x1 + x2 + x3) - (max + min);
    
    x1m = x1 % 2;
    x2m = x2 % 2;
    x3m = x3 % 2;
    
    switch(opcao) {
        case 1:
            printf("Ordem crescente: %i %i %i", min, meio, max);
            break;
        case 2:
            printf("Ordem decrescente: %i %i %i", max, meio, min);
            break;
        case 3:
            if (x1m == 0 || x2m == 0 || x3m == 0) {
                if (x1m == 0 && x2m == 0 && x3m == 0) {
                    printf("Os numeros %i %i %i sao multiplos de 2", x1, x2, x3);
                } else if (x1m == 0 && x2m == 0) {
                    printf("Apenas os numeros %i %i sao multiplos de 2", x1, x2);
                } else if (x1m == 0 && x3m == 0) {
                    printf("Apenas os numeros %i %i sao multiplos de 2", x1, x3);
                } else if (x2m == 0 && x3m == 0) {
                    printf("Apenas os numeros %i %i sao multiplos de 2", x2, x3);
                } else if (x1m == 0) {
                    printf("Apenas o numero %i eh multiplo de 2", x1);
                } else if (x2m == 0) {
                    printf("Apenas o numero %i eh multiplo de 2", x2);
                } else if (x3m == 0) {
                    printf("Apenas o numero %i eh multiplo de 2", x3);
                }
            } else {
                printf("Nenhum dos números eh multiplo de 2.");
                
            }
            break;
        default:
            printf("Opcao invalida!");
    }
    
    return 0;
}