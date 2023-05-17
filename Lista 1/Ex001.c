#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void)
{
    float comp, larg, altura, resul;
    
    printf("Informe o comprimento (cm): ");
    scanf("%f", &comp);
    
    printf("Informe a largura (cm): ");
    scanf("%f", &larg);
    
    printf("Informe a altura (cm): ");
    scanf("%f", &altura);
    
    resul = comp * larg * altura;

    printf("Volume: %.2f cm3", resul);
    return 0;
}