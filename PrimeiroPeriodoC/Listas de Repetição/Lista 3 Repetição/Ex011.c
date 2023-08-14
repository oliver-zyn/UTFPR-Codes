#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    
    int i, num, cont;
    char continuar[] = "";

    do {
        
        printf("Informe um numero: ");
        scanf("%i", &num);
        
        for (i = 1; cont < num; i++) {
            if (sqrt(i) == floor(sqrt(i)) && sqrt(i) == ceil(sqrt(i))) {
                printf("Raiz quadrada de %i eh %.0f\n", i, sqrt(i));
                cont++;
            } 
        }
        
        printf("\n Deseja repetir o programa (S ou N)? ");
        scanf(" %c", continuar);

    } while (strcmp("S", continuar) == 0);
    
}