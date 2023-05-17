#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    
    int num, numMax, numMin;
    
    numMax = 0;
    numMin = 1;
    
    printf("Informe um numero diferente de 0 para continuar: ");
    scanf("%i", &num);
    
    while (num != 0) {
        if (num > numMax) {
            numMax = num;
        }
        if (num < numMin) {
            numMin = num;
        }
        printf("Informe um numero diferente de 0 para continuar: ");
        scanf("%i", &num);
    }
    printf("\nMaior Numero: %i\n", numMax);
    printf("Menor Numero: %i", numMin);
    return 0;
}