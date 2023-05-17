#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n1, n2, resto;
    
    printf("Informe o primeiro numero: ");
    scanf("%i", &n1);
    
    printf("Informe o segundo numero: ");
    scanf("%i", &n2);
    
    resto = n1 - (n2 * (n1/n2));
    printf("Resto é: %i", resto);
    
    return 0;
}