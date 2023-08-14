#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    
    int i, y, num, soma;
    char continuar[] = "";
    
    do {
        printf("Informe um valor de 2 a 12: ");
        scanf("%i", &num);
        if (num < 2 || num > 12) break;
        y = num;
        num--;
        for (i = 1, num; i < y; i++, num--) {
            soma = i + num;
            printf("%i + %i = %i\n", i, num, soma);
        }
        printf("\n Deseja repetir o programa (S ou N)? ");
        scanf(" %c", continuar);

    } while (strcmp("S", continuar) == 0);
    return 0;
}