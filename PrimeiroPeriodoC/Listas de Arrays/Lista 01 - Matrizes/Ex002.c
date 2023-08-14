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
        
        int soma = 0, linha = 5, coluna = 5;

        int matriz[linha][coluna], vetorLinhas[5], vetorColunas[5];

        gerarMatrizInteiro(linha,coluna,matriz,5);
        printf("==== MATRIZ ====\n");
        mostrarMatrizInteiro(linha,coluna,matriz);

        for (int j = 0; j < linha; j++) {
            soma = 0;
            for (int i = 0; i < coluna; i++) {
                soma += matriz[j][i]; 
            }
            vetorLinhas[j] = soma;
        }
        for (int j = 0; j < linha; j++) {
            soma = 0;
            for (int i = 0; i < coluna; i++) {
                soma += matriz[i][j]; 
            }
            vetorColunas[j] = soma;
        }
        printf("\n\n==== SOMA DAS LINHAS ====\n");
        mostraVetorInteiros(vetorLinhas, 5);
        printf("\n\n==== SOMA DAS COLUNAS ====\n");
        mostraVetorInteiros(vetorColunas, 5);
        printf("\n");
        
        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);
        fflush(stdin);
        
    } while (continuar == 'S' || continuar == 's');
    
}



