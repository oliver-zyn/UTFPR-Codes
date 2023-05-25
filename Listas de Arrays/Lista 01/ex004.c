
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "vetores.h"

int main()
{
    int tamanhoA, tamanhoB, i, max;
    char continuar;

    do {
    
        printf("Informe o valor do vetor A: ");
        scanf("%d", &tamanhoA);
        printf("Informe o valor do vetor B: ");
        scanf("%d", &tamanhoB);
        
        int vetorA[tamanhoA], vetorB[tamanhoB];
        
        geraInteirosDe1aLimte(vetorA, tamanhoA, 20);
        geraInteirosDe1aLimte(vetorB, tamanhoB, 15);
        
        printf("\n=== VETOR A ===\n");
        
        mostraVetorInteiros(vetorA, tamanhoA);
        
        printf("\n=== VETOR B ===\n");
        
        mostraVetorInteiros(vetorB, tamanhoB);
        
        if (tamanhoB <= tamanhoA) {
            max = tamanhoA;
        } else if (tamanhoB > tamanhoA) {
            max = tamanhoB;
        }
        
        int vetorC[max];
        
        for (i = 0; i < max; i++) {
            
            if (vetorA[i] > vetorB[i]) {
                vetorC[i] = 1;
            } else if (vetorA[i] < vetorB[i]) {
                vetorC[i] = -1;
            } else {
                vetorC[i] = 0;
            }
            
        }
        
        printf("\n=== VETOR C ===\n");
        
        mostraVetorInteiros(vetorC, max);

        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);

    } while (continuar == 'S' || continuar == 's');

    return 0;
}
