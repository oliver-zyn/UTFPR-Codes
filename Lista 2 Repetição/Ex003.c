#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    
    float A, B, anos;
    
    anos = 0;
    
    for (A = 1.5, B = 1.1; A>B; A += 0.02, B += 0.03) {
        anos += 1;
    }
    printf("Arvore A altura final: %.2f\n", A);
    printf("Arvore B altura final: %.2f\n", B);
    printf("Serao necessarios %.0f anos para B passar A", anos);
    
    return 0;
}