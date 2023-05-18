#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int valor, valor0, valor1, valor2, valor3, valor4, resul;
    
    printf("Informe o valor inteiro de ate 5 digitos: ");
    scanf("%i", &valor);
    
    valor0 = valor / 10000;
    valor1 = valor % 10000 / 1000;
    valor2 = valor % 1000 / 100;
    valor3 = valor % 100 / 10;
    valor4 = valor % 10;
    resul = valor0 + valor1 + valor2 + valor3 + valor4;
    printf("%i eh o primeiro digito. \n", valor0);
    printf("%i eh o segundo digito.\n", valor1);
    printf("%i eh o terceiro digito.\n", valor2);
    printf("%i eh o quarto digito.\n", valor3);
    printf("%i eh o quinto digito.\n", valor4);
    printf("%i = %i + %i + %i + %i + %i : %i", valor, valor0, valor1, valor2, valor3, valor4, resul);
    
    return 0;
}