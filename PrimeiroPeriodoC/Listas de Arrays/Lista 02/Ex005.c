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
        
        int vetor[100], Min = 50, Max = 50, j = 0, vetor2[100];
        
        atualizaVetorComLimitesNegativosEPositivos(vetor, 100, Min, Max);
        printf("=== VETOR A ===\n");
        mostraVetorInteiros(vetor, 100);
        for (int i = 0; i < 100; i++) {
            if (vetor[i] > 0) {
                vetor2[j] = vetor[i];
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