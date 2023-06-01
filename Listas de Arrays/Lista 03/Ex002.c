#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "funcoes.h"

int main(void) {
    
    int vetor[10];
    char continuar;

    do {
        
        gerarVetorComLimitesPositivos(vetor, 10, 1, 5);
        printf("=== VETOR ===\n");
        mostraVetorInteiros(vetor, 10);
        printf("\n");
        verificaAMaiorOcorrenciaNoVetor(vetor, 10);
        printf("\n");
        
        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);
        
    } while (continuar == 'S' || continuar == 's');
    
}



