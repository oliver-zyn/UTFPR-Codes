#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    
    int i, soma, cont;
    float media;
    soma = 0;
    
    for (i = 500; i >= 0; i--) {
        if (i % 4 == 0 || i % 10 == 0) {
            printf("%i\t", i);
            soma = soma + i;
            cont = cont + 1;
        }
    }
    media = soma/cont;
    printf("\nMedia: %.2f", media);
}