#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void)
{
    int prim, seg;
    
    printf("Informe o primeiro numero: ");
    scanf("%i", &prim);
    printf("Informe o segundo numero: ");
    scanf("%i", &seg);
    
    if (prim > seg) {
        printf("%i é maior que %i", prim, seg);
    } else if (prim == seg) {
        printf("%i é igual a %i", prim, seg);
    } else if (prim < seg) {
        printf("%i é menor que %i", prim, seg);
    }
    
    return 0;
}