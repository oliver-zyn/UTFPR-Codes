#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    
    int num, soma = 0, i;

    printf("Digite um número: ");
    scanf("%i", &num);

    for (i = 1; i < num; i++) {
        if (num % i == 0) {
            printf("%i\n", i);
            soma += i;
        }
    }
    printf("-----\n");
    printf("Soma: %i\n\n", soma);
 
    if (soma > num) {
        printf("%i é um número abundante.\n", num);
    } else {
        printf("%i não é um número abundante.\n", num);
    }

    return 0;
}