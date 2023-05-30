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
        
        char vetor[100], j = 0, vetor2[200];
        int num;
        
        printf("Informe quantos char devem ser mostrados por linha: ");
        scanf("%d", &num);
        
        gerarVetorCharMinuscula(vetor, 100);
        printf("=== VETOR DE MINUSCULAS ===\n");
        mostraVetorChar(vetor, 100, num);
        
        gerarVetorCharMaiscula(vetor2, 200);
        printf("\n\n=== VETOR DE MAIUSCULAS ===\n");
        mostraVetorChar(vetor2, 200, num);
        
        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);
        
    } while (continuar == 'S' || continuar == 's');
    return 0;
}