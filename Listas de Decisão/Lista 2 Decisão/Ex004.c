#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void)
{
    int ano;
    
    printf("Informe o ano: ");
    scanf("%i", &ano);

    if (((ano % 4 == 0) && (ano % 100 != 0)) || (ano % 400 == 0)) {
        printf("Eh bisexto");
    } else {
        printf("Nao eh bissexto");
    }
    
    return 0;
}