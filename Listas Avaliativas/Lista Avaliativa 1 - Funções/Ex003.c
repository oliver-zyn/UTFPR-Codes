#include <stdio.h>
#include "quadrado.h"

int main() {
    int i, numLinhas, numColunas;
    char continuar, caractere;

    do {
        
        printf("Informe o numero de linhas: ");
        scanf("%d", &numLinhas);
        
        printf("Informe o numero de colunas: ");
        scanf("%d", &numColunas);
        
        printf("Informe um caractere: ");
        scanf(" %c", &caractere);
        
        quadrado(numLinhas, numColunas, caractere);
        
        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);
    
    } while (continuar == 'S' || continuar == 's');

    return 0;
}
