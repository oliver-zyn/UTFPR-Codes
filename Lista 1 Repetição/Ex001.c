#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    
    int i, num, soma, somaPar, mul9, cont;
    float media;
    
    printf("Informe um numero maior que 2: ");
    scanf("%i", &num);
    
    i = 1;
    soma = 0;
    somaPar = 0;
    mul9 = 1;
    cont = 0;
    
    for (i; i <= num; i += 1) {
        cont = cont + 1;
        soma = soma + i;
        if (i % 2 == 0) {
            somaPar = somaPar + i;
            printf("%i\t", i);
        } else {
            if (i % 9 == 0) {
                mul9 = mul9 * i;
            }
        }
        
        
    }
    media = soma/cont;
    printf("\nSoma dos pares: %i\n", somaPar);
    printf("Produto dos divisiveis por 9: %i\n", mul9);
    printf("Media de todos os numeros: %.2f\n", media);
    
    return 0;
}