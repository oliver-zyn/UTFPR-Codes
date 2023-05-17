#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    
    float x1, x2, x3, max, meio, min, x1pow, x2x3, x2pow, x3pow, x2powx3;
    
    printf("Informe o primeiro numero: ");
    scanf("%f", &x1);
    printf("Informe o segundo numero: ");
    scanf("%f", &x2);
    printf("Informe o terceiro numero: ");
    scanf("%f", &x3);
    
    if ((x1 > x2 && x1 > x3)) {
        max = x1;
    } else if ((x2 > x1 && x2 > x3)) {
        max = x2;
    } else {
        max = x3;
    }
    if ((x1 > x2 && x1 < x3) || (x1 > x3 && x1 < x2)) {
        meio = x1;
    } else if ((x2 > x1 && x2 < x3) || (x2 > x3 && x2 < x1)) {
        meio = x2;
    } else {
        meio = x3;
    }
    if ((x1 < x2 && x1 < x3)) {
        min = x1;
    } else if ((x2 < x1 && x2 < x3)) {
        min = x2;
    } else {
        min = x3;
    }
    
    x1pow = pow(max, 2);
    x2x3 = meio + min;
    x2pow = pow(meio,2);
    x3pow = pow(min, 2);
    x2powx3 = x2pow + x3pow;
    
    if (max >= x2x3) {
        printf("Ordem decrescente: %.2f, %.2f, %.2f\n", max, meio, min);
        printf("Não gera triangulo");
    } else if (x1pow == x2powx3) {
        printf("Ordem decrescente: %.2f, %.2f, %.2f\n", max, meio, min);
        printf("Triangulo Retangulo");
    } else if (x1pow > x2powx3) {
        printf("Ordem decrescente: %.2f, %.2f, %.2f\n", max, meio, min);
        printf("Triangulo Obtusangulo");
    } else if (x1 == x2 && x2 == x3) {
        printf("Triangulo Equilatero\n");
        printf("Triangulo Acutangulo");
    } else if ((x1 == x2 && x1 != x3) || (x2 == x3 && x2 != x1) || (x1 == x3 && x1 != x2)) {
        printf("Triangulo Obtusangulo\n");
        printf("Triangulo Isosceles");
    } else if (x1pow < x2powx3) {
        printf("Ordem decrescente: %.2f, %.2f, %.2f\n", max, meio, min);
        printf("Triangulo Acutangulo");
    }
    return 0; 
}