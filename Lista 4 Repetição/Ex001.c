#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    
    int i, y, dig1, dig2, dig3, dig4, soma1, soma2, soma3;
    char continuar[] = "";

    do {
        
        for (i = 1000; i <= 9999; i++) {
            dig1 = i % 10000 / 1000;
            dig2 = i % 1000 / 100;
            dig3 = i % 100 / 10;
            dig4 = i % 10;
            soma1 = dig1 * 10 + dig2;
            soma2 = dig3 * 10 + dig4;
            soma3 = soma2 + soma1;
            if (pow(soma3, 2) == i) {
                printf("%i\t", i);
            }
        }
            
        
        printf("\n Deseja repetir o programa (S ou N)? ");
        scanf(" %c", continuar);

    } while (strcmp("S", continuar) == 0);
    
    
    
}