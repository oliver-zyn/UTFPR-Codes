#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    
    int i, j, k, limiteInferior, limiteSuperior, resultado, soma, resto, divisor, lengthNum, num;
    char continuar[] = "";
    float dig;

    do {
        printf("Informe o valor do limite inferior do intervalo: ");
        scanf("%i", &limiteInferior);
        
        printf("Informe o valor do limite Superior do intervalo: ");
        scanf("%i", &limiteSuperior);
        
        if (limiteSuperior < 0 || limiteInferior < 0) {
            printf("Os valores dos intervalos devem ser positivos!");
            break;
        }
        
        for(i = limiteInferior; i <= limiteSuperior; i++) {
            
            
            for (j = 2; j <= i / 2; j++) {
                if (i % j == 0) {
                   resultado++;
                   break;
                }
            }

            if (resultado == 0 && i > 1) {
                
                num = i;
                
                while(num != 0) {
                    lengthNum++;
                    num /= 10;
                }
                
                for(divisor = 10, resto = 1, k = 0; k < lengthNum; divisor = divisor * 10, resto = resto * 10, k++) {
                    dig = i % divisor / resto;
                    soma += dig;
                }
                printf("\nPrimo %i => Soma dos digitos = %i", i, soma);
            }
            
            resultado = 0;
            lengthNum = 0;
            soma = 0;
        }

        printf("\n Deseja repetir o programa (S ou N)? ");
        scanf(" %c", continuar);
        
    } while (strcmp("S", continuar) == 0);
    
    return 0;
}