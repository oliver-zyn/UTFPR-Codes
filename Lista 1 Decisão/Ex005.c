#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void)
{
    int prim, seg, terc;
    
    printf("Informe o primeiro numero: ");
    scanf("%i", &prim);
    printf("Informe o segundo numero: ");
    scanf("%i", &seg);
    printf("Informe o terceiro numero: ");
    scanf("%i", &terc);
    
    if ((prim > seg && prim < terc) || (prim < seg && prim > terc)) {
        printf("%i é o valor do meio", prim);
    } else if ((seg > prim && seg < terc) || (seg < prim && seg > terc)) {
        printf("%i é o valor do meio", seg);
    } else if ((terc > prim && terc < seg) || (terc < prim && terc > seg)) {
        printf("%i é o valor do meio", seg);
    }
    
    return 0;
}