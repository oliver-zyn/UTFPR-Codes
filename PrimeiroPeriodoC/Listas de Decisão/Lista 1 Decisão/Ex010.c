#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void)
{
    int x1, x2, x3, soma, mult, min, max;
    float media;
    
    printf("Informe o primeiro numero: ");
    scanf("%i", &x1);
    printf("Informe o segundo numero: ");
    scanf("%i", &x2);
    printf("Informe o terceiro numero: ");
    scanf("%i", &x3);
    
    soma = x1 + x2 + x3;
    mult = x1 * x2 * x3;
    media = soma/3;

    if ((x1 > x2 && x1 > x3)) {
        max = x1;
    } else if ((x2 > x1 && x2 > x3)) {
        max = x2;
    } else {
        max = x3;
    }
    if ((x1 < x2 && x1 < x3)) {
        min = x1;
    } else if ((x2 < x1 && x2 < x3)) {
        min = x2;
    } else {
        min = x3;
    }
    
    printf("Soma: %i\n", soma);
    printf("Media: %.2f\n", media);
    printf("Multiplicacao: %i\n", mult);
    printf("Menor dos 3: %i\n", min);
    printf("Maior dos 3: %i", max);
    
    return 0;
}