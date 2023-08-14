
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "vetores.h"

int main()
{
    int tamanhoVetor, limite, i, indiceMenor = 0, soma = 0, count = 0;
    float media;
    char continuar;
    
    do {
        
        printf("Informe o tamanho do vetor: ");
        scanf("%d", &tamanhoVetor);
        
        printf("Informe o limite do vetor: ");
        scanf("%d", &limite);
        
        if (tamanhoVetor < 0 || limite < 0) { 
            printf("Os valores devem ser positivos!");
            break;
        }
        
        int vetor[tamanhoVetor];
        
        geraInteirosDe0aLimte(vetor, tamanhoVetor, limite);
        
        printf("\n=== VETOR GERADO ===\n");
        
        mostraVetorInteiros(vetor, tamanhoVetor);
        
        int min = limite + 1;
        
        for (i = 0; i < tamanhoVetor; i++) {
            if (vetor[i] < min) {
                min = vetor[i];
                indiceMenor = i;
            }
            
            if (vetor[i] % 2 == 0) {
                soma += vetor[i];
                count++;
            }
            
        }
        
        printf("\nO menor valor eh %d e esta no indice %d\n", min, indiceMenor);
        
        media = (float) soma / count;
        
        printf("\nMedia dos pares: %.2f\n", media);
        
        soma = 0;
        count = 0;

        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);

    } while (continuar == 'S' || continuar == 's');

    return 0;
}
