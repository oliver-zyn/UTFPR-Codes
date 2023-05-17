#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    float custo, valoring;
    int qtdC, qtdL;
    
    printf("Informe o custo da peca teatral: ");
    scanf("%f", &custo);
    printf("Informe o valor do ingresso: ");
    scanf("%f", &valoring);
    
    qtdC = ceil(custo / valoring);
    qtdL = ceil((custo + (custo * 0.25)) / valoring);
    
    printf("%i ingressos devem ser vendidos para abater o custo. \n", qtdC);
    printf("%i ingressos devem ser vendidos para abater o custo e 25%% de lucro.", qtdL);
    
    return 0;
}