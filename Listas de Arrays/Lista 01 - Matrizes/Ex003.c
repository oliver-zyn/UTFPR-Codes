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
        
        int count = 1, linha = 10, coluna = 10, countV;

        int matriz[linha][coluna];

        gerarMatrizInteiroPreenchida(linha,coluna,matriz,1);
        printf("==== MATRIZ ORIGINAL ====\n");
        mostrarMatrizInteiro(linha,coluna,matriz);
        for (int j = 0; j < linha; j++) {
            for (int i = 0; i < coluna; i++) {
                if (i == j) {
                    matriz[j][i] = 0;
                }
            }
        }
        countV = linha;
        for (int j = 0; j < linha; j++) {
            for (int i = 0; i < coluna; i++) {
                if (count == countV && count != linha*coluna) {
                    matriz[j][i] = 0;
                    countV += linha - 1;
                }
                count += 1;
            }
        }
        printf("==== MATRIZ ATUAL ====\n");
        mostrarMatrizInteiro(linha,coluna,matriz);
        
        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);
        fflush(stdin);
        
    } while (continuar == 'S' || continuar == 's');
    
}



