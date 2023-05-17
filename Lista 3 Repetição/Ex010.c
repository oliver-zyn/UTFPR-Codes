#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    
    int numeroLinhas = 5, i, j, limiteInferior, limiteSuperior, resultado, count;
    char continuar[] = "";
    float media, soma, cont;
    
    do {
        printf("Informe o valor do limite inferior do intervalo: ");
        scanf("%i", &limiteInferior);
        
        printf("Informe o valor do limite Superior do intervalo: ");
        scanf("%i", &limiteSuperior);
        
        if (numeroLinhas <= 0) {
            printf("O numero de linhas deve ser maior que 0!");
            break;
        }
        
        for(i = limiteInferior; i <= limiteSuperior; i++) {
            
            if (i % 3 == 0 && i % 7 == 0) {
                soma += i;
                cont += 1;
            }
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
        media = soma/cont;
        printf("\n\nMedia dos divisiveis por 3 e 7: %.2f\n", media);
        printf("\n Deseja repetir o programa (S ou N)? ");
        scanf(" %c", continuar);
        
    } while (strcmp("S", continuar) == 0);
    
    return 0;
}