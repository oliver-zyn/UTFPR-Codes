#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    
    int x, i, t, divi, max, y, count;
    char continuar[] = "";

    do {
        printf("Informe um numero entre 2 e 100: ");
        scanf("%i", &x);
        if (x > 100 || x < 2) break;
        t = x + 10;
        
        for (i = x; i <= t; i++) {
            count = 0;
            printf("%i => ", i);
            for (y = 1; y <= i; y++) {
                if (i % y == 0) {
                    printf("%i, ", y);
                    count++;
                }
            }
            printf("%i divisores", count);
            printf("\n");
        }




        printf("\n Deseja repetir o programa (S ou N)? ");
        scanf(" %c", continuar);

    } while (strcmp("S", continuar) == 0);  
    
}