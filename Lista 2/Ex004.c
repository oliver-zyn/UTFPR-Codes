#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int valor, valor1, valor2, valor3, resul;
    
    printf("Informe o valor inteiro de ate 3 digitos: ");
    scanf("%i", &valor);
    
    valor1 = valor / 100;
    valor2 = valor % 100 / 10;
    valor3 = valor % 10;
    resul = valor1 + valor2 + valor3;
    printf("%i = %i + %i + %i : %i", valor, valor1, valor2, valor3, resul);
    
    return 0;
}
