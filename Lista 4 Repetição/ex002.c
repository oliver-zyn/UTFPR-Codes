#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {

    int x, num, i, j, y, k, resultado, count;
    char continuar[] = "";

    do {

        printf("Informe um numero positivo: ");
        scanf("%i", &x);
        if (x < 0) break;

        num = x + 10;

        for (k = x; k <= num; k++) {
            
            printf("\n%i ==> ", k);

            for(i = 2; i <= k; i++) {
                for (j = 2; j <= i / 2; j++) {
                    if (i % j == 0) {
                        resultado++;
                        break;
                    }
                }
                
                if (resultado == 0) { 
                    printf("%i\t", i);
                    count++;
                }
                
                resultado = 0;
            }
            
            printf("==> %i primo(s)", count);
            count = 0;

        }

        printf("\n Deseja repetir o programa (S ou N)? ");
        scanf(" %c", continuar);

    } while (strcmp("S", continuar) == 0);

    return 0;
}