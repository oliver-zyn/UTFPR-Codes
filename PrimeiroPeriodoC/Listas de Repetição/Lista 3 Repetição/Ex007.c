#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    
    int num, i, j;
    long long int mult;
    char texto[] = "", texto2[] = "", continuar[] = "";
    
    do {
        num = 1;

        for(j = 1; j <= 12; j++) {
            mult = 1;
            printf("%i! => ", j);
        
            for (i = j; i >= 1; i--) {
                mult = mult * i;
                if (i != 1) {
                    printf("%i * ", i);
                }
            }
            printf("1 = %lli \n", mult);
        }
        
        printf("\n Deseja repetir o programa (S ou N)? ");
        scanf(" %c", continuar);
        
    } while (strcmp("S", continuar) == 0);
    
    return 0;
}