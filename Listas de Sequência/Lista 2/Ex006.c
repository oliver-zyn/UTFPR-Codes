#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int valorint;
    float valor, valordec, valorcentavos;
    
    printf("Informe o Valor do salario: R$ ");
    scanf("%f", &valor);
    valorint = valor;
    valordec = valor - valorint;
    valorcentavos = valordec * 100;
    printf("O salario é de: R$ %.2f \n", valor);
    printf("Reais: %i \n", valorint);
    printf("Centavos: %.0f", round(valorcentavos));
    
    return 0;
}