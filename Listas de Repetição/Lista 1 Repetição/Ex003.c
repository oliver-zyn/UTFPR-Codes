#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    
    int valorI, valorF, Incremento, x, y, soma, cont;
    float media;
    
    printf("Informe valor Inicial: ");
    scanf("%i", &valorI);
    printf("Informe valor Final: ");
    scanf("%i", &valorF);
    printf("Informe o incremento: ");
    scanf("%i", &Incremento);
    
    if (valorI > valorF) {
        x = valorF;
        y = valorI;
    } else {
        x = valorI;
        y = valorF;
    }
    
    for (x; x <= y; x = x + Incremento) {
        if (x % 2 != 0) {
            printf("%i\n", x);
            if (x % 35 == 0) {
                printf("%i\t", x);
                printf("Impar divisivel por 35\n");
                soma = soma + x;
                cont = cont + 1;
            }
        } else if (x % 2 == 0) {
            printf("%i\n", x);
        }
    }
    media = soma/cont;
    printf("Media dos impares divisiveis por 35: %.2f", media);
    
    return 0;
}