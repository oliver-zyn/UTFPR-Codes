#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "funções.h"

int main(void) {
    
    int vetor[5], i;
    char continuar;

    do {
        
        gerarVetorComLimitesPositivos(vetor, 5, 1, 9);
        printf("=== VETOR ===\n");
        mostraVetorInteiros(vetor,5);
        
        for (i = 0; i < 5; i++) {
            printf("\n\n=== Tabuada do %d ===\n", vetor[i]);
            gerarTabuada(vetor[i]);
        }
        
        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);
        
    } while (continuar == 'S' || continuar == 's');
    
}



