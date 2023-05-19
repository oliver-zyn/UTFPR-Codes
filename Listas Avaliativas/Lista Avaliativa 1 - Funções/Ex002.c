#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Retangular.h"

int main() {
    int num, i, opcao, inferior, superior;
    char continuar;

    do {

        printf("1 - Verificar se um numero eh retangular\n");
        printf("2 - Mostra os numeros retangulares que pertencem a um intervalo\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                
                printf("\nInforme um numero: ");
                scanf("%d", &num);
                calc2(num);
                break;

            case 2:

                printf("\nInforme um limite inferior: ");
                scanf("%d", &inferior);

                printf("\nInforme um limite superior: ");
                scanf("%d", &superior);
                
                calclimite2(inferior, superior);
                
                break;

            default:
                printf("\nEscolha uma opcao valida!\n");

                break;
        }

        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);

    } while (continuar == 'S' || continuar == 's');

    return 0;
}


