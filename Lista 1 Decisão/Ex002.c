#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void)
{
    int i;
    
    printf("Informe o mes: ");
    scanf("%i", &i);
    
    if (i < 0) {
        printf("%i, Opcao invalida", i);
    } else if (i >= 0 && i <= 3) {
        printf("%i, Primeiro Trimestre", i);
    } else if (i >= 4 && i <= 6) {
        printf("%i, Segundo Trimestre", i);
    } else if (i >= 7 && i <= 9) {
        printf("%i, Terceiro Trimestre", i);
    } else if (i >= 10 && i <= 12) {
        printf("%i, Quarto Trimestre", i);
    } 
    
    return 0;
}
