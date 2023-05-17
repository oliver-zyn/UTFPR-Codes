#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    
    int n, positivos, negativosPar, soma, cont;
    float media;
    
    printf("Digite um número diferente de 0 para continuar: ");
    
    do {
        scanf("%i", &n);
        if (n == 0) {
            break;
        }
        if (n > 0) {
            positivos++;
        }
        if (n % 2 == 0 && n < 0) {
            negativosPar++;
        }
        if (n % 3 == 0) {
            n = abs(n);
            soma += n;
            cont += 1;
        }
    } while (n != 0);
    media = soma/cont;
    printf("Numeros positivos: %i\n", positivos);
    printf("Numeros negativos e par: %i\n", negativosPar);
    printf("Media dos divisiveis por 3: %.2f\n", media);
    return 0;
}