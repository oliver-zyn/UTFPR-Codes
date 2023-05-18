#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    
    int n3, num, imparatual = 3, soma = 1, count;
    
    printf("Informe um numero: ");
    scanf("%i", &num);
    imparatual = -1;
    for (int i = 1; i <= num; i++) {
        count = 1;
        printf("%i => ", i);
        n3 = i * i * i;
        for (count; count <= i; count++) {
            imparatual += 2;
        }
        soma += imparatual;
        printf("%i\n", imparatual);
        if (soma == n3) {
            printf("%i\n", n3);
        }
        
    }
    
    
}

