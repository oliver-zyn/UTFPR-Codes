#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int valor, valor0, valor1, valor2, valor3, valor4, resul;
    
    printf("Informe o valor inteiro de ate 3 digitos: ");
    scanf("%i", &valor);
    
    valor2 = valor / 100;
    valor3 = valor % 100 / 10;
    valor4 = valor % 10;
    printf("%i eh o primeiro digito. \n", valor2);
    printf("%i eh o segundo digito.\n", valor3);
    printf("%i eh o terceiro digito.\n", valor4);
    valor1 = valor4*100 + valor3*10 + valor2;

    printf("O inverso é: %i", valor1);
    
    return 0;
}