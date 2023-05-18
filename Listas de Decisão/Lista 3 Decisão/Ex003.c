#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void)
{
    int num, dig1, dig2, dig3, dig4, dig5, soma, inver;
    
    printf("Informe o primeiro numero: ");
    scanf("%i", &num);
    
    dig1 = num / 10000;
    dig2 = num % 10000 / 1000;
    dig3 = num % 1000 / 100;
    dig4 = num % 100 / 10;
    dig5 = num % 10;
    
    soma = dig1 + dig2 + dig3 + dig4 + dig5;
    inver = (dig5 * 10000) + (dig4 * 1000) + (dig3 * 100) + (dig2 * 10) + (dig1);
     
    printf("Primeiro digito: %i\n",dig1);
    printf("Segundo digito: %i\n",dig2);
    printf("Terceiro digito: %i\n",dig3);
    printf("Quarto digito: %i\n",dig4);
    printf("Quinto digito: %i\n",dig5);
    
    if ((soma % 2) != 0) {
        printf("Soma: %i (impar)\n", soma);
    } else {
        printf("Soma: %i (par)\n", soma);
    }
    if (inver % 5 == 0) {
        printf("Inverso: %.5i (Multiplo de 5)\n", inver);
    } else {
        printf("Inverso: %.5i (Nao multiplo de 5)\n", inver);
    }
    
    return 0;
}