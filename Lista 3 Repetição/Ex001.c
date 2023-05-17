#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    
    int i, j, final, resultado, count;
    char continuar[] = "";
    
    do {
        
        printf("Informe a quantidade de numeros primos que serao mostrados: ");
        scanf("%i", &final);
        
        if (final <= 0) {
            printf("Informe um numero maior que 0!");
            break;
        }
        
        count = 0;
        
        for(i = 2; count < final; i++) {
            for (j = 2; j <= i / 2; j++) {
                if (i % j == 0) {
                   resultado++;
                   break;
                }
            }
            
            if (resultado == 0) {
                printf("%i \t", i);
                count++;
            }
            
            resultado = 0;
        }
        
        printf("\n Deseja repetir o programa (S ou N)? ");
        scanf(" %c", continuar);
        
    } while (strcmp("S", continuar) == 0);
    
    return 0;
}