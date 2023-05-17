#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    
    int i, num, x, y, soma, count, k;
    
    printf("Informe um número: ");
    scanf("%i", &num);
    soma = 1;
    count = 1;
    for (i = 1; i <= num; i++) {
        printf("\n%i: ",i);
        x = rand() % 10;
        printf("%i", x);
        
        if (x == y) {
            count += 1;
        } else {
            count = 1;
        }
        if (soma < count) {
            k = x;
            soma = count;
        }
        y = x;
    }
    if (k == 0) {
        printf("\nPontuacao: %i, pois %i teve %i ocorrencias.", soma, x, soma);
    } else {
        printf("\nPontuacao: %i, pois %i teve %i ocorrencias.", soma, k, soma);
    }
    
    return 0;
}