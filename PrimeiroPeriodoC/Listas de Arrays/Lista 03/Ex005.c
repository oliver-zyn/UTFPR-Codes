#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "funcoes.h"


int main() {
    char continuar;

    do {
        
        int vetA[10], vetB[10], vetC[20], i, num, j, indiceC = 0;
        
        gerarVetorSemRepeticao(vetA, 10, 15);
        gerarVetorSemRepeticao(vetB, 10, 10);
        
        for (i = 0; i < 10; i++) {
            num = vetA[i];
            
            for (j = 0; j < 10; j++) {
                if (existeNoVetor(vetB, 10, num) == 0) {
                    vetC[indiceC] = num;
                    indiceC++;
                    break;
                }
            }
        }
        
        for (i = 0; i < 10; i++) {
            num = vetB[i];
            
            for (j = 0; j < 10; j++) {
                if (existeNoVetor(vetA, 10, num) == 0) {
                    vetC[indiceC] = num;
                    indiceC++;
                    break;
                }
            }
        }
        
        for (i = 0; i < 10; i++) {
            num = vetB[i];
            
            for (j = 0; j < 10; j++) {
                if (existeNoVetor(vetA, 10, num) != 0) {
                    vetC[indiceC] = num;
                    indiceC++;
                    break;
                }
            }
        }
        
        printf("==== VETOR A ====\n");
        mostraVetorInteiros(vetA, 10);
        
        printf("\n==== VETOR B ====\n");
        mostraVetorInteiros(vetB, 10);
        
        printf("\n==== INTERSECAO ====\n");
        mostraVetorInteiros(vetC, indiceC);
        
        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);

    } while (continuar == 'S' || continuar == 's');

    return 0;
}
