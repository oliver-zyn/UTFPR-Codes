#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    
    int i;
    float soma, cont, media;
    
    for (i=200; i >= 1; i--) {
        if (i % 2 != 0 && i % 5 != 0) {
            printf("%i\t", i);
        }
        if (i % 3 == 0 && i % 5 == 0) {
            soma = soma + i;
            cont = cont + 1;
        }
    }
    media = soma/cont;
    printf("\nA media dos divisiveis por 3 e por 5 eh: %.2f", media);
    return 0;
}