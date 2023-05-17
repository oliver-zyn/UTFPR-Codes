#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    
    int num, cont10ou100, contimpar, cont10, cont30, cont10entre100, contdiff102030;
    
    do {
        printf("Informe um numero (negativo para finalizar): ");
        scanf("%i", &num);
        if (num < 0) {
            break;
        }
        if (num < 10 || num > 100) {
            cont10ou100 = cont10ou100 + 1;
        }
        if (num % 2 != 0) {
            contimpar = contimpar + 1;
        }
        if (num % 10 == 0) {
            cont10 = cont10 + 1;
        }
        if (num >= 10 && num <= 100) {
            cont10entre100 = cont10entre100 + 1;
        }
        if (num == 30) {
            cont30 = cont30 + 1;
        }
        if (num != 10 && num != 20 && num != 30) {
            contdiff102030 = contdiff102030 + 1;
        }
    } while (num >= 0);
    printf("Menor que 10 ou Maior que 100: %i\n", cont10ou100);
    printf("Impares: %i\n", contimpar);
    printf("Divisiveis por 10: %i\n", cont10);
    printf("Entre 10 e 100: %i\n", cont10entre100);
    printf("Numeros 30: %i\n", cont30);
    printf("Diferente de 10, 20 e 30: %i\n", contdiff102030);
    
    return 0;
}