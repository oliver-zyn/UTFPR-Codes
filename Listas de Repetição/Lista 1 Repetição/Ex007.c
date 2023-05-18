#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    
    int i, div3, div5;
    float div7;
    
    printf("--Divisiveis por 3--\n");
    for (i = 1; i <= 100; i++) {
        if (i % 3 == 0) {
            div3 = i;
            printf("%i\t", div3);
        }
    }
    printf("\n--Quadrado dos Divisiveis por 3--\n");
    for (i = 1; i <= 100; i++) {
        if (i % 3 == 0) {
            div3 = i*i;
            printf("%i\t", div3);
        }
    }
    printf("\n--Divisiveis por 5 ou 7--\n");
    for (i = 1; i <= 100; i++) {
        if (i % 5 == 0 || i % 7 == 0) {
            div5 = i;
            printf("%i\t", div5);
        }
    }
    printf("\n--Raiz Quadrada dos Divisiveis por 5 ou 7--\n");
    for (i = 1; i <= 100; i++) {
        if (i % 5 == 0 || i % 7 == 0) {
            div7 = sqrt(i);
            printf("%.2f\t", div7);
        }
    }
    
    return 0;
}