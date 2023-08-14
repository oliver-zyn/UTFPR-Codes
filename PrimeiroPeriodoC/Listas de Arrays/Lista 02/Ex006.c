#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "vetores.h"

int main(void) {
    
    char continuar;

    do {
        
        int vetor[300], Min = 1, Max = 100, j = 0, vetor2[300], freeL = 0;
        
        atualizaVetorComLimitesPositivos(vetor, 300, Min, Max);
        printf("=== VETOR A ===\n");
        mostraVetorInteiros(vetor, 300);
        for (int i = 0; i < 300; i++) {
            if (vetor[i] > 9) {
                freeL = vetor[i] / 10;
                vetor2[j] = freeL;
                j++;
            } else {
                vetor2[j] = 0;
                j++;
            }
        }
        printf("\n\n=== VETOR B ===\n");
        mostraVetorInteiros(vetor2, j);
        
        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);
        
    } while (continuar == 'S' || continuar == 's');
    return 0;
}