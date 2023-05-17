#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void)
{
    int x1, x2, x3, meio, min, max;
    float media;
    
    printf("Informe o primeiro numero: ");
    scanf("%i", &x1);
    printf("Informe o segundo numero: ");
    scanf("%i", &x2);
    printf("Informe o terceiro numero: ");
    scanf("%i", &x3);
    

    if ((x1 > x2 && x1 > x3)) {
        max = x1;
    } else if ((x2 > x1 && x2 > x3)) {
        max = x2;
    } else {
        max = x3;
    }
    
    if ((x1 > x2 && x1 < x3) || (x1 > x3 && x1 < x2)) {
        meio = x1;
    } else if ((x2 > x1 && x2 < x3) || (x2 > x3 && x2 < x1)) {
        meio = x2;
    } else {
        meio = x3;
    }
    
    if ((x1 < x2 && x1 < x3)) {
        min = x1;
    } else if ((x2 < x1 && x2 < x3)) {
        min = x2;
    } else {
        min = x3;
    }
    
    printf("Menor: %i\n", min);
    printf("Meio: %i\n", meio);
    printf("Maior: %i", max);
    
    return 0;
}