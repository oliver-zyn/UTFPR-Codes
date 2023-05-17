#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    float premio, prim, seg, terc;
    
    printf("Informe a quantia do premio: ");
    scanf("%f", &premio);
    
    prim = premio*0.46;
    seg = premio*0.32;
    terc = premio-(prim + seg);
    
    printf("%.2f recebe o primeiro lugar. \n", prim);
    printf("%.2f recebe o segundo lugar. \n", seg);
    printf("%.2f recebe o terceiro lugar.", terc);
    
    return 0;
}