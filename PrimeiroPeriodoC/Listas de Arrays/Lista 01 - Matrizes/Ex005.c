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
        
        int linha = 3, coluna = 3, max = 0, linhaMax = 0, colunaMax = 0;
        int matriz[linha][coluna];

        gerarMatrizInteiro(linha,coluna,matriz,100);
        printf("==== MATRIZ ====\n");
        mostrarMatrizInteiro(linha,coluna,matriz);
        for (int j = 0; j < linha; j++) {
            for (int i = 0; i < coluna; i++) {
                if (max < matriz[j][i]) {
                    max = matriz[j][i];
                    linhaMax = j;
                    colunaMax = i;
                }
            }
        }
        printf("O maior elemento da matriz eh %d e ta na coluna: %d da linha: %d", max, colunaMax + 1, linhaMax + 1);
        
        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);
        fflush(stdin);
        
    } while (continuar == 'S' || continuar == 's');
    
}



