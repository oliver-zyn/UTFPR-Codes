#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void)
{
    float x, x2,resul;
    
    printf("Informe o numerador: ");
    scanf("%f", &x);
    printf("Informe o denominador: ");
    scanf("%f", &x2);
    
    if (x2 == 0) {
        printf("%.1f/0 Erro: Divisao por zero", x);
    } else {
        resul = x/x2;
        printf("%.1f/%.1f = %.1f", x,x2,resul);
    }
    
    return 0;
}