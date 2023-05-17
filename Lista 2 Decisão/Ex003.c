#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void)
{
    int num, dig1, dig2, dig3, dig4;
    
    printf("Informe o primeiro numero: ");
    scanf("%i", &num);

    dig1 = num / 1000;
    dig2 = num % 1000 / 100;
    dig3 = num % 100 / 10;
    dig4 = num % 10;
    
    if ((dig1 == dig4) && (dig2 == dig3)) {
        printf("Eh palindromo");
    } else {
        printf("Nao eh palindromo");
    }
    
    return 0;
}