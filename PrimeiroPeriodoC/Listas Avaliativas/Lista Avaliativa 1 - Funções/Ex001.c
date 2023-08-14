#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void calc(int num) {
    
    int i = 1, n3 = 0;
    
    for (i = 1; n3 < num; i++) {
        n3 = i * (i + 1) * (i + 2);
    }
    
    if (n3 == num) {
        printf("%d eh triangular ==> %d * %d * %d = %d", num, i - 1, i, i + 1, n3);
    } else {
        printf("%d nao eh triangular.", num);
    }
}

void calclimite(int inferior, int superior) {
    
    int i = 1, n3 = 0, j;
    
    for (inferior; inferior <= superior; inferior++) {
        for (i; n3 < inferior; i++) {
            n3 = i * (i + 1) * (i + 2);
        }
        if (n3 == inferior) {
            printf("%d eh triangular ==> %d * %d * %d = %d\n", inferior, i - 1, i, i + 1, n3);
        }
    }
}

int main() {
    int num, i, opcao, inferior, superior;
    char continuar;

    do {

        printf("1 - Verificar se um numero eh triangular\n");
        printf("2 - Mostra os numeros triangulares que pertencem a um intervalo\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                
                printf("\nInforme um numero: ");
                scanf("%d", &num);
                calc(num);
                break;

            case 2:

                printf("\nInforme um limite inferior: ");
                scanf("%d", &inferior);

                printf("\nInforme um limite superior: ");
                scanf("%d", &superior);
                
                calclimite(inferior, superior);
                
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


