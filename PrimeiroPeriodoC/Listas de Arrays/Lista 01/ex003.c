
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "vetores.h"

int main()
{
    int vetorA[10], vetorB[10], i, j;
    char continuar;

    do {
    
        geraInteirosDe1aLimte(vetorA, 10, 10);
        geraInteirosDe1aLimte(vetorB, 10, 10);

        printf("\n=== VETOR A ===\n");
        
        mostraVetorInteiros(vetorA, 10);
        
        for (i = 9, j = 0; j < 10; i--, j++) {
            
            vetorB[i] = vetorA[j];
            
        }
        
        printf("\n=== VETOR B ===\n");
        
        mostraVetorInteiros(vetorB, 10);

        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);

    } while (continuar == 'S' || continuar == 's');

    return 0;
}
