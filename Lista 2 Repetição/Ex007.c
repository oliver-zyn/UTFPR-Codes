#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    
    int n, i, j, mul;
    
    printf("Digite um número como base: ");
    scanf("%i", &n);
    printf("Digite um número positivo como expoente: ");
    scanf("%i", &i);
    
    mul = 1;
    
    for (j = 1; j <= i; j++) {
        mul = mul * n;
        if (j != i) {
            printf("%i * ", n);
        } else {
            printf("%i = ", n);
        }
        
    } 
    printf("%i", mul);
    return 0;
}