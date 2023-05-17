#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    
    int pessoas;
    float ingresso;
    
    printf("Informe o numero de pessoas: ");
    scanf("%i", &pessoas);
    
    printf("Valor INGRESSO      Valor Total RECEBIDO\n");
    
    for (ingresso = 15; ingresso <= 20; ingresso = ingresso + 0.5) {
        printf("R$ %.2f\t\tR$ %.2f\n", ingresso, ingresso*pessoas);
    }
    return 0;
}