#include <stdio.h>
#include "Divisores.h"

int main()
{
    int num, i, opcao, numQtdDivisores, inferior, superior, primeiro, segundo;
    char continuar;

    do {
    
        printf("1 - Quantidade de divisores de um numero\n");
        printf("2 - Divisores de um numero\n");
        printf("3 - Divisores, quantidade e soma de um intervalo\n");
        printf("4 - Maximo Divisor Comum de dois números\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
            
                printf("\nInforme um numero para mostrar a quantidade de divisores: ");
                scanf("%d", &num);
                
                numQtdDivisores = qtdDivisores(num);
                
                printf("%d divisores", numQtdDivisores);
                
                break;
                
            case 2:
            
                printf("\nInforme um numero para mostrar seus divisores: ");
                scanf("%d", &num);
                
                quaisDiv(num);
                
                break;
                
            case 3:
            
                printf("Informe o limite inferior: ");
                scanf("%d", &inferior);
                
                printf("Informe o limite superior: ");
                scanf("%d", &superior);
                
                for(i = inferior; i <= superior; i++) {
                    printf("%d - ", i);
                    quaisDiv(i);
                    printf("=> Qtde: %d => Soma: %d\n", qtdDivisores(i), somaDiv(i));
                }
            
                break;
                
            case 4:
            
                printf("Informe o primeiro valor: ");
                scanf("%d", &primeiro);
                
                printf("Informe o segundo valor: ");
                scanf("%d", &segundo);
                
                printf("MDC: %d", maxDiv(primeiro, segundo));
            
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
