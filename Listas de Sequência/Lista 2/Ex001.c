#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int n1,n3,n4;
    float n0, n2;
    char n5[3] = "";
    
    printf("Informe o numero com 6 digitos decimais: ");
    scanf("%f", &n0);
    printf("Numero Informado: %f \n", n0);
    n3 = n0;
    printf("Parte inteira: %i \n", n3);
    printf("Parte Decimal: %f \n", n0-n3);
    n4 = (n0-n3) * 1000;
    sprintf(n5, "%i", n3);
    printf("Parte Decimal em inteiro de 3 digitos: %i \n", n4);
    printf("Centenas: %c \n",n5[0]);
    printf("Dezenas: %c \n",n5[1]);
    printf("Unidades: %c",n5[2]);
    return 0;
}

