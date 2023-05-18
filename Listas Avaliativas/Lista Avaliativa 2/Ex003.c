#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    
    int numeroLinhas, i, j, limiteInferior, limiteSuperior, resultado, count;
    char continuar[] = "";
    
    do {
        printf("Informe o valor do limite inferior do intervalo: ");
        scanf("%i", &limiteInferior);
        
        printf("Informe o valor do limite Superior do intervalo: ");
        scanf("%i", &limiteSuperior);
        
        printf("Informe quantos numeros deseja imprimir por linha: ");
        scanf("%i", &numeroLinhas);
        
        if (numeroLinhas <= 0) {
            printf("O numero de linhas deve ser maior que 0!");
            break;
        }
        
        for(i = limiteInferior; i <= limiteSuperior; i++) {
            for (j = 2; j <= i / 2; j++) {
                if (i % j == 0) {
                   resultado++;
                   break;
                }
            }
            
            if (resultado == 0) {
                if (count < numeroLinhas) {
                    printf("%i \t", i);
                    count++;
                } else {
                    printf("\n %i \t", i);
                    count = 1;
                }
            }
            
            resultado = 0;
        }
        
        printf("\n Deseja repetir o programa (S ou N)? ");
        scanf(" %c", continuar);
        
    } while (strcmp("S", continuar) == 0);
    
    return 0;
}