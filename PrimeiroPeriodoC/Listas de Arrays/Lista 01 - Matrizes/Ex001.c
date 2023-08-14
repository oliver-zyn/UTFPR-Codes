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
        
        int soma = 0, somaPrincipal = 0, somaSecundaria = 0, count = 1, linha = 3, coluna = 3, countV;

        int matriz[linha][coluna];

        gerarMatrizInteiro(linha,coluna,matriz,10);
        printf("==== MATRIZ ====\n");
        mostrarMatrizInteiro(linha,coluna,matriz);
        for (int j = 0; j < linha; j++) {
            for (int i = 0; i < coluna; i++) {
                soma += matriz[j][i]; 
            }
        }
        for (int j = 0; j < linha; j++) {
            for (int i = 0; i < coluna; i++) {
                if (i == j) {
                    somaPrincipal += matriz[j][i];
                }
            }
        }
        countV = linha;
        for (int j = 0; j < linha; j++) {
            for (int i = 0; i < coluna; i++) {
                if (count == countV && count != linha*coluna) {
                    somaSecundaria += matriz[j][i];
                    countV += linha - 1;
                }
                count += 1;
            }
        }
        printf("Soma de todos os elementos: %d\n", soma);
        printf("Soma de todos os elementos da diagonal principal: %d\n", somaPrincipal);
        printf("Soma de todos os elementos da diagonal secundaria: %d\n", somaSecundaria);
        
        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);
        fflush(stdin);
        
    } while (continuar == 'S' || continuar == 's');
    
}



