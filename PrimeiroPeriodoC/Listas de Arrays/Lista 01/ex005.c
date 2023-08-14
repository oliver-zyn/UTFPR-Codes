
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "vetores.h"

int main()
{
    int vetorA[100], vetorB[50], i, count = 0, countPosicao = 0;
    char continuar;

    do {
        
        geraInteirosDe0aLimte(vetorA, 100, 1);

        printf("\n=== VETOR A ===\n");
        
        mostraVetorInteiros(vetorA, 100);
        
        printf("\n=== VETOR B ===\n");
        
        for (i = 0; i < 100; i++) {
            if (vetorA[i] == 0) {
                
                count++;
            }
            
            if (vetorA[i] == 1 && count != 0) {
                vetorB[countPosicao] = count;
                countPosicao++;
                count = 0;
            }
        }
        
        mostraVetorInteiros(vetorB, countPosicao);
        
        countPosicao = 0;
        count = 0;

        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);

    } while (continuar == 'S' || continuar == 's');

    return 0;
}
