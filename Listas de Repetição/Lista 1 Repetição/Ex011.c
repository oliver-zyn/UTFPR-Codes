#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    
    float i, num, soma;
    
    printf("Informe um numero: ");
    scanf("%f", &num);
    
    soma = 0;
    
    for (i = 1; i <= num; i++) {
        soma = soma + (1/i);
        if (i != num) {
            printf("%i/%.0f + ", 1, i);
        } else {
            printf("%i/%.0f", 1, i);
        }
    }
    printf(" = %.2f", soma);
    return 0;
    
}