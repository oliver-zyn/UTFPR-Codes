#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void)
{
    float comp, taxa, resul;
    
    printf("Informe o valor da prestacao: ");
    scanf("%f", &comp);
    
    printf("Informe o valor da taxa (10 para 10%): ");
    scanf("%f", &taxa);
    
    taxa = taxa/100;
    resul = (comp * taxa) + comp;

    printf("Valor Total: R$$ %.2f", resul);
    return 0;
}