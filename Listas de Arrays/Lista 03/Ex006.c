#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "funções.h"

int main(void) {
    
    char continuar;

    do {
        
        int vetor[15], i, vetorRep[15], vetorNrep[15], j = 0, k = 0, num = 0;
        
        gerarVetorComLimitesPositivos(vetor,15,1,20);
        ordenaVetor(vetor,15);
        mostraVetorInteiros(vetor,15);
        for(i = 0; i < 15; i++) {
            num = existeNoVetor(vetor, 15, vetor[i]);
            if (num > 1) {
                vetorRep[j] = vetor[i];
                j++;
                i += num - 1;
            } else {
                vetorNrep[k] = vetor[i];
                k++;
            }
        }
        printf("\n\n=== VETOR DE REPETIDOS ===\n");
        mostraVetorInteiros(vetorRep,j);
        printf("\n\n=== VETOR DE NAO REPETIDOS ===\n");
        mostraVetorInteiros(vetorNrep,k);
        
        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);
        
    } while (continuar == 'S' || continuar == 's');
    return 0;
}



