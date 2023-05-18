#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    
    int idade, somaidadeB, somaidadeE, contidade, cont, contB, contB3, contB2, contE;
    char nacio, curso;
    float mediaB, mediaE;
    
    
    do {
        printf("Informe a idade: ");
        scanf("%i", &idade);
        if (idade == 0) {
            break;
        }
        printf("Informe se é (B - brasileiro) ou (E - Estrangeiro): ");
        scanf(" %c", &nacio);
        printf("Informe se tem ou não curso superior: (S - Sim) ou (N - Não): ");
        scanf(" %c", &curso);
        
        if (nacio == 'B' || nacio == 'b') {
            contB = contB + 1;
            if (curso == 'N' || curso == 'n') {
                somaidadeB = somaidadeB + idade;
                contB2 = contB2 + 1;
            }
        } else if (nacio == 'E' || nacio == 'e') {
            contE = contE + 1;
            if (curso == 'S' || curso == 's') {
                somaidadeE = somaidadeE + idade;
                contB3 = contB3 + 1;
            }
        } else {
            printf("Opcao invalida");
            break;
        }
    } while (idade != 0);
    
    mediaB = somaidadeB/contB2;
    mediaE = somaidadeE/contB3;
    printf("A quantidade de brasileiros: %i\n", contB);
    printf("A quantidade de estrangeiros: %i\n", contE);
    printf("Media dos brasileiros S/C: %.2f\n", mediaB);
    printf("Media dos estrangeiros C/C: %.2f", mediaE);
    
    return 0;
}