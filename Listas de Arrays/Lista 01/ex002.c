
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "vetores.h"

int main()
{
    int vetor[15], i, countPar, countImpar;
    char continuar;

    do {
    
        geraInteirosDe1aLimte(vetor, 15, 25);

        printf("\n=== VETOR ===\n");
        
        mostraVetorInteiros(vetor, 15);
        
        int vetorPar[15];
        int vetorImpar[15];
        
        for (i = 0; i < 15; i++) {
            
            if (vetor[i] % 2 == 0) {
                vetorPar[countPar] = vetor[i];
                countPar++;
            } else {
                vetorImpar[countImpar] = vetor[i];
                countImpar++;
            }
            
        }
        
        printf("\n=== VETOR PAR ===\n");
        
        mostraVetorInteiros(vetorPar, countPar);
        
        printf("\n=== VETOR IMPAR ===\n");
        
        mostraVetorInteiros(vetorImpar, countImpar);
        
        countPar = 0;
        countImpar = 0;

        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);

    } while (continuar == 'S' || continuar == 's');

    return 0;
}
