#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    
    int n, i, j;
    
    printf("Digite um número positivo: ");
    scanf("%i", &n);
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("%i\t", j);
        }
        printf("\n");
    }
    return 0;
}