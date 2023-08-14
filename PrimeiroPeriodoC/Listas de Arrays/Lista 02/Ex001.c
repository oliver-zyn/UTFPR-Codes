#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "vetores.h"

int main(void) {
    
    char continuar;
    int vetor[20], Min = 5, Max = 20;

    do {
    
        randomArrayComLimite(vetor, 20, Min, Max);
        printf("=== VETOR ORIGINAL ===\n");
        mostraVetorInteiros(vetor, 20);
        printf("\n\n=== VETOR ORDENADO ===\n");
        ordenaVetor(vetor, 20);
        mostraVetorInteiros(vetor, 20);
        printf("\n\n=== DIVISORES ===\n");
        divisoresDeUmArraySemrepetidos(vetor,20);
        
        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);

    } while (continuar == 'S' || continuar == 's');
    return 0;	
}

