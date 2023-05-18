#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void)
{
    int cod;
    float sal, aumento, resultado;
    
    printf("Informe o salario: ");
    scanf("%f", &sal);
    printf("Informe o codigo de sua posicao: ");
    scanf("%i", &cod);
    
    switch (cod) {
        case 1:
            printf("O seu cargo é Escriturário.\n");
            aumento = sal * 0.5;
            resultado = sal + aumento;
            printf("O aumento no seu salário é de R$ %.2f\n", aumento);
            printf("O seu salário será R$ %.2f", resultado);
            break;
        case 2:
            printf("O seu cargo é Escriturário.\n");
            aumento = sal * 0.35;
            resultado = sal + aumento;
            printf("O aumento no seu salário é de R$ %.2f\n", aumento);
            printf("O seu salário será R$ %.2f", resultado);
            break;
        case 3:
            printf("O seu cargo é Escriturário.\n");
            aumento = sal * 0.2;
            resultado = sal + aumento;
            printf("O aumento no seu salário é de R$ %.2f\n", aumento);
            printf("O seu salário será R$ %.2f", resultado);
            break;
        case 4:
            printf("O seu cargo é Escriturário.\n");
            aumento = sal * 0.1;
            resultado = sal + aumento;
            printf("O aumento no seu salário é de R$ %.2f\n", aumento);
            printf("O seu salário será R$ %.2f", resultado);
            break;
        case 5:
            printf("O seu cargo é Diretor.\n");
            printf("O aumento no seu salário é de R$ 0.00\n");
            printf("O seu salário será R$ %.2f", sal);
            break;
        default:
            printf("Cargo inexistente.");
    }
    return 0;

}