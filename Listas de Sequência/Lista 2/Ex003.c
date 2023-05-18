#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int valorint;
    float valor, valordec, valorcentavos;
    
    printf("Informe o Valor do troco: R$ ");
    scanf("%f", &valor);
    valorint = valor;
    valordec = valor - valorint;
    valorcentavos = valordec * 100;
    printf("Valor informado eh de: %i reais e %.0f centavos", valorint, round(valorcentavos));
    
    return 0;
}