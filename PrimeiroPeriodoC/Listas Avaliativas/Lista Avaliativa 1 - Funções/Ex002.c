#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void calc2(int num) {
    
    int i = 2, n3 = 0, j, y;
    
    for (i; n3 < num; i += 2) {
        n3 += i;
        j = i;
    }
    if (n3 == num) {
        for (y = 2; y <= num; y += 2) {
            if (y < j) {
                printf("%d + ", y);
            } else if (y == j) {
                printf("%d = %d ==> Eh retangular", y, num);
            }
        }
    } else if (n3 > num){
        printf("%d nao eh retangular", num);
    }
}

void calclimite2(int inferior, int superior) {
    
    int i = 2, n3 = 0, j, y;
    
    for (inferior; inferior <= superior; inferior++) {
        for (i; n3 < inferior; i += 2) {
            n3 += i;
            j = i;
        }
        if (n3 == inferior) {
            for (y = 2; y <= inferior; y += 2) {
                if (y < j) {
                    printf("%d + ", y);
                } else if (y == j) {
                    printf("%d = %d ==> Eh retangular!\n", y, inferior);
                }
            }
        }
    }
}


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


