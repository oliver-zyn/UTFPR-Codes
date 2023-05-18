#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void)
{
    float altura, peso, IMC;
    
    printf("Informe a sua altura (em Metros): ");
    scanf("%f", &altura);
    printf("Informe o seu peso (em Kg): ");
    scanf("%f", &peso);
    
    IMC = peso/pow(altura, 2);
    
    if (IMC < 20) {
        printf("IMC = %.2f (Abaixo do Peso)", IMC);
    } else if (20 <= IMC && IMC < 25) {
        printf("IMC = %.2f (Peso Normal)", IMC);
    } else if (25 <= IMC && IMC < 30) {
        printf("IMC = %.2f (Acima do Peso)", IMC);
    } else if (30 <= IMC && IMC < 34) {
        printf("IMC = %.2f (Obeso)", IMC);
    } else if (IMC >= 34) {
        printf("IMC = %.2f (Muito Obeso)", IMC);
    } 
    
    return 0;
}