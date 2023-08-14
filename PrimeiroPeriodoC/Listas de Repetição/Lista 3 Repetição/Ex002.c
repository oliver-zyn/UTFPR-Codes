#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    
    int numeroLinhas, i, j, limiteSuperior, resultado, count, cont;
    char continuar[] = "";
    
    do {
        
        printf("Informe o valor do final: ");
        scanf("%i", &limiteSuperior);
        
        printf("Informe quantos numeros deseja imprimir por linha: ");
        scanf("%i", &numeroLinhas);
        
        if (numeroLinhas <= 0) {
            printf("O numero de linhas deve ser maior que 0!");
            break;
        }
        cont = 1;
        
        for(i = 1; cont <= limiteSuperior; i++) {
            
            if (i % 2 == 0) {
                resultado++;
            }
            if (resultado == 0) {
                cont++;
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