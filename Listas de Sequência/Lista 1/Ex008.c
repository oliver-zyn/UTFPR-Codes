#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void)
{
    float bruto, distr, imposto, resul;
    
    printf("Informe o custo de fabrica do carro: R$ ");
    scanf("%f", &bruto);
    
    printf("Informe a percentagem do distribuidor (0 a 100): ");
    scanf("%f", &distr);
    distr = distr/100;
    
    printf("Informe a percentagem de impostos (0 a 100): ");
    scanf("%f", &imposto);
    imposto = imposto/100;
    
    resul = bruto + ((bruto * distr) + (bruto * imposto));

    printf("Valor final: R$ %.2f", resul);
    return 0;
}
