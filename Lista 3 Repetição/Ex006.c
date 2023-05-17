#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    
    int n, i, j, count;
    char continuar[] = "";
    
    do {
        
        printf("Digite um número positivo: ");
        scanf("%i", &n);
        
        count = 1;
        
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= i; j++) {
                printf("%i ", count);
                count++;
            }
            printf("\n");
        }
        return 0;
        
        printf("\n Deseja repetir o programa (S ou N)? ");
        scanf(" %c", continuar);
        
    } while (strcmp("S", continuar) == 0);
    
    return 0;
}