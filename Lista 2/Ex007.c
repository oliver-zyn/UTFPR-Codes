#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float salar, aumento, desconto, salarAu, salarDes,salarioLiquido,parteDec,parteDecInt;
    int parteInt;
    
    printf("Informe o salario: R$ ");
    scanf("%f", &salar);
    
    printf("Aumento (10 para 10%%): ");
    scanf("%f", &aumento);
    
    printf("Desconto (10 para 10%%): ");
    scanf("%f", &desconto);
    salarAu = (salar + (salar * (aumento/100)));
    salarDes = salarAu - (salarAu * (desconto/100));
    printf("Salario Aumentado: R$ %.2f \n", salarAu);
    printf("Salario com desconto R$ %.2f \n", salarDes);
    
    parteInt = salarDes;
    parteDec = salarDes - parteInt;
    parteDecInt = parteDec * 100;

    printf("O salario liquido eh: %i reais e %.0f centavos.", parteInt, round(parteDecInt));
    return 0;
    
}