#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void)
{
    float salr, inss, ir, salrlq;
    
    printf("Informe o salario bruto: R$ ");
    scanf("%f", &salr);
    
    printf("Informe o percentual do INSS: ");
    scanf("%f", &inss);
    inss = inss/100;
    
    printf("Informe o percentual do IR: ");
    scanf("%f", &ir);
    ir = ir/100;
    
    salrlq = salr - ((salr * inss) + (salr * ir));

    printf("Salario Liquido: R$ %.2f", salrlq);
    return 0;
}