#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "vetores.h"

int main(void) {
    
    char continuar;
    float vetor[10], vetor2[50], vetor3[50], vetor4[50];
    int j = 0, i, y = 0;

    do {
    
        geraVetorFloat0a1(vetor, 10);
        printf("=== VETOR 1 ===\n");
        mostraVetorFloat(vetor, 10);
        mostraSomaVetorFloat(vetor, 10);
        printf("\n\n=== VETOR 2 ===\n");
        geraVetorFloat0a100(vetor2, 50);
        mostraVetorFloat(vetor2, 50);
        for (i = 0; i < 50; i++) {
            if (vetor2[i] < 50) {
                vetor3[j] = vetor2[i];
                j++;
            } else {
                vetor4[y] = vetor2[i];
                y++;
            }
        }
        printf("\n\n=== VETOR 3 ===\n");
        mostraVetorFloat(vetor3, j);
        printf("\n\n=== VETOR 4 ===\n");
        mostraVetorFloat(vetor4, y);
        
        
        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);

    } while (continuar == 'S' || continuar == 's');
    return 0;	
}





