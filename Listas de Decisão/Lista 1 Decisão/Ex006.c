#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void)
{
    float peso, alt, idade, GEB;
    char gen;
    
    printf("Informe a sua altura: ");
    scanf("%f", &alt);
    printf("Informe o seu peso: ");
    scanf("%f", &peso);
    printf("Informe a sua idade: ");
    scanf("%f", &idade);
    printf("Informe o seu genero: ");
    scanf(" %c", &gen);
    
    if (gen == 'M') {
        GEB = 66.47 + (13.75 * peso) + (5 * alt) - (6.76 * idade);
        printf("Sexo: Masculino\nGEB: %f", GEB);
    } else if (gen == 'F') {
        GEB = 655.1 + (9.56 * peso) + (1.85 * alt) - (4.67 * idade);
        printf("Sexo: Feminino\nGEB: %f", GEB);
    }
    
    return 0;
}