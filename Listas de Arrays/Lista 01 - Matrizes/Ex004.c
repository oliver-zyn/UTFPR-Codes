#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "matrizes.h"

int main(void) {
    
    char continuar;

    do {
        
        int linha = 10, coluna = 2;

        int matriz[linha][coluna], vetorBase[linha], vetorExpoente[linha], vetorResultado[linha];

        gerarMatrizInteiro(linha,coluna,matriz,6);
        for (int j = 0; j < linha; j++) {
            for (int i = 0; i < coluna; i++) {
                continue; 
            }
            vetorBase[j] = matriz[0][j];
            vetorExpoente[j] = matriz[1][j];
        }
        calculaPotenciaPorVetores(vetorBase, vetorExpoente, vetorResultado, linha);
        
        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);
        fflush(stdin);
        
    } while (continuar == 'S' || continuar == 's');
    
}



